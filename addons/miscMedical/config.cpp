#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "ace_medical"};
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class ace_medical_treatment {
    class Medication {
        class Naloxone {
            painReduce = 0;
            hrIncreaseLow[] = {0, 0};
            hrIncreaseNormal[] = {0, 0};
            hrIncreaseHigh[] = {0, 0};
            timeInSystem = 180;
            timeTillMaxEffect = 1;
            maxDose = 0.1;
            onOverDose = QFUNC(Naloxone);
            incompatibleMedication[] = {};
            viscosityChange = 0;
        };
        class Painkillers;
        class Pkblister: Painkillers {};
    };
};


#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"