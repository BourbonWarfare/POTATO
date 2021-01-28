/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/

_settings = [
// Medical:
[QACEGVAR(medical,bleedingcoefficient), 1, true], // default: 1.0 (also set in mission.sqm) [forced to override old bwmf]
// [QACEGVAR(medical,fatalDamageSource), 1], // default: 0 // wait till L/K values finalized
[QACEGVAR(medical,ivFlowRate), 1.5], // default: 1.0
[QACEGVAR(medical,spontaneousWakeUpChance), 0.4], // default: 0.05
[QACEGVAR(medical,spontaneousWakeUpEpinephrineBoost), 2], // default: 1
[QACEGVAR(medical_treatment,clearTraumaAfterBandage), true], // default: false
[QACEGVAR(medical_treatment,litterCleanupDelay), 300], // default: 600
[QACEGVAR(medical_treatment,cprSuccessChance), 0.75], // default: 0.4
[QACEGVAR(medical_statemachine,AIUnconsciousness), false], // default: true
[QACEGVAR(medical_statemachine,cardiacArrestTime), 180], // default: 30

// Medical Extras:
[QACEGVAR(medical_ai,enabledFor), 0],
[QACEGVAR(medical_blood,enabledFor), 1],


// Vehicle Damage
[QEGVAR(aiVehicleBail,enableCrewBailing), false],
[QEGVAR(aiVehicleBail,enableCookoffDetonations), false],
[QEGVAR(aiVehicleBail,enableCookoff), false],
[QEGVAR(aiVehicleBail,enableCookoffMultihit), false],
[QACEGVAR(vehicle_damage,enabled), true],
[QACEGVAR(fire,enabled), true],
[QACEGVAR(fire,enableFlare), false],


[QACEGVAR(advanced_fatigue,performanceFactor), 1.4],
[QACEGVAR(advanced_fatigue,recoveryFactor), 1.6],
[QACEGVAR(cookoff,enable), 0],
[QACEGVAR(cookoff,ammoCookoffDuration), 0.15],
[QACEGVAR(finger,enabled), true],
[QACEGVAR(frag,maxTrack), 5],
[QACEGVAR(gforces,enabledFor), 0],
[QACEGVAR(goggles,effects), 1],
[QACEGVAR(hearing,autoAddEarplugsToUnits), false],
[QACEGVAR(hearing,enableCombatDeafness), false],
[QACEGVAR(laserPointer,enabled), false],
[QACEGVAR(map,DefaultChannel), 1],
[QACEGVAR(nightvision,effectScaling), 0.5, false, true],
[QACEGVAR(nightvision,fogScaling), 0.5, false, true],
[QACEGVAR(nightvision,noiseScaling), 0.5, false, true],
[QACEGVAR(nightvision,aimDownSightsBlur), 0.25, false, true],
[QACEGVAR(overheating,enabled), false],
[QACEGVAR(refuel,rate), 10],
[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
[QACEGVAR(ui,groupBar), false],
[QACEGVAR(weather,showCheckAirTemperature), false],
[QACEGVAR(zeus,autoAddObjects), true],

["niarms_magSwitch", false] // it's use of setUnitLoadout may cause problems

];
