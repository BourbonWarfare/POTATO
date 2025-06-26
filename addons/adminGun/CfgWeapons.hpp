class CfgWeapons {
	class hgun_P07_F;
	class GVAR(gun): hgun_P07_F {
		magazines[] = { QGVAR(physics) };
		magazineWell[] = {};
		displayname = "Admin Gun";
		descriptionShort = "Super Secret Admin Hacks (dont tell anyone!!)";
		scopeArsenal = 2;

		class EventHandlers {
			fired = QUOTE(call FUNC(onFired));
		};
	};
};
