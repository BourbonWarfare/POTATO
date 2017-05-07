class CfgFunctions {
    class A3 {
        tag = "BIS";
        project = QUOTE(ADDON);
        class Debug {
            class isDebugConsoleAllowed {
                file = QPATHTOF(functions\DOUBLES(fnc,isDebugConsoleAllowed).sqf);
                recompile = 1;
            };
        };
    };
};
