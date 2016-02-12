#include "script_component.hpp"

params ["_logic"];
TRACE_1("params",_logic);

if (!isServer) exitWith {};

[{
    params ["_logic"];
    (isNull _logic) || {_logic getVariable ["closed", false]}
}, {
    params ["_logic"];
    if (isNull _logic) exitWith {TRACE_1("null",_logic);};

    if (_logic getVariable ["set", false]) then {
        private _val = _logic getVariable ["aiSkill_general", -1];
        if (_val != -1) then { [QGVAR(aiSkill_general), _val, false, true] call ace_common_fnc_setSetting; };
        _val = _logic getVariable ["aiSkill_aimingAccuracy", -1];
        if (_val != -1) then { [QGVAR(aiSkill_aimingAccuracy), _val, false, true] call ace_common_fnc_setSetting; };
        _val = _logic getVariable ["aiSkill_weaponHandling", -1];
        if (_val != -1) then { [QGVAR(aiSkill_weaponHandling), _val, false, true] call ace_common_fnc_setSetting; };
        _val = _logic getVariable ["aiSkill_spotting", -1];
        if (_val != -1) then { [QGVAR(aiSkill_spotting), _val, false, true] call ace_common_fnc_setSetting; };

        TRACE_4("ai settings updated",GVAR(aiSkill_general),GVAR(aiSkill_aimingAccuracy),GVAR(aiSkill_weaponHandling),GVAR(aiSkill_spotting));

        {
            [_x] call FUNC(setSkills);
        } forEach allUnits;
    } else {
        TRACE_1("closed but not set",_logic);
    };

    deleteVehicle _logic;
}, [_logic]] call ace_common_fnc_waitUntilAndExecute;
