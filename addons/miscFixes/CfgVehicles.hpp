class CfgVehicles {
    // Add SMAW box
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
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,8);
        };
        class TransportItems {
            MACRO_ADDITEM(rhs_weap_optic_smaw,1);
        };
        class TransportBackpacks {};
    };

    // add POTATO USMC
    class SoldierWB;
    class USMC(rifleman): SoldierWB {
        author = "AACO";
        displayName = "Rifleman"
        faction = "potato_usmc";
        role = "Rifleman";
        scope = 2;
    };
    class USMC(rifleman_02): USMC(rifleman) {
        displayName = "Rifleman 2"
    };
    class USMC(rifleman_03): USMC(rifleman) {
        displayName = "Rifleman 3"
    };
    class USMC(rifleman_04): USMC(rifleman) {
        displayName = "Rifleman 4"
    };
    class USMC(sf_rifleman): USMC(rifleman) {
        displayName = "Force Recon Rifleman"
    };
    class USMC(sniper): USMC(rifleman) {
        displayName = "Sniper"
        role = "Marksman";
    };
    class USMC(aar): USMC(rifleman) {
        displayName = "Assistant Automatic Rifleman"
        role = "Assistant";
    };
    class USMC(sf_aar): USMC(aar) {
        displayName = "Force Recon Assistant Automatic Rifleman"
    };
    class USMC(mmgag): USMC(aar) {
        displayName = "MMG Assistant Gunner"
    };
    class USMC(hmgag): USMC(aar) {
        displayName = "HMG Assistant Gunner"
    };
    class USMC(matag): USMC(aar) {
        displayName = "MAT Assistant Gunner"
    };
    class USMC(hatag): USMC(aar) {
        displayName = "HAT Assistant Gunner"
    };
    class USMC(msamag): USMC(aar) {
        displayName = "MSAM Assistant Gunner"
    };
    class USMC(mtrag): USMC(aar) {
        displayName = "Mortar Assistant Gunner"
    };
    class USMC(mtrg): USMC(aar) { // for some reason the gunner is considered an assistant
        displayName = "Mortar Gunner"
    };
    class USMC(spotter): USMC(aar) {
        displayName = "Spotter"
    };
    class USMC(ar): USMC(rifleman) {
        displayName = "Automatic Rifleman"
        icon = "iconManMG";
        role = "MachineGunner";
    };
    class USMC(sf_ar): USMC(ar) {
        displayName = "Force Recon Automatic Rifleman"
    };
    class USMC(mmgg): USMC(ar) {
        displayName = "MMG Gunner"
    };
    class USMC(hmgg): USMC(ar) {
        displayName = "HMG Gunner"
    };
    class USMC(lat): USMC(rifleman) {
        displayName = "Rifleman Anti-Tank"
        icon = "iconManAT";
        role = "MissileSpecialist";
    };
    class USMC(sf_lat): USMC(lat) {
        displayName = "Force Recon Rifleman Anti-Tank"
    };
    class USMC(matg): USMC(lat) {
        displayName = "MAT Gunner"
    };
    class USMC(hatg): USMC(lat) {
        displayName = "HAT Gunner"
    };
    class USMC(msamg): USMC(lat) {
        displayName = "MSAM Gunner"
    };
    class USMC(coy): USMC(rifleman) {
        displayName = "Company Commander";
        icon = "iconManOfficer";
    };
    class USMC(xo): USMC(coy) {
        displayName = "Company Executive Officer";
    };
    class USMC(fac): USMC(coy) {
        displayName = "Forward Air Controller";
    };
    class USMC(plt): USMC(coy) {
        displayName = "Platoon Leader";
    };
    class USMC(sgt): USMC(coy) {
        displayName = "Platoon Sergent";
    };
    class USMC(sl): USMC(rifleman) {
        displayName = "Squad Leader";
        icon = "iconManLeader";
    };
    class USMC(sf_sl): USMC(sl) {
        displayName = "Force Recon Squad Leader";
    };
    class USMC(mmgl): USMC(sl) {
        displayName = "MMG Leader";
    };
    class USMC(hmgl): USMC(sl) {
        displayName = "HMG Leader";
    };
    class USMC(matl): USMC(sl) {
        displayName = "MAT Leader";
    };
    class USMC(hatl): USMC(sl) {
        displayName = "HAT Leader";
    };
    class USMC(msaml): USMC(sl) {
        displayName = "MSAM Leader";
    };
    class USMC(mtrl): USMC(sl) {
        displayName = "MTR Leader";
    };
    class USMC(stl): USMC(sl) {
        displayName = "Scout Leader";
    };
    class USMC(ftl): USMC(sl) {
        displayName = "Fire Team Leader";
    };
    class USMC(sf_ftl): USMC(sl) {
        displayName = "Force Recon Fire Team Leader";
    };
    class USMC(vicl): USMC(sl) {
        displayName = "Vehicle Leader";
        engineer = 1;
        role = "Crewman";
    };
    class USMC(eodl): USMC(sl) {
        displayName = "EOD Leader";
        engineer = 1;
        role = "Sapper";
    };
    class USMC(cm): USMC(rifleman) {
        attendant = 1;
        displayName = "Company Medic";
        icon = "iconManMedic";
        role = "CombatLifeSaver";
    };
    class USMC(plm): USMC(cm) {
        displayName = "Platoon Medic";
    };
    class USMC(sm): USMC(cm) {
        displayName = "Squad Medic";
    };
    class USMC(sf_sm): USMC(cm) {
        displayName = "Force Recon Medic";
    };
    class USMC(eod): USMC(eodl) {
        displayName = "EOD Technician";
        icon = "iconManExplosive";
    };
    class USMC(vicc): USMC(vicl) {
        displayName = "Vehicle Crew";
        icon = "iconMan";
    };
    class USMC(vicd): USMC(vicl) {
        displayName = "Vehicle Driver";
        icon = "iconManEngineer";
        role = "Sapper";
    };
    class USMC(pilot): USMC(rifleman) {
        ACE_GForceCoef = 0.55;
        displayName = "Pilot";
        engineer = 1;
        role = "Crewman";
    };
    class USMC(cc): USMC(pilot) {
        displayName = "Crew Chief";
        icon = "iconManEngineer";
        role = "Sapper";
    };

    // add POTATO MSV
    class SoldierEB;
    class MSV(rifleman): SoldierEB {
        author = "AACO";
        displayName = "Rifleman"
        faction = "potato_msv";
        role = "Rifleman";
        scope = 2;
    };
    class MSV(rifleman_02): MSV(rifleman) {
        displayName = "Rifleman 2"
    };
    class MSV(rifleman_03): MSV(rifleman) {
        displayName = "Rifleman 3"
    };
    class MSV(rifleman_04): MSV(rifleman) {
        displayName = "Rifleman 4"
    };
    class MSV(sf_rifleman): MSV(marksman) {
        displayName = "Spetsnaz Rifleman"
    };
    class MSV(marksman): MSV(rifleman) {
        displayName = "Marksman"
    };
    class MSV(sf_marksman): MSV(marksman) {
        displayName = "Spetsnaz Marksman"
    };
    class MSV(aar): MSV(rifleman) {
        displayName = "Assistant Automatic Rifleman"
        role = "Assistant";
    };
    class MSV(sf_aar): MSV(aar) {
        displayName = "Spetsnaz Assistant Automatic Rifleman"
    };
    class MSV(ag): MSV(aar) {
        displayName = "Assistant Grenadier"
    };
    class MSV(mmgag): MSV(aar) {
        displayName = "MMG Assistant Gunner"
    };
    class MSV(hmgag): MSV(aar) {
        displayName = "HMG Assistant Gunner"
    };
    class MSV(matag): MSV(aar) {
        displayName = "MAT Assistant Gunner"
    };
    class MSV(hatag): MSV(aar) {
        displayName = "HAT Assistant Gunner"
    };
    class MSV(msamag): MSV(aar) {
        displayName = "MSAM Assistant Gunner"
    };
    class MSV(mtrag): MSV(aar) {
        displayName = "Mortar Assistant Gunner"
    };
    class MSV(mtrg): MSV(aar) { // for some reason the gunner is considered an assistant
        displayName = "Mortar Gunner"
    };
    class MSV(ar): MSV(rifleman) {
        displayName = "Automatic Rifleman"
        icon = "iconManMG";
        role = "MachineGunner";
    };
    class MSV(sf_ar): MSV(ar) {
        displayName = "Spetsnaz Automatic Rifleman"
    };
    class MSV(mmgg): MSV(ar) {
        displayName = "MMG Gunner"
    };
    class MSV(hmgg): MSV(ar) {
        displayName = "HMG Gunner"
    };
    class MSV(g): MSV(rifleman) {
        displayName = "Grenadier"
        icon = "iconManAT";
        role = "MissileSpecialist";
    };
    class MSV(sf_g): MSV(g) {
        displayName = "Spetsnaz Grenadier"
    };
    class MSV(matg): MSV(g) {
        displayName = "MAT Gunner"
    };
    class MSV(hatg): MSV(g) {
        displayName = "HAT Gunner"
    };
    class MSV(msamg): MSV(g) {
        displayName = "MSAM Gunner"
    };
    class MSV(coy): MSV(rifleman) {
        displayName = "Company Commander";
        icon = "iconManOfficer";
    };
    class MSV(acoy): MSV(coy) {
        displayName = "Assistant Company Commander";
    };
    class MSV(pol): MSV(coy) {
        displayName = "Company Commissar";
    };
    class MSV(fac): MSV(coy) {
        displayName = "Forward Air Controller";
    };
    class MSV(plt): MSV(coy) {
        displayName = "Platoon Leader";
    };
    class MSV(aplt): MSV(coy) {
        displayName = "Assistant Platoon Leader";
    };
    class MSV(sl): MSV(rifleman) {
        displayName = "Squad Leader";
        icon = "iconManLeader";
    };
    class MSV(sf_sl): MSV(sl) {
        displayName = "Spetsnaz Squad Leader";
    };
    class MSV(sf_ftl): MSV(sl) {
        displayName = "Spetsnaz Fireteam Leader";
    };
    class MSV(mmgl): MSV(sl) {
        displayName = "MMG Leader";
    };
    class MSV(hmgl): MSV(sl) {
        displayName = "HMG Leader";
    };
    class MSV(matl): MSV(sl) {
        displayName = "MAT Leader";
    };
    class MSV(hatl): MSV(sl) {
        displayName = "HAT Leader";
    };
    class MSV(msaml): MSV(sl) {
        displayName = "MSAM Leader";
    };
    class MSV(mtrl): MSV(sl) {
        displayName = "MTR Leader";
    };
    class MSV(stl): MSV(sl) {
        displayName = "Scout Leader";
    };
    class MSV(sr): MSV(sl) {
        displayName = "Senior Rifleman";
    };
    class MSV(vicl): MSV(sl) {
        displayName = "Vehicle Leader";
        engineer = 1;
        role = "Crewman";
    };
    class MSV(engl): MSV(sl) {
        displayName = "Engineer Leader";
        engineer = 1;
        role = "Sapper";
    };
    class MSV(cm): MSV(rifleman) {
        attendant = 1;
        displayName = "Company Medic";
        icon = "iconManMedic";
        role = "CombatLifeSaver";
    };
    class MSV(plm): MSV(cm) {
        displayName = "Platoon Medic";
    };
    class MSV(sm): MSV(cm) {
        displayName = "Squad Medic";
    };
    class MSV(sf_sm): MSV(cm) {
        displayName = "Spetsnaz Medic";
    };
    class MSV(eng): MSV(engl) {
        displayName = "Engineer";
        icon = "iconManEngineer";
    };
    class MSV(demo): MSV(engl) {
        displayName = "Demolition Technician";
        icon = "iconManExplosive";
    };
    class MSV(vicc): MSV(vicl) {
        displayName = "Vehicle Crew";
        icon = "iconMan";
    };
    class MSV(vicd): MSV(vicl) {
        displayName = "Vehicle Driver";
        icon = "iconManEngineer";
        role = "Sapper";
    };
    class MSV(pilot): MSV(rifleman) { // "MSV"
        ACE_GForceCoef = 0.55;
        displayName = "Pilot";
        engineer = 1;
        role = "Crewman";
    };
    class MSV(cc): MSV(pilot) { // "MSV"
        displayName = "Crew Chief";
        icon = "iconManEngineer";
        role = "Sapper";
    };
};
