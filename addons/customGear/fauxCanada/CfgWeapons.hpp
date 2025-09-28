class CfgWeapons {
    // Make a C6-ish gun
    class CUP_Vlmg_M240_veh;
    class GVARMAIN(Vlmg_C6A1_veh): CUP_Vlmg_M240_veh {
        displayName = "C6A1 GPMG";
        selectionFireAnim = "muzzleflash";
        memoryPointCamera = "eye_pos";
        shotEnd = "konec hlavne";
        shotPos = "usti hlavne";
        cartridgePos = "cartridge_pos";
        cartridgeVel = "cartridge_dir";
        class gunParticles {
            class effect1 {
                positionName = "MachineGunTurret_01_Gun_dir";
                directionName = "MachineGunTurret_01_Gun_pos";
                effectName = "RifleAssaultCloud";
            };
            class effect2 {
                positionName = "MachineGunTurret_01_Cartridge_pos";
                directionName = "MachineGunTurret_01_Cartridge_dir";
                effectName = "MachineGunCartridge1";
            };
            class effect3 {
                positionName = "MachineGunTurret_01_link_pos";
                directionName = "MachineGunTurret_01_link_dir";
                effectName = "MachineGunEject";
            };
        };
    };
    class CUP_Vlmg_L7A2_veh;
    class GVARMAIN(Vlmg_C6A1_veh_coax): CUP_Vlmg_L7A2_veh {
        displayName = "C6A1 GPMG";
        selectionFireAnim = "muzzleflash";
        memoryPointCamera = "eye_pos";
        shotEnd = "konec hlavne";
        shotPos = "usti hlavne";
        cartridgePos = "cartridge_pos";
        cartridgeVel = "cartridge_dir";
        class gunParticles {}; // kill gun particles, just use leopard animation
    };
    //// C5 GPMG
    class vn_m1919_v_01;
    class GVARMAIN(c5_gpmg_static_base): vn_m1919_v_01 {
        scope = 1;
        class AImode1;
        class AImode2;
        class AImode3;
        class AImode4;
        class AImode5;
        class AImode6;
        class FullAuto;
    };
    class GVARMAIN(c5_gpmg_static): GVARMAIN(c5_gpmg_static_base) {
        descriptionShort = "C5 7.62x51 GPMG";
        displayName = "C5 GPMG";
        magazines[] = {
            QGVARMAIN(250Rnd_TE3_Red_Tracer_762x51_C5_M),
            QGVARMAIN(300Rnd_TE3_Red_Tracer_762x51_C5_M)
        };
        magazineWell[] = {"CBA_762x51_LINKS", "M240_762x51"};
        scope = 2;
        class AImode1: AImode1 {
            reloadTime = 0.1;
        };
        class AImode2: AImode2 {
            reloadTime = 0.1;
        };
        class AImode3: AImode3 {
            reloadTime = 0.1;
        };
        class AImode4: AImode4 {
            reloadTime = 0.1;
        };
        class AImode5: AImode5 {
            reloadTime = 0.1;
        };
        class AImode6: AImode6 {
            reloadTime = 0.1;
        };
        class FullAuto: FullAuto {
            displayName = "C5 GPMG";
            reloadTime = 0.1;
        };
        // getting rid of ejection particles and changing cartridges
        class GunParticles {
            class effect1 {
                directionName = "mg1_konec_hlavne";
                effectName = "vn_MachineGun_MuzzleSmoke";
                positionName = "mg1_usti_hlavne";
            };
            class effect2 {
                directionName = "mg1_machinegun_eject_dir";
                effectName = "MachineGunEject1";
                positionName = "mg1_machinegun_eject_pos";
            };
            class effect3 {
                directionName = "mg1_linkeject_end";
                effectName = "vn_machineguneject2";
                positionName = "mg1_linkeject_start";
            };
        };
    };
    // CSW C5 GPMG
    class ACEGVAR(compat_sog,m1919a4_carry);
    class GVARMAIN(c5_carry): ACEGVAR(compat_sog,m1919a4_carry) {
        dlc = "Potato";
        displayName = "[CSW] C5 Gun Bag";
        author = "Bourbone Warfare";
        scope = 2;
        class ace_csw {
            type = "weapon";
            deployTime = 4;
            pickupTime = 4;

            class assembleTo {
                ACEGVAR(csw,m3Tripod) = QGVARMAIN(ca_army_c5_high);
                ACEGVAR(csw,m3TripodLow) = QGVARMAIN(ca_army_c5_low);
            };
        };
    };
};
