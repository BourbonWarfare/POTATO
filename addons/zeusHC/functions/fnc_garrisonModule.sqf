/*
 * Author: AACO
 * Function called when the garrison module is placed in zeus or when the garrison module is loaded at init
 *
 * Arguments:
 * 0: logic object <OBJECT>
 *
 * Examples:
 * [objLogic] call potato_zeusHC_fnc_garrisonModule;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic","","_activated"];

if (_activated && local _logic) then {
    GVAR(garrisonLocation) = getPosATL _logic;

    if (isServer && (_logic getVariable [QGVAR(garrisonChance), -1]) > -1) then {
        private _radius = [abs(_logic getVariable QGVAR(garrisonRadius)),0,2000] call EFUNC(core,ensureRange);
        private _chance = [_logic getVariable QGVAR(garrisonChance),0,100] call EFUNC(core,ensureRange);

        ([
            _logic getVariable QGVAR(garrisonMin),
            _logic getVariable QGVAR(garrisonMax),
            1,
            20
        ] call EFUNC(core,ensureBoundedMinMax)) params ["_min","_max"];


        [
            { time > (_this select 7) },
            { (_this select [0,7]) call FUNC(garrisonSpawn) },
            [
                _logic getVariable QGVAR(garrisonFaction),
                [] call FUNC(garrisonUnitLimit),
                _chance,
                _radius,
                _min,
                _max,
                GVAR(garrisonLocation),
                random 15
            ]
        ] call CBA_fnc_waitUntilAndExecute;

    } else {
        createDialog QGVAR(garrison_dialog);
    };

    deleteVehicle _logic;
};
