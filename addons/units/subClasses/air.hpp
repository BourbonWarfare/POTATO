class SoldierGB;
class AIR(rifleman): SoldierGB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,airborne));
    role = "Rifleman";
    scope = 2;
    editorSubcategory = "Fireteam";
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
    displayName = "Special Forces Rifleman";
    editorSubcategory = "SF";
};
class AIR(sf_rifleman_02): AIR(sf_rifleman) {
    displayName = "Special Forces Rifleman 2";
};
class AIR(sniper): AIR(rifleman) {
    displayName = "Sniper";
    role = "Marksman";
    editorSubcategory = "Weapons";
};
class AIR(aar): AIR(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class AIR(sf_aar): AIR(aar) {
    displayName = "Special Forces Assistant Automatic Rifleman";
    editorSubcategory = "SF";
};
class AIR(mmgag): AIR(aar) {
    displayName = "MMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(hmgag): AIR(aar) {
    displayName = "HMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(matag): AIR(aar) {
    displayName = "MAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(hatag): AIR(aar) {
    displayName = "HAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(msamag): AIR(aar) {
    displayName = "MSAM Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(mtrag): AIR(aar) {
    displayName = "Mortar Assistant Gunner";
    editorSubcategory = "Weapons";
};
class AIR(mtrg): AIR(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
    editorSubcategory = "Weapons";
};
class AIR(spotter): AIR(aar) {
    displayName = "Spotter";
    editorSubcategory = "Weapons";
};
class AIR(ar): AIR(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class AIR(sf_ar): AIR(ar) {
    displayName = "Special Forces Automatic Rifleman";
    editorSubcategory = "SF";
};
class AIR(mmgg): AIR(ar) {
    displayName = "MMG Gunner";
    editorSubcategory = "Weapons";
};
class AIR(hmgg): AIR(ar) {
    displayName = "HMG Gunner";
    editorSubcategory = "Weapons";
};
class AIR(lat): AIR(rifleman) {
    displayName = "Rifleman Anti-Tank";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class AIR(sf_lat): AIR(lat) {
    displayName = "Special Forces Rifleman Anti-Tank";
    editorSubcategory = "SF";
};
class AIR(matg): AIR(lat) {
    displayName = "MAT Gunner";
    editorSubcategory = "Weapons";
};
class AIR(hatg): AIR(lat) {
    displayName = "HAT Gunner";
    editorSubcategory = "Weapons";
};
class AIR(msamg): AIR(lat) {
    displayName = "MSAM Gunner";
    editorSubcategory = "Weapons";
};
class AIR(coy): AIR(rifleman) {
    displayName = "Company Commander";
    icon = "iconManOfficer";
    editorSubcategory = "Company";
};
class AIR(xo): AIR(coy) {
    displayName = "Company Executive Officer";
    editorSubcategory = "Company";
};
class AIR(uav): AIR(coy) {
    displayName = "Company UAV Operator";
};
class AIR(fac): AIR(coy) {
    displayName = "Forward Air Controller";
    editorSubcategory = "Company";
};
class AIR(plt): AIR(coy) {
    displayName = "Platoon Leader";
    editorSubcategory = "Platoon";
};
class AIR(sgt): AIR(coy) {
    displayName = "Platoon Sergent";
    editorSubcategory = "Platoon";
};
class AIR(sl): AIR(rifleman) {
    displayName = "Squad Leader";
    icon = "iconManLeader";
    editorSubcategory = "Squad";
};
class AIR(sf_sl): AIR(sl) {
    displayName = "Special Forces Squad Leader";
    editorSubcategory = "SF";
};
class AIR(mmgl): AIR(sl) {
    displayName = "MMG Leader";
    editorSubcategory = "Weapons";
};
class AIR(hmgl): AIR(sl) {
    displayName = "HMG Leader";
    editorSubcategory = "Weapons";
};
class AIR(matl): AIR(sl) {
    displayName = "MAT Leader";
    editorSubcategory = "Weapons";
};
class AIR(hatl): AIR(sl) {
    displayName = "HAT Leader";
    editorSubcategory = "Weapons";
};
class AIR(msaml): AIR(sl) {
    displayName = "MSAM Leader";
    editorSubcategory = "Weapons";
};
class AIR(mtrl): AIR(sl) {
    displayName = "Mortar Leader";
    editorSubcategory = "Weapons";
};
class AIR(stl): AIR(sl) {
    displayName = "Scout Leader";
    editorSubcategory = "Weapons";
};
class AIR(ftl): AIR(sl) {
    displayName = "Fire Team Leader";
    editorSubcategory = "Fireteam";
};
class AIR(sf_ftl): AIR(sl) {
    displayName = "Special Forces Fire Team Leader";
    editorSubcategory = "SF";
};
class AIR(vicl): AIR(sl) {
    displayName = "Vehicle Leader";
    engineer = 1;
    role = "Crewman";
    editorSubcategory = "VicCrew";
};
class AIR(engl): AIR(sl) {
    displayName = "Sapper Leader";
    engineer = 1;
    role = "Sapper";
    editorSubcategory = "Engi";
};
class AIR(cm): AIR(rifleman) {
    attendant = 1;
    displayName = "Company Medic";
    icon = "iconManMedic";
    role = "CombatLifeSaver";
    editorSubcategory = "Company";
};
class AIR(plm): AIR(cm) {
    displayName = "Platoon Medic";
    editorSubcategory = "Platoon";
};
class AIR(sm): AIR(cm) {
    displayName = "Squad Medic";
    editorSubcategory = "Squad";
};
class AIR(sf_sm): AIR(cm) {
    displayName = "Special Forces Medic";
    editorSubcategory = "SF";
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
    editorSubcategory = "Aircrew";
};
class AIR(cc): AIR(pilot) {
    displayName = "Crew Chief";
    icon = "iconManEngineer";
    role = "Sapper";
};
