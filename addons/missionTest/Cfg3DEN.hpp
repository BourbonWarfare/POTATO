class Cfg3DEN {
    class EventHandlers {
        class ADDON {
            onMissionSave = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_onMissionSave.sqf)));
            onMissionLoad = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_onMissionLoad.sqf)));
        };
    };
};

class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(fixFloating)};
                };
                class GVAR(fixFloating) {
                    text = "Fix Floating Units";
                    action = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_fixFloating.sqf)););
                };
            };
        };
    };
};
