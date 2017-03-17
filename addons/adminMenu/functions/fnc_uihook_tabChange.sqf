#include "script_component.hpp"

params ["", "_sel"];
TRACE_1("params",_sel);

disableSerialization;

private _fnc_setListOfPlayers = {
    params [
        ["_listCtrl", controlNull, [controlNull]],
        ["_nameCode", {[[_this] call ACEFUNC(common,getName), 0]}, [{}]],
        ["_condition", {true}, [{}]]
    ];

    lbClear _listCtrl;

    private _playerList = if (time > 120) then {
        (allPlayers - (entities "HeadlessClient_F"))
    } else {
        ((entities [["CAManBase"], ["HeadlessClient_F"], true, true]) select { isPlayer _x })
    };

    {
        if (_x call _condition) then {
            (_x call _nameCode) params [
                ["_name", "", [""]],
                ["_weight", 0, [0]]
            ];

            private _recentMessages = [];
            {
                _x params ["_time", "_message", "_from"];
                if ((_from == [_x] call ACEFUNC(common,getName)) && {(time - _time) < 300}) then {
                    _recentMessages pushBack _message;
                };
            } forEach (missionNamespace getVariable [QEGVAR(adminComs,logs), []]);

             private _index = _listCtrl lbAdd _name;
             _listCtrl lbSetValue [_index, _weight];
             _listCtrl lbSetData [_index, [_x] call BIS_fnc_objectVar];
             _listCtrl lbSetColor [_index, [[1,0,0,1], [1,1,1,1]] select (_recentMessages isEqualTo [])];
             _listCtrl lbSetTooltip [_index, _recentMessages joinString "\n"];

             TRACE_6("Item added to list", _listCtrl, _x, _name, _weight, [_x] call BIS_fnc_objectVar, _recentMessages);
        };
    } forEach _playerList;

    lbSortByValue _listCtrl;
    _listCtrl lbSetCurSel 0;
};

{
    _x ctrlShow (_forEachIndex == _sel);
} forEach UI_TABS_CONTROLS;

switch (_sel) do {
case (0): {
        TRACE_1("showing zeus tab", _sel);
        [
            UI_TAB_ZEUS_PLAYERS,
            {
                private _isNotZeus = isNull (getAssignedCuratorLogic _this);
                [
                    format [
                        "%1%2",
                        [_this] call ACEFUNC(common,getName),
                        [" [ZEUS]", ""] select _isNotZeus
                    ],
                    [1, 0] select _isNotZeus
                ]
            }
        ] call _fnc_setListOfPlayers;
    };
case (1): {
        TRACE_1("showing supplies tab", _sel);
        lbClear UI_TAB_SUPPLIES_TYPE;
        GVAR(supplyClassNames) = [];
        {
            private _className = configName _x;
            if (isClass (configFile >> "CfgVehicles" >> _className)) then {
                TRACE_2("veh exists in modset",_x,_className);
                GVAR(supplyClassNames) pushBack _className;
                private _description = if (isText (_x >> "displayName")) then {
                    getText (_x >> "displayName"); //use custom name
                } else {
                    getText (configFile >> "CfgVehicles" >> _className >> "displayName"); // use veh name
                };
                _index = UI_TAB_SUPPLIES_TYPE lbAdd format ["%1", _description];
                UI_TAB_SUPPLIES_TYPE lbSetTooltip [_index, _className];
            } else {
                TRACE_2("veh missing from modset",_x,_className);
            };
        } forEach (configProperties [configFile >> QGVAR(supplies)]);
        UI_TAB_SUPPLIES_TYPE lbSetCurSel 0;

        lbClear UI_TAB_SUPPLIES_GROUP;
        GVAR(groupsArray) = [];
        {
            if ( ({(isPlayer _x)&&{alive _x}} count (units _x)) > 0) then {
                GVAR(groupsArray) pushBack _x;
                private _grpMembers = "";
                {_grpMembers = _grpMembers + format ["%1, ", (name _x)];} forEach (units _x);
                _txt = format ["%1 [%2]", _x, _grpMembers];
                private _index = UI_TAB_SUPPLIES_GROUP lbAdd _txt;
                UI_TAB_SUPPLIES_GROUP lbSetTooltip [_index, _grpMembers];
            };
        } forEach allGroups;
        UI_TAB_SUPPLIES_GROUP lbSetCurSel 0;
    };
case (2): {
        TRACE_2("showing end mission tab", _sel, GVAR(openEndMission));
        if (GVAR(openEndMission)) then {
            UI_TAB_END_TEXT ctrlShow true;
            UI_TAB_END_UNLOCK ctrlShow false;
            _txt = format ["Players Alive: %1<br/>", ({(alive _x)&&{isPlayer _x}} count allUnits)];
            _txt = _txt + format ["<br/><t color='#9999FF'>West Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == west}} count allUnits), ({(alive _x)&&(side _x == west)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#FF9999'>East Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == east}} count allUnits), ({(alive _x)&&(side _x == east)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#99FF99'>Indp Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == resistance}} count allUnits), ({(alive _x)&&(side _x == resistance)&&(isPlayer _x)} count allUnits)];
            _txt = _txt + format ["<br/><t color='#FF99FF'>Civ  Alive: %1 [Players: %2]</t>", ({(alive _x)&&{side _x == civilian}} count allUnits), ({(alive _x)&&(side _x == civilian)&&(isPlayer _x)} count allUnits)];
            UI_TAB_END_TEXT ctrlSetStructuredText parseText _txt;
        } else {
            UI_TAB_END_TEXT ctrlShow false;
            UI_TAB_END_UNLOCK ctrlShow true;
        };
    };
case (3): {
        TRACE_1("showing teleport tab", _sel);
        [
            UI_TAB_TELEPORT_PERSON,
            nil, // default to ace name
            {alive _this}
        ] call _fnc_setListOfPlayers;

        lbClear UI_TAB_TELEPORT_GROUP;
        GVAR(groupsArray) = [];
        {
            if ( ({(isPlayer _x)&&(alive _x)} count (units _x)) != 0) then {
                GVAR(groupsArray) pushBack _x;
                private _grpMembers = "";
                {_grpMembers = _grpMembers + format ["%1, ", (name _x)];} forEach (units _x);
                _txt = format ["%1 [%2]", _x, _grpMembers];
                private _index = UI_TAB_TELEPORT_GROUP lbAdd _txt;
                UI_TAB_TELEPORT_GROUP lbSetTooltip [_index, _grpMembers];
            };
        } forEach allGroups;
        UI_TAB_TELEPORT_GROUP lbSetCurSel 0;
    };
case (6): {
        TRACE_1("showing mission hint tab", _sel);
        lbClear UI_TAB_MISSIONHINT_SIDE;
        lbClear UI_TAB_MISSIONHINT_RANK;
        {
            private _sideText = if (_x isEqualType 0) then {
                ["Dead", "All Players"] select _x;
            } else {
                str _x;
            };
            UI_TAB_MISSIONHINT_SIDE lbAdd _sideText;
        } forEach MISSION_HINT_SIDES;
        UI_TAB_MISSIONHINT_SIDE lbSetCurSel 0;
        {
            private _rankText = switch (_x) do {
                case (0): {"Private or higher"};
                case (1): {"Corporal or higher"};
                case (2): {"Sergeant or higher"};
                case (3): {"Lieutenant or higher"};
                default {"All Ranks"};
            };
            UI_TAB_MISSIONHINT_RANK lbAdd _rankText;
        } forEach MISSION_HINT_RANKS;
        UI_TAB_MISSIONHINT_RANK lbSetCurSel 0;
    };
case (7): {
        TRACE_1("showing fix unit tab", _sel);

        [
            UI_TAB_FIX_UNIT_LIST,
            {
                if (alive _this) then {
                    if (_this isKindOf QEGVAR(spectate,spectator)) then {
                        [format ["%1 (SPECTATOR)", name _this], 3]
                    } else {
                        if (uniform _x == "") then {
                            [format ["%1 (NAKED)", name _this], 0]
                        } else {
                            [name _this, 1]
                        }
                    }
                } else {
                    [format ["%1 (DEAD)", [_this] call ACEFUNC(common,getName)], 2]
                }
            }
        ] call _fnc_setListOfPlayers;
    };
};
