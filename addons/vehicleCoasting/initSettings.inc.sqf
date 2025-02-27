[
    QGVAR(chance), "SLIDER",
    ["Enable vehicle coasting chance", "Vehicles will continue to drive after the driver dies or goes unconscious instead of immediately stopping\nRecomended is 40%"],
    ["POTATO - Mission Maker", "Vehicle Coasting"],
    [0,1,0,1,true], // [min, max, default value, trailing decimals (-1 for whole numbers only), isPercentage]
    true, {}, true
] call CBA_fnc_addSetting;
