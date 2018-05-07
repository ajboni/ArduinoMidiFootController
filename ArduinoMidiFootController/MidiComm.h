// MidiComm.h

#ifndef _MIDICOMM_h
#define _MIDICOMM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class MidiComm
{

	

 public:
	 MidiComm();	 
	 void SendMidi(int note, int vel, int chan);
	 void Init();
	 int Bank;
	 int NotesPerBank;
	 enum Mode { NoteOn, ControlChange, ProgramChange };
	 Mode MidiMode;
};


#endif


