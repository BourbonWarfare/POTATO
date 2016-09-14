#include "script_component.hpp"

/*
if (isServer) then {
    [] call FUNC(setAcreGlobalSettings);
    [] call FUNC(setAcreSideSettings);
};
 */

// Remove by october
if (isNil "acre_api_fnc_ignoreAntennaDirection") then {
    INFO_1("Setting omnidirectional for acre pre-904",true);
    acre_sys_signal_omnidirectionalRadios = true;
} else {
    INFO_1("Setting omnidirectional for acre post-904",true);
    [true] call acre_api_fnc_ignoreAntennaDirection;
};

// set global settings, see script_component.hpp for default values

["ace_settingsInitialized", {
    TRACE_3("",GVAR(enabled),hasInterface,EGVAR(assignGear,usePotato));

    if (GVAR(enabled)) then {
        if !(missionNamespace getVariable [QEGVAR(assignGear,usePotato), false]) exitWith {
            ERROR("Radios enabled, but gear assign is not running");
        };

        // Make sure to create presets all machines;    from ACRE API:
        // Warning All presets must exist and match on all clients and especially the server; regardless of where the presets are used.
        // If you create a preset, copy a preset or modify a presets data information; these changes must occur on all clients and the server.
        // If they do not, ACRE may not work.

        [] call FUNC(initializeRadios);


        if (!hasInterface) exitWith {
            GVAR(initState) = 999;
            INFO_2("%1 - [InitState %2] DONE (Non Interface)", diag_frameNo, GVAR(initState));
        };

        [
        {
            if (isNull player) exitWith {false};

            private _return = false;

            if (GVAR(initState) == 1) then {
                INFO_2("%1 - [InitState %2] Setting player presets", diag_frameNo, GVAR(initState));
                private _groupLanguages = (group player) getVariable [QGVAR(assignedLanguages),[]];
                GVAR(playerLanguages) = player getVariable [QGVAR(assignedLanguages), _groupLanguages];

                TRACE_1("",playerSide);
                private _presetArray = switch (playerSide) do {
                case west: { [WEST_SR, WEST_MR, WEST_LR, GVAR(westDefaultLanguages)] };
                case east: { [EAST_SR, EAST_MR, EAST_LR, GVAR(eastDefaultLanguages)] };
                case independent: { [INDY_SR, INDY_MR, INDY_LR, GVAR(indyDefaultLanguages)] };
                    default { [CIV_SR, CIV_MR, CIV_LR, GVAR(civDefaultLanguages)] }; // should just be civs
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
                if (!(player getVariable [QEGVAR(assignGear,gearSetup), false])) exitWith {};
                INFO_2("%1 - [InitState %2] Setting briefing", diag_frameNo, GVAR(initState));
                [] call FUNC(addAcreBriefing);
                GVAR(initState) = 3;
            };
            if (GVAR(initState) == 3) then {
                if (!([player] call ACRE_FUNC(isInitialized))) exitWith {};
                INFO_2("%1 - [InitState %2] Setting Channels", diag_frameNo, GVAR(initState));
                [] call FUNC(configureRadios);
                GVAR(initState) = 4;
                _return = true;
            };
            _return
        },
        {
            INFO_2("%1 - [InitState %2] DONE", diag_frameNo, GVAR(initState));
        }, []] call CBA_fnc_waitUntilAndExecute;
    };
}] call CBA_fnc_addEventHandler;
