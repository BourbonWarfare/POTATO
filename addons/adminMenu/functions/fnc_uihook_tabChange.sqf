#include "script_component.hpp"

params ["", "_sel"];
TRACE_1("params",_sel);

disableSerialization;

private _fnc_addListOfPlayers = {
    params ["_inputList", "_listCtrl", "_condition", "_nameCode"];

    lbClear _listCtrl;
    private _listOfUnits = [];
    {
        if (_x call _condition) then {
            private _name = [_x] call ace_common_fnc_getName;
            private _recentMessage = "";
            {
                _x params ["_xTime", "_xMsg", "_xFrom"];
                if ((_xFrom == _name) && {(time - _xTime) < 300}) then {_recentMessage = _recentMessage + _xMsg + "\n"};
            } forEach (missionNamespace getVariable [QEGVAR(adminComs,logs), []]);
            _name = _x call _nameCode;
            TRACE_3("pushBack",_name,_x,_recentMessage);
            _listOfUnits pushBack [_name, _x, _recentMessage];
        };
    } forEach _inputList;
    _listOfUnits sort true;
    {
        _x params ["_xName", "", "_xRecentMessage"];
        private _color = [[1,1,1,1], [1,0,0,1]] select (_xRecentMessage != "");
        private _index = _listCtrl lbAdd _xName;
        _listCtrl lbSetColor [_index, _color];
        _listCtrl lbSetTooltip [_index, _xRecentMessage];
    } forEach _listOfUnits;
    _listCtrl lbSetCurSel 0;
    _listOfUnits apply {_x select 1} // return
};

{
    _x ctrlShow (_forEachIndex == _sel);
} forEach UI_TABS_CONTROLS;

switch (_sel) do {
case (0): {
        TRACE_1("showing zeus tab", _sel);
        GVAR(ui_zeusTargets) = [allUnits, UI_TAB_ZEUS_PLAYERS, {(isPlayer _this) && {alive _this}},
        {(["[ZEUS]", ""] select (isNull (getAssignedCuratorLogic _this))) + ([_this] call ace_common_fnc_getName)}] call _fnc_addListOfPlayers;
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
        GVAR(teleportPersonList) = [allUnits, UI_TAB_TELEPORT_PERSON, {(isPlayer _this) && {alive _this}},
        {([_this] call ace_common_fnc_getName)}] call _fnc_addListOfPlayers;
        
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
        TRACE_1("showing reset gear hint tab", _sel);

        private _listOfUnits = [allUnits, UI_TAB_FIXGEAR_PERSON, {(isPlayer _this) && {alive _this}},
        {(["", "*NAKED* "] select ((uniform _this) == "")) + ([_this] call ace_common_fnc_getName)}] call _fnc_addListOfPlayers;
        
        UI_TAB_FIXGEAR_PERSON setVariable ["listOfUnits", _listOfUnits];
    };
};
