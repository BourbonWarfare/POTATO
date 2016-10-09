TRACE_1("",QUOTE(ADDON));

// radio config
PREP(setChannel);
PREP(addAcreBriefing);
PREP(configureRadios);
PREP(addSharedChannel);
PREP(initializeRadios);
PREP(reinitializeRadios);
PREP(setupPlayer);

// 3den global mission config
PREP(acreGlobalTIChange);
PREP(acreGlobalControlLoad);
PREP(acreGlobalAttributeLoad);
PREP(acreGlobalAttributeSave);
PREP(acreGlobalSetGVarsFromString);
PREP(acreGlobalSetControlsFromGVars);

// 3den side specific mission config
PREP(acreSideControlLoad);
PREP(acreSideAttributeLoad);
PREP(acreSideAttributeSave);
PREP(acreSideControlSideChange);
PREP(acreSideControlBabelChange);
PREP(acreSideControlRadioChange);
PREP(acreSideSetGVarsFromString);
PREP(acreSideControlSharedChange);
PREP(acreSideControlChannelChange);
PREP(acreSideSetControlsFromGVars);
PREP(acreSideControlChannelEditChange);

// 3den channel config
PREP(setChannels);
PREP(channelControlLoad);
PREP(channelAttributeLoad);
PREP(channelAttributeSave);
PREP(channelControlSetChange);
PREP(channelControlRadioChange);
PREP(channelControlChannelChange);

// 3den babel config
PREP(setLanguages);
PREP(babelControlLoad);
PREP(babelAttributeLoad);
PREP(babelAttributeSave);
PREP(babelControlSetChange);

// util funtions
PREP(setBabelList);
PREP(fillChannelArray);
PREP(setChannelArrays);
PREP(populateBabelList);
