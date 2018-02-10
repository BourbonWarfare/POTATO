/*
 *
 */

#include "script_component.hpp"

params [["_player", objNull, [objNull]]];

if (GVAR(initState) < 1) exitWith {  ERROR("initializeRadios failed to set initSate"); };
if (GVAR(initState) != 1) then {
    INFO_1("Reseting init state from %1 back to 1", GVAR(initState));
    GVAR(initState) = 1;
};
INFO_4("%1 - [InitState %2] Setting up new player [%3][%4]", diag_frameNo, GVAR(initState), _player, typeOf _player);

[
{
    params ["_player"];
    if (!alive _player) exitWith {true};

    private _return = false;

    if (GVAR(initState) == 1) then {
        INFO_2("%1 - [InitState %2] Setting player presets", diag_frameNo, GVAR(initState));

        private _presetArray = switch ((getNumber (configFile >> "CfgVehicles" >> (typeOf _player) >> "side"))) do {
            case 0: { [EAST_SR, EAST_MR, EAST_LR, missionNamespace getVariable [QGVAR(eastDefaultLanguages), [DEFAULT_EAST_LANGS]]] };
            case 1: { [WEST_SR, WEST_MR, WEST_LR, missionNamespace getVariable [QGVAR(westDefaultLanguages), [DEFAULT_WEST_LANGS]]] };
            case 2: { [INDY_SR, INDY_MR, INDY_LR, missionNamespace getVariable [QGVAR(indyDefaultLanguages), [DEFAULT_INDY_LANGS]]] };
            default { [CIV_SR, CIV_MR, CIV_LR, missionNamespace getVariable [QGVAR(civDefaultLanguages), [DEFAULT_CIV_LANGS]]] }; // should just be civs
        };

        _presetArray params ["_sr", "_mr", "_lr", "_babel"];
        INFO_4("radio info [SR:%1 MR:%2 LR:%3 BAB:%4]", _sr, _mr, _lr, _babel);

        GVAR(sideLanguages) = _babel;

        [RADIO_SR, _sr] call ACRE_FUNC(setPreset);
        [RADIO_MR, _mr] call ACRE_FUNC(setPreset);
        [RADIO_LR, _lr] call ACRE_FUNC(setPreset);

        GVAR(initState) = 2;
    };
    if (GVAR(initState) == 2) then {
        if (!(_player getVariable [QEGVAR(assignGear,gearSetup), false])) exitWith {};
        INFO_2("%1 - [InitState %2] Setting briefing", diag_frameNo, GVAR(initState));
        [] call FUNC(addAcreBriefing);
        GVAR(initState) = 3;
    };
    if (GVAR(initState) == 3) then {
        if (!([_player] call ACRE_FUNC(isInitialized))) exitWith {};
        INFO_2("%1 - [InitState %2] Setting Channels", diag_frameNo, GVAR(initState));
        [] call FUNC(configureRadios);
        GVAR(initState) = 4;
        _return = true;
    };
    _return
},
{
    INFO_2("%1 - [InitState %2] DONE", diag_frameNo, GVAR(initState));
}, [_player]] call CBA_fnc_waitUntilAndExecute;
