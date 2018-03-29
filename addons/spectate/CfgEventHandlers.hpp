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
        clientInit = QUOTE(call COMPILE_FILE(XEH_postClientInit));
        serverInit = QUOTE(call COMPILE_FILE(XEH_postServerInit));
    };
};

class Extended_DisplayUnload_EventHandlers {
    class RscDisplayCurator {
        ADDON = QUOTE(_this spawn FUNC(checkToReopen));
    };
};

class Extended_InitPost_EventHandlers {
    class GVAR(holder) {
        class ADDON { init = QUOTE( [ARR_2(_this select 0, true)] remoteExecCall ['hideObjectGlobal', SERVER_CLIENT_ID]; ); };
    };
    class GVAR(playableSpectator) {
        class ADDON { init = QUOTE( if (player == (_this select 0)) then { [ARR_3({time > 0}, FUNC(setup), [_this select 0])] call CBA_fnc_waitUntilAndExecute; }; ); };
    };
};
