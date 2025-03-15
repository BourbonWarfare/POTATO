["M136", [{
    (_units findIf {(secondaryWeapon _x) in ["CUP_launch_M136_Loaded", "CUP_launch_M136"]}) != -1
}, {
    format ["
Squad equiped with M136<br/><br/>
<img image='%1' width='350'/>
", QPATHTOF(img\m136.jpg)]
}]]
