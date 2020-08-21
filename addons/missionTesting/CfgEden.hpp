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
                    items[] += {QGVAR(missionTesting)};
                };
                class GVAR(briefings) {
                    text = "Mission Attributes";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(missionTesting)););
                };
            };
        };
    };
};

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class TitleWide: Default {
            class Controls;
        };
        class Edit: Title {
            class Controls: Controls {
                class Title: Title {};
                class Value;
            };
        };
        class GVAR(bigEdit): Edit {
            attributeSave = QUOTE(_this call FUNC(missionAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(missionAttributeLoad));

            h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
            class Controls: Controls {
                class Title: Title {
                    h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
                };
                class Value: Value {
                    idc = TEXT_IDC;
                    style = 16; //multi line
                    h = "5 * 5 * (pixelH * pixelGrid * 0.50)";
                };
            };
        };
        class GVAR(briefingSettings): TitleWide {
            onLoad = QUOTE(_this call FUNC(briefingSettingsControlLoad));
            attributeSave = QUOTE(_this call FUNC(briefingSettingsAttributeSave));
            attributeLoad = QUOTE([ARR_2(_this,_value)] call FUNC(briefingSettingsAttributeLoad));
            h = (2 * SIZE_M + 1) * GRID_H;

            class Controls: Controls {
                class SetCreditsTitle: Title {
                    style = 1;
                    w = (ATTRIBUTE_TITLE_W - SIZE_M) * GRID_W;
                    text = "Select Mission Type";
                };
                class SetCreditsControl: GVAR(setAttributeMissionType) {
                    idc = AUTO_CREDS_SET_IDC;
                };
            };
        };
    };
