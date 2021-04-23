// Shows a button to quickly connect to a server from main menu (only after first connecting normlally)

class RscButton;
class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay {
    class controls {
        class GVAR(quickConnectToServer_main): RscButton { // port 2303
            x = "0.5 - (0.5 * 10) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - (10 / 2) * (pixelH * pixelGridNoUIScale * 2) - 4 * (pixelH * pixelGridNoUIScale * 2)";
            w = "10 * (pixelW * pixelGridNoUIScale * 2)";
            h = "2 * (pixelH * pixelGridNoUIScale * 2)";
            text = "Connect To main BW Server"; 
            colorBackground[] = {0.2,0,0,1};
            onLoad = "call compileScript ['z\potato\addons\core\tempUpgradeServerPW.sqf']; params ['_ctrl'];  private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  if (_index isEqualTo -1) then { _ctrl ctrlShow false; };";
            onButtonClick = " private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  private _password = (_passwordCache select 1) param [_index, ''];  connectToServer ['104.128.50.152', 2303, _password];";
        };
        class GVAR(quickConnectToServer_train): GVAR(quickConnectToServer_main) { // port 2369
            x = "0.5 + (0.5 * 10.1) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - (10 / 2) * (pixelH * pixelGridNoUIScale * 2) - 4 * (pixelH * pixelGridNoUIScale * 2)";
            w = "4 * (pixelW * pixelGridNoUIScale * 2)";
            h = "0.95 * (pixelH * pixelGridNoUIScale * 2)";
            text = "Training"; 
            tooltip = "Training Server (may not always be running)"; 
            colorBackground[] = {0,0.1,0,1};
            onLoad = "params ['_ctrl'];  private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  if (_index isEqualTo -1) then { _ctrl ctrlShow false; };";
            onButtonClick = " private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  private _password = (_passwordCache select 1) param [_index, ''];  connectToServer ['104.128.50.152', 2369, _password];";
        };
        class GVAR(quickConnectToServer_oftNight): GVAR(quickConnectToServer_main) { // port 2485
            x = "0.5 + (0.5 * 10.1) * (pixelW * pixelGridNoUIScale * 2)";
            y = "0.5 - (10 / 2) * (pixelH * pixelGridNoUIScale * 2) - 2.95 * (pixelH * pixelGridNoUIScale * 2)";
            w = "4 * (pixelW * pixelGridNoUIScale * 2)";
            h = "0.95 * (pixelH * pixelGridNoUIScale * 2)";
            text = "OftNight"; 
            tooltip = "Offnight (extra mods, may not always be running)"; 
            colorBackground[] = {0,0,0.1,1};
            // ToDo: detect what modset and conditionally show - if ((count activatedAddons) < 3800) exitWith { _ctrl ctrlShow false; };
            onLoad = " params ['_ctrl'];  private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  if (_index isEqualTo -1) then { _ctrl ctrlShow false; };";
            onButtonClick = " private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];  private _index = (_passwordCache select 0) find '104.128.50.152:2303';  private _password = (_passwordCache select 1) param [_index, ''];  connectToServer ['104.128.50.152', 2485, _password];";
        };
    };
};
