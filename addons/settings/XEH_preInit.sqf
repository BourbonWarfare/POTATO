#include "script_component.hpp"

// turn off RHS engine startup script
RHS_ENGINE_STARTUP_OFF = 1; // any non-nil value turns this off

if (isServer) then {
    // set STUI settings for the BW experience (occlusion set mission side)
    ["sthud_settings_squadbar", false, 0, "server"] call CBA_settings_fnc_set;
    ["sthud_settings_removedeadviaproximity", true, 0, "server"] call CBA_settings_fnc_set;

    // set ACE settings for the BW experience
    [QACEGVAR(advanced_fatigue,performanceFactor), 1.3, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(advanced_fatigue,recoveryFactor), 2, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(cookoff,enable), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(cookoff,ammoCookoffDuration), 0.15, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(frag,maxTrack), 5, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(gforces,enabledFor), 0, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(goggles,effects), 1, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(hearing,autoAddEarplugsToUnits), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(laserPointer,enabled), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(map,DefaultChannel), 1, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(medical_ai,enabledFor), 0, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(medical_blood,enabledFor), 1, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(nightvision,effectScaling), 0.5, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(nightvision,fogScaling), 0.5, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(overheating,enabled), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(respawn,removeDeadBodiesDisconnected), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(ui,ammoCount), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(ui,groupBar), false, 0, "server"] call CBA_settings_fnc_set;
    [QACEGVAR(zeus,autoAddObjects), true, 0, "server"] call CBA_settings_fnc_set;

    // Settings Test:
    [{
        if ((ace_medical_level > 1) && {!ace_medical_healHitPointAfterAdvBandage}) then {
            ["potato_adminMsg", ["Warning: Advanced Medical but healHitPointAfterAdvBandage is false", "Mission"]] call CBA_fnc_globalEvent;
        };
    }, [], 5] call CBA_fnc_waitAndExecute;
};
