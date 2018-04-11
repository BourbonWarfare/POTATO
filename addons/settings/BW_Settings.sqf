/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/


_settings = [
[QACEGVAR(advanced_fatigue,performanceFactor), 1.4],
[QACEGVAR(advanced_fatigue,recoveryFactor), 1.6],
[QACEGVAR(cookoff,enable), false],
[QACEGVAR(cookoff,ammoCookoffDuration), 0.15],
[QACEGVAR(finger,enabled), true],
[QACEGVAR(frag,maxTrack), 5],
[QACEGVAR(gforces,enabledFor), 0],
[QACEGVAR(goggles,effects), 1],
[QACEGVAR(hearing,autoAddEarplugsToUnits), false],
[QACEGVAR(laserPointer,enabled), false],
[QACEGVAR(map,DefaultChannel), 1],
[QACEGVAR(medical_ai,enabledFor), 0],
[QACEGVAR(medical_blood,enabledFor), 1],
[QACEGVAR(nightvision,effectScaling), 0.5, false, true],
[QACEGVAR(nightvision,fogScaling), 0.5, false, true],
[QACEGVAR(nightvision,noiseScaling), 0.5, false, true],
[QACEGVAR(nightvision,aimDownSightsBlur), 0.5, false, true],
[QACEGVAR(overheating,enabled), false],
[QACEGVAR(refuel,rate), 10],
[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
[QACEGVAR(ui,groupBar), false],
[QACEGVAR(zeus,autoAddObjects), true],

["sthud_settings_squadbar", true, true] // Reversed Logic ("No Squad Bar") AND Forced because it's User settable
];
