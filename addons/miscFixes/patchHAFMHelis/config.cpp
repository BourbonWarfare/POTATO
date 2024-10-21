#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHAFMHelis

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "HAFM_NH90_Config", "HAFM_NH90", "Kimi_UI", "HAFM_EC635_Config", "jsrs_soundmod_complete_edition", "jsrs_soundmod_complete_edition_soundfiles" };
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

    class Helicopter_Base_F;
    class Helicopter_Base_H: Helicopter_Base_F {
        class UserActions;
    };
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
        class UserActions: UserActions
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
        soundgetin[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\open.ogg",1,1,50};
		soundgetout[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\close.ogg",1,1,50};
		soundengineonint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_start.ogg",1,1};
		soundengineonext[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\ext_start.ogg",1,1,300};
		soundengineoffint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_off.ogg",1,1};
		soundengineoffext[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\ext_off.ogg",1,1,300};
		sounddammage[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\helibasiccrash.ogg",0.75,1};
		soundlocked[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\opfor_lock_1.ogg",0.75,1};
		soundincommingmissile[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\opfor_lock_2.ogg",0.75,1};
		rotordamageint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_rotor_int.ogg",0.75,1};
		rotordamageout[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_rotor_ext.ogg",2.0,1,300};
		rotordamage[] = {"rotordamageint","rotordamageout"};
		taildamageint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_tail.ogg",0.75,1};
		taildamageout[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_tail.ogg",2.0,1,300};
		taildamage[] = {"taildamageint","taildamageout"};
		landingsoundint0[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\landing_skids_int1_open.ogg",0.75,1};
		landingsoundint1[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\landing_skids_int1_open.ogg",0.75,1};
		landingsoundint[] = {"landingsoundint0",0.5,"landingsoundint1",0.5};
		landingsoundout0[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\landing_skids_ext1.ogg",1,1,300};
		landingsoundout1[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\landing_skids_ext1.ogg",1,1,300};
		landingsoundout[] = {"landingsoundout0",0.5,"landingsoundout1",0.5};
		gearupext[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\gear_up_out.ogg",1.5,1,700};
		gearupint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\gear_up_in.ogg",1.5,1};
		gearup[] = {"gearupint","gearupext"};
		geardownint[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\gear_down_in.ogg",1.5,1};
		geardownext[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\gear_down_out.ogg",1.5,1,700};
		geardown[] = {"geardownint","geardownext"};
		slingcargoattach0[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_1hooklock.ogg",1.35,1};
		slingcargoattach1[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_1hooklock.ogg",1,1,300};
		slingcargoattach[] = {"slingcargoattach0","slingcargoattach1"};
		slingcargodetach0[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_1hookunlock.ogg",1.5,1};
		slingcargodetach1[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_1hookunlock.ogg",1,1,300};
		slingcargodetach[] = {"slingcargodetach0","slingcargodetach1"};
		class sounds {
			class engineext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\engine_close.ogg",1.5,1,300};
				frequency = "rotorspeed";
				volume = "campos *1.5* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
			};
			class rotorext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\rotor_close.ogg",1.6,1,300};
				frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
				volume = "campos *1.5* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
			};
			class rotorswist {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\tail_rotor.ogg",1,1,200};
				frequency = 1;
				volume = "campos * (rotorthrust factor [0.7, 0.9])";
			};
			class engineint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_main.ogg",1,1};
				frequency = "rotorspeed";
				volume = "1*(1-campos)*(0 max (rotorspeed-0.4))";
			};
			class rotorint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_rotor.ogg",1,1};
				frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
				volume = "(1 - campos) * (rotorspeed factor [0.3, 0.7]) * (1 + rotorthrust) * 0.7";
			};
			class rotorbench {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1};
				frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
				volume = "(playerpos factor [3.9, 4]) * (1 - campos) * (rotorspeed factor [0.3, 1]) * (1 + rotorthrust) * 0.4";
				cone[] = {1.6,3.14,1.6,0.95};
			};
			class enginebench {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1};
				frequency = "rotorspeed";
				volume = "(playerpos factor [3.9, 4]) * (1 - campos) * (0 max (rotorspeed-0.4))";
			};
			class transmissiondamageext_phase1 {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",1,1,300};
				frequency = "0.66 + rotorspeed / 3";
				volume = "campos * (transmissiondamage factor [0.3, 0.35]) * (transmissiondamage factor [0.5, 0.45]) * (rotorspeed factor [0.2, 0.5])";
			};
			class transmissiondamageext_phase2 {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",1,1,300};
				frequency = "0.66 + rotorspeed / 3";
				volume = "campos * (transmissiondamage factor [0.45, 0.5]) * (rotorspeed factor [0.2, 0.5])";
			};
			class transmissiondamageint_phase1 {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",0.75,1};
				frequency = "0.66 + rotorspeed / 3";
				volume = "(1 - campos) * (transmissiondamage factor [0.3, 0.35]) * (transmissiondamage factor [0.5, 0.45]) * (rotorspeed factor [0.2, 0.5])";
			};
			class transmissiondamageint_phase2 {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",0.75,1};
				frequency = "0.66 + rotorspeed / 3";
				volume = "(1 - campos) * (transmissiondamage factor [0.45, 0.5]) * (rotorspeed factor [0.2, 0.5])";
			};
			class rotornoiseext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1,200};
				frequency = 1;
				volume = "(campos*(rotorspeed factor [0.6, 0.85]))";
				cone[] = {1.6,3.14,2,0.95};
			};
			class distance {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\engine_far.ogg",1,1,1000};
				frequency = "rotorspeed";
				volume = "2 * campos * (0 max (rotorspeed-0.4))";
			};
			class fardistance {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\rotor_far.ogg",1,1,4000};
				frequency = "rotorspeed";
				volume = "campos *3* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
			};
			class damagealarmint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\damagealarm.ogg",0.75,1};
				frequency = 1;
				volume = "engineon * (1 - campos) * ( 1 - ((transmissiondamage factor [0.61, 0.60]) * (motordamage factor [0.61, 0.60]) * (rotordamage factor [0.51, 0.50]))) * (rotorspeed factor [0.0, 0.001])";
			};
			class damagealarmext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\damagealarm.ogg",1,1,100};
				frequency = 1;
				volume = "engineon * campos * ( 1 - ((transmissiondamage factor [0.61, 0.60]) * (motordamage factor [0.61, 0.60]) * (rotordamage factor [0.51, 0.50]))) * (rotorspeed factor [0, 0.001])";
			};
			class rotorlowalarmint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\lowrotoralarmint.ogg",0.75,1};
				frequency = 1;
				volume = "engineon * (1 - campos) * (rotorspeed factor [0.9, 0.8999]) * (rotorspeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class rotorlowalarmext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\lowrotoralarmint.ogg",1,1,75};
				frequency = 1;
				volume = "engineon * campos * (rotorspeed factor [0.9, 0.8999]) * (rotorspeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class windbench {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1};
				frequency = 1;
				volume = "4 * (playerpos factor [3.9, 4]) * (1 - campos) * ((speed factor[0, 30]) + (speed factor[0, -30]))";
			};
			class rainext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\rain1_ext.ogg",1,1,100};
				frequency = 1;
				volume = "campos * (rain - rotorspeed/2) * 2";
			};
			class rainint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\rain1_int_open.ogg",0.5,1};
				frequency = 1;
				volume = "(1-campos)*(rain - rotorspeed/2)*2";
			};
			class windint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1};
				frequency = 1;
				volume = "(1-campos)*(speed factor[5, 50])*(speed factor[5, 50])";
			};
			class windlateralmovementint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1,50};
				frequency = 1;
				volume = "(1-campos)*lateralmovement*((speed factor [5,40]) + (speed factor [-5,-40]))";
			};
			class gstress {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\vehicle_stress2b.ogg",0.75,1};
				frequency = 1;
				volume = "engineon * (1-campos) * ((gmeterz factor[1.5, 2.5]) + (gmeterz factor[0.5, -0.5]))";
			};
			class speedstress {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\vehicle_stress2b.ogg",0.75,1};
				frequency = 1;
				volume = "(1-campos)*(speed factor[40,80])";
			};
			class scrubtreeext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubtree.ogg",1,1,500};
				frequency = 1;
				volume = "campos * (scrubtree factor[0.02, 0.05])";
			};
			class scrublandext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrublandext.ogg",1,1,500};
				frequency = 1;
				volume = "campos * (scrubland factor[0.02, 0.05])";
			};
			class scrubbuildingext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubbuilding.ogg",1,1,500};
				frequency = 1;
				volume = "campos * (scrubbuilding factor[0.02, 0.05])";
			};
			class scrublandint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrublandint_open.ogg",0.75,1};
				frequency = 1;
				volume = "2 * (1-campos) * (scrubland factor[0.02, 0.05])";
			};
			class scrubbuildingint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubbuilding.ogg",0.75,1};
				frequency = 1;
				volume = "2 * (1 - campos) * (scrubbuilding factor[0.02, 0.05])";
			};
			class scrubtreeint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubtree.ogg",0.75,1};
				frequency = 1;
				volume = "(1 - campos) * ((scrubtree) factor [0, 0.01])";
			};
			class slingloaddownext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_enginedownext.ogg",1,1,500};
				frequency = 1;
				volume = "campos*(slingloadactive factor [0,-1])";
			};
			class slingloadupext {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_engineupext.ogg",1,1,500};
				frequency = 1;
				volume = "campos*(slingloadactive factor [0,1])";
			};
			class slingloaddownint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_enginedownint.ogg",0.75,1};
				frequency = 1;
				volume = "(1-campos)*(slingloadactive factor [0,-1])";
			};
			class slingloadupint {
				sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_engineupint.ogg",0.75,1};
				frequency = 1;
				volume = "(1-campos)*(slingloadactive factor [0,1])";
			};
		};
		class soundsext {
			class soundevents{};
			class sounds {
				class engineext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\engine_close.ogg",1.5,1,300};
					frequency = "rotorspeed";
					volume = "campos *1.5* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
				};
				class rotorext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\rotor_close.ogg",1.6,1,300};
					frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
					volume = "campos *1.5* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
				};
				class rotorswist {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\tail_rotor.ogg",1,1,200};
					frequency = 1;
					volume = "campos * (rotorthrust factor [0.7, 0.9])";
				};
				class engineint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_main.ogg",1,1};
					frequency = "rotorspeed";
					volume = "1*(1-campos)*(0 max (rotorspeed-0.4))";
				};
				class rotorint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\int_rotor.ogg",1,1};
					frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
					volume = "(1 - campos) * (rotorspeed factor [0.3, 0.7]) * (1 + rotorthrust) * 0.7";
				};
				class rotorbench {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1};
					frequency = "(rotorspeed factor [0.3, 0.7]) * (rotorspeed factor [0.3, 1]) * (1 - rotorthrust/4)";
					volume = "(playerpos factor [3.9, 4]) * (1 - campos) * (rotorspeed factor [0.3, 1]) * (1 + rotorthrust) * 0.4";
					cone[] = {1.6,3.14,1.6,0.95};
				};
				class enginebench {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1};
					frequency = "rotorspeed";
					volume = "(playerpos factor [3.9, 4]) * (1 - campos) * (0 max (rotorspeed-0.4))";
				};
				class transmissiondamageext_phase1 {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",1,1,300};
					frequency = "0.66 + rotorspeed / 3";
					volume = "campos * (transmissiondamage factor [0.3, 0.35]) * (transmissiondamage factor [0.5, 0.45]) * (rotorspeed factor [0.2, 0.5])";
				};
				class transmissiondamageext_phase2 {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",1,1,300};
					frequency = "0.66 + rotorspeed / 3";
					volume = "campos * (transmissiondamage factor [0.45, 0.5]) * (rotorspeed factor [0.2, 0.5])";
				};
				class transmissiondamageint_phase1 {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",0.75,1};
					frequency = "0.66 + rotorspeed / 3";
					volume = "(1 - campos) * (transmissiondamage factor [0.3, 0.35]) * (transmissiondamage factor [0.5, 0.45]) * (rotorspeed factor [0.2, 0.5])";
				};
				class transmissiondamageint_phase2 {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\heli_damage_transmission_int_1.ogg",0.75,1};
					frequency = "0.66 + rotorspeed / 3";
					volume = "(1 - campos) * (transmissiondamage factor [0.45, 0.5]) * (rotorspeed factor [0.2, 0.5])";
				};
				class rotornoiseext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\rotor\rotor_normal.ogg",0.5,1,200};
					frequency = 1;
					volume = "(campos*(rotorspeed factor [0.6, 0.85]))";
					cone[] = {1.6,3.14,2,0.95};
				};
				class distance {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\engine_far.ogg",1,1,1000};
					frequency = "rotorspeed";
					volume = "2 * campos * (0 max (rotorspeed-0.4))";
				};
				class fardistance {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\ch49_mohawk\rotor_far.ogg",1,1,4000};
					frequency = "rotorspeed";
					volume = "campos *3* (rotorspeed factor [0.6, 1]) * (1 + rotorthrust)";
				};
				class damagealarmint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\damagealarm.ogg",0.75,1};
					frequency = 1;
					volume = "engineon * (1 - campos) * ( 1 - ((transmissiondamage factor [0.61, 0.60]) * (motordamage factor [0.61, 0.60]) * (rotordamage factor [0.51, 0.50]))) * (rotorspeed factor [0.0, 0.001])";
				};
				class damagealarmext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\damagealarm.ogg",1,1,100};
					frequency = 1;
					volume = "engineon * campos * ( 1 - ((transmissiondamage factor [0.61, 0.60]) * (motordamage factor [0.61, 0.60]) * (rotordamage factor [0.51, 0.50]))) * (rotorspeed factor [0, 0.001])";
				};
				class rotorlowalarmint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\lowrotoralarmint.ogg",0.75,1};
					frequency = 1;
					volume = "engineon * (1 - campos) * (rotorspeed factor [0.9, 0.8999]) * (rotorspeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class rotorlowalarmext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\lowrotoralarmint.ogg",1,1,75};
					frequency = 1;
					volume = "engineon * campos * (rotorspeed factor [0.9, 0.8999]) * (rotorspeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class windbench {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1};
					frequency = 1;
					volume = "4 * (playerpos factor [3.9, 4]) * (1 - campos) * ((speed factor[0, 30]) + (speed factor[0, -30]))";
				};
				class rainext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\rain1_ext.ogg",1,1,100};
					frequency = 1;
					volume = "campos * (rain - rotorspeed/2) * 2";
				};
				class rainint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\rain1_int_open.ogg",0.5,1};
					frequency = 1;
					volume = "(1-campos)*(rain - rotorspeed/2)*2";
				};
				class windint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1};
					frequency = 1;
					volume = "(1-campos)*(speed factor[5, 50])*(speed factor[5, 50])";
				};
				class windlateralmovementint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\wind_close_in.ogg",0.5,1,50};
					frequency = 1;
					volume = "(1-campos)*lateralmovement*((speed factor [5,40]) + (speed factor [-5,-40]))";
				};
				class gstress {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\vehicle_stress2b.ogg",0.75,1};
					frequency = 1;
					volume = "engineon * (1-campos) * ((gmeterz factor[1.5, 2.5]) + (gmeterz factor[0.5, -0.5]))";
				};
				class speedstress {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\vehicle_stress2b.ogg",0.75,1};
					frequency = 1;
					volume = "(1-campos)*(speed factor[40,80])";
				};
				class scrubtreeext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubtree.ogg",1,1,500};
					frequency = 1;
					volume = "campos * (scrubtree factor[0.02, 0.05])";
				};
				class scrublandext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrublandext.ogg",1,1,500};
					frequency = 1;
					volume = "campos * (scrubland factor[0.02, 0.05])";
				};
				class scrubbuildingext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubbuilding.ogg",1,1,500};
					frequency = 1;
					volume = "campos * (scrubbuilding factor[0.02, 0.05])";
				};
				class scrublandint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrublandint_open.ogg",0.75,1};
					frequency = 1;
					volume = "2 * (1-campos) * (scrubland factor[0.02, 0.05])";
				};
				class scrubbuildingint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubbuilding.ogg",0.75,1};
					frequency = 1;
					volume = "2 * (1 - campos) * (scrubbuilding factor[0.02, 0.05])";
				};
				class scrubtreeint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\scrubtree.ogg",0.75,1};
					frequency = 1;
					volume = "(1 - campos) * ((scrubtree) factor [0, 0.01])";
				};
				class slingloaddownext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_enginedownext.ogg",1,1,500};
					frequency = 1;
					volume = "campos*(slingloadactive factor [0,-1])";
				};
				class slingloadupext {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_engineupext.ogg",1,1,500};
					frequency = 1;
					volume = "campos*(slingloadactive factor [0,1])";
				};
				class slingloaddownint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_enginedownint.ogg",0.75,1};
					frequency = 1;
					volume = "(1-campos)*(slingloadactive factor [0,-1])";
				};
				class slingloadupint {
					sound[] = {"\jsrs_soundmod_complete\JSRS_Soundmod_Soundfiles\air_vehicles\shared\sl_engineupint.ogg",0.75,1};
					frequency = 1;
					volume = "(1-campos)*(slingloadactive factor [0,1])";
				};
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
        class UserActions: UserActions
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
