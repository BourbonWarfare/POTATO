class CfgWeapons {
    class InventoryFlashLightItem_Base_F;


    class ItemCore;
    class CUP_acc_Flashlight: ItemCore { //CUP Flashlight -surefire
        class ItemInfo;
    };
    class ACE_acc_pointer_green;
    class acc_flashlight_pistol;

/////////////////////////////////////////
//////////Multimode Flashlight///////////
/////////////////////////////////////////
    class GVAR(CUP_LED_flashlight_Beam): CUP_acc_Flashlight {
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
                position = "flash dir";
            };
        };
    };
    class GVAR(CUP_LED_flashlight): CUP_acc_Flashlight {
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
    class GVAR(CUP_LED_flashlight_Flood): CUP_acc_Flashlight {
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

//////////////////////////////////////////////////
//////Medium A3 Vanilla Multimode Flashlight//////
//////////////////////////////////////////////////
    class GVAR(acc_cup_Flashlight_Dummy): CUP_acc_Flashlight {
        scope = 0;
        class ItemInfo: ItemInfo {
            class FlashLight;
        };
    };
    class GVAR(acc_cup_Flashlight_02_Spot): GVAR(acc_cup_Flashlight_Dummy) {
        scope = 1;
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_02_Wide);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_02);
        MRT_switchItemHintText = "Flashlight (Spot, Bright White)";
        baseWeapon = QGVAR(acc_Flashlight_02);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "White";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                innerAngle = 3;
                outerAngle = 5;
                coneFadeCoef = 6;
                useFlare = 1;
                dayLight = 0;
                flareMaxDistance = 250;
                flareSize = 2;
                intensity = 120;
                class Attenuation {
                    hardLimitStart = 225;
                    hardLimitEnd = 300;
                    start = 1;
                    constant = 1;
                    linear = 0;
                    quadratic = 0.01;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_02): GVAR(acc_cup_Flashlight_Dummy) {
        scope = 2;
        displayName="Flashlight (Multimode, Bright White)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_02_Spot);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_02_Wide);
        MRT_switchItemHintText = "Flashlight";
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "White";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                innerAngle = 5;
                outerAngle = 40;
                useFlare = 1;
                dayLight = 0;
                flareMaxDistance = 80;
                flareSize = 1.4;
                intensity = 80;
                class Attenuation {
                    hardLimitStart = 150;
                    hardLimitEnd = 225;
                    start = 0;
                    constant = 1;
                    linear = 0;
                    quadratic = 0.03;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_02_Wide): GVAR(acc_cup_Flashlight_Dummy) {
        scope = 1;
        displayName="Flashlight (Wide, Bright White)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_02);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_02_Spot);
        MRT_switchItemHintText = "Flashlight (Flood)";
        baseWeapon = QGVAR(acc_cup_Flashlight_02);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_beam_white_ca.paa";
                ACE_Flashlight_Colour = "White";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                useFlare = 1;
                dayLight = 0;
                flareMaxDistance = 60;
                flareSize = 1;
                intensity = 50;
                class Attenuation {
                    hardLimitStart = 40;
                    hardLimitEnd = 125;
                    start = 0;
                    constant = 0.1;
                    linear = 0.1;
                    quadratic = 0.05;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_03_Spot): GVAR(acc_cup_Flashlight_02_Spot) {
        displayName="Flashlight (Spot, Yellow)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_03_Wide);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_03);
        MRT_switchItemHintText = "Flashlight (Spot, Yellow)";
        baseWeapon = QGVAR(acc_cup_Flashlight_03);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_yellow_ca.paa";
                ACE_Flashlight_Colour = "Yellow";
                ACE_Flashlight_Size = 1;
                innerAngle = 3;
                outerAngle = 5;
                coneFadeCoef = 6;
                useFlare = 1;
                flareMaxDistance = 200;
                flareSize = 2;
                intensity = 80;
                ambient[] = {0.84, 0.86, 0.11};
                color[] = {191, 196, 26};
                class Attenuation: Attenuation {
                    hardLimitStart = 80;
                    hardLimitEnd = 200;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_03): GVAR(acc_cup_Flashlight_02) {
        displayName="Flashlight (Multimode, Yellow)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_03_Spot);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_03_Wide);
        MRT_switchItemHintText = "Flashlight (Yellow)";
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_yellow_ca.paa";
                ACE_Flashlight_Colour = "Yellow";
                ACE_Flashlight_Size = 1;
                innerAngle = 5;
                outerAngle = 40;
                useFlare = 1;
                flareMaxDistance = 40;
                flareSize = 0.7;
                intensity = 40;
                ambient[] = {0.84, 0.86, 0.11};
                color[] = {191, 196, 26};
                volumeShape = "";
                class Attenuation: Attenuation {
                    hardLimitStart = 50;
                    hardLimitEnd = 100;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_03_Wide): GVAR(acc_cup_Flashlight_02_Wide) {
        displayName="Flashlight (Flood, Yellow)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_03);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_03_Spot);
        MRT_switchItemHintText = "Flashlight (Flood, Yellow)";
        baseWeapon = QGVAR(acc_cup_Flashlight_03);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_yellow_ca.paa";
                ACE_Flashlight_Colour = "Yellow";
                ACE_Flashlight_Size = 1;
                useFlare = 1;
                flareMaxDistance = 40;
                flareSize = 0.25;
                intensity = 20;
                ambient[] = {0.84, 0.86, 0.11};
                color[] = {191, 196, 26};
                volumeShape = "";
                class Attenuation: Attenuation {
                    hardLimitStart = 30;
                    hardLimitEnd = 80;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_04_Spot): GVAR(acc_cup_Flashlight_02_Spot) {
        displayName="Flashlight (Spot, Red)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_04_Wide);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_04);
        MRT_switchItemHintText = "Flashlight (Spot, Red)";
        baseWeapon = QGVAR(acc_cup_Flashlight_04);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_red_ca.paa";
                ACE_Flashlight_Colour = "Red";
                ACE_Flashlight_Size = 1;
                innerAngle = 3;
                outerAngle = 5;
                coneFadeCoef = 6;
                useFlare = 1;
                flareMaxDistance = 200;
                flareSize = 2;
                intensity = 80;
                ambient[] = {0.4, 0.05, 0.05};
                color[] = {242, 10, 5};
                class Attenuation: Attenuation {
                    hardLimitStart = 80;
                    hardLimitEnd = 200;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_04): GVAR(acc_cup_Flashlight_02) {
        displayName="Flashlight (Multimode, Red)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_04_Spot);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_04_Wide);
        MRT_switchItemHintText = "Flashlight (Red)";
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_red_ca.paa";
                ACE_Flashlight_Colour = "Red";
                ACE_Flashlight_Size = 1;
                innerAngle = 5;
                outerAngle = 40;
                useFlare = 0;
                flareMaxDistance = 80;
                flareSize = 1.4;
                intensity = 40;
                ambient[] = {0.4, 0.05, 0.05};
                color[] = {242, 10, 5};
                volumeShape = "";
                class Attenuation: Attenuation {
                    hardLimitStart = 50;
                    hardLimitEnd = 100;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_04_Wide): GVAR(acc_cup_Flashlight_02_Wide) {
        displayName="Flashlight (Flood, White)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_04);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_04_Spot);
        MRT_switchItemHintText = "Flashlight (Flood, Red)";
        baseWeapon = QGVAR(acc_cup_Flashlight_04);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Beam = "\z\ace\addons\flashlights\UI\Flashlight_Beam_red_ca.paa";
                ACE_Flashlight_Colour = "Red";
                ACE_Flashlight_Size = 2.75;
                ACE_Flashlight_Sound = 1;
                useFlare = 0;
                flareMaxDistance = 60;
                flareSize = 1;
                intensity = 20;
                ambient[] = {0.4, 0.05, 0.05};
                color[] = {242, 10, 5};
                volumeShape = "";
                class Attenuation: Attenuation {
                    hardLimitStart = 30;
                    hardLimitEnd = 80;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_05_Spot): GVAR(acc_cup_Flashlight_02_Spot) {
        displayName="Flashlight (White, Red)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_05_Wide);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_05);
        MRT_switchItemHintText = "Flashlight (White, Red)";
        baseWeapon = QGVAR(acc_cup_Flashlight_05);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Size = 1;
                innerAngle = 3;
                outerAngle = 5;
                coneFadeCoef = 6;
                useFlare = 1;
                flareMaxDistance = 160;
                flareSize = 2;
                intensity = 80;
                class Attenuation: Attenuation {
                    hardLimitStart = 80;
                    hardLimitEnd = 200;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_05): GVAR(acc_cup_Flashlight_02) {
        displayName="Flashlight (Multimode, White)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_05_Spot);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_05_Wide);
        MRT_switchItemHintText = "Flashlight (White)";
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Size = 1;
                innerAngle = 5;
                outerAngle = 40;
                useFlare = 1;
                flareMaxDistance = 80;
                flareSize = 1.4;
                intensity = 40;
                class Attenuation: Attenuation {
                    hardLimitStart = 50;
                    hardLimitEnd = 100;
                };
            };
        };
    };
    class GVAR(acc_cup_Flashlight_05_Wide): GVAR(acc_cup_Flashlight_02_Wide) {
        displayName="Flashlight (Flood, White)";
        MRT_SwitchItemNextClass = QGVAR(acc_cup_Flashlight_05);
        MRT_SwitchItemPrevClass = QGVAR(acc_cup_Flashlight_05_Spot);
        MRT_switchItemHintText = "Flashlight (Flood, White)";
        baseWeapon = QGVAR(acc_cup_Flashlight_05);
        class ItemInfo: ItemInfo {
            class FlashLight: FlashLight {
                ACE_Flashlight_Size = 1;
                useFlare = 1;
                flareMaxDistance = 60;
                flareSize = 1;
                intensity = 20;
                volumeShape = "";
                class Attenuation: Attenuation {
                    hardLimitStart = 30;
                    hardLimitEnd = 80;
                };
            };
        };
    };
};

//////////////////////////////
//////////////RAILS///////////
//////////////////////////////
#define ACC_FLASHLIGHT_TRIPLET_LMD(var1) DOUBLES(GVAR(acc_cup_Flashlight),var1) = 1;\
TRIPLES(GVAR(acc_cup_Flashlight),var1,Wide) = 1;\
TRIPLES(GVAR(acc_cup_Flashlight),var1,Spot) = 1

class SlotInfo;
class asdg_SlotInfo;
class asdg_FrontSideRail: asdg_SlotInfo {
    class compatibleItems {
        GVAR(CUP_LED_flashlight_Flood) = 1;
        GVAR(CUP_LED_flashlight_Beam) = 1;
        GVAR(CUP_LED_flashlight) = 1;
        ACC_FLASHLIGHT_TRIPLET_LMD(02);
        ACC_FLASHLIGHT_TRIPLET_LMD(03);
        ACC_FLASHLIGHT_TRIPLET_LMD(04);
        ACC_FLASHLIGHT_TRIPLET_LMD(05);
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
        ACC_FLASHLIGHT_TRIPLET_LMD(02);
        ACC_FLASHLIGHT_TRIPLET_LMD(03);
        ACC_FLASHLIGHT_TRIPLET_LMD(04);
        ACC_FLASHLIGHT_TRIPLET_LMD(05);
	};
};