#include "script_component.hpp"

_debugMsg = format ["%1 is doing Weapon Test", profileName];
["potato_adminMsg", [_debugMsg]] call ACEFUNC(common,globalEvent);

if ((isNull player) || {!alive player}) exitWith {};

_diaryHyperlinkedText = format ["Weapon Report at %1 minutes:", (floor (time/60))];
_lowAmmo = false;

{
    _color = switch (side _x) do {
    case (west): {"#0088EE"};//0,0.45,0.9,1
    case (east): {"#DD0000"};//[0.75,0,0,1]
    case (resistance): {"#00DD00"};//[0,0.75,0,1]
    case (civilian): {"#880099"};//[0.6,0,0.75,1]
        default {"#FFFFFF"};
    };
    _playable = (({(_x in playableUnits) || (_x in switchableUnits)} count (units _x)) > 0);
    _playableText = if (_playable) then {"Playable"} else {"Non-Playable"};
    _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<br/><font color='%1' size='16'>%2 - %3</font><br/>", _color, (groupID _x), _playableText];
    {
        _pText = if ((primaryWeapon _x) == "") then {
            "[No Weapon!-<font color='#FF0000'>0</font>]"
        } else {
            _config = configfile >> "CfgWeapons" >> (primaryWeapon _x);
            _mags = getArray (_config >> "magazines");
            _count = 0;
            {
                if ((_x select 0) in _mags) then {
                    _count = _count + (_x select 1);
                };
            } forEach (magazinesAmmoFull _x);
            if (_count <= 100) then {
                _lowAmmo = true;
                _count = if (_count == 0) then {
                    format ["<font color='#FF0000'>%1</font>", _count];
                } else {
                    format ["<font color='#FFFF00'>%1</font>", _count];
                };
            };
            format ["[<img image='%1' width='40' height='20'/>-%2]", (getText (_config >> "picture")), _count];
        };
        _sText = if ((secondaryWeapon _x) == "") then {
            "[No Tube-<font color='#FF0000'>0</font>]"
        } else {
            _config = configfile >> "CfgWeapons" >> (secondaryWeapon _x);
            _mags = getArray (_config >> "magazines");
            _count = 0;
            {
                if ((_x select 0) in _mags) then {
                    _count = _count + (_x select 1);
                };
            } forEach (magazinesAmmoFull _x);
            format ["[<img image='%1' width='40' height='20'/>-%2]", (getText (_config >> "picture")), _count];
        };


        _xIcon = gettext (configfile >> "CfgVehicles" >> typeOf (vehicle _x) >> "icon");
        _image = gettext (configfile >> "CfgVehicleIcons" >> _xIcon);
        _name = if (isPlayer _x) then {
            format ["%1-%2", (vehicleVarName _x), (name _x)];
        } else {
            format ["%1-AI", (vehicleVarName _x), (name _x)];
        };

        _diaryHyperlinkedText = _diaryHyperlinkedText + format ["<img image='%1' width='16' height='16'/><font size='14'>%2 - %3 - %4</font><br/>", _image, _name, _pText, _sText];
    } forEach (units _x);
} forEach allGroups;

player createDiaryRecord ["Admin Menu", ["Weapon Report", _diaryHyperlinkedText]];
