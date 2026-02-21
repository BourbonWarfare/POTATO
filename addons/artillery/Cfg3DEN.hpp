// Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/arsenal/Cfg3DEN.hpp

#define ATTRIBUTE_W (pixelW * pixelGrid * 0.5)
#define ATTRIBUTE_H (pixelH * pixelGrid * 0.5)
class ctrlControlsGroupNoScrollbars;
class ctrlStatic;
class ctrlListNBox;
class ctrlButton;
class Cfg3DEN {
    class Attributes {
        class GVAR(attribute): ctrlControlsGroupNoScrollbars {
            idc = ARTILLERY_EDITOR_ROUND_ATTRIBUTE;
            x = 0;
            y = 0;
            w = QUOTE(130 * ATTRIBUTE_W);
            h = QUOTE(70 * ATTRIBUTE_H);
            attributeLoad = QUOTE(_this call FUNC(artyRndAttributeLoad));
            attributeSave = QUOTE(_this call FUNC(artyRndAttributeSave));
            class controls {
                class ListBackground: ctrlStatic {
                    idc = -1;
                    x = QUOTE(5 * ATTRIBUTE_W);
                    y = 0;
                    w = QUOTE(125 * ATTRIBUTE_W);
                    h = QUOTE(65 * ATTRIBUTE_H);
                    colorBackground[] = {1, 1, 1, 0.1};
                };
                class List: ctrlListNBox {
                    idc = ARTILLERY_EDITOR_ROUND_LISTBOX;
                    idcLeft = ARTILLERY_EDITOR_ROUND_LEFTARROW;
                    idcRight = ARTILLERY_EDITOR_ROUND_RIGHTARROW;
                    onLBDblClick = QUOTE(call FUNC(artyRndAttributeDblClick));
                    onSetFocus = QUOTE(missionNamespace setVariable [ARR_2(QQGVAR(artyRoundUIFocused),true)]);
                    onKillFocus = QUOTE(missionNamespace setVariable [ARR_2(QQGVAR(artyRoundUIFocused),false)]);
                    x = QUOTE(5 * ATTRIBUTE_W);
                    y = 0;
                    w = QUOTE(125 * ATTRIBUTE_W);
                    h = QUOTE(65 * ATTRIBUTE_H);
                    drawSideArrows = 1;
                    disableOverflow = 1;
                    columns[] = {0.05, 0.35, 0.9, 0.95};
                    tooltip = "Use Shift+A to select all and Shift+C to clear all";
                };
                class ArrowLeft: ctrlButton {
                    idc = ARTILLERY_EDITOR_ROUND_LEFTARROW;
                    onButtonClick = QUOTE([ARR_2(ctrlParentControlsGroup (_this select 0),true)] call FUNC(artyRndAttributeArrow));
                    text = "-";
                    font = "RobotoCondensedBold";
                    x = -1;
                    y = -1;
                    w = QUOTE(10 * ATTRIBUTE_W);
                    h = QUOTE(5 * ATTRIBUTE_H);
                };
                class ArrowRight: ArrowLeft {
                    idc = ARTILLERY_EDITOR_ROUND_RIGHTARROW;
                    onButtonClick = QUOTE([ARR_2(ctrlParentControlsGroup (_this select 0),false)] call FUNC(artyRndAttributeArrow));
                    text = "+";
                };
            };
        };
    };
};
