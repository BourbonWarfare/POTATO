#include "script_component.hpp"

#define RANGE_TO_GROUP 75
#define TIME_KEEP_SHOWING_AFTER_LOSING_SIGHT 20
#define ICON_HEIGHT_ABOVE_GROUND 20
#define RANDOM_GROUP_COLLAPSE_TEST 0.01
#define REPORT_ICON_MEDICAL "\A3\Ui_f\data\IGUI\RscIngameUI\RscUnitInfo\icon_cross_ca.paa"
#define REPORT_PRIOITY_MEDICAL 3
#define REPORT_ICON_RECON "\A3\Ui_F_Curator\Data\Logos\arma3_curator_eye_32_ca.paa"
#define REPORT_PRIOITY_RECON 1

if (GVAR(state) == 0) exitWith { // Start: Gather friendly units
    private _curator = getAssignedCuratorLogic player;
    GVAR(friendlyUnits) = (curatorEditableObjects _curator) select {
        (alive _x)
        && {_x isKindOf "CaManBase"}
        && {!(_x in GVAR(allTargets))}
        && {[_x] call ace_common_fnc_isAwake}
    };

    GVAR(friendlyGroups) = [];
    {GVAR(friendlyGroups) pushBackUnique (group _x)} forEach GVAR(friendlyUnits);
    // systemChat format ["%1: Loop Start [%2 Friendly Units] [%3 fps]", CBA_missionTime toFixed 1, count GVAR(friendlyUnits), diag_fps toFixed 1];

    if (!(GVAR(friendlyUnits) isEqualTo [])) then {
        GVAR(state) = 1;
        GVAR(stateSubIndex) = (count GVAR(friendlyUnits)) - 1;
    } else {
        if (GVAR(allTargets) isEqualTo []) then {
            GVAR(state) = 4;
        } else {
            GVAR(state) = 2;
            GVAR(stateSubIndex) = (count GVAR(allTargets)) - 1;
        };
    };
};
if (GVAR(state) == 1) exitWith { // Search for targets on each friendly unit
    private _unit = GVAR(friendlyUnits) select GVAR(stateSubIndex);

    if (alive _unit) then {

        private _unitTargets = _unit targets [true, 0, [], 60];
        {
            if (alive _x) then {
                private _index = GVAR(allTargets) find _x;

                // Get unit's info on target
                private _knowsAbout = _unit knowsAbout _x;
                (_unit targetKnowledge _x) params ["_groupKnows", "_known", "_lastSeen", "_lastShot", "_knownSide", "_posError", "_estPosASL"];

                if (_index == -1) then { // Create new entry
                    TRACE_2("First Contact",_x, typeOf _x);
                    _index = GVAR(allTargets) pushBack _x;
                    GVAR(allTargetInfo) pushBack [-1, -1, _estPosASL, CBA_missionTime, false, [], GVAR(uniqueID)];
                    GVAR(uniqueID) = GVAR(uniqueID) + 1;
                    private _unitGroup = group _unit;
                    if (!isNull _unitGroup) then {
                        [_unitGroup, REPORT_PRIOITY_RECON, "", 15, REPORT_ICON_RECON, [0,0,0,1]] call FUNC(groupReport);
                    };
                };
                // Global info on target
                private _globalInfo = GVAR(allTargetInfo) select _index;
                _globalInfo params ["_globalLastSeen", "_globalKnowsAbout"];

                if (_lastSeen > _globalLastSeen) then {
                    // Sometimes the estimated position is really far off for things like rocket lauchers, just ignore
                    if ((_estPosASL distance2d (getPos _x)) > 50) exitWith {TRACE_1("badbeef",_estPosASL distance2d (getPos _x));};
                    _globalInfo set [0, _globalLastSeen max _lastSeen];
                    _globalInfo set [2, _estPosASL];
                };
                _globalInfo set [1, _globalKnowsAbout max (_unit knowsAbout _x)];
            };
        } forEach _unitTargets;
    };
    if (GVAR(stateSubIndex) == 0) then {
        if (GVAR(allTargets) isEqualTo []) then {
            GVAR(state) = 4;
        } else {
            GVAR(state) = 2;
            GVAR(stateSubIndex) = (count GVAR(allTargets)) - 1;
        };
    } else {
        GVAR(stateSubIndex) = GVAR(stateSubIndex) - 1;
    };
};
if (GVAR(state) == 2) exitWith { // Filter deleated and process target list
    private _unit = GVAR(allTargets) select GVAR(stateSubIndex);
    private _globalInfo = GVAR(allTargetInfo) select GVAR(stateSubIndex);
    _globalInfo params [
    "_globalLastSeen",      // 0: Time last seen by any unit <NUMBER>
    "_globalKnowsAbout",    // 1: knowsAbout by any unit 0-4 <NUMBER>
    "_globalPositionASL",   // 2: Most recent known position <ARRAY>
    "_firstSeen",           // 3: Time first seen <NUMBER>
    "_addedToCurator",      // 4: Added to curator <BOOL>
    "_groupArray",          // 5: Group <ARRAY>
    "_uniqueID"             // 6: Unique ID <NUMBER>
    ];

    if (!alive _unit) then { // Remove Null or Dead from track
        TRACE_1("Removing Dead/Deleted",_unit);
        GVAR(allTargets) deleteAt GVAR(stateSubIndex);
        GVAR(allTargetInfo) deleteAt GVAR(stateSubIndex);
        if (_addedToCurator && {!isNull _unit}) then {
            GVAR(removeFromCurator) pushBack _unit;
        };
    } else {
        private _timeSinceLastSeen = CBA_missionTime - _globalLastSeen;
        if (_timeSinceLastSeen < TIME_KEEP_SHOWING_AFTER_LOSING_SIGHT) then {
            if (!_addedToCurator) then {
                _globalInfo set [4, true];
                GVAR(addToCurator) pushBack _unit;
            };
        } else {
            if (_addedToCurator) then {
                _globalInfo set [4, false];
                GVAR(removeFromCurator) pushBack _unit;
            };
        };

        private _isMan = _unit isKindOf "CaManBase";
        private _needGroup = (_groupArray isEqualTo []) || {_isMan && {((_groupArray select 1) distance2d _globalPositionASL) > RANGE_TO_GROUP}};
        if (_needGroup) then {
            TRACE_1("Need Group",_groupArray);
            if (_isMan) then {
                private _bestGroup = [];
                private _bestDistance = 999999;
                {
                    _x params ["_isInfantry", "_grpPositionAverage"];
                    private _distToGrp = _unit distance2d _grpPositionAverage;
                    if (_isInfantry && {_distToGrp < _bestDistance}) then {
                        _bestGroup = _x;
                        _bestDistance = _distToGrp;
                    };
                } forEach GVAR(targetGroups);
                if (_bestDistance < RANGE_TO_GROUP) then {
                    TRACE_2("Adding to existing group",_bestDistance,_bestGroup);
                    _groupArray = _bestGroup;
                } else {
                    TRACE_2("Creating new inf group",_bestDistance,_bestGroup);
                    _groupArray = [true, _globalPositionASL, [], "?", -1, "\A3\ui_f\data\map\markers\nato\group_0.paa"];
                    GVAR(targetGroups) pushBack _groupArray;
                };
            } else {
                private _icon = [_unit] call FUNC(getIcon);
                TRACE_1("Creating new veh group",_icon);
                _groupArray = [false, _globalPositionASL, [], "?", -1, _icon];
                GVAR(targetGroups) pushBack _groupArray;
            };
            _globalInfo set [5, _groupArray];
        };
        // Update group with unit's position:
        (_groupArray select 2) pushBack _globalPositionASL;
        // Update group's last seen time
        _groupArray set [4, (_groupArray select 4) max _globalLastSeen];
    };

    if (GVAR(stateSubIndex) == 0) then {
        if (GVAR(targetGroups) isEqualTo []) then {
            GVAR(state) = 4;
        } else {
            GVAR(state) = 3;
            GVAR(stateSubIndex) = (count GVAR(targetGroups)) - 1;
        };
    } else {
        GVAR(stateSubIndex) = GVAR(stateSubIndex) - 1;
    };
};
if (GVAR(state) == 3) exitWith {
    private _groupArray = GVAR(targetGroups) select GVAR(stateSubIndex);
    _groupArray params [
    "_isInfantry",          // 0: Is Infantry <BOOL>
    "_grpPositionAverage",  // 1: Group Position (AGL, Z always 50) <ARRAY>
    "_grpPositionList",     // 2: Array of positions <ARRAY>
    "_spotTimeString",      // 3: Last seen time (clock time) <STRING>
    "_grpLastSeen",         // 4: Last seen time (in-game) <NUMBER>
    "_icon"                 // 5: Icon (vehicle type or fireteam size) <STRING>
    ];
    private _unitsInGroup = count _grpPositionList;


    private _removeGroup = (_unitsInGroup == 0);
    // Test if we can collapse this group into other nearby ones:
    if (_isInfantry && {_unitsInGroup <= 3} && {(random 1) < RANDOM_GROUP_COLLAPSE_TEST}) then {
        private _countInRangeOfOtherGroups = 0;
        {
            private _unitPos = _x;
            {
                _x params ["_isInfantry", "_grpPositionAverage"];
                private _distToGrp = _unitPos distance2d _grpPositionAverage;
                if (_isInfantry && {_distToGrp < (0.75 * RANGE_TO_GROUP)} && {!(_x isEqualTo _groupArray)}) exitWith {
                    _countInRangeOfOtherGroups = _countInRangeOfOtherGroups + 1;
                };
            } forEach GVAR(targetGroups);
        } forEach _grpPositionList;
        TRACE_2("random collapse test",_countInRangeOfOtherGroups,_unitsInGroup);
        if (_countInRangeOfOtherGroups == _unitsInGroup) then {
            TRACE_1("badbeef collapsing",_groupArray);
            _removeGroup = true;
        };
    };

    if (_removeGroup) then { // Remove Null or Dead from track
        TRACE_1("badbeef Removing Group",_groupArray);
        _groupArray resize 0; // Arrays are references, so this will force a group rescan on all targets using this group
        GVAR(targetGroups) deleteAt GVAR(stateSubIndex);
    } else {
        // Last Seen:
        private _timeSinceLastSeen = CBA_missionTime - _grpLastSeen;
        private _spotTimeString = [daytime - (_timeSinceLastSeen / 3600), "HH:MM"] call BIS_fnc_timeToString;
        _groupArray set [3, _spotTimeString];
        // Position Avg:
        private _newPosAvg = [0,0,0];
        {
            _newPosAvg = _newPosAvg vectorAdd _x;
        } forEach _grpPositionList;
        _newPosAvg = _newPosAvg vectorMultiply (1 / _unitsInGroup);
        _newPosAvg set [2, ICON_HEIGHT_ABOVE_GROUND];
        _grpPositionList resize 0;
        _groupArray set [1, _newPosAvg];
        // Unit Icon:
        if (_isInfantry) then {
            _icon = [_unitsInGroup] call FUNC(getIcon);
            _groupArray set [5, _icon];
        };
    };

    if (GVAR(stateSubIndex) == 0) then {
        GVAR(state) = 4;
    } else {
        GVAR(stateSubIndex) = GVAR(stateSubIndex) - 1;
    };
};
if (GVAR(state) == 4) exitWith { // Send add/remove zeus units info to server
    if (!(GVAR(addToCurator) isEqualTo [])) then {
        TRACE_1("Adding to Curator",GVAR(addToCurator));
        private _curator = getAssignedCuratorLogic player;
        [QGVAR(addToCurator), [_curator, GVAR(addToCurator)]] call CBA_fnc_serverEvent;
        GVAR(addToCurator) resize 0;
    };
    if (!(GVAR(removeFromCurator) isEqualTo [])) then {
        TRACE_1("Removing from Curator",GVAR(removeFromCurator));
        private _curator = getAssignedCuratorLogic player;
        [QGVAR(removeFromCurator), [_curator, GVAR(removeFromCurator)]] call CBA_fnc_serverEvent;
        GVAR(removeFromCurator) resize 0;
    };

    if (GVAR(friendlyGroups) isEqualTo []) then {
        GVAR(state) = 6;
    } else {
        GVAR(state) = 5;
        GVAR(stateSubIndex) = (count GVAR(friendlyGroups)) - 1;
    };
};
if (GVAR(state) == 5) exitWith { // Check medical status of friendly groups
    private _zeusGroup = GVAR(friendlyGroups) select GVAR(stateSubIndex);

    if (!isNull _zeusGroup) then {
        private _problems = 0;
        {
            if (!alive _x) then {
                if (_x getVariable [QGVAR(needToReport_dead), true]) then {
                    _x setVariable [QGVAR(needToReport_dead), false];
                    _problems = _problems + 3;
                };
            } else {
                if (_x getVariable ["ace_medical_isBleeding", false]) then {
                    if (_x getVariable [QGVAR(needToReport_bleeding), true]) then {
                        _x setVariable [QGVAR(needToReport_bleeding), false];
                        _problems = _problems + 1;
                    };
                };
            };
        } forEach (units _zeusGroup);

        if (_problems > 0) then {
            TRACE_2("Casulties",_zeusGroup,_problems);
            private _showFor = linearConversion [1, 3, _problems, 15, 30, true];
            private _showFor = 99999999;
            [_zeusGroup, REPORT_PRIOITY_MEDICAL, "Taking Casulties", _showFor, REPORT_ICON_MEDICAL, [0,0,0,1]] call FUNC(groupReport);
        };
    };

    if (GVAR(stateSubIndex) == 0) then {
        GVAR(state) = 6;
    } else {
        GVAR(stateSubIndex) = GVAR(stateSubIndex) - 1;
    };
};
if (GVAR(state) == 6) exitWith { // Filter reports if group is null or time out

    GVAR(friendlyReports) = GVAR(friendlyReports) select {
        _x params ["_xGroup", "_xKeepUntil"];
        private _keep = (!isNull _xGroup) && {CBA_missionTime < _xKeepUntil};
        if (!_keep) then {TRACE_1("Dropping Report", _x);};
        _keep
    };

    GVAR(state) = 0;
};

ERROR("Error bad state");

