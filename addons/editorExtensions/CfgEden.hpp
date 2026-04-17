#define ATTRIBUTE_W (pixelW * pixelGrid * 0.5)
#define ATTRIBUTE_H (pixelH * pixelGrid * 0.5)

class ctrlXSliderH;
class ctrlStaticFrame;
class ctrlStatic; 
class ctrlEdit;
class ctrlListNBox;
class Cfg3DEN {
    class Attributes {
        class Default;

        class GVAR(titled): Default {
            class Controls {
                class Title: ctrlStatic {
                    style = 1;
                    x = 0;
                    w = QUOTE(48 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                    colorBackground[] = {0,0,0,0};
                };
            };
        };

        class GVAR(sliderTime): GVAR(titled) {
            attributeLoad = QUOTE(call FUNC(sliderTime_load));
            attributeSave = QUOTE(call FUNC(sliderTime_save));
            class Controls: Controls {
                class Title: Title {};
                class Slider: ctrlXSliderH {
                    idc = IDC_SLIDER_TIME_SLIDER;
                    x = QUOTE(48 * ATTRIBUTE_W);
                    w = QUOTE((82 - 8 * 3) * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                    sliderRange[] = {0,0};
                    sliderPosition = 0;
                    pageSize = 1;
                    onSliderPosChanged = QUOTE(call FUNC(sliderTime_onSliderPosChanged));
                };
                class Frame: ctrlStaticFrame {
                    x = QUOTE((48 + 82 - 8 * 3) * ATTRIBUTE_W);
                    w = QUOTE(3 * 8 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                };
                class Separator: ctrlStatic {
                    style = 2;
                    x = QUOTE((48 + 82 - 8 * 3) * ATTRIBUTE_W);
                    w = QUOTE(3 * 8 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                    font = "EtelkaMonospacePro";
                    sizeEx = "3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
                    colorBackground[] = {0,0,0,0.5};
                    text = ":   :";
                };
                class Hour: ctrlEdit {
                    idc = IDC_SLIDER_TIME_HOUR;
                    text = "00";
                    tooltip = "$STR_3DEN_Attributes_SliderTime_Hour_tooltip";
                    style = "0x02 + 0x200";
                    x = QUOTE((48 + 82 - 8 * 3) * ATTRIBUTE_W);
                    w = QUOTE(8 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                    colorBackground[] = {0,0,0,0};
                    font = "EtelkaMonospacePro";
                    sizeEx = "3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
                    onKillFocus = QUOTE(call FUNC(sliderTime_onInputChanged));
                };
                class Minute: Hour {
                    idc = IDC_SLIDER_TIME_MINUTE;
                    tooltip = "$STR_3DEN_Attributes_SliderTime_Minute_tooltip";
                    x = QUOTE((48 + 82 - 8 * 2) * ATTRIBUTE_W);
                    w = QUOTE(8 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                };
                class Second: Hour {
                    idc = IDC_SLIDER_TIME_SECOND;
                    tooltip = "$STR_3DEN_Attributes_SliderTime_Second_tooltip";
                    x = QUOTE((48 + 82 - 8) * ATTRIBUTE_W);
                    w = QUOTE(8 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                };
            };
        };

        class GVAR(editTable): Default {
            attributeLoad = QUOTE(call FUNC(editTable_load));
            attributeSave = QUOTE(call FUNC(editTable_save));
            class Controls {
                class Container: ctrlListNBox {
                    idc = IDC_EDIT_TABLE_LISTBOX;
                    idcLeft = IDC_EDIT_TABLE_LEFT;
                    idcRight = IDC_EDIT_TABLE_RIGHT;
                    drawSideArrows = 1;
                    disableOverflow = 1;
                    x = QUOTE(5 * ATTRIBUTE_W);
                    y = 0;
                    w = QUOTE(125 * ATTRIBUTE_W);
                    h = QUOTE(65 * ATTRIBUTE_H);
                };
            };
        };
    };
};
