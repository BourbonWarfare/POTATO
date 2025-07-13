 class CfgRecoils {
    class GVAR(recoil_SAW_coop) {
        muzzleOuter[] = {0.2,0.6,0.25,0.15};
        kickBack[] = {0.005,0.02};
        permanent = 0.065;
        temporary = 0.015;
    };
    class GVAR(recoil_SAW_prone_coop): GVAR(recoil_SAW_coop) {
        kickBack[] = {0.005,0.01};
        permanent = 0.045;
    };
};
