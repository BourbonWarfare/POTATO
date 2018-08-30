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
        class GVAR(add_tank_hd) {
            init = QUOTE(call LINKFUNC(addEventHandler_tank));
        };
    };
    class Wheeled_APC_F {
        class GVAR(add_apc_hd) {
            init = QUOTE(call LINKFUNC(addEventHandler_apc));
        };
    };
};

