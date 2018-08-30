class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_Init_EventHandlers {
    class Tank {
        GVAR(add_tank_hd) = QUOTE(call potato_aiVehicleBail_addEventHandler_tank);
    };
    class Wheeled_APC_F {
        GVAR(add_apc_hd) = QUOTE(call potato_aiVehicleBail_addEventHandler_apc);
    };
};

