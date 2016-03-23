//Code EH:
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
class Extended_PostInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE( call COMPILE_FILE(XEH_postInit) );
    };
};


//Vehicle EH:
class Extended_InitPost_EventHandlers {
    class GVAR(mortar) {
        class ADDON {
            init = QUOTE(_this call FUNC(handleInit));
        };
    };
};
class Extended_GetOut_EventHandlers {
    class GVAR(mortar) {
        class ADDON {
            serverGetOut = QUOTE(_this call FUNC(handleGetOut));
        };
    };
};
class Extended_FiredBIS_EventHandlers {
    class GVAR(mortar) {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(handleFired));
        };
    };
};
