class CfgFactionClasses {
    class BLU_F;
    class TRIPLES(PREFIX,W,NOLAMBS): BLU_F {
        displayName = "POTATO: West (No Lambs)";
        flag = "a3\data_f\Flags\flag_us_co.paa";
        icon = QPATHTOF(data\icon_usmc.paa);
    };

    class OPF_F;
    class TRIPLES(PREFIX,E,NOLAMBS): OPF_F {
        displayName = "POTATO: East (No Lambs)";
        flag = QPATHTOF(data\flag_rus.paa);
        icon = QPATHTOF(data\icon_msv.paa);
    };

    class IND_F;
    class TRIPLES(PREFIX,I,NOLAMBS): IND_F {
        displayName = "POTATO: Indy (No Lambs)";
    };
};
