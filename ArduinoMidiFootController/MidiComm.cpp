// 
// 
// 

#include "MidiComm.h"
#include <MIDI.h>


MIDI_CREATE_DEFAULT_INSTANCE();
MidiComm::MidiComm()
{
	
}

void MidiComm::Init()
{
	MIDI.begin();
}


void MidiComm::SendMidi(int note, int vel, int chan)
{
	switch (MidiMode)
	{
	case NoteOn:
		MIDI.sendNoteOn(note, vel, chan);
		break;
	case ControlChange:
		MIDI.sendControlChange(note, vel, chan);
		break;
	case ProgramChange:
		MIDI.sendProgramChange(note, chan);
		break;
	default:
		break;
	}

}

