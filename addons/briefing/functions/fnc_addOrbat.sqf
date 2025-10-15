/*
 * Author: PabstMirror
 * Function used to add the order of battle to player's diary, or update a
 * previously added orbat.
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
    params ["_unit", ["_delay", 10, [123]]];
    uiSleep _delay;

    TRACE_1("",_unit);
    private _orbatHash = createHashMap;
    private _diaryBuilder = [];
    private _colorSelectArray = ["#FFFFFF", GVAR(highlighColorOption) call BIS_fnc_colorRGBtoHTML];
    private _drawCompact = GVAR(useCompactOrbat);
    private _shouldSort = GVAR(sortOrbat);
    {
        if (({isPlayer _x} count (units _x)) > 0) then {
            if (((side _x) getFriend playerSide) >= 0.6) then {
                private _color = switch (side _x) do {
                    case (west): { "#0088EE" }; // use profile colors here?
                    case (east): { "#DD0000" };
                    case (resistance): { "#00DD00" };
                    case (civilian): { "#880099" };
                    default { "#FFFFFF" };
                };
                if (_drawCompact) then {
                    private _groupID = groupId _x;
                    private _groupIDArr = _groupID splitString " ";
                    _groupId = (_groupIDArr select {
                        !(_x regexMatch ".*opf.*|.*ind.*|.*blu.*|.*msv.*|.*mech.*|.*commonwealth.*/gi")
                    }) joinString " ";
                    private _groupArray = [[],["<br/>"]] select (count _groupID > 2 && _diaryBuilder isNotEqualTo [] && _shouldSort);
                    _groupArray pushBack format ["<font color='%1' size=12>%2 </font>", _color, _groupID];
                    private _groupUnitArray = [];
                    {
                        private _color = _colorSelectArray select (_unit == _x);
                        private _xIcon = getText (configOf _x >> "icon");
                        private _roleText = switch (true) do {
                            case (_xIcon == "iconMan"): {""};
                            case ([_xIcon == "iconManEngineer"]): {QPATHTOF(data\wrench.paa)};
                            case (_xIcon == "iconManMedic"): {"\A3\ui_f\data\map\vehicleicons\pictureHeal_ca.paa"};
                            default {""};
                        };
                        if (_roleText == "") then {
                            _groupUnitArray pushBack format ["<font color='%1' size=12>%2</font>", _color, name _x];
                        } else {
                            _groupUnitArray pushBack format ["<font color='%2' size=12><img src='%1' width=12 height=12/> %3</font>", _roleText, _color, name _x];
                        };
                    } forEach (units _x);
                    _groupArray pushBack (_groupUnitArray joinString ", ");
                    if (_shouldSort) then {
                        _orbatHash set [_groupID, [roleDescription leader _x, _groupArray joinString "", false]];
                    } else {
                        _diaryBuilder pushBack ((_groupArray joinString "")+ "<br/>");
                    };
                } else {
                    _diaryBuilder pushBack format ["<font color='%1' size=16>%2</font>", _color, groupId _x];
                    {
                        private _color = _colorSelectArray select (_unit == _x);
                        private _xIcon = getText (configOf _x >> "icon");
                        private _image = getText (configFile >> "CfgVehicleIcons" >> _xIcon);
                        _diaryBuilder pushBack format ["<img src='%1' width=16 height=16/><font color='%2' size=14>%3</font>", _image, _color, name _x];
                    } forEach (units _x);
                };
            };
        };
    } forEach allGroups;


    if (_shouldSort) then {
        [_orbatHash, _diaryBuilder] call FUNC(sortOrbat);
    };
    _diaryBuilder pushBack "<font size='8'>Only accurate at mission start.</font>";
    // Clean leading newlines
    while {_diaryBuilder isNotEqualTo [] && {_diaryBuilder#0 == "<br/>"}} do {
        _diaryBuilder deleteAt 0;
    };
    if (_diaryBuilder isNotEqualTo [] && {(_diaryBuilder#0) select [0, 5] == "<br/>"}) then {
        _diaryBuilder set [0, (_diaryBuilder#0) select [5]];
    };

    // find the diary
    private _diaryEntries = _unit allDiaryRecords "diary";
    // find and replace existing orbat pages
    private _newDiaryEntryText = _diaryBuilder joinString "<br/>";
    private _noOrbatFound = true;
    {
        _x params ["_idx", "_title", "", "", "", "", "", "", "_record"];
        if (_title == "ORBAT") then {
            _unit setDiaryRecordText [["diary", _record], ["ORBAT", _newDiaryEntryText]];
            _noOrbatFound = false;
        };
    } forEach _diaryEntries;

    // if we didn't find and replace, add one
    if (_noOrbatFound) then {
        _unit createDiaryRecord ["diary", ["ORBAT", _newDiaryEntryText]];
    };
};
