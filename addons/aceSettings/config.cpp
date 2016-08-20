#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "ace_laserPointer", "ace_map", "ace_zeus", "ace_hearing", "ace_overheating", "ace_gforces", "ace_goggles", "ace_frag", "ace_medical"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


// ACE Settings: (see http://forums.bourbonwarfare.com/viewtopic.php?f=8&t=2026)
class ACE_Settings {

    // Lets force this at 2x for now (from 6x in missions) while adjusting to new basic medical
    class ace_medical_bleedingCoefficient {
        typeName = "NUMBER";
        value = 2;
        force = 1; // This overrides mission setting/module!!!
    };


    //Daylight laser pointer:
    class ace_laserPointer_enabled {
        typeName = "BOOL";
        value = 0;
    };
    class ace_map_DefaultChannel {//ACE 3.4.0 - https://github.com/acemod/ACE3/pull/2650
        typeName = "NUMBER";
        value = 1; //SIDE
    };
    class ace_zeus_autoAddObjects {
        typeName = "BOOL";
        value = 1;
    };
    class ace_hearing_autoAddEarplugsToUnits {
        typeName = "BOOL";
        value = 0;
    };
    class ace_overheating_unJamOnreload { //Normal (R key) reload will fix jams
        typeName = "BOOL";
        value = 1;
    };
    class ace_overheating_unJamFailChance {
        typeName = "SCALAR";
        value = 0;
    };
    class ace_overheating_enabled {
        typeName = "BOOL";
        value = 0;
    };
    class ace_ui_ammoCount {
        typeName = "BOOL";
        value = 0;
        force = 1;
    };
    class ace_ui_groupBar {
        typeName = "BOOL";
        value = 0;
        force = 1;
    };
    class ace_respawn_removeDeadBodiesDisconnected {
        typeName = "BOOL";
        value = 0;
    };
    class ace_goggles_effects { //Disable rotor-wash and prone dust effects
        typeName = "SCALAR";
        value = 1;
    };
    class ace_gforces_enabledFor {
        typeName = "SCALAR";
        value = 0;
    };
    class ace_frag_maxTrack {
        typeName = "SCALAR";
        value = 2;
    };
};
