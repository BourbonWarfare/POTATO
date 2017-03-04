class CfgVehicles {
    // stubs
    class Logic;
    class Module_F: Logic {};

    // placeable respawn point to aide respawning
    class GVAR(placeRespawnPoint): Module_F {
        author = QUOTE(PREFIX);
        displayName = "Respawn Point";
        category = QGVAR(respawnFaction);
        icon = QPATHTOF(data\respawn_point);
        portrait = QPATHTOF(data\respawn_point);
        scope = 2;
        scopeCurator = 2;
        isTriggerActivated = 0;
        isGlobal = 0;
        function = QFUNC(placeRespawnPointModule);
        curatorCost = 0;
        class Arguments {};
        class Attributes {
            class GVAR(rpName) {
                displayName = "Respawn Point Name";
                tooltip = "Name of the respawn point";
                property = QGVAR(rpName);
                control = "Edit";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = "''";
            };
        };
    };

    // zeus module to open respawn
    class GVAR(openRespawnMenu): GVAR(placeRespawnPoint) {
        displayName = "Open Respawn";
        icon = QPATHTOF(data\respawn_tool);
        portrait = QPATHTOF(data\respawn_tool);
        scope = 1;
        function = QFUNC(openRespawnMenuModule);
        class Attributes {};
    };
};
