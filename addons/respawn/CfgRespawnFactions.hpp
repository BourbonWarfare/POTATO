class CfgRespawnFactions {
    class potato_w {
        displayName = "NATO";
        callsignPrefix = "BluFor";
        factionClassname = "potato_w";
        factionPrefix = "potato_w_";
        groups[] = {
            "Command",
            "PlatoonLead",
            "SquadLead",
            "FireTeamFull",
            "FireTeamReduced",
            "MMG",
            "MAT",
            "Mortar",
            "MSAM",
            "ST",
            "ENG",
            "ArmorGroup",
            "THGroup",
            "AHGroup"
        };
    };

    class potato_e: blu_f {
        displayName = "CSAT";
        callsignPrefix = "OpFor";
        factionClassname = "potato_e";
        factionPrefix = "potato_e_";
    };

    class potato_i: blu_f {
        displayName = "Independent";
        callsignPrefix = "Indy";
        factionClassname = "potato_i";
        factionPrefix = "potato_i_";
    };

    class msv {
        displayName = "MSV";
        callsignPrefix = "MSV";
        factionClassname = "potato_e";
        factionPrefix = "potato_e_";
        groups[] = {
            "MSVCommand",
            "MSVPlatoonLead",
            "MSVSquad",
            "MSVSquadMarksman",
            "MSVMMG",
            "MSVMAT",
            "MSVMSAM",
            "MSVEng",
            "MSVSF",
            "MSVArmor",
            "MSVTH",
            "MSVAH"
        };
    };

    class civ_f {
        displayName = "Civilian";
        callsignPrefix = "Civ";
        factionClassname = "civ_f";
        factionPrefix = "";
        groups[] = {
            "MiscCivilians",
            "PressTeam"
        };
    };
};
