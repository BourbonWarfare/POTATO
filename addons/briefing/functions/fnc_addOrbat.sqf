/*
 * Author: PabstMirror
 * Function used to add the order of battle to player's diary
 *
 * Arguments:
 * 0: Unit to add to the OrBat to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addOrbat;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

_this spawn {
    uiSleep 10;

    params ["_unit"];
    TRACE_1("",_unit);

    private _diaryBuilder = [];
    _diaryBuilder pushBack "<font size='8'>Only accurate at mission start.</font>";

    {
        if (({isPlayer _x} count (units _x)) > 0) then {
            if (((side _x) getFriend playerSide) >= 0.6) then {
                private _color = switch (side _x) do {
                    case (west): { "#0088EE" }; // use profile colors here
                    case (east): { "#DD0000" };
                    case (resistance): { "#00DD00" };
                    case (civilian): { "#880099" };
                    default { "#FFFFFF" };
                };
                _diaryBuilder pushBack format ["<font color='%1' size='16'>%2</font>", _color, (groupID _x)];
                {
                    private _xIcon = gettext (configfile >> "CfgVehicles" >> typeOf (vehicle _x) >> "icon");
                    private _image = gettext (configfile >> "CfgVehicleIcons" >> _xIcon);
                    _diaryBuilder pushBack format ["<img image='%1' width='16' height='16'/><font size='14'>%2</font>", _image, (name _x)];
                } forEach (units _x);
            };
        };
    } forEach allGroups;

    _unit createDiaryRecord ["diary", ["ORBAT", _diaryBuilder joinString "<br/>"]];
};
