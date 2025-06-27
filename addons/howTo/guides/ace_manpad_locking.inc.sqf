["Manpad/Stinger", [{
    (_units findIf {
            (getNumber (configFile >> "CfgWeapons" >> secondaryWeapon _x >> "ace_manpad_enabled")) == 1
    }) != -1
}, {"
<font  color='#FFA700'>Usage Instructions:</font color> <br/>
---------------------------------- <br/>
<br/>
- Put target in sights <br/>
- Press and hold TAB (default keybind for 'ACE-Weapons: Missile Lock') <br/>
- Wait for tone to become steady (~3 seconds) <br/>
- Fire missile <br/>
<br/>
- Optionally: while continuing to hold TAB you can also hold CTRL to uncage seeker; allowing you to elevate and lead the target
"}]]
