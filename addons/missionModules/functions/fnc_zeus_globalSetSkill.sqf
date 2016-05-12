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

        [QGVAR(aiSkill_set), true, false, true] call ace_common_fnc_setSetting;
        if (!GVAR(aiSkill_set)) exitWith {
            TRACE_1("Setting must be forced off", GVAR(aiSkill_set));
        };

        private _val = _logic getVariable ["aiSkill_general", -1];
        if (_val != -1) then {
            [QGVAR(aiSkill_commanding_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_commanding_max), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_courage_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_courage_max), _val, false, true] call ace_common_fnc_setSetting;
        };

        _val = _logic getVariable ["aiSkill_aimingAccuracy", -1];
        if (_val != -1) then {
            [QGVAR(aiSkill_aimingAccuracy_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_aimingAccuracy_max), _val, false, true] call ace_common_fnc_setSetting;
        };

        _val = _logic getVariable ["aiSkill_weaponHandling", -1];
        if (_val != -1) then {
            [QGVAR(aiSkill_aimingShake_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_aimingShake_max), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_aimingSpeed_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_aimingSpeed_max), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_reloadSpeed_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_reloadSpeed_max), _val, false, true] call ace_common_fnc_setSetting;
        };

        _val = _logic getVariable ["aiSkill_spotting", -1];
        if (_val != -1) then {
            [QGVAR(aiSkill_spotDistance_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_spotDistance_max), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_spotTime_min), _val, false, true] call ace_common_fnc_setSetting;
            [QGVAR(aiSkill_spotTime_max), _val, false, true] call ace_common_fnc_setSetting;
        };

        _val = _logic getVariable ["aiSkill_COVER", -1];
        if (!(_val isEqualTo -1)) then { [QGVAR(aiSkill_COVER), _val, false, true] call ace_common_fnc_setSetting; };

        _val = _logic getVariable ["aiSkill_AUTOCOMBAT", -1];
        if (!(_val isEqualTo -1)) then { [QGVAR(aiSkill_AUTOCOMBAT), _val, false, true] call ace_common_fnc_setSetting; };

        ["UpdateAISettings", []] call ace_common_fnc_globalEvent;

        TRACE_2("ai settings updated",GVAR(aiSkill_COVER),GVAR(aiSkill_AUTOCOMBAT));
    } else {
        TRACE_1("closed but not set",_logic);
    };

    deleteVehicle _logic;
}, [_logic]] call ace_common_fnc_waitUntilAndExecute;
