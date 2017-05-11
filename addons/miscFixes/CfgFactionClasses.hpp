class CfgFactionClasses {
    class BLU_F;
    class DOUBLES(PREFIX,usmc): BLU_F {
        displayName = "POTATO: USMC";
        flag = "a3\data_f\Flags\flag_us_co.paa";
        icon = QPATHTOF(data\icon_usmc.paa);
    };

    class OPF_F;
    class DOUBLES(PREFIX,msv): OPF_F {
        displayName = "POTATO: MSV";
        flag = QPATHTOF(data\flag_rus.paa);
        icon = QPATHTOF(data\icon_msv.paa);
    };

    class IND_F;
    class DOUBLES(PREFIX,airborne): IND_F {
        displayName = "POTATO: Airborne";
    };
};
