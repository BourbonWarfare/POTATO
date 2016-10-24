class CfgVehicles {
     //ACRE uses this for vehicle sound attenuation (makes it easy to hear mortar gunners)
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        insideSoundCoef = 0;
    };

    // add SMAW box
    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "SMAW Weapon Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {
            MACRO_ADDWEAPON(rhs_weap_smaw,1);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,2);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,4);
        };
        class TransportItems {};
        class TransportBackpacks {};
    };

    // add POTATO USMC
    class SoldierWB;
    class potato_usmc_rifleman: SoldierWB {
        author = "AACO";
        displayName = "Rifleman"
        faction = "potato_usmc";
        role = "Rifleman";
        scope = 2;
    };
    class potato_usmc_rifleman_02: potato_usmc_rifleman {
        displayName = "Rifleman 2"
    };
    class potato_usmc_rifleman_03: potato_usmc_rifleman {
        displayName = "Rifleman 3"
    };
    class potato_usmc_rifleman_04: potato_usmc_rifleman {
        displayName = "Rifleman 4"
    };
    class potato_usmc_sf_rifleman: potato_usmc_rifleman {
        displayName = "Force Recon Rifleman"
    };
    class potato_usmc_sniper: potato_usmc_rifleman {
        displayName = "Sniper"
        role = "Marksman";
    };
    class potato_usmc_aar: potato_usmc_rifleman {
        displayName = "Assistant Automatic Rifleman"
        role = "Assistant";
    };
    class potato_usmc_sf_aar: potato_usmc_aar {
        displayName = "Force Recon Assistant Automatic Rifleman"
    };
    class potato_usmc_mmgag: potato_usmc_aar {
        displayName = "MMG Assistant Gunner"
    };
    class potato_usmc_hmgag: potato_usmc_aar {
        displayName = "HMG Assistant Gunner"
    };
    class potato_usmc_matag: potato_usmc_aar {
        displayName = "MAT Assistant Gunner"
    };
    class potato_usmc_hatag: potato_usmc_aar {
        displayName = "HAT Assistant Gunner"
    };
    class potato_usmc_msamag: potato_usmc_aar {
        displayName = "MSAM Assistant Gunner"
    };
    class potato_usmc_mtrag: potato_usmc_aar {
        displayName = "Mortar Assistant Gunner"
    };
    class potato_usmc_mtrg: potato_usmc_aar { // for some reason the gunner is considered an assistant
        displayName = "Mortar Gunner"
    };
    class potato_usmc_ar: potato_usmc_rifleman {
        displayName = "Automatic Rifleman"
        icon = "iconManMG";
        role = "MachineGunner";
    };
    class potato_usmc_sf_ar: potato_usmc_ar {
        displayName = "Force Recon Automatic Rifleman"
    };
    class potato_usmc_mmgg: potato_usmc_ar {
        displayName = "MMG Gunner"
    };
    class potato_usmc_hmgg: potato_usmc_ar {
        displayName = "HMG Gunner"
    };
    class potato_usmc_lat: potato_usmc_rifleman {
        displayName = "Rifleman Anti-Tank"
        icon = "iconManAT";
        role = "MissileSpecialist";
    };
    class potato_usmc_sf_lat: potato_usmc_lat {
        displayName = "Force Recon Rifleman Anti-Tank"
    };
    class potato_usmc_matg: potato_usmc_lat {
        displayName = "MAT Gunner"
    };
    class potato_usmc_hatg: potato_usmc_lat {
        displayName = "HAT Gunner"
    };
    class potato_usmc_msamg: potato_usmc_lat {
        displayName = "MSAM Gunner"
    };
    class potato_usmc_coy: potato_usmc_rifleman {
        displayName = "Company Commander";
        icon = "iconManOfficer";
    };
    class potato_usmc_xo: potato_usmc_coy {
        displayName = "Company Executive Officer";
    };
    class potato_usmc_fac: potato_usmc_coy {
        displayName = "Forward Air Controller";
    };
    class potato_usmc_plt: potato_usmc_coy {
        displayName = "Platoon Leader";
    };
    class potato_usmc_sgt: potato_usmc_coy {
        displayName = "Platoon Sergent";
        icon = "iconManOfficer";
    };
    class potato_usmc_sl: potato_usmc_rifleman {
        displayName = "Squad Leader";
        icon = "iconManLeader";
    };
    class potato_usmc_sf_sl: potato_usmc_sl {
        displayName = "Force Recon Squad Leader";
    };
    class potato_usmc_mmgl: potato_usmc_sl {
        displayName = "MMG Leader";
    };
    class potato_usmc_hmgl: potato_usmc_sl {
        displayName = "HMG Leader";
    };
    class potato_usmc_matl: potato_usmc_sl {
        displayName = "MAT Leader";
    };
    class potato_usmc_hatl: potato_usmc_sl {
        displayName = "HAT Leader";
    };
    class potato_usmc_msaml: potato_usmc_sl {
        displayName = "MSAM Leader";
    };
    class potato_usmc_mtrl: potato_usmc_sl {
        displayName = "MTR Leader";
    };
    class potato_usmc_stl: potato_usmc_sl {
        displayName = "Scout Leader";
    };
    class potato_usmc_ftl: potato_usmc_sl {
        displayName = "Fire Team Leader";
    };
    class potato_usmc_sf_ftl: potato_usmc_sl {
        displayName = "Force Recon Fire Team Leader";
    };
    class potato_usmc_vicl: potato_usmc_sl {
        displayName = "Vehicle Leader";
        engineer = 1;
        role = "Crewman";
    };
    class potato_usmc_cm: potato_usmc_rifleman {
        attendant = 1;
        displayName = "Company Medic";
        icon = "iconManMedic";
        role = "CombatLifeSaver";
    };
    class potato_usmc_plm: potato_usmc_cm {
        displayName = "Platoon Medic";
    };
    class potato_usmc_sm: potato_usmc_cm {
        displayName = "Squad Medic";
    };
    class potato_usmc_sf_sm: potato_usmc_cm {
        displayName = "Force Recon Squad Medic";
    };
    class potato_usmc_eodl: potato_usmc_sl {
        displayName = "EOD Leader";
        engineer = 1;
        role = "Sapper";
    };
    class potato_usmc_eod: potato_usmc_eodl {
        displayName = "EOD Technician";
        icon = "iconManExplosive";
    };
    class potato_usmc_vicc: potato_usmc_vicl {
        displayName = "Vehicle Crew";
        icon = "iconMan";
    };
    class potato_usmc_vicd: potato_usmc_vicl {
        displayName = "Vehicle Driver";
        icon = "iconManEngineer";
        role = "Sapper";
    };
    class potato_usmc_pilot: potato_usmc_rifleman {
        ACE_GForceCoef = 0.55;
        displayName = "Pilot";
        engineer = 1;
        role = "Crewman";
    };
    class potato_usmc_cc: potato_usmc_pilot {
        displayName = "Crew Chief";
        icon = "iconManEngineer";
        role = "Sapper";
    };
};
