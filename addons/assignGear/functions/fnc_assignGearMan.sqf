/*
 * Author: PabstMirror
 * Applies a loadout to a unit (cached)
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player] call potato_assignGear_fnc_assignGearMan;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);

params ["_unit", ["_request", false, [false]]];
TRACE_3("",_unit, local _unit,_request);

BEGIN_COUNTER(assignGearMan);

private _faction = toLower faction _unit;
private _unitClassname = [typeOf _unit] call FUNC(cleanPrefix);
private _loadout = _unit getVariable ["F_Gear", _unitClassname]; //Check variable f_gear, otherwise default to typeof
private _path = missionConfigFile >> "CfgLoadouts" >> _faction >> _loadout;

if ((!isClass(_path)) && GVAR(useFallback)) then {
    _path = missionConfigFile >> "CfgLoadouts" >> _faction >> "fallback";
};

if (!isClass(_path)) exitWith {
    TRACE_2("No Class Found",_unit,typeOf _unit);
    _unit setVariable [QGVAR(gearSetup), true, true];
};

private _randomIndex = floor (random GVAR(maxRandomization));
private _loadoutKey = format ["%1:%2", _path, _randomIndex];

private _loadoutArray = GVAR(loadoutCache) getVariable _loadoutKey;

if (isNil "_loadoutArray") then {
    TRACE_1("compiling new",_loadoutKey);
    BEGIN_COUNTER(getLoadoutFromConfig);
    _loadoutArray = [_path] call FUNC(getLoadoutFromConfig);
    END_COUNTER(getLoadoutFromConfig);
    TRACE_1("loadout array: ", _loadoutArray);
    GVAR(loadoutCache) setVariable [_loadoutKey, _loadoutArray];
};

// set unit loadout overrides our sick shades :(
_loadoutArray set [LA_FACEWARE_INDEX, goggles _unit];
_unit setUnitLoadout _loadoutArray;

if (isText (_path >> "init")) then {
    TRACE_1("calling init code", getText (_path >> "init"));
    _unit call compile ("this = _this;"+ getText (_path >> "init"));
};

_unit setVariable [QGVAR(gearSetup), true, true];

END_COUNTER(assignGearMan);

if (_request) exitWith {}; // don't run hack on requests
// Stupid hack to fix gear automaticly until we can sort out why setUnitLoadout ocasionly fails on JIPs
[{
    params ["_unit", "_loadoutArray"];
    if (isNull _unit) exitWith {};

    private _arrayUniform = (_loadoutArray select LA_UNIFORM_INDEX) param [0, ""];
    private _arrayVest = (_loadoutArray select LA_VEST_INDEX) param [0, ""];
    private _arrayBackpack = (_loadoutArray select LA_BACKPACK_INDEX) param [0, ""];
    TRACE_6("Checking loadout: Uniform [%1-%2] Vest [%3-%4] Backpack [%5-%6]", _arrayUniform, uniform _unit, _arrayVest, vest _unit, _arrayBackpack, backpack _unit);

    if ((_arrayUniform != (uniform _unit)) || {_arrayVest != (vest _unit)} || {_arrayBackpack != (backpack _unit)}) then {
        ERROR_2("Mismatch [%1] [%2]", name _unit, typeOf _unit);
        _unit setUnitLoadout _loadoutArray;
        ["potato_adminMsg", [(format ["Auto-reset gear on %1", name _unit]), "Server"]] call CBA_fnc_globalEvent;
    };
}, [_unit, _loadoutArray], 15] call CBA_fnc_waitAndExecute;
