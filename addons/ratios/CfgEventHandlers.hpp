class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(_this spawn COMPILE_FILE(functions\fnc_displayLoad));
    };
};
class Extended_DisplayUnload_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(_this call COMPILE_FILE(functions\fnc_displayUnload));
    };
};
