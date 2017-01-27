﻿class CfgVehicles {
    class Module_F;
    class GVAR(factory): Module_F {
        author = QUOTE(PREFIX);
        category = QGVAR(factoryFaction);
        scope = 1;
        scopeCurator = 2;
        isGlobal = 0;
        isTriggerActivated = 0;
        displayName = "Factory";
        function = QFUNC(module_factory);
        curatorInfoType = QGVAR(RscDisplayAttributes_factory);
        icon = PATHTOF(UI\icon_factory_ca.paa);
        portrait = PATHTOF(UI\icon_factory_ca.paa);
    };
    class GVAR(attackBeacon): GVAR(factory) {
        displayName = "Mark Target";
        curatorInfoType = "";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\target_ca";
        portrait = "\a3\ui_f\data\igui\cfg\simpletasks\types\target_ca";
        function = QFUNC(module_attackBeacon);
    };
    class GVAR(place_fireteam): GVAR(factory) {
        displayName = "Create Fireteam (4)";
        function = QFUNC(module_place);
        curatorInfoType = QGVAR(RscDisplayAttributes_place);
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        portrait = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(soldierList)[] = {"_soldier_TL_F","_soldier_AR_F","_Soldier_LAT_F","_soldier_F"};
    };
    class GVAR(place_squad): GVAR(place_fireteam) {
        displayName = "Create Squad (8)";
        GVAR(soldierList)[] = {"_soldier_SL_F","_soldier_AR_F","_Soldier_LAT_F","_soldier_F","_soldier_M_F","_soldier_F","_soldier_AR_F","_Soldier_LAT_F"};
    };
};
