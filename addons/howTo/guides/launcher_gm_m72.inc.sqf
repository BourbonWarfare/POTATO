["M72A3", [{
    (_units findIf {(secondaryWeapon _x) == "gm_m72a3_oli"}) != -1
}, {
    format ["
Squad equiped with M72A3<br/><br/>
<img image='%1' width='350'/>
<img image='%2' width='350'/>
", QPATHTOF(img\m72_A.jpg), QPATHTOF(img\m72_B.jpg)]
}]]
