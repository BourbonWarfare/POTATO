class CfgMagazines {
    class Pylon_1Rnd_Leaflets_West_F;
    class Pylon_1Rnd_Leaflets_Custom_01_F: Pylon_1Rnd_Leaflets_West_F {
        displayName = "Leaflets (Pro-Potato)";
        leafletClass = "Custom_01"; // shouldn't need this, but broken in 1.76 (missing the _)
    };
};
class CfgLeaflets {
    class Default;
    class Custom_01: Default {
        text = "POTATO IS YOUR FRIEND";
        texture = QPATHTOF(ui\leaflet_potato_ca.paa);
    };
};
