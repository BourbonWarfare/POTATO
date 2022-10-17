//pragma SKIP_COMPILE
/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/

_settings = [
	// Medical:
	[QACEGVAR(medical,bleedingcoefficient), 0.4, true], // default: 1.0 (also set in mission.sqm) [forced to override old bwmf]
	[QACEGVAR(medical,ivFlowRate), 2.5], // default: 1.0
	[QACEGVAR(medical,spontaneousWakeUpChance), 0.6, true], // default: 0.05
	[QACEGVAR(medical,spontaneousWakeUpEpinephrineBoost), 2, true], // default: 1
	[QACEGVAR(medical,deathChance), 0, true],
	[QACEGVAR(medical,fatalDamageSource), 0, true],
	[QACEGVAR(medical,fractureChance), 0.5, true],
	[QACEGVAR(medical,painCoefficient), 1.3, true],
	[QACEGVAR(medical,painUnconsciousChance), 0.3, true],
	[QACEGVAR(medical_treatment,advancedDiagnose), 1, true], // default: 1 (Allows diagnosing death/CA)
	[QACEGVAR(medical_treatment,clearTrauma), 0, true], // default: 0
	[QACEGVAR(medical_treatment,litterCleanupDelay), 300, true], // default: 600
	[QACEGVAR(medical_treatment,cprSuccessChanceMin), 0.4, true], // default: 0.4
	[QACEGVAR(medical_treatment,cprSuccessChanceMax), 0.85, true], // default: 0.4
	[QACEGVAR(medical_statemachine,AIUnconsciousness), true], // default: true
	[QACEGVAR(medical_statemachine,cardiacArrestTime), 600, true], // default: 30
	[QACEGVAR(medical_statemachine,fatalInjuriesAI), 0, true], // default: 0
	[QACEGVAR(medical_treatment,advancedBandages), 1, true], // default: 0
	[QACEGVAR(medical_treatment,advancedMedication), true, true], // default: true
	[QACEGVAR(medical,limping), 1, true], // default: 1
	[QACEGVAR(medical_treatment,allowSelfIV), 1, true], // default: true
	[QACEGVAR(medical_treatment,woundReopenChance), 0.69, true], // default: who fuckin knows eh bud

	// Medical Extras:
	[QACEGVAR(medical_ai,enabledFor), 0, true],
	[QACEGVAR(medical_blood,enabledFor), 2],
	[QACEGVAR(medical_treatment,holsterRequired), 1, true],
	[QACEGVAR(medical,playerDamageThreshold), 1.25, true],
	[QACEGVAR(medical,AIDamageThreshold), 0.3, true],
	[QACEGVAR(medical_feedback,painEffectType), 1, true],
	[QACEGVAR(medical_feedback,bloodVolumeEffectType), 0, true],

	// Medical GUI
	[QACEGVAR(medical_gui,enableActions), 2, true],
	[QACEGVAR(medical_gui,enableMedicalMenu), 1, true],
	[QACEGVAR(medical_gui,enableSelfActions), false, true],
	[QACEGVAR(medical_gui,interactionMenuShowTriage), 1, true],
	[QACEGVAR(medical_gui,maxDistance), 3, true],
	[QACEGVAR(medical_gui,openAfterTreatment), true, true],


	// Vehicle Damage
	// [QEGVAR(aiVehicleBail,enableCrewBailing), false],
	// [QEGVAR(aiVehicleBail,enableCookoffDetonations), false],
	// [QEGVAR(aiVehicleBail,enableCookoff), false],
	// [QEGVAR(aiVehicleBail,enableCookoffMultihit), false],
	[QACEGVAR(vehicle_damage,enabled), true],
	[QACEGVAR(fire,enabled), true],
	[QACEGVAR(fire,enableFlare), false],


	[QACEGVAR(advanced_fatigue,performanceFactor), 1.4],
	[QACEGVAR(advanced_fatigue,recoveryFactor), 1.6],
	[QACEGVAR(cookoff,enable), 1],
	[QACEGVAR(cookoff,ammoCookoffDuration), 0.15],
	[QACEGVAR(finger,enabled), true],
	[QACEGVAR(fortify,timeCostCoefficient), 0.5, true],
	[QACEGVAR(fortify,timeMin), 0, true],
	[QACEGVAR(frag,maxTrack), 2],
	[QACEGVAR(gforces,enabledFor), 0],
	[QACEGVAR(goggles,effects), 1], // note: user-setting, we don't force
	[QACEGVAR(hearing,autoAddEarplugsToUnits), false],
	[QACEGVAR(hearing,enableCombatDeafness), false, true],
	[QACEGVAR(interaction,enableGroupRenaming), false, true],
	[QACEGVAR(laserPointer,enabled), false],
	[QACEGVAR(map,DefaultChannel), 1],
	[QACEGVAR(nightvision,effectScaling), 0.4, true, true],
	[QACEGVAR(nightvision,fogScaling), 0, true, true],
	[QACEGVAR(nightvision,noiseScaling), 0.3, true, true],
	[QACEGVAR(nightvision,aimDownSightsBlur), 0.25, true, true],
	[QACEGVAR(nightvision,disableNVGsWithSights), false, true, true],
	[QACEGVAR(nightvision,shutterEffects), false, true, true],
	[QACEGVAR(overheating,enabled), false, true, true],
	[QACEGVAR(refuel,rate), 10],
	[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
	[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
	[QACEGVAR(ui,groupBar), false, true], // Forced because it's User settable
	[QACEGVAR(weather,showCheckAirTemperature), false],
	[QACEGVAR(zeus,autoAddObjects), true],
	
	// Quick mount
	[QACEGVAR(quickmount,distance), 3, true],
	[QACEGVAR(quickmount,enabled), true, true], 
	[QACEGVAR(quickmount,enableMenu), 0, true], 
	[QACEGVAR(quickmount,priority), 0],
	[QACEGVAR(quickmount,speed), 10, true]
];


