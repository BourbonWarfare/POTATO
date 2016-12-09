#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (GVAR(allowChangeableOptics) && hasInterface) then {
    private _path = (
        missionConfigFile >>
        "CfgLoadouts" >>
        (toLower faction player) >>
        (player getVariable ["F_Gear", [typeOf player] call FUNC(cleanPrefix)])
    );

    private _opticOptions = [];
    {
        if (isText (configFile >> "CfgWeapons" >> _x >> "weaponInfoType")) then {
            if (!GVAR(allowMagnifiedOptics)) then {
                private _minZoom = 999; //FOV, so smaller is more zoomed in
                {
                    if (isNumber (_x >> "opticsZoomMin")) then { _minZoom = _minZoom min (getNumber (_x >> "opticsZoomMin")); };
                    if (isText (_x >> "opticsZoomMin")) then { _minZoom = _minZoom min (call compile getText (_x >> "opticsZoomMin")); };
                    nil
                } count configProperties [configFile >> "CfgWeapons" >> _x >> "ItemInfo" >> "OpticsModes"]; // count used here for speed, make sure nil is above this line

                if (_minZoom >= 0.25) then {
                    _opticOptions pushBackUnique (toLower _x);
                };
            } else {
                _opticOptions pushBackUnique (toLower _x);
            };
        };
    } forEach ((getArray (_path >> "opticChoices")) + (getArray (_path >> "attachments")));

    if (_opticOptions isEqualTo []) exitWith { LOG("No optic options found"); };

    private _baseAction = [
        "BaseOpticChoice",
        "Choose Optic",
        QPATHTOF(data\scope.paa),
        {},
        {missionNamespace getVariable [QEGVAR(safeStart,startTime_PV), -1] != -1}
    ] call ACEFUNC(interact_menu,createAction);

    [
        typeOf player, 1,
        ["ACE_SelfActions", "ACE_Equipment"],
        _baseAction
    ] call  ACEFUNC(interact_menu,addActionToClass);

    {
        if (isClass (configFile >> "CfgWeapons" >> _x)) then {
            private _picture = QPATHTOF(data\scope.paa);
            if (isText (configFile >> "CfgWeapons" >> _x >> "picture")) then {
                _picture = getText (configFile >> "CfgWeapons" >> _x >> "picture");
            };

            private _name = _x;
            if (isText (configFile >> "CfgWeapons" >> _x >> "displayName")) then {
                _name = getText (configFile >> "CfgWeapons" >> _x >> "displayName");
            };

            private _action = [
                format ["OpticChoice%1",_forEachIndex],
                _name,
                _picture,
                FUNC(setOptic),
                FUNC(canSetOptic),
                {},
                [_x, _opticOptions]
            ] call ACEFUNC(interact_menu,createAction);

            [
                typeOf player, 1,
                ["ACE_SelfActions", "ACE_Equipment", "BaseOpticChoice"],
                _action
            ] call ACEFUNC(interact_menu,addActionToClass);
        } else {
            WARNING_1("Optic option not a valid class", _x);
        };
    } forEach _opticOptions;
};
