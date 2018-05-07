// MidiMessage.h

#ifndef _MIDIMESSAGE_h
#define _MIDIMESSAGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MidiMessageClass
{
 protected:


 public:
	void init();
};

extern MidiMessageClass MidiMessage;

#endif

