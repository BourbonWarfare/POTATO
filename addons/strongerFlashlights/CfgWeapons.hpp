class CfgWeapons {
    class InventoryFlashLightItem_Base_F;    
    
    class cup_acc_flashlight; //CUP Flashlight -surefire
    
    class ItemCore;
    class ACE_acc_pointer_green;
    class acc_flashlight_pistol;
    
/////////////////////////////////////////
//////////Multimode Flashlight///////////
/////////////////////////////////////////    
    
    class GVAR(CUP_LED_flashlight_Beam): cup_acc_flashlight {
        author = "Potato";
        scope = 1;
        displayName = "Tactical LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: Focused White Beam. Ctrl+L to change Mode";
        descriptionShort = "Mode: Focused White Beam. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(CUP_LED_flashlight);
        MRT_SwitchItemPrevClass = QGVAR(CUP_LED_flashlight_Flood);
        MRT_switchItemHintText = "Focused White Beam";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 6;
            RMBhint="LED Flashlight (Beam)";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                dayLight = 1;
                useFlare = 1;
                direction = "flash";
                flareMaxDistance = 554;
                flareSize = 4;
                innerAngle = 8;    
                outerAngle = 14;
                coneFadeCoef = 4;
                intensity = 400;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 100;
                    constant = 100;
                    linear = 60;
                    quadratic = 20;
                    hardLimitStart = 50;
                    hardLimitEnd = 300;
                };
            };
        };
    };
    class GVAR(CUP_LED_flashlight): cup_acc_flashlight {
        author = "Potato";
        scope = 2;
        displayName = "Tactical LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: White Light. Ctrl+L to change Mode";
        descriptionShort = "Mode: White Light. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(CUP_LED_flashlight_Flood);
        MRT_SwitchItemPrevClass = QGVAR(CUP_LED_flashlight_Beam);
        MRT_switchItemHintText = "Standard Spread";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 6;
            RMBhint = "LED Flashlight";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                coneFadeCoef = 10;
                dayLight = 1;
                direction = "flash";
                flareMaxDistance = 300;
                flareSize = 4;
                innerAngle = 10;
                intensity = 3000;
                outerAngle = 80;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                useFlare = 1;
                class Attenuation {
                    constant = 32;
                    hardLimitEnd = 155;
                    hardLimitStart = 25;
                    linear = 1;
                    quadratic = 0.050000001;
                    start = 0;
                };
            };
        };
    };
    class GVAR(CUP_LED_flashlight_Flood): cup_acc_flashlight {
        author = "Potato";
        scope = 1;
        displayName = "Tactical LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: White Floodlight. Ctrl+L to change Mode";
        descriptionShort = "Mode: White Floodlight. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(CUP_LED_flashlight_Beam);
        MRT_SwitchItemPrevClass = QGVAR(CUP_LED_flashlight);
        MRT_switchItemHintText = "White Flood";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 6;
            RMBhint = "LED Flashlight (Wide)";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                coneFadeCoef = 11;
                dayLight = 1;
                direction = "flash";
                flareMaxDistance = 300;
                flareSize = 4;
                innerAngle = 35;
                intensity = 2000;
                outerAngle = 140;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                useFlare = 1;
                class Attenuation {
                    constant = 32;
                    hardLimitEnd = 100;
                    hardLimitStart = 1;
                    linear = 1;
                    quadratic = 0.2;
                    start = 0;
                };
            };
        };
    };
    
    
//////////////////////////////////////////////////
//////A3 Vanilla Handgun Multimode Flashlight//////
//////////////////////////////////////////////////    
    
    class GVAR(Vanilla_HG_LED_flashlight_Beam): acc_flashlight_pistol {
        author = "Potato";
        scope = 1;
        displayName = "Tactical Handgun LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: Focused White Beam. Ctrl+L to change Mode";
        descriptionShort = "Mode: Focused White Beam. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(Vanilla_HG_LED_flashlight);
        MRT_SwitchItemPrevClass = QGVAR(Vanilla_HG_LED_flashlight_Flood);
        MRT_switchItemHintText = "Focused White Beam";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 3;
            RMBhint = "LED Flashlight (Beam)";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                dayLight = 1;
                useFlare = 1;
                direction = "flash";
                flareMaxDistance = 554;
                flareSize = 4;
                innerAngle = 8;    
                outerAngle = 14;
                coneFadeCoef = 4;
                intensity = 400;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 100;
                    constant = 100;
                    linear = 60;
                    quadratic = 20;
                    hardLimitStart = 50;
                    hardLimitEnd = 300;
                };
            };
        };
    };
    class GVAR(Vanilla_HG_LED_flashlight): acc_flashlight_pistol {
        author = "Potato";
        scope = 2;
        displayName = "Tactical Handgun LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: White Light. Ctrl+L to change Mode";
        descriptionShort = "Mode: White Light. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(Vanilla_HG_LED_flashlight_Flood);
        MRT_SwitchItemPrevClass = QGVAR(Vanilla_HG_LED_flashlight_Beam);
        MRT_switchItemHintText = "Standard Spread";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 3;
            RMBhint = "LED Flashlight";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                coneFadeCoef = 10;
                dayLight = 1;
                direction = "flash";
                flareMaxDistance = 300;
                flareSize = 4;
                innerAngle = 10;
                intensity = 3000;
                outerAngle = 80;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                useFlare = 1;
                class Attenuation {
                    constant = 32;
                    hardLimitEnd = 155;
                    hardLimitStart = 25;
                    linear = 1;
                    quadratic = 0.050000001;
                    start = 0;
                };
            };
        };
    };
    class GVAR(Vanilla_HG_LED_flashlight_Flood): acc_flashlight_pistol {
        author = "Potato";
        scope = 1;
        displayName = "Tactical Handgun LED Flashlight (Multi-Mode)";
        descriptionUse = "Mode: White Floodlight. Ctrl+L to change Mode";
        descriptionShort = "Mode: White Floodlight. Ctrl+L to change Mode";
        MRT_SwitchItemNextClass = QGVAR(Vanilla_HG_LED_flashlight_Beam);
        MRT_SwitchItemPrevClass = QGVAR(Vanilla_HG_LED_flashlight);
        MRT_switchItemHintText = "White Flood";
        class ItemInfo: InventoryFlashLightItem_Base_F {
            mass = 3;
            RMBhint = "LED Flashlight (Wide)";
            class FlashLight {
                ambient[] = {0.58431,0.72940999,0.81568998};
                color[] = {149,186,208};
                coneFadeCoef = 11;
                dayLight = 1;
                direction = "flash";
                flareMaxDistance = 300;
                flareSize = 4;
                innerAngle = 35;
                intensity = 2000;
                outerAngle = 140;
                position = "flash dir";
                scale[] = {0};
                size = 1;
                useFlare = 1;
                class Attenuation {
                    constant = 32;
                    hardLimitEnd = 100;
                    hardLimitStart = 1;
                    linear = 1;
                    quadratic = 0.2;
                    start = 0;
                };
            };
        };
    };        
};

//////////////////////////////
//////////////RAILS///////////
//////////////////////////////


class asdg_SlotInfo;
class asdg_FrontSideRail: asdg_SlotInfo {
    class compatibleItems {
        GVAR(CUP_LED_flashlight_Flood) = 1;
        GVAR(CUP_LED_flashlight_Beam) = 1;
        GVAR(CUP_LED_flashlight) = 1;
    };
};
class PointerSlot;
class PointerSlot_Rail: PointerSlot {
    class compatibleItems {
        GVAR(CUP_LED_flashlight_Flood) = 1;
        GVAR(CUP_LED_flashlight_Beam) = 1;
        GVAR(CUP_LED_flashlight) = 1;
    };
};
class asdg_PistolUnderRail: asdg_SlotInfo {
    class compatibleItems {
        GVAR(Vanilla_HG_LED_flashlight_Flood) = 1;
        GVAR(Vanilla_HG_LED_flashlight_Beam) = 1;
        GVAR(Vanilla_HG_LED_flashlight) = 1;
    }
};