#define GROUP_DEF(SIDE_DEF,FAC_DEF_PRETTY,FACTION_LETTER,SIDE_NUM)\
class SIDE_DEF {\
    class TRIPLES(PREFIX,FACTION_LETTER,NOLAMBS) {\
        name = FAC_DEF_PRETTY;\
        class Infantry {\
            name = "Infantry";\
            class CLASS_MACRO(fireteam_full) {\
                name = "Fireteam (Full)";\
                side = SIDE_NUM;\
                faction = QUOTE(TRIPLES(PREFIX,FACTION_LETTER,NOLAMBS));\
                icon = "\z\potato\addons\markers\data\infantry.paa";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ftl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ar));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(aar));\
                };\
                class Unit3 {\
                    position[] = {10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(lat));\
                };\
                class Unit4 {\
                    position[] = {-10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman));\
                };\
                class Unit5 {\
                    position[] = {15,-15,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman_02));\
                };\
            };\
            class CLASS_MACRO(fireteam_red) : CLASS_MACRO(fireteam_full) {\
                name = "Fireteam (Reduced)";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ftl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ar));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(aar));\
                };\
                class Unit3 {\
                    position[] = {10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(lat));\
                };\
            };\
            class CLASS_MACRO(sqd_ele) : CLASS_MACRO(fireteam_full) {\
                name = "Squad Element";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGENT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(sl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(sm));\
                };\
            };\
            class CLASS_MACRO(sqd) : CLASS_MACRO(fireteam_full) {\
                name = "Squad";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGENT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(sl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(sm));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ftl));\
                };\
                class Unit3 {\
                    position[] = {10,-10,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ar));\
                };\
                class Unit4 {\
                    position[] = {-10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(aar));\
                };\
                class Unit5 {\
                    position[] = {15,-15,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(lat));\
                };\
                class Unit6 {\
                    position[] = {-15,-15,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman));\
                };\
                class Unit7 {\
                    position[] = {20,-20,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman_02));\
                };\
                class Unit8 {\
                    position[] = {-20,-20,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ftl));\
                };\
                class Unit9 {\
                    position[] = {25,-25,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ar));\
                };\
                class Unit10 {\
                    position[] = {-25,-25,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(aar));\
                };\
                class Unit11 {\
                    position[] = {30,-30,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(lat));\
                };\
                class Unit12 {\
                    position[] = {-30,-30,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman));\
                };\
                class Unit13 {\
                    position[] = {35,-35,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman_02));\
                };\
            };\
            class CLASS_MACRO(rifleteam) : CLASS_MACRO(fireteam_full) {\
                name = "Fireteam (Rifleteam)";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(ftl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman));\
                };\
                class Unit3 {\
                    position[] = {10,-10,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(lat));\
                };\
                class Unit4 {\
                    position[] = {-10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman_02));\
                };\
                class Unit5 {\
                    position[] = {15,-15,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(rifleman_02));\
                };\
            };\
        };\
        class Crew {\
            name = "Crew";\
            class CLASS_MACRO(armor_crew) {\
                name = "Armored Crew";\
                icon = "\z\potato\addons\markers\data\armor.paa";\
                side = SIDE_NUM;\
                faction = QUOTE(TRIPLES(PREFIX,FACTION_LETTER,NOLAMBS));\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(vicl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(vicc));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(vicd));\
                };\
            };\
            class CLASS_MACRO(air_crew):CLASS_MACRO(armor_crew) {\
                name = "Air Crew";\
                icon = "\z\potato\addons\markers\data\helicopter.paa";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "CAPTAIN";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(pilot));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "LIEUTENANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(pilot));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(cc));\
                };\
                class Unit3 {\
                    position[] = {10,-10,0};\
                    rank = "PRIVATE";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(helicrew));\
                };\
            };\
        };\
        class Weapons {\
            name = "Weapons";\
            class CLASS_MACRO(mmg) {\
                name = "MMG";\
                icon = "\z\potato\addons\markers\data\mmg.paa";\
                side = SIDE_NUM;\
                faction = QUOTE(TRIPLES(PREFIX,FACTION_LETTER,NOLAMBS));\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(mmgl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(mmgg));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(mmgag));\
                };\
            };\
            class CLASS_MACRO(mat):CLASS_MACRO(mmg) {\
                name = "MAT";\
                icon = "\z\potato\addons\markers\data\mat.paa";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(matl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(matg));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(matag));\
                };\
            };\
            class CLASS_MACRO(hmg):CLASS_MACRO(mmg) {\
                name = "HMG";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hmgl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hmgg));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hmgag));\
                };\
            };\
            class CLASS_MACRO(hat):CLASS_MACRO(mat) {\
                name = "HAT";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hatl));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hatg));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(hatag));\
                };\
            };\
            class CLASS_MACRO(msam):CLASS_MACRO(mat) {\
                name = "MSAM";\
                icon = "\z\potato\addons\markers\data\msam.paa";\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(msaml));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(msamg));\
                };\
                class Unit2 {\
                    position[] = {-5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(msamag));\
                };\
            };\
            class CLASS_MACRO(st) {\
                name = "Sniper Team";\
                icon = "\z\potato\addons\markers\data\recon.paa";\
                side = SIDE_NUM;\
                faction = QUOTE(TRIPLES(PREFIX,FACTION_LETTER,NOLAMBS));\
                class Unit0 {\
                    position[] = {0,0,0};\
                    rank = "SERGEANT";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(sniper));\
                };\
                class Unit1 {\
                    position[] = {5,-5,0};\
                    rank = "CORPORAL";\
                    side = SIDE_NUM;\
                    vehicle = QUOTE(CLASS_MACRO(spotter));\
                };\
            };\
        };\
    };\
};\
