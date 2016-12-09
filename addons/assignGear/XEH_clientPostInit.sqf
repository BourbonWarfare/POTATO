#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (GVAR(allowChangeableOptics) && hasInterface) then {
    private _path = (
        missionConfigFile >>
        "CfgLoadouts" >>
        (toLower faction player) >>
        (player getVariable ["F_Gear", [typeOf player] call FUNC(cleanPrefix)])
    );

    private _opticOptions = getArray (_path >> "opticChoices");
    if (_opticOptions isEqualTo []) exitWith { LOG("No optic options found"); };

    {
        private _attachment = _x;
        if (isText (configFile >> "CfgWeapons" >> _attachment >> "weaponInfoType") && {{ _x == _attachment} count _opticOptions < 1}) then {
            _opticOptions pushBack _attachment;
        };
    } forEach (getArray (_path >> "attachments"));

    private _baseAction = [
        "BaseOpticChoice",
        "Choose Optic",
        QPATHTOF(data\scope.paa), // TODO: create base optic image
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
            private _picture = QPATHTOF(data\scope.paa); // TODO: create base optic image
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
                _x
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
