#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is an intermediate with the goal of handling multiple seekers
 * for a single projectile using ACE missile guidance. While somewhat generic,
 * it is intended for use the MULTI seeker type that combines at least SALH and
 * GPS seekers. The function first takes the missile guidance paramters, and if
 * the seekerTypes array is not properly set, will exit with a target of
 * [0, 0, 0]. The seeker arguments are cached in a variable attached to hte
 * projectile. All seekers parameters are computed, with only the latest
 * valid parameters being stored and returned.
 *
 * Arguments:
 * Missile guidance seeker params
 *
 * Return Value:
 * New target seeker position
 *
 * Examples:
 * [Missile guidance params] call potato_aceEdits_fnc_seekerType_multi;
 *
 * Public: No
 */
params ["", "_args"];
_args params ["_firedEH"];
_firedEH params ["_shooter","","","","_ammo","","_projectile"];

private _seekerModes = getArray (configFile >> "CfgAmmo" >> _ammo >> "ace_missileguidance" >> "seekerTypes");
if (_seekerModes isEqualTo ["MULTI"] || _seekerModes isEqualTo []) exitWith {
    [0, 0, 0]
};
_seekerModes = _seekerModes select [1]; // remove where MULTI should sit in the array

// Create or retrieve the seeker arg hash
private _seekerHash = _projectile getVariable [QGVAR(state), createHashMap];
if (_seekerHash isEqualTo createHashMap) then {
    private _seekerStateParams = _args#4#1;
    if (_shooter != ace_player &&
            !isPlayer _shooter &&
            (_seekerStateParams#0#0) isEqualTo [0, 0, 0]) then {
        (_seekerStateParams#0) set [0, getPosASL getAttackTarget _shooter];
    };
    {
        _seekerHash set [_x, +_seekerStateParams];
    } forEach _seekerModes;
    _projectile setVariable [QGVAR(state), _seekerHash];
};

// Go through and do every seeker calculations in reverse order as to keep
// the earlier defined seekers at a higher precidence
private _seekerTypesPath = configFile >> "ace_missileGuidance_SeekerTypes";
private _seekerTargetPos = [0, 0, 0];
{
    (_args#4) set [1, _seekerHash get _x];
    private _seekerFunction = getText (_seekerTypesPath >> _x >> "functionName");
    private _localSeekerTargetPos = call (missionNamespace getVariable _seekerFunction);
    // override with "most valued" seeker value - we could do some sort of fusion here
    //              may look into that for GBU-53/B w/ SALH, Active Radar, and GPS
    if (_localSeekerTargetPos isNotEqualTo [0, 0, 0]) then {
        _seekerTargetPos = _localSeekerTargetPos;
    };
} forEachReversed _seekerModes;

_seekerTargetPos
