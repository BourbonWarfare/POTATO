#include "..\script_component.hpp"

[FUNC(loop), [], 5] call CBA_fnc_waitAndExecute;

if ((GVAR(show) == 0) || {GVAR(show) == 1 && {!EGVAR(safeStart,safeStartEnabled)}}) exitWith {
    if (GVAR(setOn) isEqualTo []) exitWith {};
    TRACE_1("full cleanup",GVAR(show));
    {
        _x setVariable ["diwako_dui_nametags_customGroup", nil];
    } forEach (GVAR(setOn) + allUnits); // handle respawns
    GVAR(setOn) = [];
};

{
    private _goby = _x getVariable [QGVAR(goBy), ""];
    if (_goby == "") then {
        _x setVariable ["diwako_dui_nametags_customGroup", nil];
    } else {
        GVAR(setOn) pushBackUnique _x;
        TRACE_2("setting",_x,_goby);

        // DUI is expecting a simple string for customGroup ie `<t>%1</t>`
        // We inject the group and then a fake </t> and new line to add a third line to the nametag

        private _group = groupId (group _x);
        private _formating = format ["<t font='%1' color='%2' size='%3' shadow='%4'>", diwako_dui_nametags_fontGroup, GVAR(colorHex), (profileNamespace getVariable ['igui_diwako_dui_nametags_h', pixelH * 64]) * 9, diwako_dui_nametags_groupFontShadow];
        private _customGroup = format ["%1</t><br/>%2[ %3 ]", _group, _formating, _goby];
        _x setVariable ["diwako_dui_nametags_customGroup", _customGroup];
    };
} forEach (player nearEntities ["CAManBase", 50]);
