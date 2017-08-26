class SoldierGB;
class AIR(rifleman): SoldierGB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,airborne));
    role = "Rifleman";
    scope = 2;
};
class AIR(rifleman_02): AIR(rifleman) {
    displayName = "Rifleman 2";
};
class AIR(rifleman_03): AIR(rifleman) {
    displayName = "Rifleman 3";
};
class AIR(rifleman_04): AIR(rifleman) {
    displayName = "Rifleman 4";
};
class AIR(sf_rifleman): AIR(rifleman) {
    displayName = "SAS Rifleman";
};
class AIR(sniper): AIR(rifleman) {
    displayName = "Sniper";
    role = "Marksman";
};
class AIR(aar): AIR(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class AIR(sf_aar): AIR(aar) {
    displayName = "SAS Assistant Automatic Rifleman";
};
class AIR(mmgag): AIR(aar) {
    displayName = "MMG Assistant Gunner";
};
class AIR(hmgag): AIR(aar) {
    displayName = "HMG Assistant Gunner";
};
class AIR(matag): AIR(aar) {
    displayName = "MAT Assistant Gunner";
};
class AIR(hatag): AIR(aar) {
    displayName = "HAT Assistant Gunner";
};
class AIR(msamag): AIR(aar) {
    displayName = "MSAM Assistant Gunner";
};
class AIR(mtrag): AIR(aar) {
    displayName = "Mortar Assistant Gunner";
};
class AIR(mtrg): AIR(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
};
class AIR(spotter): AIR(aar) {
    displayName = "Spotter";
};
class AIR(ar): AIR(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class AIR(sf_ar): AIR(ar) {
    displayName = "SAS Automatic Rifleman";
};
class AIR(mmgg): AIR(ar) {
    displayName = "MMG Gunner";
};
class AIR(hmgg): AIR(ar) {
    displayName = "HMG Gunner";
};
class AIR(lat): AIR(rifleman) {
    displayName = "Rifleman Anti-Tank";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class AIR(sf_lat): AIR(lat) {
    displayName = "SAS Rifleman Anti-Tank";
};
class AIR(matg): AIR(lat) {
    displayName = "MAT Gunner";
};
class AIR(hatg): AIR(lat) {
    displayName = "HAT Gunner";
};
class AIR(msamg): AIR(lat) {
    displayName = "MSAM Gunner";
};
class AIR(coy): AIR(rifleman) {
    displayName = "Company Commander";
    icon = "iconManOfficer";
};
class AIR(xo): AIR(coy) {
    displayName = "Company Executive Officer";
};
class AIR(fac): AIR(coy) {
    displayName = "Forward Air Controller";
};
class AIR(plt): AIR(coy) {
    displayName = "Platoon Leader";
};
class AIR(sgt): AIR(coy) {
    displayName = "Platoon Sergent";
};
class AIR(sl): AIR(rifleman) {
    displayName = "Squad Leader";
    icon = "iconManLeader";
};
class AIR(sf_sl): AIR(sl) {
    displayName = "SAS Squad Leader";
};
class AIR(mmgl): AIR(sl) {
    displayName = "MMG Leader";
};
class AIR(hmgl): AIR(sl) {
    displayName = "HMG Leader";
};
class AIR(matl): AIR(sl) {
    displayName = "MAT Leader";
};
class AIR(hatl): AIR(sl) {
    displayName = "HAT Leader";
};
class AIR(msaml): AIR(sl) {
    displayName = "MSAM Leader";
};
class AIR(mtrl): AIR(sl) {
    displayName = "Mortar Leader";
};
class AIR(stl): AIR(sl) {
    displayName = "Scout Leader";
};
class AIR(ftl): AIR(sl) {
    displayName = "Fire Team Leader";
};
class AIR(sf_ftl): AIR(sl) {
    displayName = "SAS Fire Team Leader";
};
class AIR(vicl): AIR(sl) {
    displayName = "Vehicle Leader";
    engineer = 1;
    role = "Crewman";
};
class AIR(engl): AIR(sl) {
    displayName = "Sapper Leader";
    engineer = 1;
    role = "Sapper";
};
class AIR(cm): AIR(rifleman) {
    attendant = 1;
    displayName = "Company Medic";
    icon = "iconManMedic";
    role = "CombatLifeSaver";
};
class AIR(plm): AIR(cm) {
    displayName = "Platoon Medic";
};
class AIR(sm): AIR(cm) {
    displayName = "Squad Medic";
};
class AIR(sf_sm): AIR(cm) {
    displayName = "SAS Medic";
};
class AIR(eng): AIR(engl) {
    displayName = "Sapper";
    icon = "iconManExplosive";
};
class AIR(demo): AIR(engl) {
    displayName = "Demolition Technician";
    icon = "iconManExplosive";
};
class AIR(vicc): AIR(vicl) {
    displayName = "Vehicle Crew";
    icon = "iconMan";
};
class AIR(vicd): AIR(vicl) {
    displayName = "Vehicle Driver";
    icon = "iconManEngineer";
    role = "Sapper";
};
class AIR(pilot): AIR(rifleman) {
    ACE_GForceCoef = 0.55;
    displayName = "Pilot";
    engineer = 1;
    role = "Crewman";
};
class AIR(cc): AIR(pilot) {
    displayName = "Crew Chief";
    icon = "iconManEngineer";
    role = "Sapper";
};
