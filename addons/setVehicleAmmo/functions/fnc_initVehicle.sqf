#include "script_component.hpp"
/*Arguments:
 * 0: Vehicle <OBJECT>
 * 1: Loadout Value <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle, _loadoutValue] call potato_setVehicleAmmo_fnc_initVehicle
 */

params ["_vehicle", "_loadoutValue"];
TRACE_2("params",_vehicle,_loadoutValue);
if (_vehicle getVariable [QGVAR(ammoInit), false]) exitWith {TRACE_1("ammoinit",_vehicle getVariable [ARR_2(QGVAR(ammoInit),false)])};
if (!(_loadoutValue isEqualType "")) exitWith {TRACE_1("not string",_loadoutValue)};
if (_loadoutValue == "") exitWith {TRACE_1("default",_loadoutValue);};
if (CBA_missionTime < 1) then { // we want it to be a string for code reuse, etc.
    [{
        params ["_vehicle", "_loadoutStr"];
        TRACE_1("copy loadout",_vehicle getVariable [ARR_2(QGVAR(copy),false)]);
        if (_vehicle getVariable [QGVAR(copy), false]) then {
            private _vicCust = GVAR(vehicleCustomization) getOrDefault [typeOf _vehicle, [], true];
            _vicCust set [2, [_loadoutStr, _vehicle getVariable ["ace_rearm_scriptedLoadout", false]]];
        };
    }, [_vehicle, _loadoutValue]] call CBA_fnc_execNextFrame;
};
_loadoutValue = call compile _loadoutValue;
if (!(_loadoutValue isEqualType [])) exitWith {TRACE_1("not array",_loadoutValue)};

TRACE_1("",_loadoutValue);
TRACE_3("veh",typeOf _vehicle,local _vehicle,magazines _vehicle);

{
    _x params ["_xPath", "_xMag", "_xCount"];
    while {_xCount < 0} do {
        _vehicle removeMagazineTurret [_xMag, _xPath];
        TRACE_2("removing",_xMag,_xPath);
        _xCount = _xCount + 1;
    };
    while {_xCount > 0} do {
        if (_xCount >= 1) then {
            _vehicle addMagazineTurret [_xMag, _xPath];
            TRACE_2("adding full",_xMag,_xPath);
            _xCount = _xCount - 1;
        } else {
            private _rounds = floor (_xCount * getNumber (configFile >> "CfgMagazines" >> _xMag >> "count"));
            _vehicle addMagazineTurret [_xMag, _xPath, _rounds];
            TRACE_3("adding partial",_xMag,_xPath,_rounds);
            _xCount = 0;
        };
    };
} forEach _loadoutValue;
_vehicle setVariable [QGVAR(ammoInit), true];

TRACE_1("veh",magazines _vehicle);
