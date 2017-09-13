/*
 * Author: Glowbal
 * Replace a (dead) body by a body bag
 *
 * Arguments:
 * 0: The actor <OBJECT>
 * 1: The patient <OBJECT>
 *
 * Return Value:
 * body bag (will return objNull when run where target is not local) <OBJECT>
 *
 * Example:
 * [player, cursorTarget] call ace_medical_fnc_actionPlaceInBodyBag
 *
 * Public: Yes
 */

#include "script_component.hpp"
#define TREATMENT_TIME 4
#define BODY_BAG_OBJ "ACE_bodyBag"

params ["_caller", "_target"];
TRACE_2("params",_caller,_target);

// If the cursorMenu is open, the loading bar will fail. If we execute the function one frame later, it will work fine
if (uiNamespace getVariable [QACEGVAR(interact_menu,cursorMenuOpened), false]) exitwith {
    [FUNC(treatmentPlaceInBodyBag), _this] call CBA_fnc_execNextFrame;
};

if (!(_target isKindOf "CAManBase") || _caller == _target) exitWith { false };

// Check item
private _items = [BODY_BAG_OBJ];
if (!([_caller, _target, _items] call ACEFUNC(medical,hasItems))) exitwith { false };

private _usersOfItems = ([_caller, _target, _items] call ACEFUNC(medical,useItems)) select 1;

// Player Animation
private _callerAnim = ["AinvPknlMstpSlayWrflDnon_medicOther", "AinvPpneMstpSlayW[wpn]Dnon_medicOther"] select (stance _caller == "PRONE");
_caller setVariable [QGVAR(selectedWeaponOnTreatment), (weaponState _caller)];

// Cannot use secondairy weapon for animation
if (currentWeapon _caller == secondaryWeapon _caller) then {
    _caller selectWeapon (primaryWeapon _caller);
};

private _wpn = ["non", "rfl", "pst"] select (1 + ([primaryWeapon _caller, handgunWeapon _caller] find (currentWeapon _caller)));
private _callerAnim = [_callerAnim, "[wpn]", _wpn] call CBA_fnc_replace;
if (vehicle _caller == _caller && {_callerAnim != ""}) then {
    if (primaryWeapon _caller == "") then {
        _caller addWeapon "ACE_FakePrimaryWeapon";
    };
    if (currentWeapon _caller == "") then {
        _caller selectWeapon (primaryWeapon _caller); // unit always has a primary weapon here
    };

    if (!underwater _caller) then {
        // Weapon on back also does not work underwater
        if (isWeaponDeployed _caller) then {
            TRACE_1("Weapon Deployed, breaking out first",(stance _caller));
            [_caller, "", 0] call ACEFUNC(common,doAnimation);
        };

        if ((stance _caller) == "STAND") then {
            switch (_wpn) do {//If standing, end in a crouched animation based on their current weapon
                case ("rfl"): {_caller setVariable [QGVAR(treatmentPrevAnimCaller), "AmovPknlMstpSrasWrflDnon"];};
                case ("pst"): {_caller setVariable [QGVAR(treatmentPrevAnimCaller), "AmovPknlMstpSrasWpstDnon"];};
                case ("non"): {_caller setVariable [QGVAR(treatmentPrevAnimCaller), "AmovPknlMstpSnonWnonDnon"];};
            };
        } else {
            _caller setVariable [QGVAR(treatmentPrevAnimCaller), animationState _caller];
        };
        [_caller, _callerAnim] call ACEFUNC(common,doAnimation);
    };
};

// Start treatment
[
    TREATMENT_TIME,
    [_caller, _target, _usersOfItems],
    FUNC(successPlaceInBodyBag),
    FUNC(failurePlaceInBodyBag),
    "Placing body in bodybag...",
    {true},
    ["isNotInside", "isNotSwimming"]
] call ACEFUNC(common,progressBar);
