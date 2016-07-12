TRACE_1("",QUOTE(ADDON));

// radio config
PREP(setChannel);
PREP(configureRadios);
PREP(addSharedChannel);
PREP(initializeRadios);

// 3den mission config
PREP(acreControlLoad);
PREP(acreAttributeLoad);
PREP(acreAttributeSave);
PREP(acreGetChannelArrays);
PREP(acreControlSideChange);
PREP(acreControlBabelChange);
PREP(acreControlRadioChange);
PREP(acreControlSharedChange);
PREP(acreControlChannelChange);
PREP(acreSetAcreConfiguration);
PREP(acreControlChannelEditChange);

// 3den channel config
PREP(setChannels);
PREP(setChannelsLocal);
PREP(channelControlLoad);
PREP(channelAttributeLoad);
PREP(channelAttributeSave);
PREP(channelControlSetChange);
PREP(channelControlRadioChange);
PREP(channelControlChannelChange);

// util funtions
PREP(fillChannelArray);
PREP(setChannelArrays);
