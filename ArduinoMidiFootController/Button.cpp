// 
// 
// 

#include "MidiComm.h"
#include "Button.h"
#include "Arduino.h"



Button::Button(char description[], int pinNumber, int midiValue, MidiComm *midiComm)
{
	Description = description;
	PinNumber = pinNumber;
	MidiValue = midiValue;
	MidiCommInstance = midiComm;

	pinMode(PinNumber, INPUT_PULLUP);
	if (LedPinNumber > 0) {
		pinMode(LedPinNumber, OUTPUT);
	}


}

Button::Button()
{
}

void Button::Press()
{
	MidiCommInstance->SendMidi(MidiValue + (MidiCommInstance->Bank * MidiCommInstance->NotesPerBank), 127, 1);
	//Serial.println("ButtonPressed" + Description + " | " + PinNumber	);
}

void Button::Release()
{
	MidiCommInstance->SendMidi(MidiValue + (MidiCommInstance->Bank * MidiCommInstance->NotesPerBank), 0, 1);
	//MIDI.sendNoteOf(MidiValue, 0, 1);
}

// Check for buttons change of status
void Button::Monitor()
{
	Status = digitalRead(PinNumber);
	
	if (Status != LastStatus) {
		if (Status == LOW) {
			//Serial.println("ButtonPressed" + Description);
			Press();
		}

		if (Status == HIGH) {
			Release();
			//Serial.println("ButtonReleased" + Description);
		}
	}
	
	else if (Status == LastStatus) {
		if (Status == LOW) {
			//Serial.println("Holding Button" + Description);
		}
	}
	
	LastStatus = Status;


}

bool Button::IsPressed()
{
	if (Status == LOW) {
		return true;
	}
	else {
		return false;
	}
}
