class ctrlXSliderH;
class ctrlStaticFrame;
class ctrlStatic; 
class ctrlEdit;
class Cfg3DEN {
    class Attributes {
        class Default;

        class Titled: Default {
            class Controls {
                class Title: ctrlStatic {
                    style = 1;
                    x = 0;
                    w = "48 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                    colorBackground[] = {0,0,0,0};
                };
            };
        };

        class GVAR(sliderTime): Titled {
            attributeLoad = QUOTE(call FUNC(sliderTime_load));
            attributeSave = QUOTE(call FUNC(sliderTime_save));
            class Controls: Controls {
                class Title: Title {};
                class Slider: ctrlXSliderH {
                    idc = IDC_SLIDER_TIME_SLIDER;
                    x = "48 * (pixelW * pixelGrid * 0.50)";
                    w = "(82 - 8 * 3) * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                    sliderRange[] = {0,0};
                    sliderPosition = 0;
                    pageSize = 1;
                    onSliderPosChanged = QUOTE(call FUNC(sliderTime_onSliderPosChanged));
                };
                class Frame: ctrlStaticFrame {
                    x = "(48 + 82 - 8 * 3) * (pixelW * pixelGrid * 0.50)";
                    w = "3 * 8 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                };
                class Separator: ctrlStatic {
                    style = 2;
                    x = "(48 + 82 - 8 * 3) * (pixelW * pixelGrid * 0.50)";
                    w = "3 * 8 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
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
                    x = "(48 + 82 - 8 * 3) * (pixelW * pixelGrid * 0.50)";
                    w = "8 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                    colorBackground[] = {0,0,0,0};
                    font = "EtelkaMonospacePro";
                    sizeEx = "3.875 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
                    onKillFocus = QUOTE(call FUNC(sliderTime_onInputChanged));
                };
                class Minute: Hour {
                    idc = IDC_SLIDER_TIME_MINUTE;
                    tooltip = "$STR_3DEN_Attributes_SliderTime_Minute_tooltip";
                    x = "(48 + 82 - 8 * 2) * (pixelW * pixelGrid * 0.50)";
                    w = "8 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                };
                class Second: Hour {
                    idc = IDC_SLIDER_TIME_SECOND;
                    tooltip = "$STR_3DEN_Attributes_SliderTime_Second_tooltip";
                    x = "(48 + 82 - 8) * (pixelW * pixelGrid * 0.50)";
                    w = "8 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                };
            };
        };
    };
};
