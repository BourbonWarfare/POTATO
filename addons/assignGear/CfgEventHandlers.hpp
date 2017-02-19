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


class Extended_Init_EventHandlers {
    class CAManBase {
        class ADDON { serverInit = QUOTE(_this call FUNC(assignGearMan)); };
    };
    class Car {
        class ADDON { serverInit  = QUOTE([ARR_2((_this select 0), 'Car')] call FUNC(assignGearVehicle);); };
    };
    class Tank {
        class ADDON { serverInit  = QUOTE([ARR_2((_this select 0), 'Tank')] call FUNC(assignGearVehicle);); };
    };
    class Helicopter {
        class ADDON { serverInit  = QUOTE([ARR_2((_this select 0), 'Helicopter')] call FUNC(assignGearVehicle);); };
    };
    class Plane {
        class ADDON { serverInit  = QUOTE([ARR_2((_this select 0), 'Plane')] call FUNC(assignGearVehicle);); };
    };
    class Ship_F {
        class ADDON { serverInit  = QUOTE([ARR_2((_this select 0), 'Ship_F')] call FUNC(assignGearVehicle);); };
    };
};
