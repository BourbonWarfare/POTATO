#include "\a3\3den\UI\macros.inc"
#include "\a3\3den\UI\resincl.inc"
#define SIZE_XXS 1

class ctrlToolbox;
class ctrlMenuStrip;

class GVAR(setAttributeMissionType): ctrlToolbox {
    x = (ATTRIBUTE_TITLE_W + SIZE_XXS) * GRID_W;
    y = 0.02 * SIZE_M * GRID_H;
    w = ATTRIBUTE_CONTENT_W * GRID_W;
    h = 0.96 * SIZE_M * GRID_H;

    rows = 1;
    columns = 3;
    strings[] = {"COOP", "TVT"};
    tooltips[] = {"Cooperative Mission", "Adversarial Mission"};
    values[] = {1, 2};
};

//This is a mess and is going to be a nightmare. I will figure it out though.

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(missionAttributes)};
                };
                class GVAR(missionAttributes) {
                    text = "Mission Attributes";
                    action = QUOTE(call compile preprocessFileLineNumbers QUOTE(QPATHTOF(functions\fnc_displayMenu.sqf)););
                };
            };
        };
    };
};
