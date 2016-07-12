class ctrlToolbox;

class Cfg3DEN {
    class Attributes {
        class Default;
        class Title: Default {
            class Controls {
                class Title;
            };
        };
        class GVAR(fireTeamControl): Title {
            attributeLoad = "(_this controlsGroupCtrl 100) lbsetcursel (['MAIN','RED','GREEN','BLUE','YELLOW'] find (toUpper _value));";
            attributeSave = "['MAIN','RED','GREEN','BLUE','YELLOW'] select (missionnamespace getvariable ['potato_teamColors_temp',0])";
            class Controls: Controls {
                class Title: Title{};
                class Value: ctrlToolbox {
                    idc = 100;
                    style = "0x02";
                    x = "48 * (pixelW * pixelGrid * 0.50)";
                    w = "82 * (pixelW * pixelGrid * 0.50)";
                    h = "5 * (pixelH * pixelGrid * 0.50)";
                    rows = 1;
                    columns = 5;
                    strings[] = {"$STR_TEAM_MAIN","$STR_TEAM_RED","$STR_TEAM_GREEN","$STR_TEAM_BLUE","$STR_TEAM_YELLOW"};
                    onToolboxSelChanged = "missionnamespace setVariable ['potato_teamColors_temp',_this select 1];";
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class ADDON {
                displayName = "POTATO: Team Color";
                collapsed = 1;
                class Attributes {
                    class GVAR(unitMarkerColor) {
                        control = QGVAR(fireTeamControl);
                        displayName = "Team Color";
                        tooltip = "Team Color";
                        property = QGVAR(teamColor);
                        expression = QUOTE([ARR_2(_this,_value)] call FUNC(setColor));
                        typeName = "STRING";
                        condition = "objectBrain";
                        defaultValue = "MAIN";
                        class values {
                            class 1 { name = "white"; value = "MAIN"; default = 1; };
                            class 2 { name = "red"; value = "RED"; };
                            class 3 { name = "green"; value = "GREEN"; };
                            class 4 { name = "blue"; value = "BLUE"; };
                            class 5 { name = "yellow"; value = "YELLOW"; };
                        };
                    };
                };
            };
        };
    };
};
