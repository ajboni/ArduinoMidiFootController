// Button.h

#ifndef _BUTTON_h
#define _BUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "MidiComm.h"
	#include "arduino.h"


class Button {
public:
	MidiComm *MidiCommInstance;
	Button(char description[], int pinNumber, int midiValue, MidiComm *midiComm);
	Button();
	void Press();
	void Release();
	virtual void Monitor();

	// Button Description
	String Description;

	//Arduino Oin
	int PinNumber;

	// Midi we will send with this button
	int MidiValue;
	
	// 0 for push up, 1 for switch button
	int ButtonType;
	
	// 0 = no light, 
	int LedPinNumber;

	bool Status;
	bool LastStatus;
	bool IsPressed();

};













#else
	#include "WProgram.h"
#endif


#endif

