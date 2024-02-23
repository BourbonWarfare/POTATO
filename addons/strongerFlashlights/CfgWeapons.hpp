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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 400;
                direction = "flash";
                flareMaxDistance = 554;
                flareSize = 4;
                innerAngle = 8;
                outerAngle = 14;
                coneFadeCoef = 4;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 155;
                    constant = 205;
                    linear = 1;
                    quadratic = 0.2;
                    hardLimitStart = 50;
                    hardLimitEnd = 300;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 554;
                position = "flash dir";
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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 3000;
                direction = "flash";
                innerAngle = 10;
                outerAngle = 60;
                coneFadeCoef = 10;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 0;
                    constant = 32;
                    linear = 1;
                    quadratic = 0.050000001;
                    hardLimitStart = 25;
                    hardLimitEnd = 125;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 300;
                position = "flash dir";
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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 2000;
                direction = "flash";
                innerAngle = 35;
                outerAngle = 150;
                coneFadeCoef = 11;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 0;
                    constant = 32;
                    linear = 1;
                    quadratic = 0.2;
                    hardLimitStart = 1;
                    hardLimitEnd = 100;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 300;
                position = "flash dir";
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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 400;
                direction = "flash";
                flareMaxDistance = 554;
                flareSize = 4;
                innerAngle = 8;
                outerAngle = 14;
                coneFadeCoef = 4;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 155;
                    constant = 205;
                    linear = 60;
                    quadratic = 0.2;
                    hardLimitStart = 50;
                    hardLimitEnd = 300;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 554;
                position = "flash dir";
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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 3000;
                direction = "flash";
                innerAngle = 10;
                outerAngle = 60;
                coneFadeCoef = 10;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 0;
                    constant = 32;
                    linear = 1;
                    quadratic = 0.050000001;
                    hardLimitStart = 25;
                    hardLimitEnd = 125;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 300;
                position = "flash dir";
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
                color[] = {149,186,208};
                ambient[] = {0.58431,0.72940999,0.81568998};
                intensity = 2000;
                direction = "flash";
                innerAngle = 35;
                outerAngle = 150;
                coneFadeCoef = 11;
                scale[] = {0};
                size = 1;
                class Attenuation {
                    start = 0;
                    constant = 32;
                    linear = 1;
                    quadratic = 0.2;
                    hardLimitStart = 1;
                    hardLimitEnd = 100;
                };
                dayLight = 1;
                useFlare = 1;
                flareSize = 4;
                flareMaxDistance = 300;
                position = "flash dir";
            };
        };
    };
};

//////////////////////////////
//////////////RAILS///////////
//////////////////////////////

class SlotInfo;
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
    };
};
class rhs_russian_ak_barrel_slot: SlotInfo {
	class compatibleItems {
		rhs_acc_2dpZenit = 1;
		rhs_acc_perst1ik = 1;
        GVAR(CUP_LED_flashlight_Flood) = 1;
        GVAR(CUP_LED_flashlight_Beam) = 1;
        GVAR(CUP_LED_flashlight) = 1;
	};
};