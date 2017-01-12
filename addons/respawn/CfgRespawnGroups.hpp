class CfgRespawnGroups {
    // group configuration stubs
    class Alpha {
        markerText = "";
        markerColor[] = {0.9,0,0,1};
        markerTexture = "\A3\ui_f\data\map\markers\nato\b_inf.paa";
        markerSize = 24;

        srChannel = 0;
        mrChannel = 0;
        lrChannel = 0;
    };
    class Bravo: Alpha {
        markerColor[] = {0,0,1,1};

        srChannel = 1;
    };
    class Charlie: Alpha {
        markerColor[] = {0,0.8,0,1};

        srChannel = 2;
    };
    class Delta: Alpha {
        srChannel = 4;
        mrChannel = 1;
        lrChannel = 1;
    };
    class Echo: Delta {
        markerColor[] = {0,0,1,1};

        srChannel = 5;
    };
    class Foxtrot: Delta {
        markerColor[] = {0,0.8,0,1};

        srChannel = 6;
    };
    class Golf: Alpha {
        srChannel = 8;
        mrChannel = 2;
        lrChannel = 2;
    };
    class Hotel: Golf {
        markerColor[] = {0,0,1,1};

        srChannel = 9;
    };
    class India: Golf {
        markerColor[] = {0,0.8,0,1};

        srChannel = 10;
    };
    class Weapons: Alpha {
        markerColor[] = {1,0.647,0,1};

        srChannel = 15;
        mrChannel = 6;
        lrChannel = 3;
    };
    class Armor: Alpha {
        markerTexture = "\A3\ui_f\data\map\markers\nato\b_armor.paa";
        markerSize = 32;

        srChannel = 14;
        mrChannel = 5;
        lrChannel = 3;
    };
    class Air: Tank {
        markerTexture = "\A3\ui_f\data\map\markers\nato\b_air.paa";

        srChannel = 13;
        mrChannel = 4;
        lrChannel = 3;
    };

    // base unit all units inherit from
    class BaseUnit {
        displayName = "Rifleman";
        type = "soldier_f";
        rank = "private";
        colorTeam = 0;
        leader = 0;
        medic = 0;
    };

    // group configs
    class Command { // if you need to respawn COY, you've fucked up
        displayName = "Command";

        class Units {
            class CO: BaseUnit {
                displayName = "Company Commander";
                type = "officer_f";
                rank = "captain";
                leader = 1;
            };
            class COMedic: BaseUnit {
                displayName = "Company Medic";
                type = "medic_f";
                rank = "corporal";
                medic = 1;
            };
            class CXO: BaseUnit {
                displayName = "Company Executive Officer";
                type = "officer_f";
                rank = "lieutenant";
            };
            class UAV: BaseUnit {
                displayName = "Company UAV Operator";
                type = "soldier_uav_f";
            };
        };

        class Configurations {
            class COY {
                markerText = "COY";
                markerColor[] = {0.9,0.9,0,1};
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
                markerSize = 24;

                srChannel = 12;
                mrChannel = 3;
                lrChannel = 3;
            };
        };
    };

    class PlatoonLead {
        displayName = "Platoon Lead";

        class Units {
            class PlatoonLeader: BaseUnit {
                displayName = "Platoon Leader";
                type = "officer_f";
                rank = "lieutenant";
                leader = 1;
            };
            class PlatoonMedic: BaseUnit {
                displayName = "Platoon Medic";
                type = "medic_f";
                rank = "corporal";
                medic = 1;
            };
            class PlatoonSgt: BaseUnit {
                displayName = "Platoon Sgt";
                type = "officer_f";
                rank = "sergeant";
            };
        };

        class Configurations {
            class OnePlt {
                markerText = "1PLT";
                markerColor[] = {0.9,0.9,0,1};
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
                markerSize = 24;

                srChannel = 3;
                mrChannel = 0;
                lrChannel = 3;
            };
            class TwoPlt: OnePlt {
                markerText = "2PLT";

                srChannel = 7;
                mrChannel = 1;
            };
            class ThreePlt: OnePlt {
                markerText = "3PLT";

                srChannel = 11;
                mrChannel = 2;
            };
        };
    };

    class SquadLead {
        displayName = "Squad Lead";

        class Units {
            class SquadLeader: BaseUnit {
                displayName = "Squad Leader";
                type = "soldier_sl_f";
                rank = "sergeant";
                leader = 1;
            };
            class SquadMedic: BaseUnit {
                displayName = "Squad Medic";
                type = "medic_f";
                rank = "corporal";
                medic = 1;
            };
        };

        class Configurations {
            class ASL: Alpha {
                markerText = "ASL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class BSL: Bravo {
                markerText = "BSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class CSL: Charlie {
                markerText = "CSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class DSL: Delta {
                markerText = "DSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class ESL: Echo {
                markerText = "ESL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class FSL: Foxtrot {
                markerText = "FSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class GSL: Golf {
                markerText = "GSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class HSL: Hotel {
                markerText = "HSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class ISL: India {
                markerText = "ISL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
            class WSL: Weapons {
                markerText = "WSL";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_hq.paa";
            };
        };
    };

    class FireTeamFull {
        displayName = "Fireteam (Full)";

        class Units {
            class FireteamLeader: BaseUnit {
                displayName = "Fireteam Leader";
                type = "soldier_tl_f";
                rank = "corporal";
                leader = 1;
            };
            class AutomaticRifleman: BaseUnit {
                displayName = "Automatic Rifleman";
                type = "soldier_ar_f";
                colorTeam = 1;
            };
            class AssistantAutomaticRifleman: BaseUnit {
                displayName = "Assistant Automatic Rifleman";
                type = "soldier_aar_f";
                colorTeam = 1;
            };
            class RiflemanAntiTank: BaseUnit {
                displayName = "Rifleman Anti-Tank";
                type = "soldier_lat_f";
                colorTeam = 2;
            };
            class Rifleman1: BaseUnit {
                displayName = "Rifleman 1";
                colorTeam = 2;
            };
            class Rifleman2: BaseUnit {
                displayName = "Rifleman 2";
            };
        };

        class Configurations {
            class A1: Alpha {
                markerText = "A1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class A2: Alpha {
                markerText = "A2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class A3: A1 {
                markerText = "A3";
            };
            class A4: A2 {
                markerText = "A4";
            };
            class B1: Bravo {
                markerText = "B1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class B2: Bravo {
                markerText = "B1";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class B3: B1 {
                markerText = "B3";
            };
            class B4: B2 {
                markerText = "B4";
            };
            class C1: Charlie {
                markerText = "C1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class C2: Charlie {
                markerText = "C2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class C3: C1 {
                markerText = "C3";
            };
            class C4: C2 {
                markerText = "C4";
            };
            class D1: Delta {
                markerText = "D1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class D2: Delta {
                markerText = "D2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class D3: D1 {
                markerText = "D3";
            };
            class D4: D2 {
                markerText = "D4";
            };
            class E1: Echo {
                markerText = "E1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class E2: Echo {
                markerText = "E2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class E3: E1 {
                markerText = "E3";
            };
            class E4: E2 {
                markerText = "E4";
            };
            class F1: Foxtrot {
                markerText = "F1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class F2: Foxtrot {
                markerText = "F2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class F3: F1 {
                markerText = "F3";
            };
            class F4: F2 {
                markerText = "F4";
            };
            class G1: Golf {
                markerText = "G1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class G2: Golf {
                markerText = "G2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class G3: G1 {
                markerText = "G3";
            };
            class G4: G2 {
                markerText = "G4";
            };
            class H1: Hotel {
                markerText = "H1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class H2: Hotel {
                markerText = "H2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class H3: H1 {
                markerText = "H3";
            };
            class H4: H2 {
                markerText = "H4";
            };
            class I1: India {
                markerText = "I1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class I2: India {
                markerText = "I2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class I3: I1 {
                markerText = "I3";
            };
            class I4: I2 {
                markerText = "I4";
            };
        };
    };

    class FireTeamReduced {
        displayName = "Fireteam (Reduced)";

        class Units {
            class FireteamLeader: BaseUnit {
                displayName = "Fireteam Leader";
                type = "soldier_tl_f";
                rank = "corporal";
                leader = 1;
            };
            class AutomaticRifleman: BaseUnit {
                displayName = "Automatic Rifleman";
                type = "soldier_ar_f";
                colorTeam = 1;
            };
            class AssistantAutomaticRifleman: BaseUnit {
                displayName = "Assistant Automatic Rifleman";
                type = "soldier_aar_f";
                colorTeam = 1;
            };
            class RiflemanAntiTank: BaseUnit {
                displayName = "Rifleman Anti-Tank";
                type = "soldier_lat_f";
            };
        };

        class Configurations {
            class A1: Alpha {
                markerText = "A1";
                colorTeam1 = "RED";
            };
            class A2: Alpha {
                markerText = "A2";
                colorTeam1 = "GREEN";
            };
            class A3: Alpha {
                markerText = "A3";
                colorTeam1 = "BLUE";
            };
            class A4: Alpha {
                markerText = "A4";
                colorTeam1 = "YELLOW";
            };
            class B1: Bravo {
                markerText = "B1";
                colorTeam1 = "RED";
            };
            class B2: Bravo {
                markerText = "B1";
                colorTeam1 = "GREEN";
            };
            class B3: Bravo {
                markerText = "B3";
                colorTeam1 = "BLUE";
            };
            class B4: Bravo {
                markerText = "B4";
                colorTeam1 = "YELLOW";
            };
            class C1: Charlie {
                markerText = "C1";
                colorTeam1 = "RED";
            };
            class C2: Charlie {
                markerText = "C2";
                colorTeam1 = "GREEN";
            };
            class C3: Charlie {
                markerText = "C3";
                colorTeam1 = "BLUE";
            };
            class C4: Charlie {
                markerText = "C4";
                colorTeam1 = "YELLOW";
            };
            class D1: Delta {
                markerText = "D1";
                colorTeam1 = "RED";
            };
            class D2: Delta {
                markerText = "D2";
                colorTeam1 = "GREEN";
            };
            class D3: Delta {
                markerText = "D3";
                colorTeam1 = "BLUE";
            };
            class D4: Delta {
                markerText = "D4";
                colorTeam1 = "YELLOW";
            };
            class E1: Echo {
                markerText = "E1";
                colorTeam1 = "RED";
            };
            class E2: Echo {
                markerText = "E2";
                colorTeam1 = "GREEN";
            };
            class E3: Echo {
                markerText = "E3";
                colorTeam1 = "BLUE";
            };
            class E4: Echo {
                markerText = "E4";
                colorTeam1 = "YELLOW";
            };
            class F1: Foxtrot {
                markerText = "F1";
                colorTeam1 = "RED";
            };
            class F2: Foxtrot {
                markerText = "F2";
                colorTeam1 = "GREEN";
            };
            class F3: Foxtrot {
                markerText = "F3";
                colorTeam1 = "BLUE";
            };
            class F4: Foxtrot {
                markerText = "F4";
                colorTeam1 = "YELLOW";
            };
            class G1: Golf {
                markerText = "G1";
                colorTeam1 = "RED";
            };
            class G2: Golf {
                markerText = "G2";
                colorTeam1 = "GREEN";
            };
            class G3: Golf {
                markerText = "G3";
                colorTeam1 = "BLUE";
            };
            class G4: Golf {
                markerText = "G4";
                colorTeam1 = "YELLOW";
            };
            class H1: Hotel {
                markerText = "H1";
                colorTeam1 = "RED";
            };
            class H2: Hotel {
                markerText = "H2";
                colorTeam1 = "GREEN";
            };
            class H3: Hotel {
                markerText = "H3";
                colorTeam1 = "BLUE";
            };
            class H4: Hotel {
                markerText = "H4";
                colorTeam1 = "YELLOW";
            };
            class I1: India {
                markerText = "I1";
                colorTeam1 = "RED";
            };
            class I2: India {
                markerText = "I2";
                colorTeam1 = "GREEN";
            };
            class I3: India {
                markerText = "I3";
                colorTeam1 = "BLUE";
            };
            class I4: India {
                markerText = "I4";
                colorTeam1 = "YELLOW";
            };
        };
    };

    class MMG {
        displayName = "MMG Team";

        class Units {
            class MMGLeader: BaseUnit {
                displayName = "MMG Leader";
                type = "soldier_sl_f";
                rank = "corporal";
                leader = 1;
            };
            class MMGG: BaseUnit {
                displayName = "MMG Gunner";
                type = "support_mg_f";
            };
            class MMGAG: BaseUnit {
                displayName = "MMG Assistant";
                type = "soldier_a_f";
            };
        };

        class Configurations {
            class MMG1: Weapons {
                markerText = "MMG1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_support.paa";
            };
            class MMG2: MMG1 {
                markerText = "MMG2";
            };
            class MMG3: MMG1 {
                markerText = "MMG3";
            };
            class MMG4: MMG1 {
                markerText = "MMG4";
            };
        };
    };

    class MAT {
        displayName = "MAT Team";

        class Units {
            class MATLeader: BaseUnit {
                displayName = "MAT Leader";
                type = "soldier_sl_f";
                rank = "corporal";
                leader = 1;
            };
            class MATG: BaseUnit {
                displayName = "MAT Gunner";
                type = "soldier_at_f";
            };
            class MATAG: BaseUnit {
                displayName = "MAT Assistant";
                type = "soldier_aat_f";
            };
        };

        class Configurations {
            class MAT1: Weapons {
                markerText = "MAT1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_motor_inf.paa";
            };
            class MAT2: MAT1 {
                markerText = "MAT2";
            };
            class MAT3: MAT1 {
                markerText = "MAT3";
            };
            class MAT4: MAT1 {
                markerText = "MAT4";
            };
        };
    };

    class Mortar {
        displayName = "Mortar Team";

        class Units {
            class MTRLeader: BaseUnit {
                displayName = "Mortar Leader";
                type = "soldier_sl_f";
                rank = "corporal";
                leader = 1;
            };
            class MTRG: BaseUnit {
                displayName = "Mortar Gunner";
                type = "support_mort_f";
            };
            class MTRAG: BaseUnit {
                displayName = "Mortar Assistant";
                type = "support_amort_f";
            };
        };

        class Configurations {
            class MTR1: Weapons {
                markerText = "MTR1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_mortar.paa";
            };
            class MTR2: MTR1 {
                markerText = "MTR2";
            };
            class MTR3: MTR1 {
                markerText = "MTR3";
            };
            class MTR4: MTR1 {
                markerText = "MTR4";
            };
        };
    };

    class MSAM {
        displayName = "MSAM Team";

        class Units {
            class MSAMLeader: BaseUnit {
                displayName = "MSAM Leader";
                type = "soldier_sl_f";
                rank = "corporal";
                leader = 1;
            };
            class MSAMG: BaseUnit {
                displayName = "MSAM Gunner";
                type = "soldier_aa_f";
            };
            class MSAMAG: BaseUnit {
                displayName = "MSAM Assistant";
                type = "soldier_aaa_f";
            };
        };

        class Configurations {
            class MSAM1: Weapons {
                markerText = "MSAM1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_motor_inf.paa";
            };
            class MSAM2: MSAM1 {
                markerText = "MSAM2";
            };
            class MSAM3: MSAM1 {
                markerText = "MSAM3";
            };
            class MSAM4: MSAM1 {
                markerText = "MSAM4";
            };
        };
    };

    class ST {
        displayName = "Sniper Team";

        class Units {
            class Spotter: BaseUnit {
                displayName = "Spotter";
                type = "spotter_F";
                rank = "corporal";
                leader = 1;
            };
            class Sniper: BaseUnit {
                displayName = "Sniper";
                type = "sniper_F";
            };
        };

        class Configurations {
            class ST1: Weapons {
                markerText = "ST1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_recon.paa";
            };
            class ST2: ST1 {
                markerText = "ST2";
            };
            class ST3: ST1 {
                markerText = "ST3";
            };
            class ST4: ST1 {
                markerText = "ST4";
            };
        };
    };

    class ENG {
        displayName = "Engineer Team";

        class Units {
            class ExpLead: BaseUnit {
                displayName = "Engineer Lead (Exp)";
                type = "soldier_exp_f";
                rank = "corporal";
                leader = 1;
            };
            class Exp: BaseUnit {
                displayName = "Engineer (Exp)";
                type = "soldier_exp_f";
            };
            class Mine1: BaseUnit {
                displayName = "Engineer (Mine)";
                type = "engineer_f";
            };
            class Mine2: BaseUnit {
                displayName = "Engineer (Mine)";
                type = "engineer_f";
            };
        };

        class Configurations {
            class ENG1: Weapons {
                markerText = "ENG1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_maint.paa";
            };
            class ENG2: ENG1 {
                markerText = "ENG2";
            };
            class ENG3: ENG1 {
                markerText = "ENG3";
            };
            class ENG4: ENG1 {
                markerText = "ENG4";
            };
        };
    };

    class ArmorGroup {
        displayName = "Armor";

        class Units {
            class ArmorLead: BaseUnit {
                displayName = "Vehicle Commander";
                type = "crew_f";
                rank = "sergeant";
                leader = 1;
            };
            class ArmorGunner: BaseUnit {
                displayName = "Vehicle Gunner";
                type = "crew_f";
                rank = "corporal";
            };
            class ArmorDriver: BaseUnit {
                displayName = "Vehicle Driver";
                type = "soldier_repair_f";
            };
        };

        class Configurations {
            class Tank1: Armor {
                markerText = "Tank1";
            };
            class Tank2: Armor {
                markerText = "Tank2";
                markerColor[] = {0,0,1,1};
            };
            class Tank3: Tank1 {
                markerText = "Tank3";
            };
            class Tank4: Tank2 {
                markerText = "Tank4";
            };
            class Tank5: Tank1 {
                markerText = "Tank5";
            };
            class Tank6: Tank2 {
                markerText = "Tank6";
            };
            class Tank7: Tank1 {
                markerText = "Tank7";
            };
            class Tank8: Tank2 {
                markerText = "Tank8";
            };
            class IFV1: Tank1 {
                markerText = "IFV1";
                markerTexture = "\A3\ui_f\data\map\markers\nato\b_mech_inf.paa";
            };
            class IFV2: IFV1 {
                markerText = "IFV2";
                markerColor[] = {0,0,1,1};
            };
            class IFV3: IFV1 {
                markerText = "IFV3";
            };
            class IFV4: IFV2 {
                markerText = "IFV4";
            };
            class IFV5: IFV1 {
                markerText = "IFV5";
            };
            class IFV6: IFV2 {
                markerText = "IFV6";
            };
            class IFV7: IFV1 {
                markerText = "IFV7";
            };
            class IFV8: IFV2 {
                markerText = "IFV8";
            };
        };
    };

    class AirGroup {
        displayName = "Air";

        class Units {
            class Pilot: BaseUnit {
                displayName = "Pilot";
                type = "helipilot_f";
                rank = "captain";
                leader = 1;
            };
            class CoPilot: BaseUnit {
                displayName = "Co-Pilot";
                type = "helipilot_f";
                rank = "lieutenant";
            };
            class CrewChief: BaseUnit {
                displayName = "Crew Chief";
                type = "soldier_repair_f";
                rank = "sergeant";
            };
            class Gunner: BaseUnit {
                displayName = "Gunner";
                type = "helicrew_f";
                rank = "corporal";
            };
        };

        class Configurations {
            class AH1: Air {
                markerText = "AH1";
            };
            class AH2: Air {
                markerText = "AH2";
                markerColor[] = {0,0,1,1};
            };
            class AH3: AH1 {
                markerText = "AH3";
            };
            class AH4: AH2 {
                markerText = "AH4";
            };
            class TH1: AH1 {
                markerText = "TH1";
            };
            class TH2: AH2 {
                markerText = "TH2";
            };
            class TH3: TH1 {
                markerText = "TH3";
            };
            class TH4: TH2 {
                markerText = "TH4";
            };
            class TH5: TH1 {
                markerText = "TH5";
            };
            class TH6: TH2 {
                markerText = "TH6";
            };
            class TH7: TH1 {
                markerText = "TH7";
            };
            class TH8: TH2 {
                markerText = "TH8";
            };
        };
    };
};
