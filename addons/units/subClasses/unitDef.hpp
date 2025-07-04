#ifdef NO_LAMBS
#define BASE_EH class EventHandlers;
#define NO_LAMBS_CONFIG \
crouchProbabilityCombat = 0.4;\
crouchProbabilityEngage = 0.75;\
crouchProbabilityHiding = 0.8;\
formationTime = 5;\
formationX = 5;\
brakeDistance = 1;\
sensitivity = 5;\
fsmDanger = "";\
class EventHandlers: EventHandlers {\
    class PREFIX {\
        init = "params [""_unit""]; _unit setVariable [""lambs_danger_disableAI"", true]; (group _unit) setVariable [""lambs_danger_disableGroupAI"", true];";\
    };\
};
#else
#define NO_LAMBS_CONFIG /* nothing */
#define BASE_EH /* nothing */
#endif


#define FACTION_DEF(BASE_UNIT,FACTION_LETTER,SCOPE)\
class BASE_UNIT: CAManBase {\
  BASE_EH\
};\
class FACTION_MACRO(rifleman): BASE_UNIT {\
    author = "AACO";\
    displayName = "Rifleman";\
    faction = QUOTE(DOUBLES(PREFIX,FACTION_LETTER));\
    role = "Rifleman";\
    scope = SCOPE;\
NO_LAMBS_CONFIG\
    editorSubcategory = "Fireteam";\
};\
class FACTION_MACRO(rifleman_02): FACTION_MACRO(rifleman) {\
    displayName = "Rifleman 2";\
};\
class FACTION_MACRO(rifleman_03): FACTION_MACRO(rifleman) {\
    displayName = "Rifleman 3";\
};\
class FACTION_MACRO(rifleman_04): FACTION_MACRO(rifleman) {\
    displayName = "Rifleman 4";\
};\
class FACTION_MACRO(sf_rifleman): FACTION_MACRO(rifleman) {\
    displayName = "Special Forces Rifleman";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(sf_rifleman_02): FACTION_MACRO(sf_rifleman) {\
    displayName = "Special Forces Rifleman 2";\
};\
class FACTION_MACRO(sniper): FACTION_MACRO(rifleman) {\
    displayName = "Sniper";\
    role = "Marksman";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(aar): FACTION_MACRO(rifleman) {\
    displayName = "Assistant Automatic Rifleman";\
    role = "Assistant";\
};\
class FACTION_MACRO(sf_aar): FACTION_MACRO(aar) {\
    displayName = "Special Forces Assistant Automatic Rifleman";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(mmgag): FACTION_MACRO(aar) {\
    displayName = "MMG Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hmgag): FACTION_MACRO(aar) {\
    displayName = "HMG Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(matag): FACTION_MACRO(aar) {\
    displayName = "MAT Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hatag): FACTION_MACRO(aar) {\
    displayName = "HAT Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(msamag): FACTION_MACRO(aar) {\
    displayName = "MSAM Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(mtrag): FACTION_MACRO(aar) {\
    displayName = "Mortar Assistant Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(mtrg): FACTION_MACRO(aar) { \
    displayName = "Mortar Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(spotter): FACTION_MACRO(aar) {\
    displayName = "Spotter";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(ar): FACTION_MACRO(rifleman) {\
    displayName = "Automatic Rifleman";\
    icon = "iconManMG";\
    role = "MachineGunner";\
};\
class FACTION_MACRO(sf_ar): FACTION_MACRO(ar) {\
    displayName = "Special Forces Automatic Rifleman";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(mmgg): FACTION_MACRO(ar) {\
    displayName = "MMG Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hmgg): FACTION_MACRO(ar) {\
    displayName = "HMG Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(lat): FACTION_MACRO(rifleman) {\
    displayName = "Rifleman Anti-Tank";\
    icon = "iconManAT";\
    role = "MissileSpecialist";\
};\
class FACTION_MACRO(sf_lat): FACTION_MACRO(lat) {\
    displayName = "Special Forces Rifleman Anti-Tank";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(matg): FACTION_MACRO(lat) {\
    displayName = "MAT Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hatg): FACTION_MACRO(lat) {\
    displayName = "HAT Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(msamg): FACTION_MACRO(lat) {\
    displayName = "MSAM Gunner";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(coy): FACTION_MACRO(rifleman) {\
    displayName = "Company Commander";\
    icon = "iconManOfficer";\
    editorSubcategory = "Company";\
};\
class FACTION_MACRO(xo): FACTION_MACRO(coy) {\
    displayName = "Company Executive Officer";\
    editorSubcategory = "Company";\
};\
class FACTION_MACRO(uav): FACTION_MACRO(coy) {\
    displayName = "Company UAV Operator";\
};\
class FACTION_MACRO(fac): FACTION_MACRO(coy) {\
    displayName = "Forward Air Controller";\
    editorSubcategory = "Company";\
};\
class FACTION_MACRO(plt): FACTION_MACRO(coy) {\
    displayName = "Platoon Leader";\
    editorSubcategory = "Platoon";\
};\
class FACTION_MACRO(sgt): FACTION_MACRO(coy) {\
    displayName = "Platoon Sergent";\
    editorSubcategory = "Platoon";\
};\
class FACTION_MACRO(sl): FACTION_MACRO(rifleman) {\
    displayName = "Squad Leader";\
    icon = "iconManLeader";\
    editorSubcategory = "Squad";\
};\
class FACTION_MACRO(sf_sl): FACTION_MACRO(sl) {\
    displayName = "Special Forces Squad Leader";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(mmgl): FACTION_MACRO(sl) {\
    displayName = "MMG Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hmgl): FACTION_MACRO(sl) {\
    displayName = "HMG Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(matl): FACTION_MACRO(sl) {\
    displayName = "MAT Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(hatl): FACTION_MACRO(sl) {\
    displayName = "HAT Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(msaml): FACTION_MACRO(sl) {\
    displayName = "MSAM Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(mtrl): FACTION_MACRO(sl) {\
    displayName = "Mortar Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(stl): FACTION_MACRO(sl) {\
    displayName = "Scout Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(ftl): FACTION_MACRO(sl) {\
    displayName = "Fire Team Leader";\
    editorSubcategory = "Fireteam";\
};\
class FACTION_MACRO(sf_ftl): FACTION_MACRO(sl) {\
    displayName = "Special Forces Fire Team Leader";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(vicl): FACTION_MACRO(sl) {\
    displayName = "Vehicle Leader";\
    engineer = 1;\
    role = "Crewman";\
    editorSubcategory = "VicCrew";\
};\
class FACTION_MACRO(demol): FACTION_MACRO(sl) {\
    displayName = "Demolitions Leader";\
    engineer = 1;\
    role = "Engineer";\
    editorSubcategory = "Demo";\
};\
class FACTION_MACRO(engl): FACTION_MACRO(sl) {\
    displayName = "Engineer Leader";\
    engineer = 1;\
    role = "Engineer";\
    editorSubcategory = "Engi";\
};\
class FACTION_MACRO(cm): FACTION_MACRO(rifleman) {\
    attendant = 1;\
    displayName = "Company Medic";\
    icon = "iconManMedic";\
    role = "CombatLifeSaver";\
    editorSubcategory = "Company";\
};\
class FACTION_MACRO(plm): FACTION_MACRO(cm) {\
    displayName = "Platoon Medic";\
    editorSubcategory = "Platoon";\
};\
class FACTION_MACRO(sm): FACTION_MACRO(cm) {\
    displayName = "Squad Medic";\
    editorSubcategory = "Squad";\
};\
class FACTION_MACRO(sf_sm): FACTION_MACRO(cm) {\
    displayName = "Special Forces Medic";\
    editorSubcategory = "SF";\
};\
class FACTION_MACRO(eng): FACTION_MACRO(engl) {\
    displayName = "Engineer";\
    icon = "iconManEngineer";\
};\
class FACTION_MACRO(demo): FACTION_MACRO(demol) {\
    displayName = "Demolition Technician";\
    icon = "iconManExplosive";\
};\
class FACTION_MACRO(mine): FACTION_MACRO(demo) {\
    displayName = "Mine Technician";\
    icon = "iconManExplosive";\
};\
class FACTION_MACRO(vicc): FACTION_MACRO(vicl) {\
    displayName = "Vehicle Crew";\
    icon = "iconMan";\
};\
class FACTION_MACRO(vicd): FACTION_MACRO(vicl) {\
    displayName = "Vehicle Driver";\
    icon = "iconManEngineer";\
    role = "Engineer";\
};\
class FACTION_MACRO(pilot): FACTION_MACRO(rifleman) {\
    ACE_GForceCoef = 0.55;\
    displayName = "Pilot";\
    engineer = 1;\
    role = "Crewman";\
    editorSubcategory = "Aircrew";\
};\
class FACTION_MACRO(cc): FACTION_MACRO(pilot) {\
    displayName = "Crew Chief";\
    icon = "iconManEngineer";\
    role = "Engineer";\
};\
class FACTION_MACRO(helicrew): FACTION_MACRO(cc) {\
    displayName = "Air Crew";\
};\
class FACTION_MACRO(artl): FACTION_MACRO(vicl) {\
    displayName = "Artillery Leader";\
    editorSubcategory = "Weapons";\
};\
class FACTION_MACRO(artg): FACTION_MACRO(artl) {\
    displayName = "Artillery Gunner";\
};\
