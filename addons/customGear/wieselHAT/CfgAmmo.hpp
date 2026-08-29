class cfgAmmo {
	class M_120mm_cannon_ATGM_LG;
	class potato_M_120mm_cannon_ATGM_LG: M_120mm_cannon_ATGM_LG {
		flightProfiles[] = {"TopDown", "Direct"};
		class TopDown {
			ascendHeight=250;
			descendDistance=400;
			minDistance=400;
			ascendAngle=25;
		};
		class Direct {};
		manualControl = 1;
	};
};
