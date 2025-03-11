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
        clientInit = QUOTE(call COMPILE_SCRIPT(XEH_postClientInit));
        serverInit = QUOTE(call COMPILE_SCRIPT(XEH_postServerInit));
    };
};

class Extended_DisplayUnload_EventHandlers {
    class RscDisplayCurator {
        ADDON = QUOTE(_this spawn FUNC(checkToReopen));
    };
};

class Extended_InitPost_EventHandlers {
    class GVAR(playableSpectator) {
        class ADDON { init = QUOTE(call FUNC(initSpectatorUnit);); };
    };
};
