#include "script_component.hpp"

// Attempt to upgrade saved PW from old server to new
private _passwordCache = profileNamespace getVariable ['cba_ui_ServerPasswords', [[], []]];
INFO_1("tempUpgradeServerPW: cba_ui_ServerPasswords = %1", _passwordCache);


private _indexNew = (_passwordCache select 0) find '104.128.50.152:2303';
if (_indexNew != -1) then { 
    INFO("quickConnectToServer: Ready for new server");    
} else {
    // don't have new pw, try to upgrade from old
    private _indexOld = (_passwordCache select 0) find '208.100.19.226:2303';
    if (_indexOld == -1) exitWith { INFO("quickConnectToServer: No old password"); };
    private _password = (_passwordCache select 1) param [_indexOld, ''];

    private _listIndex = (_passwordCache select 0) pushBack '104.128.50.152:2303';
    (_passwordCache select 1) set [_listIndex, _password];

    INFO("quickConnectToServer: Updated to new IP");

    profileNamespace setVariable ['cba_ui_ServerPasswords', _passwordCache];
    saveProfileNamespace;
};
