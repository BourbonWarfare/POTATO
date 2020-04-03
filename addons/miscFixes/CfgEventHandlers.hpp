class Extended_PreInit_EventHandlers {
    class GVAR(crewTraining) {
        init = QUOTE(call COMPILE_FILE(XEH_crewTraining));
    };
};
class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_kilTracker));
        serverInit = QUOTE(call COMPILE_FILE(XEH_serverPostInit));
    };
};
