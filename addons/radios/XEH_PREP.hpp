TRACE_1("",QUOTE(ADDON));

// radio config
PREP(configureRadios);
PREP(initializeRadios);

// 3den mission config
PREP(acreControlLoad);
PREP(acreAttributeLoad);
PREP(acreAttributeSave);
PREP(acreControlSideChange);
PREP(acreControlRadioChange);
PREP(acreControlChannelChange);
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
