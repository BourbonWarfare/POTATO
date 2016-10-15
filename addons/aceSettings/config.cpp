#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core","ace_laserPointer","ace_map","ace_zeus","ace_hearing","ace_overheating","ace_gforces","ace_goggles","ace_frag","ace_medical","ace_medical_ai","ace_advanced_fatigue", "ace_cookoff"};
        author = "Potato";
        authors[] = {"PabstMirror"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

// ACE Settings: (see http://forums.bourbonwarfare.com/viewtopic.php?f=8&t=2026)
class ACE_Settings {
    class ace_advanced_fatigue_performanceFactor {
        typeName = "SCALAR";
        value = 1.3;  
    };
    class ace_advanced_fatigue_recoveryFactor {
        typeName = "SCALAR";
        value = 2;  
    };
    class ace_cookoff_enable { // Disable cookoff until we verify it's working how we want
        typeName = "BOOL";
        value = 0;  
    };
    class ace_frag_maxTrack {
        typeName = "SCALAR";
        value = 2;
    };
    class ace_gforces_enabledFor {
        typeName = "SCALAR";
        value = 0;
    };
    class ace_goggles_effects { //Disable rotor-wash and prone dust effects
        typeName = "SCALAR";
        value = 1;
    };
    class ace_hearing_autoAddEarplugsToUnits {
        typeName = "BOOL";
        value = 0;
    };
    class ace_laserPointer_enabled { // Daylight laser pointer
        typeName = "BOOL";
        value = 0;
    };
    class ace_map_DefaultChannel {//ACE 3.4.0 - https://github.com/acemod/ACE3/pull/2650
        typeName = "NUMBER";
        value = 1; //SIDE
    };
    class ace_medical_bleedingCoefficient {
        typeName = "NUMBER";
        value = 2;
        force = 1; // This overrides mission setting/module!!!
    };
    class ace_medical_ai_enabledFor {
        typeName = "SCALAR";
        value = 1;
    };
    class ace_overheating_enabled {
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
    class ace_respawn_removeDeadBodiesDisconnected {
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
    class ace_zeus_autoAddObjects {
        typeName = "BOOL";
        value = 1;
    };
};
