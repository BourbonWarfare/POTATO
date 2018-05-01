class CfgVehicles {
    class All;
    class AllVehicles: All {
    };
    class Air: AllVehicles {
    };
    class Helicopter: Air {
        audible = 10;
    };
    class Plane: Air {
        audible = 10;
    };
    class ParachuteBase: Helicopter {
    };
    class Helicopter_Base_F: Helicopter {
    };
    class ParachuteWest: ParachuteBase {
    };
    class Paraglide: ParachuteWest {
    };
    class Steerable_Parachute_F: Paraglide {
    };
    class CUP_T10_Parachute: Steerable_Parachute_F {
    };
    class Plane_Base_F: Plane {
    };
    class UAV: Plane {
    };
    class CUP_DC3_Base: Plane_Base_F {
    };
    class Plane_CAS_01_base_F: Plane_Base_F {
    };
    class rhs_mig29s_base: Plane_Base_F {
    };
    class Plane_Fighter_03_base_F: Plane_Base_F {
    };
    class Helicopter_Base_H: Helicopter_Base_F {
    };
    class UAV_06_base_F: Helicopter_Base_F {
    };
    class Heli_Attack_02_base_F: Helicopter_Base_F {
    };
    class UAV_01_base_F: Helicopter_Base_F {
    };
    class CUP_AH6_BASE: Helicopter_Base_H {
    };
    class Heli_Light_02_base_F: Helicopter_Base_H {
    };
    class CUP_B_AH6X_USA: CUP_AH6_BASE {
    };
    class RHS_A10: Plane_CAS_01_base_F {
    };
    class rhs_mi28_base: Heli_Attack_02_base_F {
    };
    class RHS_Mi24_base: Heli_Attack_02_base_F {
    };
    class UAV_02_base_F: UAV {
    };
    class rhs_pchela1t_base: UAV_02_base_F {
    };
    class RHS_Mi8_base: Heli_Light_02_base_F {
    };
    class rhsusf_f22: Plane_Fighter_03_base_F {
    };
};

