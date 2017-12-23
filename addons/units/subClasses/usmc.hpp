class SoldierWB;
class USMC(rifleman): SoldierWB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,usmc));
    role = "Rifleman";
    scope = 2;
};
class USMC(rifleman_02): USMC(rifleman) {
    displayName = "Rifleman 2";
};
class USMC(rifleman_03): USMC(rifleman) {
    displayName = "Rifleman 3";
};
class USMC(rifleman_04): USMC(rifleman) {
    displayName = "Rifleman 4";
};
class USMC(sf_rifleman): USMC(rifleman) {
    displayName = "Force Recon Rifleman";
};
class USMC(sniper): USMC(rifleman) {
    displayName = "Sniper";
    role = "Marksman";
};
class USMC(aar): USMC(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class USMC(sf_aar): USMC(aar) {
    displayName = "Force Recon Assistant Automatic Rifleman";
};
class USMC(mmgag): USMC(aar) {
    displayName = "MMG Assistant Gunner";
};
class USMC(hmgag): USMC(aar) {
    displayName = "HMG Assistant Gunner";
};
class USMC(matag): USMC(aar) {
    displayName = "MAT Assistant Gunner";
};
class USMC(hatag): USMC(aar) {
    displayName = "HAT Assistant Gunner";
};
class USMC(msamag): USMC(aar) {
    displayName = "MSAM Assistant Gunner";
};
class USMC(mtrag): USMC(aar) {
    displayName = "Mortar Assistant Gunner";
};
class USMC(mtrg): USMC(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
};
class USMC(hmtrag): USMC(aar) {
    displayName = "Heavy Mortar Assistant Gunner";
};
class USMC(hmtrg): USMC(aar) { // for some reason the gunner is considered an assistant
    displayName = "Heavy Mortar Gunner";
};
class USMC(spotter): USMC(aar) {
    displayName = "Spotter";
};
class USMC(ar): USMC(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class USMC(sf_ar): USMC(ar) {
    displayName = "Force Recon Automatic Rifleman";
};
class USMC(mmgg): USMC(ar) {
    displayName = "MMG Gunner";
};
class USMC(hmgg): USMC(ar) {
    displayName = "HMG Gunner";
};
class USMC(lat): USMC(rifleman) {
    displayName = "Rifleman Anti-Tank";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class USMC(sf_lat): USMC(lat) {
    displayName = "Force Recon Rifleman Anti-Tank";
};
class USMC(matg): USMC(lat) {
    displayName = "MAT Gunner";
};
class USMC(hatg): USMC(lat) {
    displayName = "HAT Gunner";
};
class USMC(msamg): USMC(lat) {
    displayName = "MSAM Gunner";
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
    displayName = "Mortar Leader";
};
class USMC(hmtrl): USMC(sl) {
    displayName = "Heavy Mortar Leader";
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
