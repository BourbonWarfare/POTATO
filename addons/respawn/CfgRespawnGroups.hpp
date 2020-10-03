class CfgRespawnGroups {

    // load stubs
    #include "BaseGroupConfigs.hpp"

    // group configs
    class Command { // if you need to respawn COY, you've fucked up
        displayName = "Command";

        class Units {
            class CO: BaseUnit {
                displayName = "Company Commander";
                type = "coy";
                rank = "captain";
                leader = 1;
            };
            class COMedic: BaseMedic {
                displayName = "Company Medic";
                type = "cm";
            };
            class CXO: BaseUnit {
                displayName = "Company Executive Officer";
                type = "xo";
                rank = "lieutenant";
            };
            class UAV: BaseUnit {
                displayName = "Company UAV Operator";
                type = "uav";
            };
            class FAC: BaseUnit {
                displayName = "Company Forward Air Controller";
                type = "fac";
            };
        };

        class Configurations {
            class COY {
                displayName = "Company Command";

                markerPrefix = "CO";
                markerText = "Y";
                markerColor[] = {1,0.647,0,1};
                markerTexture = QPATHTOEF(markers,data\hq.paa);
                markerSize = 24;

                srChannel = 13;
                mrChannel = 4;
                lrChannel = 4;
            };
        };
    };

    class PlatoonLead {
        displayName = "Platoon Lead";

        class Units {
            class PlatoonLeader: BaseUnit {
                displayName = "Platoon Leader";
                type = "plt";
                rank = "lieutenant";
                leader = 1;
            };
            class PlatoonMedic: BaseMedic {
                displayName = "Platoon Medic";
                type = "plm";
            };
            class PlatoonSgt: BaseUnit {
                displayName = "Platoon Sgt";
                type = "sgt";
                rank = "sergeant";
            };
        };

        class Configurations {
            class OnePlt {
                displayName = "First Platoon Command";

                markerPrefix = "1P";
                markerText = "LT";
                markerColor[] = {1,0.647,0,1};
                markerTexture = QPATHTOEF(markers,data\hq.paa);
                markerSize = 24;

                srChannel = 4;
                mrChannel = 1;
                lrChannel = 4;
            };
            class TwoPlt: OnePlt {
                displayName = "Second Platoon Command";

                markerPrefix = "2P";

                srChannel = 8;
                mrChannel = 2;
            };
            class ThreePlt: OnePlt {
                displayName = "Third Platoon Command";

                markerPrefix = "3P";

                srChannel = 12;
                mrChannel = 3;
            };
        };
    };

    class SquadLead {
        displayName = "Squad Lead";

        class Units {
            class SquadLeader: BaseSquadLead {};
            class SquadMedic: BaseMedic {
                displayName = "Squad Medic";
                type = "sm";
            };
        };

        class Configurations {
            class ASL: Alpha {
                displayName = "Alpha";
                markerTexture = "";
            };
            class BSL: Bravo {
                displayName = "Bravo";
                markerTexture = "";
            };
            class CSL: Charlie {
                displayName = "Charlie";
                markerTexture = "";
            };
            class DSL: Delta {
                displayName = "Delta";
                markerTexture = "";
            };
            class ESL: Echo {
                displayName = "Echo";
                markerTexture = "";
            };
            class FSL: Foxtrot {
                displayName = "Foxtrot";
                markerTexture = "";
            };
            class GSL: Golf {
                displayName = "Golf";
                markerTexture = "";
            };
            class HSL: Hotel {
                displayName = "Hotel";
                markerTexture = "";
            };
            class ISL: India {
                displayName = "India";
                markerTexture = "";
            };
            class WSL: Weapons {
                markerPrefix = "W";
                displayName = "Weapons";
                markerTexture = "";
            };
        };
    };

    class FireTeamFull {
        displayName = "Fireteam (Full)";

        class Units {
            class FireteamLeader: BaseUnit {
                displayName = "Fireteam Leader";
                type = "ftl";
                rank = "corporal";
                leader = 1;
            };
            class AutomaticRifleman: BaseUnit {
                displayName = "Automatic Rifleman";
                type = "ar";
                colorTeam = 1;
            };
            class AssistantAutomaticRifleman: BaseUnit {
                displayName = "Assistant Automatic Rifleman";
                type = "aar";
                colorTeam = 1;
            };
            class RiflemanAntiTank: BaseUnit {
                displayName = "Rifleman Anti-Tank";
                type = "lat";
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
                displayName = "Alpha 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class A2: Alpha {
                displayName = "Alpha 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class A3: A1 {
                displayName = "Alpha 3";
                markerText = "3";
            };
            class A4: A2 {
                displayName = "Alpha 4";
                markerText = "4";
            };
            class B1: Bravo {
                displayName = "Bravo 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class B2: Bravo {
                displayName = "Bravo 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class B3: B1 {
                displayName = "Bravo 3";
                markerText = "3";
            };
            class B4: B2 {
                displayName = "Bravo 4";
                markerText = "4";
            };
            class C1: Charlie {
                displayName = "Charlie 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class C2: Charlie {
                displayName = "Charlie 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class C3: C1 {
                displayName = "Charlie 3";
                markerText = "3";
            };
            class C4: C2 {
                displayName = "Charlie 4";
                markerText = "4";
            };
            class D1: Delta {
                displayName = "Delta 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class D2: Delta {
                displayName = "Delta 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class D3: D1 {
                displayName = "Delta 3";
                markerText = "3";
            };
            class D4: D2 {
                displayName = "Delta 4";
                markerText = "4";
            };
            class E1: Echo {
                displayName = "Echo 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class E2: Echo {
                displayName = "Echo 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class E3: E1 {
                displayName = "Echo 3";
                markerText = "3";
            };
            class E4: E2 {
                displayName = "Echo 4";
                markerText = "4";
            };
            class F1: Foxtrot {
                displayName = "Foxtrot 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class F2: Foxtrot {
                displayName = "Foxtrot 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class F3: F1 {
                displayName = "Foxtrot 3";
                markerText = "3";
            };
            class F4: F2 {
                displayName = "Foxtrot 4";
                markerText = "4";
            };
            class G1: Golf {
                displayName = "Golf 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class G2: Golf {
                displayName = "Golf 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class G3: G1 {
                displayName = "Golf 3";
                markerText = "3";
            };
            class G4: G2 {
                displayName = "Golf 4";
                markerText = "4";
            };
            class H1: Hotel {
                displayName = "Hotel 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class H2: Hotel {
                displayName = "Hotel 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class H3: H1 {
                displayName = "Hotel 3";
                markerText = "3";
            };
            class H4: H2 {
                displayName = "Hotel 4";
                markerText = "4";
            };
            class I1: India {
                displayName = "India 1";
                markerText = "1";
                colorTeam1 = "RED";
                colorTeam2 = "GREEN";
            };
            class I2: India {
                displayName = "India 2";
                markerText = "2";
                colorTeam1 = "BLUE";
                colorTeam2 = "YELLOW";
            };
            class I3: I1 {
                displayName = "India 3";
                markerText = "3";
            };
            class I4: I2 {
                displayName = "India 4";
                markerText = "4";
            };
        };
    };

    class FireTeamReduced {
        displayName = "Fireteam (Reduced)";

        class Units {
            class FireteamLeader: BaseUnit {
                displayName = "Fireteam Leader";
                type = "ftl";
                rank = "corporal";
                leader = 1;
            };
            class AutomaticRifleman: BaseUnit {
                displayName = "Automatic Rifleman";
                type = "ar";
                colorTeam = 1;
            };
            class AssistantAutomaticRifleman: BaseUnit {
                displayName = "Assistant Automatic Rifleman";
                type = "aar";
                colorTeam = 1;
            };
            class RiflemanAntiTank: BaseUnit {
                displayName = "Rifleman Anti-Tank";
                type = "lat";
            };
        };

        class Configurations {
            class A1: Alpha {
                displayName = "Alpha 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class A2: Alpha {
                displayName = "Alpha 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class A3: Alpha {
                displayName = "Alpha 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class A4: Alpha {
                displayName = "Alpha 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class B1: Bravo {
                displayName = "Bravo 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class B2: Bravo {
                displayName = "Bravo 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class B3: Bravo {
                displayName = "Bravo 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class B4: Bravo {
                displayName = "Bravo 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class C1: Charlie {
                displayName = "Charlie 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class C2: Charlie {
                displayName = "Charlie 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class C3: Charlie {
                displayName = "Charlie 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class C4: Charlie {
                displayName = "Charlie 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class D1: Delta {
                displayName = "Delta 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class D2: Delta {
                displayName = "Delta 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class D3: Delta {
                displayName = "Delta 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class D4: Delta {
                displayName = "Delta 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class E1: Echo {
                displayName = "Echo 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class E2: Echo {
                displayName = "Echo 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class E3: Echo {
                displayName = "Echo 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class E4: Echo {
                displayName = "Echo 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class F1: Foxtrot {
                displayName = "Foxtrot 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class F2: Foxtrot {
                displayName = "Foxtrot 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class F3: Foxtrot {
                displayName = "Foxtrot 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class F4: Foxtrot {
                displayName = "Foxtrot 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class G1: Golf {
                displayName = "Golf 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class G2: Golf {
                displayName = "Golf 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class G3: Golf {
                displayName = "Golf 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class G4: Golf {
                displayName = "Golf 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class H1: Hotel {
                displayName = "Hotel 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class H2: Hotel {
                displayName = "Hotel 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class H3: Hotel {
                displayName = "Hotel 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class H4: Hotel {
                displayName = "Hotel 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
            class I1: India {
                displayName = "India 1";
                markerText = "1";
                colorTeam1 = "RED";
            };
            class I2: India {
                displayName = "India 2";
                markerText = "2";
                colorTeam1 = "GREEN";
            };
            class I3: India {
                displayName = "India 3";
                markerText = "3";
                colorTeam1 = "BLUE";
            };
            class I4: India {
                displayName = "India 4";
                markerText = "4";
                colorTeam1 = "YELLOW";
            };
        };
    };

    class MMG {
        displayName = "MMG Team";

        class Units {
            class MMGLeader: BaseUnit {
                displayName = "MMG Leader";
                type = "mmgl";
                rank = "corporal";
                leader = 1;
            };
            class MMGG: BaseUnit {
                displayName = "MMG Gunner";
                type = "mmgg";
            };
            class MMGAG: BaseUnit {
                displayName = "MMG Assistant";
                type = "mmgag";
            };
        };

        class Configurations {
            class MMG1: Weapons {
                displayName = "MMG 1";
                markerText = "MMG1";
                markerTexture = QPATHTOEF(markers,data\mmg.paa);
            };
            class MMG2: MMG1 {
                displayName = "MMG 2";
                markerText = "MMG2";
            };
            class MMG3: MMG1 {
                displayName = "MMG 3";
                markerText = "MMG3";
            };
            class MMG4: MMG1 {
                displayName = "MMG 4";
                markerText = "MMG4";
            };
        };
    };

    class HMG {
        displayName = "HMG Team";

        class Units {
            class HMGLeader: BaseUnit {
                displayName = "HMG Leader";
                type = "HMGl";
                rank = "corporal";
                leader = 1;
            };
            class HMGG: BaseUnit {
                displayName = "HMG Gunner";
                type = "HMGg";
            };
            class HMGAG: BaseUnit {
                displayName = "HMG Assistant";
                type = "HMGg";
            };
        };

        class Configurations {
            class HMG1: Weapons {
                displayName = "HMG 1";
                markerText = "HMG1";
                markerTexture = QPATHTOEF(markers,data\support.paa);
            };
            class HMG2: HMG1 {
                displayName = "HMG 2";
                markerText = "HMG2";
            };
            class HMG3: HMG1 {
                displayName = "HMG 3";
                markerText = "HMG3";
            };
            class HMG4: HMG1 {
                displayName = "HMG 4";
                markerText = "HMG4";
            };
        };
    };

    class MAT {
        displayName = "MAT Team";

        class Units {
            class MATLeader: BaseUnit {
                displayName = "MAT Leader";
                type = "matl";
                rank = "corporal";
                leader = 1;
            };
            class MATG: BaseUnit {
                displayName = "MAT Gunner";
                type = "matg";
            };
            class MATAG: BaseUnit {
                displayName = "MAT Assistant";
                type = "matag";
            };
        };

        class Configurations {
            class MAT1: Weapons {
                displayName = "MAT 1";
                markerText = "MAT1";
                markerTexture = QPATHTOEF(markers,data\mat.paa);
            };
            class MAT2: MAT1 {
                displayName = "MAT 2";
                markerText = "MAT2";
            };
            class MAT3: MAT1 {
                displayName = "MAT 3";
                markerText = "MAT3";
            };
            class MAT4: MAT1 {
                displayName = "MAT 4";
                markerText = "MAT4";
            };
        };
    };

    class HAT {
        displayName = "HAT Team";

        class Units {
            class HATLeader: BaseUnit {
                displayName = "HAT Leader";
                type = "HATl";
                rank = "corporal";
                leader = 1;
            };
            class HATG: BaseUnit {
                displayName = "HAT Gunner";
                type = "HATg";
            };
            class HATAG: BaseUnit {
                displayName = "HAT Assistant";
                type = "HATg";
            };
        };

        class Configurations {
            class HAT1: Weapons {
                displayName = "HAT 1";
                markerText = "HAT1";
                markerTexture = QPATHTOEF(markers,data\support.paa);
            };
            class HAT2: HAT1 {
                displayName = "HAT 2";
                markerText = "HAT2";
            };
            class HAT3: HAT1 {
                displayName = "HAT 3";
                markerText = "HAT3";
            };
            class HAT4: HAT1 {
                displayName = "HAT 4";
                markerText = "HAT4";
            };
        };
    };

    class Mortar {
        displayName = "Mortar Team";

        class Units {
            class MTRLeader: BaseUnit {
                displayName = "Mortar Leader";
                type = "mtrl";
                rank = "corporal";
                leader = 1;
            };
            class MTRG: BaseUnit {
                displayName = "Mortar Gunner";
                type = "mtrg";
            };
            class MTRAG: BaseUnit {
                displayName = "Mortar Assistant";
                type = "mtrag";
            };
        };

        class Configurations {
            class MTR1: Weapons {
                displayName = "Mortar 1";
                markerText = "MTR1";
                markerTexture = QPATHTOEF(markers,data\mortar.paa);
            };
            class MTR2: MTR1 {
                displayName = "Mortar 2";
                markerText = "MTR2";
            };
            class MTR3: MTR1 {
                displayName = "Mortar 3";
                markerText = "MTR3";
            };
            class MTR4: MTR1 {
                displayName = "Mortar 4";
                markerText = "MTR4";
            };
        };
    };

    class Artillery {
        displayName = "Artillery Team";

        class Units {
            class ArtLeader: BaseUnit {
                displayName = "Artillery Leader";
                type = "Artl";
                rank = "corporal";
                leader = 1;
            };
            class ArtG1: BaseUnit {
                displayName = "Artillery Gunner";
                type = "Artg";
            };
            class ArtG2: ArtG1 {
            };
            class ArtG3: ArtG1 {
            };
            class ArtG4: ArtG1 {
            };
        };

        class Configurations {
            class Art1: Weapons {
                displayName = "Artillery";
                markerText = "Artillery";
                markerTexture = QPATHTOEF(markers,data\mortar.paa);
            };
        };
    };

    class MSAM {
        displayName = "MSAM Team";

        class Units {
            class MSAMLeader: BaseUnit {
                displayName = "MSAM Leader";
                type = "msaml";
                rank = "corporal";
                leader = 1;
            };
            class MSAMG: BaseUnit {
                displayName = "MSAM Gunner";
                type = "msamg";
            };
            class MSAMAG: BaseUnit {
                displayName = "MSAM Assistant";
                type = "msamag";
            };
        };

        class Configurations {
            class MSAM1: Weapons {
                displayName = "MSAM 1";
                markerText = "MSAM1";
                markerTexture = QPATHTOEF(markers,data\msam.paa);
            };
            class MSAM2: MSAM1 {
                displayName = "MSAM 2";
                markerText = "MSAM2";
            };
            class MSAM3: MSAM1 {
                displayName = "MSAM 3";
                markerText = "MSAM3";
            };
            class MSAM4: MSAM1 {
                displayName = "MSAM 4";
                markerText = "MSAM4";
            };
        };
    };

    class ST {
        displayName = "Sniper Team";

        class Units {
            class Spotter: BaseUnit {
                displayName = "Spotter";
                type = "spotter";
                rank = "corporal";
                leader = 1;
            };
            class Sniper: BaseUnit {
                displayName = "Sniper";
                type = "sniper";
            };
        };

        class Configurations {
            class ST1: Weapons {
                displayName = "Scout Team 1";
                markerText = "ST1";
                markerTexture = QPATHTOEF(markers,data\recon.paa);
            };
            class ST2: ST1 {
                displayName = "Scout Team 2";
                markerText = "ST2";
            };
            class ST3: ST1 {
                displayName = "Scout Team 3";
                markerText = "ST3";
            };
            class ST4: ST1 {
                displayName = "Scout Team 4";
                markerText = "ST4";
            };
        };
    };

    class DEMO {
        displayName = "Demolitions Team";

        class Units {
            class ExpLead: BaseUnit {
                displayName = "Demolitions Team Lead";
                type = "demol";
                rank = "corporal";
                leader = 1;
            };
            class Exp: BaseUnit {
                displayName = "Demolitions Specialist";
                type = "demo";
            };
            class Exp2: Exp {
            };
            class Mine1: BaseUnit {
                displayName = "Mine Specialist";
                type = "mine";
            };
            class Mine2: Mine1 {
            };
        };

        class Configurations {
            class DEMO1: Weapons {
                displayName = "Demolitions Team 1";
                markerText = "DEMO1";
                markerTexture = QPATHTOEF(markers,data\engineer.paa);
            };
            class DEMO2: DEMO1 {
                displayName = "Demolitions Team 2";
                markerText = "DEMO2";
            };
            class DEMO3: DEMO1 {
                displayName = "Demolitions Team 3";
                markerText = "DEMO3";
            };
            class DEMO4: DEMO1 {
                displayName = "Demolitions Team 4";
                markerText = "DEMO4";
            };
        };
    };

    class ENG {
        displayName = "Logistics Team";

        class Units {
            class EngLead: BaseUnit {
                displayName = "Engineer Team Lead";
                type = "engl";
                rank = "corporal";
                leader = 1;
            };
            class Eng: BaseUnit {
                displayName = "Engineer";
                type = "eng";
            };
            class Eng2: Eng {
            };
            class Eng3: Eng {
            };
            class Eng4: Eng {
            };
        };

        class Configurations {
            class ENG1: Weapons {
                displayName = "Logistics Team 1";
                markerText = "ENG1";
                markerTexture = QPATHTOEF(markers,data\maintenance.paa);
            };
            class ENG2: ENG1 {
                displayName = "Logistics Team 2";
                markerText = "ENG2";
            };
            class ENG3: ENG1 {
                displayName = "Logistics Team 3";
                markerText = "ENG3";
            };
            class ENG4: ENG1 {
                displayName = "Logistics Team 4";
                markerText = "ENG4";
            };
        };
    };

    class ArmorGroup {
        displayName = "Armor";

        class Units {
            class ArmorLead: BaseUnit {
                displayName = "Vehicle Commander";
                type = "vicl";
                rank = "sergeant";
                leader = 1;
            };
            class ArmorGunner: BaseUnit {
                displayName = "Vehicle Gunner";
                type = "vicc";
                rank = "corporal";
            };
            class ArmorDriver: BaseUnit {
                displayName = "Vehicle Driver";
                type = "vicd";
            };
        };

        class Configurations {
            class Tank1: Armor {
                displayName = "Tank 1";
                markerText = "Tank1";
            };
            class Tank2: Armor {
                displayName = "Tank 2";
                markerText = "Tank2";
                markerColor[] = {0,0,1,1};
            };
            class Tank3: Tank1 {
                displayName = "Tank 3";
                markerText = "Tank3";
            };
            class Tank4: Tank2 {
                displayName = "Tank 4";
                markerText = "Tank4";
            };
            class Tank5: Tank1 {
                displayName = "Tank 5";
                markerText = "Tank5";
            };
            class Tank6: Tank2 {
                displayName = "Tank 6";
                markerText = "Tank6";
            };
            class Tank7: Tank1 {
                displayName = "Tank 7";
                markerText = "Tank7";
            };
            class Tank8: Tank2 {
                displayName = "Tank 8";
                markerText = "Tank8";
            };
            class IFV1: Tank1 {
                displayName = "IFV 1";
                markerText = "IFV1";
                markerTexture = QPATHTOEF(markers,data\mechanized_infantry.paa);
            };
            class IFV2: IFV1 {
                displayName = "IFV 2";
                markerText = "IFV2";
                markerColor[] = {0,0,1,1};
            };
            class IFV3: IFV1 {
                displayName = "IFV 3";
                markerText = "IFV3";
            };
            class IFV4: IFV2 {
                displayName = "IFV 4";
                markerText = "IFV4";
            };
            class IFV5: IFV1 {
                displayName = "IFV 5";
                markerText = "IFV5";
            };
            class IFV6: IFV2 {
                displayName = "IFV 6";
                markerText = "IFV6";
            };
            class IFV7: IFV1 {
                displayName = "IFV 7";
                markerText = "IFV7";
            };
            class IFV8: IFV2 {
                displayName = "IFV 8";
                markerText = "IFV8";
            };
        };
    };

    class THGroup {
        displayName = "Air Transport";

        class Units {
            class Pilot: BaseUnit {
                displayName = "Pilot";
                type = "pilot";
                rank = "captain";
                leader = 1;

                markerText = "";
                markerTexture = QPATHTOEF(markers,data\helicopter.paa);
                markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
                markerSize = 36;
            };
            class CoPilot: BaseUnit {
                displayName = "Co-Pilot";
                type = "pilot";
                rank = "lieutenant";
            };
            class CrewChief: BaseUnit {
                displayName = "Crew Chief";
                type = "cc";
                rank = "sergeant";
            };
            class Gunner: BaseUnit {
                displayName = "Gunner";
                type = "helicrew";
                rank = "corporal";
            };
        };

        class Configurations {
            class TH1: Air {
                displayName = "TH 1";
                markerPrefix = "TH1";
            };
            class TH2: TH1 {
                displayName = "TH 2";
                markerPrefix = "TH2";
                markerColor[] = {0,0,1,1};
            };
            class TH3: TH1 {
                displayName = "TH 3";
                markerPrefix = "TH3";
            };
            class TH4: TH2 {
                displayName = "TH 4";
                markerPrefix = "TH4";
            };
            class TH5: TH1 {
                displayName = "TH 5";
                markerPrefix = "TH5";
            };
            class TH6: TH2 {
                displayName = "TH 6";
                markerPrefix = "TH6";
            };
            class TH7: TH1 {
                displayName = "TH 7";
                markerPrefix = "TH7";
            };
            class TH8: TH2 {
                displayName = "TH 8";
                markerPrefix = "TH8";
            };
        };
    };

    class AHGroup {
        displayName = "Air Attack";

        class Units {
            class Pilot: BaseUnit {
                displayName = "Pilot";
                type = "pilot";
                rank = "captain";
                leader = 1;

                markerText = "";
                markerTexture = QPATHTOEF(markers,data\attack_helicopter.paa);
                markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
                markerSize = 36;
            };
            class CoPilot: BaseUnit {
                displayName = "Co-Pilot";
                type = "pilot";
                rank = "lieutenant";
            };
            class CrewChief: BaseUnit {
                displayName = "Crew Chief";
                type = "cc";
                rank = "sergeant";
            };
            class Gunner: BaseUnit {
                displayName = "Gunner";
                type = "helicrew";
                rank = "corporal";
            };
        };

        class Configurations {
            class AH1: Air {
                displayName = "AH 1";
                markerPrefix = "AH1";
            };
            class AH2: AH1 {
                displayName = "AH 2";
                markerPrefix = "AH2";
                markerColor[] = {0,0,1,1};
            };
            class AH3: AH1 {
                displayName = "AH 3";
                markerPrefix = "AH3";
            };
            class AH4: AH2 {
                displayName = "AH 4";
                markerPrefix = "AH4";
            };
        };
    };
    class MSVCommand { // if you need to respawn COY, you've fucked up
        displayName = "Command";

        class Units {
            class CO: BaseMSVUnit {
                displayName = "Company Commander";
                type = "coy";
                rank = "captain";
                leader = 1;
            };
            class COMedic: BaseMSVMedic {
                displayName = "Company Medic";
                type = "cm";
                rank = "corporal";
            };
            class CXO: BaseMSVUnit {
                displayName = "Company Executive Officer";
                type = "xo";
                rank = "lieutenant";
            };
            class COFAC: BaseMSVUnit {
                displayName = "Company Forward Air Controller";
                type = "fac";
                rank = "lieutenant";
            };
            class COGunner: BaseMSVGunner {
                displayName = "Company Gunner";
            };
            class CODriver: BaseMSVUnit {
                displayName = "Company Driver";
                type = "vicd";
                colorTeam = 1;
            };
        };

        class Configurations {
            class COY {
                displayName = "Company Command";
                colorTeam1 = "YELLOW";

                markerPrefix = "CO";
                markerText = "Y";
                markerColor[] = {1,0.647,0,1};
                markerTexture = QPATHTOEF(markers,data\hq.paa);
                markerSize = 24;

                srChannel = 13;
                mrChannel = 4;
                lrChannel = 4;
            };
        };
    };

    class MSVPlatoonLead {
        displayName = "Platoon Lead";

        class Units {
            class PlatoonLeader: BaseMSVUnit {
                displayName = "Platoon Leader";
                type = "plt";
                rank = "lieutenant";
                leader = 1;
            };
            class PlatoonMedic: BaseMSVMedic {
                displayName = "Platoon Medic";
                type = "plm";
                rank = "corporal";
            };
            class AssistantPlatoonLeader: BaseMSVUnit {
                displayName = "Platoon Sergent";
                type = "sgt";
                rank = "sergeant";
            };
        };

        class Configurations {
            class OnePlt {
                displayName = "First Platoon Command";

                markerPrefix = "1P";
                markerText = "LT";
                markerColor[] = {1,0.647,0,1};
                markerTexture = QPATHTOEF(markers,data\hq.paa);
                markerSize = 24;

                srChannel = 4;
                mrChannel = 1;
                lrChannel = 4;
            };
            class TwoPlt: OnePlt {
                displayName = "Second Platoon Command";

                markerPrefix = "2P";

                srChannel = 8;
                mrChannel = 2;
            };
            class ThreePlt: OnePlt {
                displayName = "Third Platoon Command";

                markerPrefix = "3P";

                srChannel = 12;
                mrChannel = 3;
            };
            class WeaponsPlt: OnePlt {
                displayName = "Weapons Platoon Command";

                markerPrefix = "WP";

                srChannel = 16;
                mrChannel = 7;
            };
        };
    };

    class MSVSquad {
        displayName = "Squad";

        class Units {
            class SquadLeader: BaseMSVUnit {
                displayName = "Squad Leader";
                type = "sl";
                rank = "sergeant";
                leader = 1;
            };
            class SquadGunner: BaseMSVGunner {
                displayName = "Squad Gunner";
            };
            class SquadDriver: BaseMSVUnit {
                displayName = "Squad Driver";
                type = "vicd";
                colorTeam = 1;
            };
            class SeniorRifleman: BaseSeniorRifleman {};
            class Rifleman: BaseMSVUnit {};
            class SquadMedic: BaseMSVMedic {};
            class AutomaticRifleman: BaseMSVUnit {
                displayName = "Automatic Rifleman";
                type = "ar";
                colorTeam = 2;
            };
            class Grenadier: BaseMSVUnit {
                displayName = "Rifleman Anti-Tank";
                type = "lat";
                colorTeam = 3;
            };
            class AssistantGrenadier: BaseMSVUnit {
                displayName = "Rifleman";
                type = "rifleman";
                colorTeam = 3;
            };
        };

        class Configurations {
            class MSVAlpha: Alpha {
                displayName = "Alpha";
            };
            class MSVBravo: Bravo {
                displayName = "Bravo";
            };
            class MSVCharlie: Charlie {
                displayName = "Charlie";
            };
            class MSVDelta: Delta {
                displayName = "Delta";
            };
            class MSVEcho: Echo {
                displayName = "Echo";
            };
            class MSVFoxtrot: Foxtrot {
                displayName = "Foxtrot";
            };
            class MSVGolf: Golf {
                displayName = "Golf";
            };
            class MSVHotel: Hotel {
                displayName = "Hotel";
            };
            class MSVIndia: India {
                displayName = "India";
            };
        };
    };

    class MSVMMG {
        displayName = "MMG Team";

        class Units {
          class MMGL: BaseMSVUnit {
              displayName = "MMG Leader";
              type = "mmgl";
              rank = "sergeant";
              leader = 1;
          };
            class MMGG: BaseMSVUnit {
                displayName = "MMG Gunner";
                type = "mmgg";
                rank = "corporal";
            };
            class MMGAG: BaseMSVUnit {
                displayName = "MMG Spotter";
                type = "mmgag";
            };
        };

        class Configurations {
            class MMG1: Weapons {
                displayName = "MMG 1";
                markerText = "MMG1";
                markerTexture = QPATHTOEF(markers,data\mmg.paa);
            };
            class MMG2: MMG1 {
                displayName = "MMG 2";
                markerText = "MMG2";
            };
            class MMG3: MMG1 {
                displayName = "MMG 3";
                markerText = "MMG3";
            };
            class MMG4: MMG1 {
                displayName = "MMG 4";
                markerText = "MMG4";
            };
            class MMG5: MMG1 {
                displayName = "MMG 5";
                markerText = "MMG5";
            };
            class MMG6: MMG1 {
                displayName = "MMG 6";
                markerText = "MMG6";
            };
        };
    };

    class MSVHMG {
        displayName = "HMG Team";

        class Units {
            class HMGLeader: BaseMSVUnit {
                displayName = "HMG Leader";
                type = "HMGl";
                rank = "corporal";
                leader = 1;
            };
            class HMGG: BaseMSVUnit {
                displayName = "HMG Gunner";
                type = "HMGg";
            };
            class HMGAG: BaseMSVUnit {
                displayName = "HMG Assistant";
                type = "HMGg";
            };
        };

        class Configurations {
            class HMG1: Weapons {
                displayName = "HMG 1";
                markerText = "HMG1";
                markerTexture = QPATHTOEF(markers,data\support.paa);
            };
            class HMG2: HMG1 {
                displayName = "HMG 2";
                markerText = "HMG2";
            };
            class HMG3: HMG1 {
                displayName = "HMG 3";
                markerText = "HMG3";
            };
            class HMG4: HMG1 {
                displayName = "HMG 4";
                markerText = "HMG4";
            };
        };
    };

    class MSVMAT {
        displayName = "MAT Team";

        class Units {
          class MATL: BaseMSVUnit {
              displayName = "MAT Leader";
              type = "matl";
              rank = "sergeant";
              leader = 1;
          };
            class MATG: BaseMSVUnit {
                displayName = "MAT Gunner";
                type = "matg";
                rank = "corporal";
            };
            class MATAG: BaseMSVUnit {
                displayName = "MAT Spotter";
                type = "matag";
            };
        };

        class Configurations {
            class MAT1: Weapons {
                displayName = "MAT 1";
                markerText = "MAT1";
                markerTexture = QPATHTOEF(markers,data\mat.paa);
            };
            class MAT2: MAT1 {
                displayName = "MAT 2";
                markerText = "MAT2";
            };
            class MAT3: MAT1 {
                displayName = "MAT 3";
                markerText = "MAT3";
            };
            class MAT4: MAT1 {
                displayName = "MAT 4";
                markerText = "MAT4";
            };
            class MAT5: MAT1 {
                displayName = "MAT 5";
                markerText = "MAT5";
            };
            class MAT6: MAT1 {
                displayName = "MAT 6";
                markerText = "MAT6";
            };
        };
    };

    class MSVHAT {
        displayName = "HAT Team";

        class Units {
            class HATLeader: BaseMSVUnit {
                displayName = "HAT Leader";
                type = "HATl";
                rank = "corporal";
                leader = 1;
            };
            class HATG: BaseMSVUnit {
                displayName = "HAT Gunner";
                type = "HATg";
            };
            class HATAG: BaseMSVUnit {
                displayName = "HAT Assistant";
                type = "HATg";
            };
        };

        class Configurations {
            class HAT1: Weapons {
                displayName = "HAT 1";
                markerText = "HAT1";
                markerTexture = QPATHTOEF(markers,data\support.paa);
            };
            class HAT2: HAT1 {
                displayName = "HAT 2";
                markerText = "HAT2";
            };
            class HAT3: HAT1 {
                displayName = "HAT 3";
                markerText = "HAT3";
            };
            class HAT4: HAT1 {
                displayName = "HAT 4";
                markerText = "HAT4";
            };
        };
    };

    class MSVArty {
        displayName = "Artillery Team";

        class Units {
            class ArtLeader: BaseMSVUnit {
                displayName = "Artillery Leader";
                type = "Artl";
                rank = "corporal";
                leader = 1;
            };
            class ArtG1: BaseMSVUnit {
                displayName = "Artillery Gunner";
                type = "Artg";
            };
            class ArtG2: ArtG1 {
            };
            class ArtG3: ArtG1 {
            };
            class ArtG4: ArtG1 {
            };
        };

        class Configurations {
            class Art1: Weapons {
                displayName = "Artillery";
                markerText = "Artillery";
                markerTexture = QPATHTOEF(markers,data\mortar.paa);
            };
        };
    };

    class MSVMSAM {
        displayName = "MSAM Team";

        class Units {
            class MSAMLeader: BaseMSVUnit {
                displayName = "MSAM Leader";
                type = "msaml";
                rank = "corporal";
                leader = 1;
            };
            class MSAMG: BaseMSVUnit {
                displayName = "MSAM Gunner";
                type = "msamg";
            };
            class MSAMAG: BaseMSVUnit {
                displayName = "MSAM Assistant";
                type = "msamg";
            };
        };

        class Configurations {
            class MSAM1: Weapons {
                displayName = "MSAM 1";
                markerText = "MSAM1";
                markerTexture = QPATHTOEF(markers,data\msam.paa);
            };
            class MSAM2: MSAM1 {
                displayName = "MSAM 2";
                markerText = "MSAM2";
            };
            class MSAM3: MSAM1 {
                displayName = "MSAM 3";
                markerText = "MSAM3";
            };
            class MSAM4: MSAM1 {
                displayName = "MSAM 4";
                markerText = "MSAM4";
            };
        };
    };

    class MSVDEMO {
        displayName = "Demolitions Team";

        class Units {
            class EngLead: BaseMSVUnit {
                displayName = "Demolitions Team Lead";
                type = "engl";
                rank = "corporal";
                leader = 1;
            };
            class Eng1: BaseMSVUnit {
                displayName = "Demolitions Specialist";
                type = "demo";
            };
            class Eng2: Eng1 {
            };
            class Eng: Eng1 {
              displayName = "Mine Specialist";
                type = "mine";
            };
            class Eng4: Eng2 {
            };
        };

        class Configurations {
            class DEMO1: Weapons {
                displayName = "Demolitions Team 1";
                markerText = "DEMO1";
                markerTexture = QPATHTOEF(markers,data\engineer.paa);
            };
            class DEMO2: DEMO1 {
                displayName = "Demolitions Team 2";
                markerText = "DEMO2";
            };
            class DEMO3: DEMO1 {
                displayName = "Demolitions Team 3";
                markerText = "DEMO3";
            };
            class DEMO4: DEMO1 {
                displayName = "Demolitions Team 4";
                markerText = "DEMO4";
            };
        };
    };

    class MSVENG {
        displayName = "Logistics Team";

        class Units {
            class EngLead: BaseUnit {
                displayName = "Engineer Team Lead";
                type = "engl";
                rank = "corporal";
                leader = 1;
            };
            class Eng: BaseUnit {
                displayName = "Engineer";
                type = "eng";
            };
            class Eng2: Eng {
            };
            class Eng3: Eng {
            };
            class Eng4: Eng {
            };
        };

        class Configurations {
            class ENG1: Weapons {
                displayName = "Logistics Team 1";
                markerText = "ENG1";
                markerTexture = QPATHTOEF(markers,data\maintenance.paa);
            };
            class ENG2: ENG1 {
                displayName = "Logistics Team 2";
                markerText = "ENG2";
            };
            class ENG3: ENG1 {
                displayName = "Logistics Team 3";
                markerText = "ENG3";
            };
            class ENG4: ENG1 {
                displayName = "Logistics Team 4";
                markerText = "ENG4";
            };
        };
    };

/* Commented out as SF is not currently implimented.
    class MSVSF {
        displayName = "Special Forces";

        class Units {
            class SquadLeader: BaseMSVUnit {
                displayName = "Squad Leader";
                type = "sf_sl";
                rank = "sergeant";
                leader = 1;
            };
            class SquadMedic: BaseMSVMedic {
                type = "sf_sm";
            };
            class SeniorRifleman: BaseSeniorRifleman {
                type = "sf_ftl";
                colorTeam = 1;
            };
            class Marksman: BaseMSVUnit {
                displayName = "Marksman";
                type = "sniper";
                colorTeam = 1;
            };
            class AutomaticRifleman: BaseMSVUnit {
                displayName = "Automatic Rifleman";
                type = "sf_ar";
                colorTeam = 2;
            };
            class AssistantAutomaticRifleman: BaseMSVUnit {
                displayName = "Assistant Automatic Rifleman";
                type = "sf_aar";
                colorTeam = 2;
            };
            class Grenadier: BaseMSVUnit {
                displayName = "Rifleman Anti-Tank";
                type = "sf_lat";
                colorTeam = 3;
            };
            class AssistantGrenadier: BaseMSVUnit {
                displayName = "Rifleman 1";
                type = "sf_rifleman";
                colorTeam = 3;
            };
            class Rifleman: BaseMSVUnit {
              displayName = "Rifleman 2";
                type = "sf_rifleman_02";
                colorTeam = 1;
            };
        };

        class Configurations {
            class MSVRecon1: Weapons {
                displayName = "Recon 1";
                markerPrefix = "R1";
                markerTexture = QPATHTOEF(markers,data\recon.paa);
            };
            class MSVRecon2: MSVRecon1 {
                displayName = "Recon 2";
                markerPrefix = "R2";
            };
            class MSVRecon3: MSVRecon1 {
                displayName = "Recon 3";
                markerPrefix = "R3";
            };
            class MSVRecon4: MSVRecon1 {
                displayName = "Recon 4";
                markerPrefix = "R4";
            };
        };
    };
*/
    class MSVArmor {
        displayName = "Armor";

        class Units {
            class ArmorLead: BaseMSVUnit {
                displayName = "Vehicle Commander";
                type = "vicl";
                rank = "sergeant";
                leader = 1;
            };
            class ArmorGunner: BaseMSVUnit {
                displayName = "Vehicle Gunner";
                type = "vicc";
                rank = "corporal";
            };
            class ArmorDriver: BaseMSVUnit {
                displayName = "Vehicle Driver";
                type = "vicd";
            };
        };

        class Configurations {
            class Tank1: Armor {
                displayName = "Tank 1";
                markerText = "Tank1";
            };
            class Tank2: Armor {
                displayName = "Tank 2";
                markerText = "Tank2";
                markerColor[] = {0,0,1,1};
            };
            class Tank3: Tank1 {
                displayName = "Tank 3";
                markerText = "Tank3";
            };
            class Tank4: Tank2 {
                displayName = "Tank 4";
                markerText = "Tank4";
            };
            class Tank5: Tank1 {
                displayName = "Tank 5";
                markerText = "Tank5";
            };
            class Tank6: Tank2 {
                displayName = "Tank 6";
                markerText = "Tank6";
            };
            class Tank7: Tank1 {
                displayName = "Tank 7";
                markerText = "Tank7";
            };
            class Tank8: Tank2 {
                displayName = "Tank 8";
                markerText = "Tank8";
            };
            class IFV1: Tank1 {
                displayName = "IFV 1";
                markerText = "IFV1";
                markerTexture = QPATHTOEF(markers,data\mechanized_infantry.paa);
            };
            class IFV2: IFV1 {
                displayName = "IFV 2";
                markerText = "IFV2";
                markerColor[] = {0,0,1,1};
            };
            class IFV3: IFV1 {
                displayName = "IFV 3";
                markerText = "IFV3";
            };
            class IFV4: IFV2 {
                displayName = "IFV 4";
                markerText = "IFV4";
            };
            class IFV5: IFV1 {
                displayName = "IFV 5";
                markerText = "IFV5";
            };
            class IFV6: IFV2 {
                displayName = "IFV 6";
                markerText = "IFV6";
            };
            class IFV7: IFV1 {
                displayName = "IFV 7";
                markerText = "IFV7";
            };
            class IFV8: IFV2 {
                displayName = "IFV 8";
                markerText = "IFV8";
            };
            class WPLV1: IFV1 {
                displayName = "WV 1";
                markerText = "WV1";
                markerColor[] = {1,0.647,0,1};
            };
            class WPLV2: WPLV1 {
                displayName = "WV 2";
                markerText = "WV2";
            };
            class WPLV3: WPLV1 {
                displayName = "WV 3";
                markerText = "WV3";
            };
            class WPLV4: WPLV1 {
                displayName = "WV 4";
                markerText = "WV4";
            };
            class WPLV5: WPLV1 {
                displayName = "WV 5";
                markerText = "WV5";
            };
            class WPLV6: WPLV1 {
                displayName = "WV 6";
                markerText = "WV6";
            };
        };
    };

    class MSVTH {
        displayName = "Air Transport";

        class Units {
            class Pilot: BaseMSVUnit {
                displayName = "Pilot";
                type = "pilot";
                rank = "captain";
                leader = 1;

                markerText = "";
                markerTexture = QPATHTOEF(markers,data\helicopter.paa);
                markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
                markerSize = 36;
            };
            class CoPilot: BaseMSVUnit {
                displayName = "Co-Pilot";
                type = "pilot";
                rank = "lieutenant";
            };
            class CC: BaseMSVUnit {
                displayName = "Crew Chief";
                type = "cc";
                rank = "sergeant";
            };
            class AirCrew: BaseMSVUnit {
                displayName = "Air Crew";
                type = "helicrew";
                rank = "corporal";
            };
        };

        class Configurations {
            class TH1: Air {
                displayName = "TH 1";
                markerPrefix = "TH1";
            };
            class TH2: TH1 {
                displayName = "TH 2";
                markerPrefix = "TH2";
                markerColor[] = {0,0,1,1};
            };
            class TH3: TH1 {
                displayName = "TH 3";
                markerPrefix = "TH3";
            };
            class TH4: TH2 {
                displayName = "TH 4";
                markerPrefix = "TH4";
            };
            class TH5: TH1 {
                displayName = "TH 5";
                markerPrefix = "TH5";
            };
            class TH6: TH2 {
                displayName = "TH 6";
                markerPrefix = "TH6";
            };
            class TH7: TH1 {
                displayName = "TH 7";
                markerPrefix = "TH7";
            };
            class TH8: TH2 {
                displayName = "TH 8";
                markerPrefix = "TH8";
            };
        };
    };

    class MSVAH {
        displayName = "Air Attack";

        class Units {
            class Pilot: BaseMSVUnit {
                displayName = "Pilot";
                type = "pilot";
                rank = "captain";
                leader = 1;

                markerText = "";
                markerTexture = QPATHTOEF(markers,data\helicopter.paa);
                markerColor[] = {0,0,0,0}; // <- same as no color, will be overriden by group cfg
                markerSize = 36;
            };
            class CoPilot: BaseMSVUnit {
                displayName = "Gunner";
                type = "cc";
                rank = "lieutenant";
            };
        };

        class Configurations {
            class AH1: Air {
                displayName = "AH 1";
                markerPrefix = "AH1";
            };
            class AH2: AH1 {
                displayName = "AH 2";
                markerPrefix = "AH2";
                markerColor[] = {0,0,1,1};
            };
            class AH3: AH1 {
                displayName = "AH 3";
                markerPrefix = "AH3";
            };
            class AH4: AH2 {
                displayName = "AH 4";
                markerPrefix = "AH4";
            };
        };
    };

    class MiscCivilians {
        displayName = "Misc Civilians";

        class Units {
            class Civ1: BaseUnit {
                displayName = "Civilian";
                type = "c_man_1";
                leader = 1;
            };
            class Civ2: BaseUnit {
                displayName = "Civilian";
                type = "c_man_1";
            };
            class Civ3: BaseUnit {
                displayName = "Civilian";
                type = "c_man_2";
            };
            class Civ4: BaseUnit {
                displayName = "Civilian";
                type = "c_man_2";
            };
            class Civ5: BaseUnit {
                displayName = "Civilian";
                type = "c_man_3";
            };
            class Civ6: BaseUnit {
                displayName = "Civilian";
                type = "c_man_3";
            };
        };

        class Configurations {
            class MiscCiv {
                displayName = "Civilians";
            };
        };
    };

    class PressTeam {
        displayName = "Press Team";

        class Units {
            class Reporter: BaseUnit {
                displayName = "Reporter";
                type = "c_journalist_f";
                leader = 1;
            };
            class Cameraman: BaseUnit {
                displayName = "Cameraman";
                type = "c_journalist_f";
            };
        };

        class Configurations {
            class PT {
                displayName = "Press Team";
            };
        };
    };
};
