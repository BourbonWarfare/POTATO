class MachineGunCloud;
class GVARMAIN(MachineGunCloud): MachineGunCloud {
    class MachineGunCloud1 {
        intensity = 0.1;
        interval = 1;
        lifeTime = 0.05;
        position[] = {0,0,0};
        simulation = "particles";
        type = QGVARMAIN(MachineGunCloud1);
    };
};

class CfgCloudlets {
    class MachineGunCloud1;
    class GVARMAIN(MachineGunCloud1): MachineGunCloud1 {
        size[] = {0.26,0.33,0.41,0.51,0.64,0.8,1};
    };
};
