class Cfg3DEN {
    class EventHandlers {
        class ADDON {
            onMissionSave = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_onMissionSave.sqf)));
            onMissionLoad = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_onMissionLoad.sqf)));
        };
    };
};

class ctrlMenu;
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
    class ContextMenu: ctrlMenu {
        class Items {
            items[]+={QGVAR(changeUnitType)};
            class GVAR(changeUnitType) {
                text = "POTATO: Change Unit Type";
                value = 0;
                items[] = {
                    QGVAR(changeUnitType_ar),
                    QGVAR(changeUnitType_aar),
                    QGVAR(changeUnitType_lat),
                    QGVAR(changeUnitType_uav),
                    QGVAR(changeUnitType_sm),
                    QGVAR(changeUnitType_vicd),
                    QGVAR(changeUnitType_mtrg)
                };
                conditionShow = "hoverObjectBrain * (1 - (hoverObjectVehicle))";
            };
            class GVAR(changeUnitType_ar) {
                text = "AR";
                action = QUOTE(['ar'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_aar) {
                text = "AAR";
                action = QUOTE(['aar'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_lat) {
                text = "LAT";
                action = QUOTE(['lat'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_uav) {
                text = "UAV";
                action = QUOTE(['uav'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_sm) {
                text = "SM (medic)";
                action = QUOTE(['sm'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_vicd) {
                text = "VICD (Driver/Repair)";
                action = QUOTE(['vicd'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
            class GVAR(changeUnitType_mtrg) {
                text = "MTRG (Mortar)";
                action = QUOTE(['mtrg'] call compileScript [QUOTE(QPATHTOF(functions\fnc_changeUnitType.sqf))];);
            };
        };
    };
};
