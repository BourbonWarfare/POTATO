class CfgMarkerBrushes {
    class Cross;
    class GVAR(stayOut): Cross {
        name = "Stay Out";
		drawBorder=1;
		texture=QPATHTOF(UI\stayOut_symbol_ca.paa);
    };
    class GVAR(actualMinefieldV1): Cross { // make sure to keep this marker backwards compatible
        name = "Actual Minefield [Scripted]";
		drawBorder=1;
		texture=QPATHTOF(UI\stayOut_fill_ca.paa);
    };
};
