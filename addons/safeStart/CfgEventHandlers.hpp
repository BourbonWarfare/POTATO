class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};

class Extended_FiredBIS_EventHandlers {
    class AllVehicles {
        class ADDON {
            firedBIS = QUOTE(if (GVAR(safeStartEnabled)) then {_this call DFUNC(handleFired)});
        };
    };
};
