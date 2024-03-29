class CfgVehicles {
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
        icon = QPATHTOF(UI\icon_factory_ca.paa);
        portrait = QPATHTOF(UI\icon_factory_ca.paa);
    };
    class GVAR(attackBeacon): GVAR(factory) {
        displayName = "Mark Target";
        curatorInfoType = "";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\target_ca";
        portrait = "\a3\ui_f\data\igui\cfg\simpletasks\types\target_ca";
        function = QFUNC(module_attackBeacon);
    };
    class GVAR(place_fireteam): GVAR(factory) {
        displayName = "(4) Create Fireteam";
        function = QFUNC(module_place);
        curatorInfoType = QGVAR(RscDisplayAttributes_place);
        icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        portrait = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";
        GVAR(soldierList)[] = {"ftl","ar","lat","rifleman"};
    };
    class GVAR(place_squad): GVAR(place_fireteam) {
        displayName = "(8) Create Squad";
        GVAR(soldierList)[] = {"sl","cm","rifleman","ar","lat","rifleman","ar","lat"};
    };
    class GVAR(place_platoon): GVAR(place_fireteam) {
        displayName = "(14) Create Platoon";
        GVAR(soldierList)[] = {"sl","cm","rifleman","ar","lat","rifleman","ar","lat","rifleman","ar","lat","rifleman","ar","lat"};
    };
};
