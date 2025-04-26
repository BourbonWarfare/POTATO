#define UNIT_DEF(SIDE,TYPE) QUOTE(TRIPLES(DOUBLES(PREFIX,nolambs),SIDE,TYPE))
#define GROUP_MODULES(SIDE,SIDE_CHAR) class GVAR(TRIPLES(SIDE,manpadTeam,noLambs)): EGVAR(zeusHC,base_prebuilt) {\
    scope = 2;\
    scopeCurator = 2;\
    category = QEGVAR(zeusHC,DOUBLES(SIDE,noLambs));\
    displayName = "#MANPAD Team (2)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,crewAir) = UNIT_DEF(SIDE_CHAR,pilot);\
    EGVAR(zeusHC,crewArmor)= UNIT_DEF(SIDE_CHAR,vicc);\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,msamg),UNIT_DEF(SIDE_CHAR,msamag)};\
};\
class GVAR(TRIPLES(SIDE,matTeam,noLambs)): GVAR(TRIPLES(SIDE,manpadTeam,noLambs)) {\
    displayName = "#MAT Team (2)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,matg),UNIT_DEF(SIDE_CHAR,matag)};\
};\
class GVAR(TRIPLES(SIDE,mmgTeam,noLambs)): GVAR(TRIPLES(SIDE,manpadTeam,noLambs)) {\
    displayName = "#MMG Team (2)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,mmgg),UNIT_DEF(SIDE_CHAR,mmgag)};\
};\
class GVAR(TRIPLES(SIDE,patrol,noLambs)): GVAR(TRIPLES(SIDE,manpadTeam,noLambs)) {\
    displayName = "#Patrol (2)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,rifleman),UNIT_DEF(SIDE_CHAR,rifleman_02)};\
};\
class GVAR(TRIPLES(SIDE,fireteam,noLambs)): GVAR(TRIPLES(SIDE,manpadTeam,noLambs)) {\
    displayName = "#Fireteam (4)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,ftl),UNIT_DEF(SIDE_CHAR,ar),UNIT_DEF(SIDE_CHAR,rifleman),UNIT_DEF(SIDE_CHAR,lat)};\
};\
class GVAR(TRIPLES(SIDE,squad,noLambs)): GVAR(TRIPLES(SIDE,manpadTeam,noLambs)) {\
    displayName = "#Squad (8)";\
    icon = "\a3\Ui_F_Curator\Data\Displays\RscDisplayCurator\modeGroups_ca.paa";\
    EGVAR(zeusHC,createUnits)[] = {UNIT_DEF(SIDE_CHAR,sl),UNIT_DEF(SIDE_CHAR,ftl),UNIT_DEF(SIDE_CHAR,ar),UNIT_DEF(SIDE_CHAR,ar),UNIT_DEF(SIDE_CHAR,lat),UNIT_DEF(SIDE_CHAR,rifleman),UNIT_DEF(SIDE_CHAR,rifleman_02),UNIT_DEF(SIDE_CHAR,rifleman_03)};\
}
class CfgVehicles {
    class EGVAR(zeusHC,base_prebuilt);
    GROUP_MODULES(east,e);
    GROUP_MODULES(west,w);
    GROUP_MODULES(ind,i);
};
