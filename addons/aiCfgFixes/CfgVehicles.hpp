class CfgVehicles {
    class Land;
    class Man: Land {
        sensitivityEar = 1.0;
    };
    class CAManBase: Man {
        sensitivity = 4;
        sensitivityEar = 0.75;
    };
    class SoldierWB: CAManBase {
        sensitivity = 5;
        sensitivityEar = 1.0;
    };
    class SoldierEB: CAManBase {
        sensitivity = 5;
        sensitivityEar = 1.0;
    };
    class SoldierGB: CAManBase {
        sensitivity = 5;
        sensitivityEar = 1.0;
    };
};

