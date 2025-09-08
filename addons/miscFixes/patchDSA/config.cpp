#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchDSA

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "DSA_Spooks" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
class CfgVehicles {
    // Fix: Drongo's Spooks and Anomalies XEH
    class DSA_SpookBase;
    class DSA_SpookBase2;
    class DSA_AnomalyBase;
    class B_Soldier_F;
    class DSA_Vampire: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Vampire
    class DSA_Wendigo: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Wendigo
    class DSA_Shadowman: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Shadowman
    class DSA_Hatman: DSA_Shadowman { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Hatman
    class DSA_Mindflayer: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Mindflayer
    class DSA_411: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> 411
    class DSA_Rake: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Rake
    class DSA_Abomination: DSA_411 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Abomination
    class DSA_Snatcher: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Snatcher
    class DSA_Crazy: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Crazy
    class DSA_Launchpad: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Launchpad
    class DSA_Leech: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Leech
    class DSA_Zapper: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Zapper
    class DSA_Trapdoor: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Trapdoor
    class DSA_DeltaX_Operator: B_Soldier_F { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Delta X Operator
    class DSA_DeltaX_CBRN: B_Soldier_F { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Delta X CBRN
    class DSA_ActiveIdol: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; };
    class DSA_ActiveIdol2: DSA_ActiveIdol { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; };
};

class CfgFaces {
    class Default;
    class Man_A3: Default {
        class Default;
        class DSA_Noface: Default {
            disabled = 1;
        };
    };
};
