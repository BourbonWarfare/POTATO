class SoldierWB;
class USMC(rifleman): SoldierWB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,usmc));
    role = "Rifleman";
    scope = 2;
    editorSubcategory = "Fireteam";
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
    displayName = "Special Forces Rifleman";
    editorSubcategory = "SF";
};
class USMC(sf_rifleman_02): USMC(sf_rifleman) {
    displayName = "Special Forces Rifleman 2";
};
class USMC(sniper): USMC(rifleman) {
    displayName = "Sniper";
    role = "Marksman";
    editorSubcategory = "Weapons";
};
class USMC(aar): USMC(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class USMC(sf_aar): USMC(aar) {
    displayName = "Special Forces Assistant Automatic Rifleman";
    editorSubcategory = "SF";
};
class USMC(mmgag): USMC(aar) {
    displayName = "MMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(hmgag): USMC(aar) {
    displayName = "HMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(matag): USMC(aar) {
    displayName = "MAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(hatag): USMC(aar) {
    displayName = "HAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(msamag): USMC(aar) {
    displayName = "MSAM Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(mtrag): USMC(aar) {
    displayName = "Mortar Assistant Gunner";
    editorSubcategory = "Weapons";
};
class USMC(mtrg): USMC(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
    editorSubcategory = "Weapons";
};
class USMC(spotter): USMC(aar) {
    displayName = "Spotter";
    editorSubcategory = "Weapons";
};
class USMC(ar): USMC(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class USMC(sf_ar): USMC(ar) {
    displayName = "Special Forces Automatic Rifleman";
    editorSubcategory = "SF";
};
class USMC(mmgg): USMC(ar) {
    displayName = "MMG Gunner";
    editorSubcategory = "Weapons";
};
class USMC(hmgg): USMC(ar) {
    displayName = "HMG Gunner";
    editorSubcategory = "Weapons";
};
class USMC(lat): USMC(rifleman) {
    displayName = "Rifleman Anti-Tank";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class USMC(sf_lat): USMC(lat) {
    displayName = "Special Forces Rifleman Anti-Tank";
    editorSubcategory = "SF";
};
class USMC(matg): USMC(lat) {
    displayName = "MAT Gunner";
    editorSubcategory = "Weapons";
};
class USMC(hatg): USMC(lat) {
    displayName = "HAT Gunner";
    editorSubcategory = "Weapons";
};
class USMC(msamg): USMC(lat) {
    displayName = "MSAM Gunner";
    editorSubcategory = "Weapons";
};
class USMC(coy): USMC(rifleman) {
    displayName = "Company Commander";
    icon = "iconManOfficer";
    editorSubcategory = "Company";
};
class USMC(xo): USMC(coy) {
    displayName = "Company Executive Officer";
};
class USMC(uav): USMC(coy) {
    displayName = "Company UAV Operator";
};
class USMC(fac): USMC(coy) {
    displayName = "Forward Air Controller";
};
class USMC(plt): USMC(coy) {
    displayName = "Platoon Leader";
    editorSubcategory = "Platoon";
};
class USMC(sgt): USMC(coy) {
    displayName = "Platoon Sergent";
    editorSubcategory = "Platoon";
};
class USMC(sl): USMC(rifleman) {
    displayName = "Squad Leader";
    icon = "iconManLeader";
    editorSubcategory = "Squad";
};
class USMC(sf_sl): USMC(sl) {
    displayName = "Special Forces Squad Leader";
    editorSubcategory = "SF";
};
class USMC(mmgl): USMC(sl) {
    displayName = "MMG Leader";
    editorSubcategory = "Weapons";
};
class USMC(hmgl): USMC(sl) {
    displayName = "HMG Leader";
    editorSubcategory = "Weapons";
};
class USMC(matl): USMC(sl) {
    displayName = "MAT Leader";
    editorSubcategory = "Weapons";
};
class USMC(hatl): USMC(sl) {
    displayName = "HAT Leader";
    editorSubcategory = "Weapons";
};
class USMC(msaml): USMC(sl) {
    displayName = "MSAM Leader";
    editorSubcategory = "Weapons";
};
class USMC(mtrl): USMC(sl) {
    displayName = "Mortar Leader";
    editorSubcategory = "Weapons";
};
class USMC(stl): USMC(sl) {
    displayName = "Scout Leader";
    editorSubcategory = "Weapons";
};
class USMC(ftl): USMC(sl) {
    displayName = "Fire Team Leader";
    editorSubcategory = "Fireteam";
};
class USMC(sf_ftl): USMC(sl) {
    displayName = "Special Forces Fire Team Leader";
    editorSubcategory = "SF";
};
class USMC(vicl): USMC(sl) {
    displayName = "Vehicle Leader";
    engineer = 1;
    role = "Crewman";
    editorSubcategory = "VicCrew";
};
class USMC(engl): USMC(sl) {
    displayName = "Sapper Leader";
    engineer = 1;
    role = "Sapper";
    editorSubcategory = "Engi";
};
class USMC(cm): USMC(rifleman) {
    attendant = 1;
    displayName = "Company Medic";
    icon = "iconManMedic";
    role = "CombatLifeSaver";
    editorSubcategory = "Company";
};
class USMC(plm): USMC(cm) {
    displayName = "Platoon Medic";
    editorSubcategory = "Platoon";
};
class USMC(sm): USMC(cm) {
    displayName = "Squad Medic";
    editorSubcategory = "Squad";
};
class USMC(sf_sm): USMC(cm) {
    displayName = "Special Forces Medic";
    editorSubcategory = "SF";
};
class USMC(eng): USMC(engl) {
    displayName = "Sapper";
    icon = "iconManExplosive";
};
class USMC(demo): USMC(engl) {
    displayName = "Demolition Technician";
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
    editorSubcategory = "Aircrew";
};
class USMC(cc): USMC(pilot) {
    displayName = "Crew Chief";
    icon = "iconManEngineer";
    role = "Sapper";
};
