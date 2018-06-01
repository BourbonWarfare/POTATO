/*
 * Author: AACO
 * Resets animation when putting in body bage completes
 *
 * Arguments:
 * 0: The mortician <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call potato_bodyBag_fnc_resetAnimation
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_caller"];

if (primaryWeapon _caller == "ACE_FakePrimaryWeapon") then {
    _caller removeWeapon "ACE_FakePrimaryWeapon";
};
if (vehicle _caller == _caller && {!underwater _caller}) then {
    private _lastAnim = _caller getVariable [QGVAR(treatmentPrevAnimCaller), ""];
    //Don't play another medic animation (when player is rapidily treating)
    TRACE_2("Reseting to old animation", animationState player, _lastAnim);
    switch (toLower _lastAnim) do {
        case "ainvpknlmstpslaywrfldnon_medic": { _lastAnim = "AmovPknlMstpSrasWrflDnon" };
        case "ainvppnemstpslaywrfldnon_medic": { _lastAnim = "AmovPpneMstpSrasWrflDnon" };
        case "ainvpknlmstpslaywnondnon_medic": { _lastAnim = "AmovPknlMstpSnonWnonDnon" };
        case "ainvppnemstpslaywpstdnon_medic": { _lastAnim = "AinvPpneMstpSlayWpstDnon" };
        case "ainvpknlmstpslaywpstdnon_medic": { _lastAnim = "AmovPknlMstpSrasWpstDnon" };
    };
    [_caller, _lastAnim, 2] call EFUNC(common,doAnimation);
};
_caller setVariable [QGVAR(treatmentPrevAnimCaller), nil];

private _weaponSelect = (_caller getVariable [QGVAR(selectedWeaponOnTreatment), []]);
if ((_weaponSelect params [["_previousWeapon", ""]]) && {(_previousWeapon != "") && {_previousWeapon in (weapons _caller)}}) then {
    for "_index" from 0 to 299 do {
        _caller action ["SwitchWeapon", _caller, _caller, _index];
        //Just check weapon, muzzle and mode (ignore ammo in case they were reloading)
        if (((weaponState _caller) select [0,3]) isEqualTo (_weaponSelect select [0,3])) exitWith {TRACE_1("Restoring", (weaponState _caller));};
        if ((weaponState _caller) isEqualTo ["","","","",0]) exitWith {ERROR("weaponState not found");};
    };
} else {
    _caller action ["SwitchWeapon", _caller, _caller, 299];
};
