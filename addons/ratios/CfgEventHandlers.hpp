class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(_this spawn COMPILE_SCRIPT(functions\fnc_displayLoad));
    };
};
class Extended_DisplayUnload_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(call COMPILE_SCRIPT(functions\fnc_displayUnload));
    };
};
