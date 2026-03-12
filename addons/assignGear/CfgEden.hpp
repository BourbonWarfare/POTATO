class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(resetLoadouts)};
                };
                class GVAR(resetLoadouts) {
                    text = "Save \& Reload BWMF Loadouts";
                    action = QUOTE(call compileScript [QUOTE(QPATHTOF(functions\fnc_resetLoadouts.sqf))];);
                };
            };
        };
    };
};
