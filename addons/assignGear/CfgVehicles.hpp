class CfgVehicles {
    class B_supplyCrate_F;
    class GVAR(supply): B_supplyCrate_F {
        scope = 1;
        ace_cargo_size = 2;
        class TransportMagazines {};
        class TransportWeapons {};
        class TransportItems {};
        class TransportBackpacks {};
    };
    class GVAR(supply_westSquad): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: West Squad";
        scope = 2;
        GVAR(faction) = "potato_w";
        GVAR(type) = "squad";
    };
    class GVAR(supply_westPlatoon): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: West Platoon";
        scope = 2;
        GVAR(faction) = "potato_w";
        GVAR(type) = "platoon";
    };
    class GVAR(supply_eastSquad): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: East Squad";
        scope = 2;
        GVAR(faction) = "potato_e";
        GVAR(type) = "squad";
    };
    class GVAR(supply_eastPlatoon): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: East Platoon";
        scope = 2;
        GVAR(faction) = "potato_e";
        GVAR(type) = "platoon";
    };
    class GVAR(supply_indSquad): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: Ind Squad";
        scope = 2;
        GVAR(faction) = "potato_i";
        GVAR(type) = "squad";
    };
    class GVAR(supply_indPlatoon): GVAR(supply) {
        author = "POTATO";
        displayName = "[POTATO] Supply: Ind Platoon";
        scope = 2;
        GVAR(faction) = "potato_i";
        GVAR(type) = "platoon";
    };
};