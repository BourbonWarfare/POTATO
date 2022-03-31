//pragma SKIP_COMPILE
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
[QACEGVAR(medical_treatment,advancedDiagnose), 2], // default: 1 (Allows diagnosing death/CA)
[QACEGVAR(medical_treatment,clearTrauma), 2], // default: 0
[QACEGVAR(medical_treatment,litterCleanupDelay), 300], // default: 600
[QACEGVAR(medical_treatment,cprSuccessChanceMin), 0.75], // default: 0.4
[QACEGVAR(medical_treatment,cprSuccessChanceMax), 0.85], // default: 0.4
[QACEGVAR(medical_statemachine,AIUnconsciousness), false], // default: true
[QACEGVAR(medical_statemachine,cardiacArrestTime), 180], // default: 30

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

// ACE 
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
[QACEGVAR(map,DefaultChannel), 1],
[QACEGVAR(nightvision,effectScaling), 0.5, false, true],
[QACEGVAR(nightvision,fogScaling), 0.5, false, true],
[QACEGVAR(nightvision,noiseScaling), 0.5, false, true],
[QACEGVAR(nightvision,aimDownSightsBlur), 0.25, false, true],
[QACEGVAR(overheating,enabled), false],
[QACEGVAR(refuel,rate), 10],
[QACEGVAR(respawn,removeDeadBodiesDisconnected), false],
[QACEGVAR(ui,ammoCount), false, true], // Forced because it's User settable
[QACEGVAR(ui,groupBar), false, true], // Forced because it's User settable
[QACEGVAR(weather,showCheckAirTemperature), false],
[QACEGVAR(zeus,autoAddObjects), true],

["niarms_magSwitch", false], // it's use of setUnitLoadout may cause problems
["niarms_gripSwitch", false] // it's use of setUnitLoadout may cause problems

// DUI

// DUI - Squad Radar - Indicators
["force diwako_dui_indicators_crew_range_enabled", false],
["diwako_dui_indicators_fov_scale", false],
["diwako_dui_indicators_icon_buddy", true],
["diwako_dui_indicators_icon_leader", true],
["diwako_dui_indicators_icon_medic"", true],
["force diwako_dui_indicators_range"", 20],
["diwako_dui_indicators_range_crew"", 300],
["diwako_dui_indicators_range_scale", false],
["diwako_dui_indicators_show", true],
["diwako_dui_indicators_size", 1],
["diwako_dui_indicators_style", "standard"],
["diwako_dui_indicators_useACENametagsRange", true],

// DUI - Squad Radar - Main
["force diwako_dui_ace_hide_interaction", false],
["diwako_dui_colors", "standard"],
["diwako_dui_font", "RobotoCondensed"],
["diwako_dui_icon_style", "standard"],
["force diwako_dui_main_hide_dialog", false],
["diwako_dui_main_hide_ui_by_default", false],
["diwako_dui_main_squadBlue", [0",0",1",1]],
["diwako_dui_main_squadGreen", [0",1",0",1]],
["diwako_dui_main_squadMain", [1",1",1",1]],
["diwako_dui_main_squadRed", [1",0",0",1]],
["diwako_dui_main_squadYellow", [1",1",0",1]],
["diwako_dui_main_trackingColor", [0.93",0.26",0.93",1]],
["diwako_dui_reset_ui_pos", false],

// DUI - Squad Radar - Nametags
["diwako_dui_nametags_customRankStyle", "[[""PRIVATE""",""CORPORAL""",""SERGEANT""",""LIEUTENANT""",""CAPTAIN""",""MAJOR""",""COLONEL""]",[""Pvt.""",""Cpl.""",""Sgt.""",""Lt.""",""Capt.""",""Maj.""",""Col.""]]"],
["force diwako_dui_nametags_deadColor", [1",1",1",1]],
["force diwako_dui_nametags_deadRenderDistance", 10],
["diwako_dui_nametags_drawRank", true],
["force diwako_dui_nametags_enabled", true],
["diwako_dui_nametags_enableFOVBoost", true],
["force diwako_dui_nametags_enableOcclusion", false],
["diwako_dui_nametags_fadeInTime", 0.05],
["diwako_dui_nametags_fadeOutTime", 0.5],
["diwako_dui_nametags_fontGroup", "RobotoCondensedLight"],
["diwako_dui_nametags_fontGroupNameSize", 8],
["diwako_dui_nametags_fontName", "RobotoCondensedBold"],
["diwako_dui_nametags_fontNameSize", 10],
["force diwako_dui_nametags_groupColor", [1",1",1",1]],
["diwako_dui_nametags_groupFontShadow", 1],
["force diwako_dui_nametags_groupNameOtherGroupColor", [1",1",1",1]],
["diwako_dui_nametags_nameFontShadow", 1],
["force diwako_dui_nametags_nameOtherGroupColor", [1",1",1",1]],
["diwako_dui_nametags_rankNameStyle", "default"],
["force diwako_dui_nametags_renderDistance", 40],
["diwako_dui_nametags_showUnconAsDead", true],
["force diwako_dui_nametags_useLIS", true],
["diwako_dui_nametags_useSideIsFriendly", true],

// DUI - Squad Radar - Radar
["diwako_dui_compass_hide_alone_group", false],
["diwako_dui_compass_hide_blip_alone_group", false],
["diwako_dui_compass_icon_scale", 1],
["diwako_dui_compass_opacity", 1],
["diwako_dui_compass_style", ["\z\diwako_dui\addons\radar\UI\compass_styles\standard\compass_limited.paa"","\z\diwako_dui\addons\radar\UI\compass_styles\standard\compass.paa"]],
["diwako_dui_compassRange", 35],
["diwako_dui_compassRefreshrate", 0],
["diwako_dui_dir_showMildot", false],
["diwako_dui_dir_size", 1.25],
["diwako_dui_distanceWarning", 3],
["diwako_dui_enable_compass", true],
["force diwako_dui_enable_compass_dir", 4],
["diwako_dui_enable_occlusion", false],
["diwako_dui_enable_occlusion_cone", 360],
["diwako_dui_hudScaling", 1.33333],
["diwako_dui_namelist", true],
["diwako_dui_namelist_bg", 0],
["diwako_dui_namelist_only_buddy_icon", false],
["diwako_dui_namelist_size", 1.5396],
["diwako_dui_namelist_text_shadow", 2],
["diwako_dui_namelist_width", 215],
["diwako_dui_radar_ace_finger", true],
["diwako_dui_radar_ace_medic", true],
["force diwako_dui_radar_compassRangeCrew", 74.2897],
["diwako_dui_radar_dir_padding", 25],
["diwako_dui_radar_dir_shadow", 2],
["force diwako_dui_radar_group_by_vehicle", false],
["diwako_dui_radar_icon_opacity", 1],
["diwako_dui_radar_icon_opacity_no_player", true],
["diwako_dui_radar_icon_priority_setting", 1],
["diwako_dui_radar_icon_scale_crew", 6],
["diwako_dui_radar_leadingZeroes", false],
["diwako_dui_radar_namelist_hideWhenLeader", false],
["diwako_dui_radar_namelist_vertical_spacing", 0.75],
["diwako_dui_radar_occlusion_fade_in_time", 1],
["diwako_dui_radar_occlusion_fade_time", 10],
["diwako_dui_radar_pointer_color", [1",0.5",0",1]],
["diwako_dui_radar_pointer_style", "standard"],
["diwako_dui_radar_show_cardinal_points", true],
["diwako_dui_radar_showSpeaking", true],
["force diwako_dui_radar_showSpeaking_radioOnly", true],
["diwako_dui_radar_showSpeaking_replaceIcon", true],
["force diwako_dui_radar_sortType", "none"],
["force diwako_dui_radar_sqlFirst", true],
["force diwako_dui_radar_syncGroup", true],
["force diwako_dui_radar_vehicleCompassEnabled", true],
["diwako_dui_use_layout_editor", false]

];
