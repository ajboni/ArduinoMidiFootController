// 
// 
// 

#include "BankButton.h"


BankButton::BankButton(char description[], int pinNumber, int midiValue, int ledPinNumber, int bankBitNumber, MidiComm * midiComm)
{
	Description = description;
	PinNumber = pinNumber;
	LedPinNumber = ledPinNumber;
	MidiValue = midiValue;
	MidiCommInstance = midiComm;
	BankBitNumber = bankBitNumber;
	pinMode(PinNumber, INPUT_PULLUP);
	if (LedPinNumber > 0) {
		pinMode(LedPinNumber, OUTPUT);
	}

}

void BankButton::Monitor() {
	Status = digitalRead(PinNumber);
	
	// Reversed to match lightswitch position.
	Status = !Status;

	if (Status != LastStatus) {

		//This will set the bank, each button will have a bit position that will
		// modify the bank byte.

		// Clear Bit
		MidiCommInstance->Bank &= ~(1u << BankBitNumber);

		//Set Bit
		MidiCommInstance->Bank |= Status << BankBitNumber;

		// Turn On
		digitalWrite(LedPinNumber,Status);
		//Serial.println(MidiCommInstance->Bank);

	}

	else if (Status == LastStatus) {
	
	
	}

	LastStatus = Status;
}
