// Shows a button to quickly connect to a server from main menu (only after first connecting normlally)

class RscButton;
class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay {
    class controls {
        class GVAR(quickConnectToServer): RscButton {
            x = "0.5 - (0.5 * 10) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - (10 / 2) * (pixelH * pixelGridNoUIScale * 2) - 4 * (pixelH * pixelGridNoUIScale * 2)";
            w = "10 * (pixelW * pixelGridNoUIScale * 2)";
            h = "2 * (pixelH * pixelGridNoUIScale * 2)";
            text = "BW Server changing IP soon, and you may have to manually connect"; 
            tooltip = "Check TS/Discord for more info - this button is hardcoded to connect to old IP"; 
            colorBackground[] = {0.2,0,0,1};
            onLoad = " params ['_ctrl'];  private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '208.100.19.226:2303';  if (_index isEqualTo -1) then { _ctrl ctrlShow false; };";
            onButtonClick = " private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '208.100.19.226:2303';  private _password = (_passwordCache select 1) param [_index, ''];  connectToServer ['208.100.19.226', 2303, _password];";
        };
    };
};
