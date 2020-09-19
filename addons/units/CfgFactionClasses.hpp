class CfgFactionClasses {
    class BLU_F;
    class DOUBLES(PREFIX,W): BLU_F {
        displayName = "POTATO: West";
        flag = "a3\data_f\Flags\flag_us_co.paa";
        icon = QPATHTOF(data\icon_usmc.paa);
    };

    class OPF_F;
    class DOUBLES(PREFIX,E): OPF_F {
        displayName = "POTATO: East";
        flag = QPATHTOF(data\flag_rus.paa);
        icon = QPATHTOF(data\icon_msv.paa);
    };

    class IND_F;
    class DOUBLES(PREFIX,I): IND_F {
        displayName = "POTATO: Indy";
    };
};
