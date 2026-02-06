#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHAFMHelis

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "HAFM_NH90_Config", "HAFM_NH90", "Kimi_UI", "HAFM_EC635_Config", "jsrs2025_config_c" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class HelicopterWreck;
    class HAFM_NH90Wreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" @HAFM
    class HAFM_EC635Wreck: HelicopterWreck { XEH_ENABLED; }; // "Wreck" 909320014

    class Helicopter_Base_H;
    class NH90: Helicopter_Base_H {
        ace_fastroping_enabled = 2;
        ace_fastroping_friesType = "ACE_friesAnchorBar";
        ace_fastroping_friesAttachmentPoint[] = {0.02,1.38,-0.37};
        ace_fastroping_onCut = "ace_fastroping_fnc_onCutCommon";
        ace_fastroping_onPrepare = "ace_fastroping_fnc_onPrepareCommon";
        ace_fastroping_ropeOrigins[] = {"ropeOriginLeft","ropeOriginRight"};
        class textureSources { // enables Virtual Garage skin functionality
            class NATO {
                displayName = "NATO (Black)";
                textures[] = {"HAFM_NH90\data\outerHaul_co.paa","HAFM_NH90\data\upperTail_co.paa","HAFM_NH90\data\misc_co.paa","HAFM_NH90\data\doors_co.paa"};
            };
            class AAF {
                displayName = "AAF";
                textures[] = {"HAFM_NH90\aaf\AAFouterHaul_co.paa","HAFM_NH90\aaf\AAFupperTail_co.paa","HAFM_NH90\aaf\AAFmisc_co.paa","HAFM_NH90\aaf\AAFdoors_co.paa"};
            };
            class GR {
                displayName = "Hellenic Armed Forces";
                textures[] = {"HAFM_NH90\gr\GRouterHaul_co.paa","HAFM_NH90\gr\GRupperTail_co.paa","HAFM_NH90\gr\GRmisc_co.paa","HAFM_NH90\gr\GRdoors_co.paa"};
            };
            class FIN { // adds Finnish NH90 skin authored by troska and Centurion_101 via SFP: Finnish Forces Pack (https://steamcommunity.com/sharedfiles/filedetails/?id=917042703)
                displayName = "Finnish Defense Forces";
                textures[] = {QPATHTOEF(miscFixes,patchHAFMHelis\data\outerHaul_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\upperTail_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\misc_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\doors_co.paa)};
            };
        };
        #include "mfd_nh90.hpp"
        defaultUserMFDvalues[]={0,1,0,0,1,0,0.2};
        class UserActions {
            class HMDs_Kimi_UserAction_0_ON
            {
                displayName="<t color='#26ff00'>HMD ON</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [0,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-1;
            };
            class HMDs_Kimi_UserAction_0_OFF
            {
                displayName="<t color='#ffff00'>HMD OFF</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [0,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-2;
            };
            class HMDs_Kimi_UserAction_1_IMPERIAL
            {
                displayName="<t color='#26ff00'>HMD IMPERIAL</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [1,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-3;
            };
            class HMDs_Kimi_UserAction_1_METRIC
            {
                displayName="<t color='#ffff00'>HMD METRIC</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [1,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-4;
            };
            class HMDs_Kimi_UserAction_2_FULL
            {
                displayName="<t color='#26ff00'>HMD FULL</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [2,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-5;
            };
            class HMDs_Kimi_UserAction_2_DECLUTTER
            {
                displayName="<t color='#ffff00'>HMD DECLUTTER</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [2,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-6;
            };
            class HMDs_Kimi_UserAction_345_COLOR_GREEN
            {
                displayName="<t color='#00ff00'>HMD GREEN</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [3,0];this SetUserMFDvalue [4,1];this SetUserMFDvalue [5,0];";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-7;
            };
            class HMDs_Kimi_UserAction_345_COLOR_YELLOW
            {
                displayName="<t color='#ffff00'>HMD YELLOW</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [3,1];this SetUserMFDvalue [4,0.65];this SetUserMFDvalue [5,0];";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-8;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_HIGH
            {
                displayName="HMD BRT HIGH";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.5]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-9;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_MED
            {
                displayName="HMD BRT MED";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.2]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-10;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_LOW
            {
                displayName="HMD BRT LOW";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.05]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-11;
            };
        };	
        // JSRSTODO: 
        // Copied from JSRS's BWA3_NH90_base
        class Sounds
		{
			class engineext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_ext_close.ogg",1.4,1,400};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_close.ogg",1,1,700};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class engineextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_ext_distance.ogg",1,1,1000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "campos*((rotorspeed-0.72)*4)";
			};
			class rotorextdist
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_distance.ogg",1,1,3000};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class rotornoiseext
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_distance.ogg",0,1,0};
				frequency = "rotorspeed* 1";
				volume = "campos * (rotorthrust factor [0.7,0.9])";
				cone[] = {0.7,1.3,1,0};
			};
			class engineint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_int.ogg",1,1};
				frequency = "1";
				volume = "(1-campos)*((rotorspeed-0.75)*3)";
			};
			class rotorint
			{
				sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_int.ogg",0.5011872,1};
				frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
				volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
			};
			soundsetsint[] = {"jsrs_2025_helicopter_ch49_mohawk_engineint_soundset","jsrs_2025_helicopter_ch49_mohawk_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_ch49_mohawk_gstress_soundset"};
			soundsetsext[] = {"jsrs_2025_helicopter_ch49_mohawk_engineext_soundset","jsrs_2025_helicopter_ch49_mohawk_rotorext_soundset","jsrs_2025_helicopter_ch49_mohawk_evr_soundset","jsrs_2025_helicopter_ch49_mohawk_rotordistance_soundset","jsrs_2025_helicopter_ch49_mohawk_enginedistance_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
		};
		class soundsext
		{
			class soundevents{};
			class Sounds
			{
				class engineext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_ext_close.ogg",1.4,1,400};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_close.ogg",1,1,700};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class engineextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_ext_distance.ogg",1,1,1000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "campos*((rotorspeed-0.72)*4)";
				};
				class rotorextdist
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_distance.ogg",1,1,3000};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "1*campos*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class rotornoiseext
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_ext_distance.ogg",0,1,0};
					frequency = "rotorspeed* 1";
					volume = "campos * (rotorthrust factor [0.7,0.9])";
					cone[] = {0.7,1.3,1,0};
				};
				class engineint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\turbine_int.ogg",1,1};
					frequency = "1";
					volume = "(1-campos)*((rotorspeed-0.75)*3)";
				};
				class rotorint
				{
					sound[] = {"z\jsrs2025\addons\sounds_air\sounds\helicopters\ch49_mohawk\rotor_int.ogg",0.5011872,1};
					frequency = "rotorspeed * (1-rotorthrust/15) * 1.25";
					volume = "(1-campos)*(0 max (rotorspeed-0.5))*(1 + rotorthrust)";
				};
				soundsetsint[] = {"jsrs_2025_helicopter_ch49_mohawk_engineint_soundset","jsrs_2025_helicopter_ch49_mohawk_rotorint_soundset","jsrs_2025_helicopter_transmissiondamageint_phase1_soundset","jsrs_2025_helicopter_transmissiondamageint_phase2_soundset","jsrs_2025_helicopter_damagealarmint_soundset","jsrs_2025_helicopter_rotorlowalarmint_soundset","jsrs_2025_helicopter_scrublandint_soundset","jsrs_2025_helicopter_scrubbuildingint_soundset","jsrs_2025_helicopter_scrubtreeint_soundset","jsrs_2025_helicopter_slingloaddownint_soundset","jsrs_2025_helicopter_slingloadupint_soundset","jsrs_2025_helicopter_rainint_soundset","jsrs_2025_helicopter_windint_soundset","jsrs_2025_helicopter_ch49_mohawk_gstress_soundset"};
				soundsetsext[] = {"jsrs_2025_helicopter_ch49_mohawk_engineext_soundset","jsrs_2025_helicopter_ch49_mohawk_rotorext_soundset","jsrs_2025_helicopter_ch49_mohawk_evr_soundset","jsrs_2025_helicopter_ch49_mohawk_rotordistance_soundset","jsrs_2025_helicopter_ch49_mohawk_enginedistance_soundset","jsrs_2025_helicopter_ch49_mohawk_tailrotor_soundset","jsrs_2025_helicopter_transmissiondamageext_phase1_soundset","jsrs_2025_helicopter_transmissiondamageext_phase2_soundset","jsrs_2025_helicopter_scrublandext_soundset","jsrs_2025_helicopter_scrubbuildingext_soundset","jsrs_2025_helicopter_scrubtreeext_soundset","jsrs_2025_helicopter_slingloaddownext_soundset","jsrs_2025_helicopter_slingloadupext_soundset","jsrs_2025_helicopter_rainext_soundset"};
			};
		};
    };
    class NH90Armed_AAF: NH90 {
        transportSoldier = 8; // fixes issue where there are more available seats than physically present on model
        ace_fastroping_enabled = 2;
        ace_fastroping_friesType = "ACE_friesAnchorBar";
        ace_fastroping_friesAttachmentPoint[] = {0.02,1.38,-0.37};
        ace_fastroping_onCut = "ace_fastroping_fnc_onCutCommon";
        ace_fastroping_onPrepare = "ace_fastroping_fnc_onPrepareCommon";
        ace_fastroping_ropeOrigins[] = {"ropeOriginLeft","ropeOriginRight"};
        class textureSources { // enables Virtual Garage skin functionality
            class NATO {
                displayName = "NATO (Black)";
                textures[] = {"HAFM_NH90\data\outerHaul_co.paa","HAFM_NH90\data\upperTail_co.paa","HAFM_NH90\data\misc_co.paa","HAFM_NH90\data\doors_co.paa"};
            };
            class AAF {
                displayName = "AAF";
                textures[] = {"HAFM_NH90\aaf\AAFouterHaul_co.paa","HAFM_NH90\aaf\AAFupperTail_co.paa","HAFM_NH90\aaf\AAFmisc_co.paa","HAFM_NH90\aaf\AAFdoors_co.paa"};
            };
            class GR {
                displayName = "Hellenic Armed Forces";
                textures[] = {"HAFM_NH90\gr\GRouterHaul_co.paa","HAFM_NH90\gr\GRupperTail_co.paa","HAFM_NH90\gr\GRmisc_co.paa","HAFM_NH90\gr\GRdoors_co.paa"};
            };
            class FIN { // adds Finnish NH90 skin authored by troska and Centurion_101 via SFP: Finnish Forces Pack (https://steamcommunity.com/sharedfiles/filedetails/?id=917042703)
                displayName = "Finnish Defense Forces (Camo)";
                textures[] = {QPATHTOEF(miscFixes,patchHAFMHelis\data\outerHaul_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\upperTail_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\misc_co.paa),QPATHTOEF(miscFixes,patchHAFMHelis\data\doors_co.paa)};
            };
        };
        #include "mfd_nh90a.hpp"
        defaultUserMFDvalues[]={0,1,0,0,1,0,0.2};
        class UserActions
        {
            class HMDs_Kimi_UserAction_0_ON
            {
                displayName="<t color='#26ff00'>HMD ON</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [0,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-1;
            };
            class HMDs_Kimi_UserAction_0_OFF
            {
                displayName="<t color='#ffff00'>HMD OFF</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [0,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-2;
            };
            class HMDs_Kimi_UserAction_1_IMPERIAL
            {
                displayName="<t color='#26ff00'>HMD IMPERIAL</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [1,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-3;
            };
            class HMDs_Kimi_UserAction_1_METRIC
            {
                displayName="<t color='#ffff00'>HMD METRIC</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [1,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-4;
            };
            class HMDs_Kimi_UserAction_2_FULL
            {
                displayName="<t color='#26ff00'>HMD FULL</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [2,0]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-5;
            };
            class HMDs_Kimi_UserAction_2_DECLUTTER
            {
                displayName="<t color='#ffff00'>HMD DECLUTTER</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [2,1]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-6;
            };
            class HMDs_Kimi_UserAction_345_COLOR_GREEN
            {
                displayName="<t color='#00ff00'>HMD GREEN</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [3,0];this SetUserMFDvalue [4,1];this SetUserMFDvalue [5,0];";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-7;
            };
            class HMDs_Kimi_UserAction_345_COLOR_YELLOW
            {
                displayName="<t color='#ffff00'>HMD YELLOW</t>";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [3,1];this SetUserMFDvalue [4,0.65];this SetUserMFDvalue [5,0];";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-8;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_HIGH
            {
                displayName="HMD BRT HIGH";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.5]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-9;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_MED
            {
                displayName="HMD BRT MED";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.2]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-10;
            };
            class HMDs_Kimi_UserAction_6_ALPHA_LOW
            {
                displayName="HMD BRT LOW";
                condition="(player in [driver this, this turretUnit [0]]) && (alive this)";
                statement="this SetUserMFDvalue [6,0.05]";
                position="pilotcontrol";
                radius=20;
                onlyforplayer=1;
                showWindow=1;
                hideOnUse=1;
                priority=-11;
            };
        };
    };
};
