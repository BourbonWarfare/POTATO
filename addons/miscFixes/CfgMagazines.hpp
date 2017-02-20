class CfgMagazines {
    class CA_LauncherMagazine;
    class rhs_mag_smaw_HEAA: CA_LauncherMagazine {
        mass = 80;
    };
    class rhs_mag_smaw_HEDP: CA_LauncherMagazine {
        mass = 65;
    };

    class rhs_30Rnd_762x39mm_tracer;
    class potato_75Rnd_762x39mm_tracer: rhs_30Rnd_762x39mm_tracer {
        author = "POTATO";
        count = 75;
        descriptionShort = "Caliber: 7.62x39mm<br/>Rounds: 75<br/>Used in: RPK";
        displayName = "57-N-231P 75 round Drum Mag";
        mass = 25;
    };

    class 200Rnd_65x39_cased_Box_Tracer;
    class 200Rnd_65x39_cased_Box_Tracer_Red: 200Rnd_65x39_cased_Box_Tracer {
        ammo = "B_65x39_Case_red";
        author = "POTATO";
        descriptionShort = "6.5mm 200Rnd Tracer Box<br/>Caliber: 6.5x39 mm Tracer - Red<br/>Rounds: 200<br/>Used in: Mk200";
        displayName = "6.5mm 200Rnd Tracer Box (Red)";
        displayNameShort = "Tracer";
        picture = "\A3\Weapons_F\Data\UI\m_200rnd_65x39_red_ca.paa";
    };
    class 200Rnd_65x39_cased_Box_Tracer_Green: 200Rnd_65x39_cased_Box_Tracer {
        ammo = "B_65x39_Case_green";
        author = "POTATO";
        descriptionShort = "6.5mm 200Rnd Tracer Box<br/>Caliber: 6.5x39 mm Tracer - Green<br/>Rounds: 200<br/>Used in: Mk200";
        displayName = "6.5mm 200Rnd Tracer Box (Green)";
        displayNameShort = "Tracer";
        picture = "\A3\Weapons_F\Data\UI\m_200rnd_65x39_green_ca.paa";
    };
    class 100Rnd_65x39_cased_Box_Tracer_Yellow: 200Rnd_65x39_cased_Box_Tracer {
        author = "POTATO";
        count = 100;
        descriptionShort = "6.5mm 100Rnd Tracer Box<br/>Caliber: 6.5x39 mm Tracer - Yellow<br/>Rounds: 100<br/>Used in: Mk200";
        displayName = "6.5mm 100Rnd Tracer Box (Yellow)";
        displaynameshort = "Tracer";
        lastRoundsTracer = 100;
        mass = 23.5;
    };
    class 100Rnd_65x39_cased_Box_Tracer_Red: 100Rnd_65x39_cased_Box_Tracer_Yellow {
        ammo = "B_65x39_Case_red";
        descriptionShort = "6.5mm 100Rnd Tracer Box<br/>Caliber: 6.5x39 mm Tracer - Red<br/>Rounds: 100<br/>Used in: Mk200";
        displayName = "6.5mm 100Rnd Tracer Box (Red)";
        displaynameshort = "Tracer";
        picture = "\A3\Weapons_F\Data\UI\m_200rnd_65x39_red_ca.paa";
    };
    class 100Rnd_65x39_cased_Box_Tracer_Green: 100Rnd_65x39_cased_Box_Tracer_Yellow {
        ammo = "B_65x39_Case_green";
        descriptionShort = "6.5mm 100Rnd Tracer Box<br/>Caliber: 6.5x39 mm Tracer - Green<br/>Rounds: 100<br/>Used in: Mk200";
        displayName = "6.5mm 100Rnd Tracer Box (Green)";
        displayNameShort = "Tracer";
        picture = "\A3\Weapons_F\Data\UI\m_200rnd_65x39_green_ca.paa";
    };

    class 150Rnd_762x54_Box_Tracer;
    class 150Rnd_762x54_Box_Tracer_Red: 150Rnd_762x54_Box_Tracer {
        ammo = "B_762x54_Tracer_Red";
        author = "POTATO";
        descriptionShort = "7.62mm 150Rnd Tracer Box<br/>Caliber: 7.62x54 mm Tracer - Red<br/>Rounds: 150<br/>Used in: Zafir";
        displayName = "7.62mm 150Rnd Tracer Box (Red)";
        displayNameShort = "Tracer";
        picture = QPATHTOF(data\m_150Rnd_762x51_tracer_red_CA.paa);
    };
    class 150Rnd_762x54_Box_Tracer_Yellow: 150Rnd_762x54_Box_Tracer {
        ammo = "B_762x54_Tracer_Yellow";
        author = "POTATO";
        descriptionShort = "7.62mm 150Rnd Tracer Box<br/>Caliber: 7.62x54 mm Tracer - Yellow<br/>Rounds: 150<br/>Used in: Zafir";
        displayName = "7.62mm 150Rnd Tracer Box (Yellow)";
        displayNameShort = "Tracer";
        picture = QPATHTOF(data\m_150Rnd_762x51_tracer_yellow_CA.paa);
    };
    class 100Rnd_762x54_Box_Tracer_Green: 150Rnd_762x54_Box_Tracer {
        ammo = "B_762x54_Tracer_Green";
        author = "POTATO";
        count = 100;
        descriptionShort = "7.62mm 100Rnd Tracer Box<br/>Caliber: 7.62x54 mm Tracer - Green<br/>Rounds: 100<br/>Used in: Zafir";
        displayName = "7.62mm 100Rnd Tracer Box (Green)";
        displayNameShort = "Tracer";
        mass = 32;
    };
    class 100Rnd_762x54_Box_Tracer_Red: 100Rnd_762x54_Box_Tracer_Green {
        ammo = "B_762x54_Tracer_Red";
        descriptionShort = "7.62mm 100Rnd Tracer Box<br/>Caliber: 7.62x54 mm Tracer - Red<br/>Rounds: 100<br/>Used in: Zafir";
        displayName = "7.62mm 100Rnd Tracer Box (Red)";
        displayNameShort = "Tracer";
        picture = QPATHTOF(data\m_150Rnd_762x51_tracer_red_CA.paa);
    };
    class 100Rnd_762x54_Box_Tracer_Yellow: 100Rnd_762x54_Box_Tracer_Green {
        ammo = "B_762x54_Tracer_Yellow";
        descriptionShort = "7.62mm 100Rnd Tracer Box<br/>Caliber: 7.62x54 mm Tracer - Yellow<br/>Rounds: 100<br/>Used in: Zafir";
        displayName = "7.62mm 100Rnd Tracer Box (Yellow)";
        displayNameShort = "Tracer";
        picture = QPATHTOF(data\m_150Rnd_762x51_tracer_yellow_CA.paa);
    };

};
