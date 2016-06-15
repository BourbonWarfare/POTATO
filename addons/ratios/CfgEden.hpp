class ctrlMenuStrip;
class ctrlEdit;
class ctrlXSliderH;

class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                class PREFIX {
                    items[] += {QGVAR(ratio)};
                };
                class GVAR(ratio) {
                    text = "Set Player Ratios";
                    action = QUOTE(edit3DENMissionAttributes QUOTE(QGVAR(ratio)););
                };
            };
        };
    };
};

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class Slider: Title {
            class Controls: Controls {
                class Value: ctrlXSliderH {};
                class Edit: ctrlEdit {};
            };
        };
        class SliderMultiplier: Slider {};
        class GVAR(ratioSlider): SliderMultiplier {
            class Controls: Controls {
                class Title: Title {};
                class Value: Value {
                    sliderRange[] = {0,10};
                };
                class Edit: Edit {};
            };
        };
    };

    class Mission {
        class GVAR(ratio) {// Custom section class, everything inside will be opened in one window
            displayName = "Side Ratios"; // Text visible in the window title as "Edit <displayName>"
            display = "Display3DENEditAttributes"; // Optional - display for attributes window. Must have the same structure and IDCs as the default Display3DENEditAttributes
            class AttributeCategories {
                class Ratios {
                    displayName = "Slotting Ratios:"; // Category name visible in Edit Attributes window
                    collapsed = 0; // When 1, the category is collapsed by default
                    class Attributes {
                        class GVAR(westRatio) {
                            displayName = "West Ratio";
                            tooltip = "";
                            property = QGVAR(westRatio);
                            control = QGVAR(ratioSlider);
                            defaultValue = "1";
                            typeName="NUMBER";
                            wikiType="[[Number]]";
                        };
                        class GVAR(eastRatio): GVAR(westRatio) {
                            displayName = "East Ratio"; // Name assigned to UI control class Title
                            property = QGVAR(eastRatio); // Unique config property name saved in SQM
                        };
                        class GVAR(indpRatio): GVAR(westRatio) {
                            displayName = "Indpendent Ratio"; // Name assigned to UI control class Title
                            property = QGVAR(indpRatio); // Unique config property name saved in SQM
                        };
                        class GVAR(civRatio): GVAR(westRatio) {
                            displayName = "Civ Ratio"; // Name assigned to UI control class Title
                            property = QGVAR(civRatio); // Unique config property name saved in SQM
                            defaultValue = "0";
                        };
                    };
                };
            };
        };
    };
};
