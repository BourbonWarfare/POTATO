class Extended_PreInit_EventHandlers {
    class ADDON {
        serverinit = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        serverinit = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};
