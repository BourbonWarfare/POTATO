class Params {
  class BWMF_ParamWeather {
    title = "Weather";
    function =  QPFUNC(missionModules,setWeather);

    values[] = {-1,0,1,2,3,4,5,6,7,8};
    texts[] = {"Leave it the fuck alone", "Clear (Calm)", "Cloudy (Light Winds)", "Cloudy (Strong Winds)", "Overcast (Calm)", "Overcast (Light Winds)", "Overcast (Strong Winds)", "Rain (Light Winds)", "Rain (Strong Winds)", "Storm"};
    default = -1;
  };
  class BWMF_ParamFog {
    title = "Fog";
    function = QPFUNC(missionModules,setFog);

    values[] = {-1,0,0.2,0.4,0.6};
    texts[] = {"Leave it the fuck alone", "None","Light","Medium","Heavy"};
    default = -1;
  };
  class BWMF_ParamTimeOfDay {
    title = "Time of Day";
    function = QPFUNC(missionModules,setTime);

    values[] = {-1,0,1,2,3,4,5,6,7};
    texts[] = {"Leave it the fuck alone", "Dawn", "Early Morning", "Morning", "Noon", "Afternoon", "Evening", "Dusk", "Night"};
    default = -1;
  };
  class GVAR(gradMode) {
    title = "GRAD - Enable Mode";
    values[] = {0, 1, 2, 3, 4};
    texts[] = {"Disable GRAD vehicle spawn", "Normal spawn limitations", "No limits per vehicle type", "Transport Only", "Light Vehicles Only"};
    default = 4;
  };
};
