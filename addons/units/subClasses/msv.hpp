class SoldierEB;
class MSV(rifleman): SoldierEB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,e));
    role = "Rifleman";
    scope = 2;
    editorSubcategory = "Fireteam";
};
class MSV(rifleman_02): MSV(rifleman) {
    displayName = "Rifleman 2";
};
class MSV(rifleman_03): MSV(rifleman) {
    displayName = "Rifleman 3";
};
class MSV(rifleman_04): MSV(rifleman) {
    displayName = "Rifleman 4";
};
class MSV(sf_rifleman): MSV(rifleman) {
    displayName = "Special Forces Rifleman";
    editorSubcategory = "SF";
};
class MSV(sf_rifleman_02): MSV(sf_rifleman) {
    displayName = "Special Forces Rifleman 2";
};
class MSV(sniper): MSV(rifleman) {
    displayName = "Sniper";
    role = "Marksman";
    editorSubcategory = "Weapons";
};
class MSV(aar): MSV(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class MSV(sf_aar): MSV(aar) {
    displayName = "Special Forces Assistant Automatic Rifleman";
    editorSubcategory = "SF";
};
class MSV(mmgag): MSV(aar) {
    displayName = "MMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(hmgag): MSV(aar) {
    displayName = "HMG Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(matag): MSV(aar) {
    displayName = "MAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(hatag): MSV(aar) {
    displayName = "HAT Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(msamag): MSV(aar) {
    displayName = "MSAM Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(mtrag): MSV(aar) {
    displayName = "Mortar Assistant Gunner";
    editorSubcategory = "Weapons";
};
class MSV(mtrg): MSV(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
    editorSubcategory = "Weapons";
};
class MSV(spotter): MSV(aar) {
    displayName = "Spotter";
    editorSubcategory = "Weapons";
};
class MSV(ar): MSV(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class MSV(sf_ar): MSV(ar) {
    displayName = "Special Forces Automatic Rifleman";
    editorSubcategory = "SF";
};
class MSV(mmgg): MSV(ar) {
    displayName = "MMG Gunner";
    editorSubcategory = "Weapons";
};
class MSV(hmgg): MSV(ar) {
    displayName = "HMG Gunner";
    editorSubcategory = "Weapons";
};
class MSV(lat): MSV(rifleman) {
    displayName = "Rifleman Anti-Tank";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class MSV(sf_lat): MSV(lat) {
    displayName = "Special Forces Rifleman Anti-Tank";
    editorSubcategory = "SF";
};
class MSV(matg): MSV(lat) {
    displayName = "MAT Gunner";
    editorSubcategory = "Weapons";
};
class MSV(hatg): MSV(lat) {
    displayName = "HAT Gunner";
    editorSubcategory = "Weapons";
};
class MSV(msamg): MSV(lat) {
    displayName = "MSAM Gunner";
    editorSubcategory = "Weapons";
};
class MSV(coy): MSV(rifleman) {
    displayName = "Company Commander";
    icon = "iconManOfficer";
    editorSubcategory = "Company";
};
class MSV(xo): MSV(coy) {
    displayName = "Company Executive Officer";
    editorSubcategory = "Company";
};
class MSV(uav): MSV(coy) {
    displayName = "Company UAV Operator";
};
class MSV(fac): MSV(coy) {
    displayName = "Forward Air Controller";
    editorSubcategory = "Company";
};
class MSV(plt): MSV(coy) {
    displayName = "Platoon Leader";
    editorSubcategory = "Platoon";
};
class MSV(sgt): MSV(coy) {
    displayName = "Platoon Sergent";
    editorSubcategory = "Platoon";
};
class MSV(sl): MSV(rifleman) {
    displayName = "Squad Leader";
    icon = "iconManLeader";
    editorSubcategory = "Squad";
};
class MSV(sf_sl): MSV(sl) {
    displayName = "Special Forces Squad Leader";
    editorSubcategory = "SF";
};
class MSV(mmgl): MSV(sl) {
    displayName = "MMG Leader";
    editorSubcategory = "Weapons";
};
class MSV(hmgl): MSV(sl) {
    displayName = "HMG Leader";
    editorSubcategory = "Weapons";
};
class MSV(matl): MSV(sl) {
    displayName = "MAT Leader";
    editorSubcategory = "Weapons";
};
class MSV(hatl): MSV(sl) {
    displayName = "HAT Leader";
    editorSubcategory = "Weapons";
};
class MSV(msaml): MSV(sl) {
    displayName = "MSAM Leader";
    editorSubcategory = "Weapons";
};
class MSV(mtrl): MSV(sl) {
    displayName = "Mortar Leader";
    editorSubcategory = "Weapons";
};
class MSV(stl): MSV(sl) {
    displayName = "Scout Leader";
    editorSubcategory = "Weapons";
};
class MSV(ftl): MSV(sl) {
    displayName = "Fire Team Leader";
    editorSubcategory = "Fireteam";
};
class MSV(sf_ftl): MSV(sl) {
    displayName = "Special Forces Fire Team Leader";
    editorSubcategory = "SF";
};
class MSV(vicl): MSV(sl) {
    displayName = "Vehicle Leader";
    engineer = 1;
    role = "Crewman";
    editorSubcategory = "VicCrew";
};
class MSV(engl): MSV(sl) {
    displayName = "Engineer Leader";
    engineer = 1;
    role = "Engineer";
    editorSubcategory = "Engi";
};
class MSV(cm): MSV(rifleman) {
    attendant = 1;
    displayName = "Company Medic";
    icon = "iconManMedic";
    role = "CombatLifeSaver";
    editorSubcategory = "Company";
};
class MSV(plm): MSV(cm) {
    displayName = "Platoon Medic";
    editorSubcategory = "Platoon";
};
class MSV(sm): MSV(cm) {
    displayName = "Squad Medic";
    editorSubcategory = "Squad";
};
class MSV(sf_sm): MSV(cm) {
    displayName = "Special Forces Medic";
    editorSubcategory = "SF";
};
class MSV(eng): MSV(engl) {
    displayName = "Engineer";
    icon = "iconManEngineer";
};
class MSV(demo): MSV(engl) {
    displayName = "Demolition Technician";
    icon = "iconManExplosive";
};
class MSV(mine): MSV(demo) {
    displayName = "Mine Technician";
    icon = "iconManExplosive";
};
class MSV(vicc): MSV(vicl) {
    displayName = "Vehicle Crew";
    icon = "iconMan";
};
class MSV(vicd): MSV(vicl) {
    displayName = "Vehicle Driver";
    icon = "iconManEngineer";
    role = "Engineer";
};
class MSV(pilot): MSV(rifleman) {
    ACE_GForceCoef = 0.55;
    displayName = "Pilot";
    engineer = 1;
    role = "Crewman";
    editorSubcategory = "Aircrew";
};
class MSV(cc): MSV(pilot) {
    displayName = "Crew Chief";
    icon = "iconManEngineer";
    role = "Engineer";
};
class MSV(helicrew): MSV(cc) {
    displayName = "Air Crew";
};
