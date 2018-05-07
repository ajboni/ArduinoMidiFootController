// SwitchButton.h

#ifndef _SWITCHBUTTON_h
#define _SWITCHBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "MidiComm.h"
	#include "Button.h"

#else
	#include "WProgram.h"
#endif

class BankButton : public Button
{

 public:
	 BankButton(char description[], int pinNumber, int midiValue, int LedPinNumber, int bankBitNumber, MidiComm *midiComm);
	 void Monitor() override;
	 int BankBitNumber;
};

#endif

