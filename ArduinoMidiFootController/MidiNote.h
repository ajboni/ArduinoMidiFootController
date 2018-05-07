// MidiNote.h

#ifndef _MIDINOTE_h
#define _MIDINOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"

class MidiNote {
	MidiNote(int note, int velocity, int channel);
	int Note;
	int Velocity;
	int Channel;
	
};



#else
	#include "WProgram.h"
#endif


#endif

