// class SoldierEB;
class BWC_MSV(rifleman): SoldierEB {
    author = "AACO";
    displayName = "Rifleman";
    faction = QUOTE(DOUBLES(PREFIX,msv));
    role = "Rifleman";
    scope = 1; // don't show in editor
};
class BWC_MSV(rifleman_02): BWC_MSV(rifleman) {
    displayName = "Rifleman 2";
};
class BWC_MSV(rifleman_03): BWC_MSV(rifleman) {
    displayName = "Rifleman 3";
};
class BWC_MSV(rifleman_04): BWC_MSV(rifleman) {
    displayName = "Rifleman 4";
};
class BWC_MSV(sf_rifleman): BWC_MSV(rifleman) {
    displayName = "Spetsnaz Rifleman";
};
class BWC_MSV(marksman): BWC_MSV(rifleman) {
    displayName = "Marksman";
};
class BWC_MSV(sf_marksman): BWC_MSV(marksman) {
    displayName = "Spetsnaz Marksman";
};
class BWC_MSV(aar): BWC_MSV(rifleman) {
    displayName = "Assistant Automatic Rifleman";
    role = "Assistant";
};
class BWC_MSV(sf_aar): BWC_MSV(aar) {
    displayName = "Spetsnaz Assistant Automatic Rifleman";
};
class BWC_MSV(ag): BWC_MSV(aar) {
    displayName = "Assistant Grenadier";
};
class BWC_MSV(sf_ag): BWC_MSV(ag) {
    displayName = "Spetsnaz Assistant Grenadier";
};
class BWC_MSV(mmgag): BWC_MSV(aar) {
    displayName = "MMG Assistant Gunner";
};
class BWC_MSV(hmgag): BWC_MSV(aar) {
    displayName = "HMG Assistant Gunner";
};
class BWC_MSV(matag): BWC_MSV(aar) {
    displayName = "MAT Assistant Gunner";
};
class BWC_MSV(hatag): BWC_MSV(aar) {
    displayName = "HAT Assistant Gunner";
};
class BWC_MSV(msamag): BWC_MSV(aar) {
    displayName = "MSAM Assistant Gunner";
};
class BWC_MSV(mtrag): BWC_MSV(aar) {
    displayName = "Mortar Assistant Gunner";
};
class BWC_MSV(mtrg): BWC_MSV(aar) { // for some reason the gunner is considered an assistant
    displayName = "Mortar Gunner";
};
class BWC_MSV(ar): BWC_MSV(rifleman) {
    displayName = "Automatic Rifleman";
    icon = "iconManMG";
    role = "MachineGunner";
};
class BWC_MSV(sf_ar): BWC_MSV(ar) {
    displayName = "Spetsnaz Automatic Rifleman";
};
class BWC_MSV(mmgg): BWC_MSV(ar) {
    displayName = "MMG Gunner";
};
class BWC_MSV(hmgg): BWC_MSV(ar) {
    displayName = "HMG Gunner";
};
class BWC_MSV(g): BWC_MSV(rifleman) {
    displayName = "Grenadier";
    icon = "iconManAT";
    role = "MissileSpecialist";
};
class BWC_MSV(sf_g): BWC_MSV(g) {
    displayName = "Spetsnaz Grenadier";
};
class BWC_MSV(matg): BWC_MSV(g) {
    displayName = "MAT Gunner";
};
class BWC_MSV(hatg): BWC_MSV(g) {
    displayName = "HAT Gunner";
};
class BWC_MSV(msamg): BWC_MSV(g) {
    displayName = "MSAM Gunner";
};
class BWC_MSV(coy): BWC_MSV(rifleman) {
    displayName = "Company Commander";
    icon = "iconManOfficer";
};
class BWC_MSV(acoy): BWC_MSV(coy) {
    displayName = "Assistant Company Commander";
};
class BWC_MSV(pol): BWC_MSV(coy) {
    displayName = "Company Commissar";
};
class BWC_MSV(fac): BWC_MSV(coy) {
    displayName = "Forward Air Controller";
};
class BWC_MSV(plt): BWC_MSV(coy) {
    displayName = "Platoon Leader";
};
class BWC_MSV(aplt): BWC_MSV(coy) {
    displayName = "Assistant Platoon Leader";
};
class BWC_MSV(sl): BWC_MSV(rifleman) {
    displayName = "Squad Leader";
    icon = "iconManLeader";
};
class BWC_MSV(sf_sl): BWC_MSV(sl) {
    displayName = "Spetsnaz Squad Leader";
};
class BWC_MSV(sf_ftl): BWC_MSV(sl) {
    displayName = "Spetsnaz Fireteam Leader";
};
class BWC_MSV(mmgl): BWC_MSV(sl) {
    displayName = "MMG Leader";
};
class BWC_MSV(hmgl): BWC_MSV(sl) {
    displayName = "HMG Leader";
};
class BWC_MSV(matl): BWC_MSV(sl) {
    displayName = "MAT Leader";
};
class BWC_MSV(hatl): BWC_MSV(sl) {
    displayName = "HAT Leader";
};
class BWC_MSV(msaml): BWC_MSV(sl) {
    displayName = "MSAM Leader";
};
class BWC_MSV(mtrl): BWC_MSV(sl) {
    displayName = "Mortar Leader";
};
class BWC_MSV(stl): BWC_MSV(sl) {
    displayName = "Scout Leader";
};
class BWC_MSV(sr): BWC_MSV(sl) {
    displayName = "Senior Rifleman";
};
class BWC_MSV(vicl): BWC_MSV(sl) {
    displayName = "Vehicle Leader";
    engineer = 1;
    role = "Crewman";
};
class BWC_MSV(engl): BWC_MSV(sl) {
    displayName = "Engineer Leader";
    engineer = 1;
    role = "Sapper";
};
class BWC_MSV(cm): BWC_MSV(rifleman) {
    attendant = 1;
    displayName = "Company Medic";
    icon = "iconManMedic";
    role = "CombatLifeSaver";
};
class BWC_MSV(plm): BWC_MSV(cm) {
    displayName = "Platoon Medic";
};
class BWC_MSV(sm): BWC_MSV(cm) {
    displayName = "Squad Medic";
};
class BWC_MSV(sf_sm): BWC_MSV(cm) {
    displayName = "Spetsnaz Medic";
};
class BWC_MSV(eng): BWC_MSV(engl) {
    displayName = "Engineer";
    icon = "iconManEngineer";
};
class BWC_MSV(demo): BWC_MSV(engl) {
    displayName = "Demolition Technician";
    icon = "iconManExplosive";
};
class BWC_MSV(vicc): BWC_MSV(vicl) {
    displayName = "Vehicle Crew";
    icon = "iconMan";
};
class BWC_MSV(vicd): BWC_MSV(vicl) {
    displayName = "Vehicle Driver";
    icon = "iconManEngineer";
    role = "Sapper";
};
class BWC_MSV(pilot): BWC_MSV(rifleman) { // "MSV"
    ACE_GForceCoef = 0.55;
    displayName = "Pilot";
    engineer = 1;
    role = "Crewman";
};
class BWC_MSV(cc): BWC_MSV(pilot) { // "MSV"
    displayName = "Crew Chief";
    icon = "iconManEngineer";
    role = "Sapper";
};