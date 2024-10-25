class CfgWeapons {
    class LMG_Mk200_F;
    class GVAR(LAMG): LMG_Mk200_F {
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun";
        descriptionShort = "Light Machine Gun<br />Caliber: 5.56x45 mm";
        baseWeapon = QGVAR(LAMG);
        recoil = "CUP_SAW_recoil";
        magazineWell[] = {"CBA_556x45_MINIMI"};
        magazines[] = {"CUP_100Rnd_TE4_Red_Tracer_556x45_M249"};
    };
    class GVAR(LAMG_black): GVAR(LAMG) {
        author = "Potato";
        displayName = "KAC Light Assault Machine Gun (Black)";
        baseWeapon = QGVAR(LAMG_black);
        picture = "\a3\Weapons_F_Enoch\Machineguns\M200\Data\UI\icon_LMG_Mk200_black_F_ca.paa";
        hiddenSelectionsTextures[] = {
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\1st_person_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\Body_black_co.paa",
            "a3\Weapons_F_Enoch\Machineguns\M200\Data\grip_black_co.paa"
        };
    };
};
