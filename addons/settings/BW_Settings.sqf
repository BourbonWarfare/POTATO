/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/



/*
// Old medical settings from mission.sqm:
Setting ace_medical_level not used - value: [2,1]
Setting ace_medical_medicsetting not used - value: [2,1]
Setting ace_medical_enableunconsciousnessai not used - value: [0,1]
Setting ace_medical_littercleanupdelay not used - value: [300,1]
Setting ace_medical_medicsetting_pak not used - value: [1,1]
Setting ace_medical_medicsetting_surgicalkit not used - value: [2,1]
Setting ace_medical_consumeitem_pak not used - value: [1,1]
Setting ace_medical_consumeitem_surgicalkit not used - value: [1,1]
Setting ace_medical_usecondition_pak not used - value: [1,1]
Setting ace_medical_usecondition_surgicalkit not used - value: [1,1]
Setting ace_medical_healhitpointafteradvbandage not used - value: [true,1]
Setting ace_medical_painisonlysuppressed not used - value: [false,1]
*/


_settings = [
// Medical:
[QACEGVAR(medical,bleedingcoefficient), 1, true], // default: 1.0 (also set in mission.sqm) [forced to override old bwmf]
// [QACEGVAR(medical,fatalDamageSource), 1], // default: 0
[QACEGVAR(medical,ivFlowRate), 1.5], // default: 1.0
[QACEGVAR(medical,spontaneousWakeUpChance), 0.4], // default: 0.05
[QACEGVAR(medical,spontaneousWakeUpEpinephrineBoost), 2], // default: 1
[QACEGVAR(medical_treatment,woundReopening), false], // default: true
[QACEGVAR(medical_treatment,clearTraumaAfterBandage), true], // default: false
[QACEGVAR(medical_treatment,litterCleanupDelay), 300], // default: 600
// [QACEGVAR(medical_treatment,cprSuccessChance), 0.6], // default: 0.4
[QACEGVAR(medical_statemachine,AIUnconsciousness), false], // default: true
[QACEGVAR(medical_statemachine,cardiacArrestTime), 1], // default: 30

// Medical Extras:
[QACEGVAR(medical_ai,enabledFor), 0],
[QACEGVAR(medical_blood,enabledFor), 1],


[QACEGVAR(advanced_fatigue,performanceFactor), 1.4],
[QACEGVAR(advanced_fatigue,recoveryFactor), 1.6],
[QACEGVAR(cookoff,enable), false],
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
[QACEGVAR(zeus,autoAddObjects), true],

["sthud_settings_squadbar", true, true], // Reversed Logic ("No Squad Bar") AND Forced because it's User settable

["niarms_magSwitch", false] // it's use of setUnitLoadout may cause problems

];
