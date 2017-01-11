class CfgRespawnFactions {
    class blu_f {
        displayName = "NATO";
        callsignPrefix = "BluFor"
        factionClassname = "blu_f";
        factionPrefix = "b_";
        groups[] = {
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
            "AirGroup"
        };
    };

    class opf_f: blu_f {
        displayName = "CAST";
        callsignPrefix = "OpFor"
        factionClassname = "opf_f";
        factionPrefix = "o_";
    };

    class ind_f: blu_f {
        displayName = "Independent";
        callsignPrefix = "Indy"
        factionClassname = "ind_f";
        factionPrefix = "i_";
    };

    // TODO: civs
};
