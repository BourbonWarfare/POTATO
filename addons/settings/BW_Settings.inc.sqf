//pragma SKIP_COMPILE
/*
    SettingName <STRING>
    Value <ANY>
    Force (can't be changed by mission or user) <BOOL>
    Skip warning if changed by mission <BOOL>
*/
_skip = [];
_settings = [
// ACE 
// Medical:
[QACEGVAR(medical,bleedingcoefficient), 1, true], // default: 1.0 (also set in mission.sqm) [forced to override old bwmf]
// [QACEGVAR(medical,fatalDamageSource), 1], // default: 0 // wait till L/K values finalized
[QACEGVAR(medical,ivFlowRate), 1.5], // default: 1.0
[QACEGVAR(medical,spontaneousWakeUpChance), 0.4], // default: 0.05
[QACEGVAR(medical,spontaneousWakeUpEpinephrineBoost), 2], // default: 1
[QACEGVAR(medical,playerDamageThreshold), 1], // default: 1
[QACEGVAR(medical_treatment,advancedDiagnose), 3], // default: 1 (Allows diagnosing death/CA)
[QACEGVAR(medical_treatment,clearTrauma), 2], // default: 0
[QACEGVAR(medical_treatment,litterCleanupDelay), 300], // default: 600
[QACEGVAR(medical_treatment,cprSuccessChanceMin), 0.75], // default: 0.4
[QACEGVAR(medical_treatment,cprSuccessChanceMax), 0.85], // default: 0.4
[QACEGVAR(medical_statemachine,AIUnconsciousness), false], // default: true
[QACEGVAR(medical_statemachine,cardiacArrestTime), 180], // default: 30
[QACEGVAR(medical_treatment,treatmentTimeTourniquet), 4], // default: 7

["ace_medical_engine_damagepassthrougheffect", 0],

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
[QACEGVAR(advanced_fatigue,terraingradientfactor), 0.4],
[QACEGVAR(advanced_fatigue,loadfactor), 0.5],
[QACEGVAR(cookoff,ammoCookoffDuration), 0.15],
[QACEGVAR(dragging,weightCoefficient), 0.25], // allows carry/drag 4x the normal weight
[QACEGVAR(finger,enabled), true],
[QACEGVAR(finger,maxrange), 7],
[QACEGVAR(fortify,timeCostCoefficient), 0],
[QACEGVAR(fortify,timeMin), 0],
[QACEGVAR(frag,maxTrack), 5],
[QACEGVAR(gforces,enabledFor), 0],
[QACEGVAR(goggles,effects), 1], // note: user-setting, we don't force
[QACEGVAR(hearing,autoAddEarplugsToUnits), 0],
[QACEGVAR(hearing,enableCombatDeafness), false],
[QACEGVAR(interaction,enableGroupRenaming), false],
[QACEGVAR(killTracker,showCrewKills), true],
[QACEGVAR(laser,showLaserOnMap), 2],
[QACEGVAR(marker_flags,placeanywhere), true],
[QACEGVAR(map,DefaultChannel), 1],
[QACEGVAR(nightvision,effectScaling), 0.2, false, true],
[QACEGVAR(nightvision,fogScaling), 0.2, false, true],
[QACEGVAR(nightvision,noiseScaling), 0.2, false, true],
[QACEGVAR(nightvision,aimDownSightsBlur), 0.25, false, true],
[QACEGVAR(overheating,enabled), false],
[QACEGVAR(refuel,rate), 10],
[QACEGVAR(refuel,progressduration), 0.1],
[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
[QACEGVAR(towing,addRopeToVehicleInventory), false], // added via potato_assignGear - alwaysAddLandRopes
[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
[QACEGVAR(ui,groupBar), false, true], // Forced because it's User settable
[QACEGVAR(weather,showCheckAirTemperature), false], // note: user-setting, we don't force
[QACEGVAR(zeus,autoAddObjects), true]
];

// WBK Melee
if (["WBK_MeleeMechanics"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["ims_rifledodgeset", false],
["ims_isfistsallowd", false],
["ims_isimscanhitallies", false],
["ims_bluntweapon", true] // uncon instead of kill
];} else { _skip pushBack "WBK_MeleeMechanics" };

// WBK Melee
if (["WBK_DyingAnimationsMod"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["WBK_DeathAnimMod_Deaths_PLR", false],
["WBK_DeathAnimMod_Hit_PLR", false],
["WBK_DeathAnimMod_Flinch_PLR", false],
["wbk_deathanimmod_death_chance", "50"], // why are these strings??
["wbk_deathanimmod_hit_chance", "70"],
["wbk_zombiesisusestatdeathcontrol", true],
["wbk_zombiesisusebitinganimation", false]
];} else { _skip pushBack "WBK_DyingAnimationsMod" };


// NIARMS (HLC)
if (["hlcweapons_core"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["niarms_magSwitch", false], // it's use of setUnitLoadout may cause problems
["niarms_gripSwitch", false] // it's use of setUnitLoadout may cause problems
];} else { _skip pushBack "hlcweapons_core" };


// DUI
if (["diwako_dui_main"] call ACEFUNC(common,isModLoaded)) then { _settings append [
// DUI - Squad Radar - Main
["diwako_dui_main_hide_dialog", true, true], // User-Setting
["diwako_dui_ace_hide_interaction", true, true], // User-Setting

// DUI - Squad Radar - Indicators
["diwako_dui_indicators_show", false, true], // User-Setting
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
];} else { _skip pushBack "diwako_dui_main" };

// LAMBS
if (["lambs_danger"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["lambs_danger_disableAIHideFromTanksAndAircraft", true]
];} else { _skip pushBack "lambs_danger" };

// ACRE
if (["acre_sys_core"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["acre_sys_core_fullduplex", true]
];} else { _skip pushBack "acre_sys_core" };

if (["tuncon_unconinfo"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["tuncon_unconinfo_enableshowepinephrine", false],
["tuncon_unconinfo_enableshowbleeding", false],
["tuncon_unconinfo_enableshowheartrate", false],
["tuncon_unconinfo_enableshowstablevitals", false],
["tuncon_unconinfo_allownearestunit", false],
["tuncon_unconinfo_nofriendliesnearbytext", "You are near death."]
["tuncon_unconinfo_enableshowdetailedtreatment", false]
["tuncon_unconinfo_unconinfonearestunitdistance", 10]
];} else { _skip pushBack "tuncon_unconinfo" };

if (["OCAP_main"] call ACEFUNC(common,isModLoaded)) then { _settings append [
["ocap_administratorlist", "[76561198029918230]"],
["ocap_settings_minplayercount", 10],
["ocap_settings_savetag", "Mission"],
["ocap_settings_minmissiontime", 15],
["ocap_settings_tracktickets", false]
];} else { _skip pushBack "OCAP_main" };
