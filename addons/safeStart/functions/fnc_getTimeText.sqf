#include "script_component.hpp"

private _elapsedTime = CBA_missionTime - (_this select 0);

format [
    "<t align='center'>Safe Start Enabled<br/>%1 %2:%3:%4</t>",
    "<img image='\A3\UI_F\data\IGUI\Cfg\Actions\settimer_ca.paa'/>",
    [floor (((_elapsedTime / 60) / 60) % 24)] call FUNC(getTimeStrFromNum),
    [floor ((_elapsedTime / 60) % 60)] call FUNC(getTimeStrFromNum),
    [floor (_elapsedTime % 60)] call FUNC(getTimeStrFromNum)
]
