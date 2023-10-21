class CfgRespawnFactions {
    class potato_w {
        displayName = "BluFor";
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
            "HMG",
            "MAT",
            "HAT",
            "Mortar",
            "Artillery",
            "MSAM",
            "ST",
            "DEMO",
            "ENG",
            "ArmorGroup",
            "THGroup",
            "AHGroup"
        };
    };

    class potato_e: potato_w {
        displayName = "OpFor";
        callsignPrefix = "OpFor";
        factionClassname = "potato_e";
        factionPrefix = "potato_e_";
    };

    class potato_i: potato_w {
        displayName = "Independent";
        callsignPrefix = "Indy";
        factionClassname = "potato_i";
        factionPrefix = "potato_i_";
    };

    class msv {
        displayName = "OpFor: Mechanized";
        callsignPrefix = "MSV";
        factionClassname = "potato_e";
        factionPrefix = "potato_e_";
        groups[] = {
            "MSVCommand",
            "MSVPlatoonLead",
            "MSVSquad",
            "MSVMMG",
            "MSVHMG",
            "MSVMAT",
            "MSVHAT",
            "MSVArty",
            "MSVMSAM",
            "MSVDEMO",
            "MSVENG",
            //"MSVSF",
            "MSVArmor",
            "MSVTH",
            "MSVAH"
        };
    };
    class cwl {
        displayName = "BluFor: Commonwealth";
        callsignPrefix = "CWL";
        factionClassname = "potato_w";
        factionPrefix = "potato_w_";
        groups[] = {
            "CWLCommand",
            "CWLPlatoonLead",
            "CWLSection",
            "CWLMMG",
            "CWLHMG",
            "CWLMAT",
            "CWLHAT",
            "CWLArty",
            "CWLMSAM",
            "CWLDEMO",
            "CWLENG",
            "CWLArmor",
            "CWLTH",
            "CWLAH"
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
