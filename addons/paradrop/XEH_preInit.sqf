#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

ADDON = true;

GVAR(paradropId) = 0;
GVAR(paradropObjects) = createHashMap;
[QGVAR(ejectAndParachuteUnit), {
    params ["_unit", "_vehicle", "_parachute", "_planeVelocity", ["_delay", 2]];
    
    _unit allowDamage false;
    _unit disableCollisionWith _v;
    moveOut _unit;
    unassignVehicle _unit;
    [_unit] allowGetIn false;
    _unit setDir (getDir _vehicle);
    
    [{
        params ["_unit", "_parachute", "_vehicle", "_planeVelocity"];
        
        private _para = createVehicle[_parachute, [0, 0, 0], [], 0, "NONE"];
        _unit disableCollisionWith _para;
        
        _para setPosASL (getPosASLVisual _unit);
        _para setVectorDirAndUp [vectorDirVisual _unit, vectorUpVisual _unit];
        _para setVelocity _planeVelocity;
        
        _unit moveInDriver _para;
        _unit assignAsDriver _para;
        [_unit] allowGetIn true;
        [_unit] orderGetIn true;
        
        _unit enableCollisionWith _vehicle;
        _unit allowDamage true;
        
    }, [_unit, _parachute, _vehicle, _planeVelocity], _delay] call CBA_fnc_waitAndExecute;
    
}] call CBA_fnc_addEventHandler;

