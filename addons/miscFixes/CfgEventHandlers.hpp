class Extended_PreInit_EventHandlers {
    class ADDON {
        clientInit = QUOTE(call COMPILE_FILE(XEH_fixEnumError));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_kilTracker));
        serverInit = QUOTE(call COMPILE_FILE(XEH_serverPostInit));
    };
};
