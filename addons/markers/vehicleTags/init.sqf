#include "\z\potato\addons\markers\script_component.hpp"

if (isServer) then {
    [QGVAR(serverTag), {
        params ["_vehicle", "_tag", "_unit"];
        INFO_3("serverTag",_vehicle,_tag,name _unit);
        private _selectionClan = getText (configOf _vehicle >> "selectionClan");
        _vehicle setObjectTextureGlobal [_selectionClan, _tag]
    }] call CBA_fnc_addEventHandler;
};

if (!hasInterface) exitWith {};

GVAR(tags) = [
    [["Blank", ""], "#(argb,1,1,1)color(0,0,0,0)"],
    [["COY"]], [["1PLT"]], [["2PLT"]],
    [["ASL", "Alpha"]], [["A1"]], [["A2"]],
    [["BSL", "Bravo"]], [["B1"]], [["B2"]],
    [["CSL", "Charlie"]], [["C1"]], [["C2"]],
    [["WSL", "WPL", "MMG", "MAT", "HAT", "MTR", "SAM", "ST", "Arty"]],
    [["ENG", "DEMO"]],
    [["LOGI", "ENG", "DEMO"]],
    [["IFV1"]], [["IFV2"]], [["IFV3"]], [["IFV4"]],
    [["TH1"]], [["TH2"]], [["TH3"]], [["TH4"]]
];

private _fnc_statement = {};
private _fnc_condition = {
    (missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1)  // safe start active
    && {(rankID _player) >= 1}
    && {
        private _selectionClan = getText (configOf _target >> "selectionClan");
        (_selectionClan in selectionNames _target)
    }
};
private _fnc_children = {
    params ["_target", "_player", "_params"];
    private _actions = [];

    private _fnc_childStatement = {
        params ["_target", "_player", "_xTag"];

        TRACE_2("sending tag",_target, _xTag);
        [QGVAR(serverTag), [_target, _xTag, _player]] call CBA_fnc_serverEvent;
    };

    private _groupID = groupID (group _player);
    {
        _x params ["_xNames", ["_xTag", ""]];
        if ((_xNames findIf {_x in _groupID}) == -1) then { continue };

        private _name = _xNames # 0;
        if (_xTag == "") then { _xTag = format [QPATHTOF(vehicleTags\%1_ca.paa), _name] };

        private _action = [str _forEachIndex, _name, _xTag, _fnc_childStatement, {true}, {}, _xTag] call ace_interact_menu_fnc_createAction;
        _actions pushBack [_action, [], _target];
    } forEach GVAR(tags);

    _actions
};
private _action = [QGVAR(vehicleTags), "Set Logo", "", _fnc_statement, _fnc_condition, _fnc_children] call ACEFUNC(interact_menu,createAction);
["Car", 0, ["ACE_MainActions"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
["Tank", 0, ["ACE_MainActions"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
["Helicopter", 0, ["ACE_MainActions"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
