class CfgRespawnFactions {
    class blu_f {
        displayName = "NATO";
        callsignPrefix = "BluFor";
        factionClassname = "blu_f";
        factionPrefix = "b_";
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

    class opf_f: blu_f {
        displayName = "CSAT";
        callsignPrefix = "OpFor";
        factionClassname = "opf_f";
        factionPrefix = "o_";
    };

    class ind_f: blu_f {
        displayName = "Independent";
        callsignPrefix = "Indy";
        factionClassname = "ind_f";
        factionPrefix = "i_";
    };

    class msv {
        displayName = "MSV";
        callsignPrefix = "MSV";
        factionClassname = "potato_msv";
        factionPrefix = "potato_msv_";
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
