//pragma SKIP_COMPILE
/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/

_settings = [
// ACE 
// Medical:
[QACEGVAR(medical,bleedingcoefficient), 1, true], // default: 1.0 (also set in mission.sqm) [forced to override old bwmf]
// [QACEGVAR(medical,fatalDamageSource), 1], // default: 0 // wait till L/K values finalized
[QACEGVAR(medical,ivFlowRate), 1.5], // default: 1.0
[QACEGVAR(medical,spontaneousWakeUpChance), 0.4], // default: 0.05
[QACEGVAR(medical,spontaneousWakeUpEpinephrineBoost), 2], // default: 1
[QACEGVAR(medical,playerDamageThreshold), 1], // default: 1
[QACEGVAR(medical_treatment,advancedDiagnose), 2], // default: 1 (Allows diagnosing death/CA)
[QACEGVAR(medical_treatment,clearTrauma), 2], // default: 0
[QACEGVAR(medical_treatment,litterCleanupDelay), 300], // default: 600
[QACEGVAR(medical_treatment,cprSuccessChanceMin), 0.75], // default: 0.4
[QACEGVAR(medical_treatment,cprSuccessChanceMax), 0.85], // default: 0.4
[QACEGVAR(medical_statemachine,AIUnconsciousness), false], // default: true
[QACEGVAR(medical_statemachine,cardiacArrestTime), 180], // default: 30
[QACEGVAR(medical_treatment,treatmentTimeTourniquet), 4], // default: 7

// Medical Extras:
[QACEGVAR(medical_ai,enabledFor), 0],
[QACEGVAR(medical_blood,enabledFor), 1],


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
[QACEGVAR(fortify,timeCostCoefficient), 0],
[QACEGVAR(fortify,timeMin), 0],
[QACEGVAR(frag,maxTrack), 5],
[QACEGVAR(gforces,enabledFor), 0],
[QACEGVAR(goggles,effects), 1], // note: user-setting, we don't force
[QACEGVAR(hearing,autoAddEarplugsToUnits), false],
[QACEGVAR(hearing,enableCombatDeafness), false],
[QACEGVAR(interaction,enableGroupRenaming), false],
[QACEGVAR(laserPointer,enabled), false],
[QACEGVAR(laser,showLaserOnMap), 2],
[QACEGVAR(map,DefaultChannel), 1],
[QACEGVAR(nightvision,effectScaling), 0.2, false, true],
[QACEGVAR(nightvision,fogScaling), 0.2, false, true],
[QACEGVAR(nightvision,noiseScaling), 0.2, false, true],
[QACEGVAR(nightvision,aimDownSightsBlur), 0.25, false, true],
[QACEGVAR(overheating,enabled), false],
[QACEGVAR(refuel,rate), 10],
[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
[QACEGVAR(ui,groupBar), false, true], // Forced because it's User settable
[QACEGVAR(weather,showCheckAirTemperature), false],
[QACEGVAR(zeus,autoAddObjects), true],

// NIARMS (HLC)
["niarms_magSwitch", false], // it's use of setUnitLoadout may cause problems
["niarms_gripSwitch", false], // it's use of setUnitLoadout may cause problems

// DUI
// DUI - Squad Radar - Main
["diwako_dui_main_hide_dialog", true, true], // User-Setting
["diwako_dui_ace_hide_interaction", true, true], // User-Setting

// DUI - Squad Radar - Indicators
["diwako_dui_indicators_range", 20], // User-Setting

// DUI - Squad Radar - Radar
["diwako_dui_compassRange", 35, true], // User-Setting
["diwako_dui_radar_compassrangecrew", 75, true], // User-Setting
["diwako_dui_enable_compass_dir", 1, true], // User-Setting "Show Bearing = only in vehicles"
["diwako_dui_radar_sqlfirst", true],
["diwako_dui_radar_vehiclecompassenabled", false], // (getting giant markers if this is on w/ low range, so I think leave off??)

// DUI - Squad Radar - Nametags
["diwako_dui_nametags_enableocclusion", false, true], // User-Setting
["diwako_dui_nametags_showunconasdead", true, true], // User-Setting
["diwako_dui_nametags_renderdistance", 40, true], // User-Setting
["diwako_dui_nametags_deadrenderdistance", 3.5, true] // User-Setting
];
