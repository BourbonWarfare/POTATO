class SoldierEB;
class MSV(rifleman): SoldierEB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,E));
    role = "Rifleman";
    scope = 2;
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
    displayName = "Spetsnaz Rifleman";
};
class MSV(marksman): MSV(rifleman) {
    displayName = "Marksman";
};
class MSV(sf_marksman): MSV(marksman) {
    displayName = "Spetsnaz Marksman";
};
class MSV(aar): MSV(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class MSV(sf_aar): MSV(aar) {
    displayName = "Spetsnaz Assistant Automatic Rifleman";
};
class MSV(ag): MSV(aar) {
    displayName = "Assistant Grenadier";
};
class MSV(sf_ag): MSV(ag) {
    displayName = "Spetsnaz Assistant Grenadier";
};
class MSV(mmgag): MSV(aar) {
    displayName = "MMG Assistant Gunner";
};
class MSV(hmgag): MSV(aar) {
    displayName = "HMG Assistant Gunner";
};
class MSV(matag): MSV(aar) {
    displayName = "MAT Assistant Gunner";
};
class MSV(hatag): MSV(aar) {
    displayName = "HAT Assistant Gunner";
};
class MSV(msamag): MSV(aar) {
    displayName = "MSAM Assistant Gunner";
};
class MSV(mtrag): MSV(aar) {
    displayName = "Mortar Assistant Gunner";
};
class MSV(mtrg): MSV(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
};
class MSV(ar): MSV(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class MSV(sf_ar): MSV(ar) {
    displayName = "Spetsnaz Automatic Rifleman";
};
class MSV(mmgg): MSV(ar) {
    displayName = "MMG Gunner";
};
class MSV(hmgg): MSV(ar) {
    displayName = "HMG Gunner";
};
class MSV(g): MSV(rifleman) {
    displayName = "Grenadier";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class MSV(sf_g): MSV(g) {
    displayName = "Spetsnaz Grenadier";
};
class MSV(matg): MSV(g) {
    displayName = "MAT Gunner";
};
class MSV(hatg): MSV(g) {
    displayName = "HAT Gunner";
};
class MSV(msamg): MSV(g) {
    displayName = "MSAM Gunner";
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
    displayName = "Mortar Leader";
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
