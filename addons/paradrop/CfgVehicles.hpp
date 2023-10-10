class CfgVehicles {
	class Logic;
	class Module_F: Logic {};

	class GVAR(ingress): Module_F {
		author = QUOTE(PREFIX);
        displayName = "Ingress Point";
        category = QGVAR(faction);
		scope = 2;
        scopeCurator = 0;
        isTriggerActivated = 0;
        isGlobal = 0;
        function = QFUNC(placeIngress);
        curatorCost = 0;
        class Arguments {};
        class Attributes {
            class GVAR(runAfterSafeStart) {
                displayName = "Run After Safe-Start";
                tooltip = "Whether or not planes will start moving towards the ingress when safe-start turns off";
                property = QGVAR(runAfterSafeStart);
                control = "Checkbox";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = 0;
            };
            class GVAR(flyInHeight) {
				displayName = "Fly in height";
                tooltip = "How high the planes will drop from";
                property = QGVAR(flyInHeight);
                control = "Edit";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = "'150'";
            };
			class GVAR(dropDelay) {
                displayName = "Drop Delay";
                tooltip = "How long between drops";
                property = QGVAR(dropDelay);
                control = "Edit";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = "'0.3'";
            };
			class GVAR(infantryParachuteType) {
                displayName = "Infantry Parachute Type";
                tooltip = "Classname of parachute to deploy on units";
                property = QGVAR(infantryParachuteType);
                control = "Edit";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = "'Steerable_Parachute_F'";
            };
            class GVAR(cargoParachuteType) {
                displayName = "Cargo Parachute Type";
                tooltip = "Classname of parachute to deploy on cargo";
                property = QGVAR(cargoParachuteType);
                control = "Edit";
                expression = "_this setVariable ['%s', _value, true];";
                defaultValue = "'B_Parachute_02_F'";
            };
        };
	};

	class GVAR(dz): Module_F {
		author = QUOTE(PREFIX);
        displayName = "Drop Zone";
        category = QGVAR(faction);
		scope = 2;
        scopeCurator = 0;
        isTriggerActivated = 0;
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
	};

	class GVAR(exit): Module_F {
		author = QUOTE(PREFIX);
        displayName = "Egress Point";
        category = QGVAR(faction);
		scope = 2;
        scopeCurator = 0;
        isTriggerActivated = 0;
        isGlobal = 0;
        curatorCost = 0;
        class Arguments {};
        class Attributes {};
	};
};