class ace_arsenal_stats {
    class statBase {};
    class GVAR(recoil): statBase {
        scope = 2;
        priority = -1;
        stats[] = {"recoil"};
        displayName = "Recoil";
        showBar = 1;
        showText = 1;
        barStatement = QUOTE([ARR_2(0, _this)] call FUNC(statRecoil));
        textStatement = QUOTE([ARR_2(1, _this)] call FUNC(statRecoil));
        tabs[] = {{0,1}, {}};
    };
};
