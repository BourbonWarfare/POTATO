//Code EH:
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
        clientInit = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};


//Vehicle EH:
class Extended_FiredBIS_EventHandlers {
    class GVAR(mortar) {
        class ADDON {
            firedBIS = QUOTE(_this call FUNC(handleFired));
        };
    };
};
