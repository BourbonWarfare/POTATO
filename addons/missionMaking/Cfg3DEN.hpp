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
                    items[] += {QGVAR(copyMapName), QGVAR(fixFloating), QGVAR(vehicleReport)};
                };
                class GVAR(copyMapName) {
                    text = "Copy Mapname to Clipboard";
                    action = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_copyMapName.sqf)););
                };
                class GVAR(fixFloating) {
                    text = "Fix Floating Units";
                    action = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_fixFloating.sqf)););
                };
                class GVAR(vehicleReport) {
                    text = "Vehicle Crew Capacity";
                    action = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_vehicleReport.sqf)););
                };
            };
        };
    };
};
