/*
 Name:		ArduinoMidiFootController.ino
 Created:	5/5/2018 3:14:17 PM
 Author:	rodobodolfo
*/

// the setup function runs once when you press reset or power the board
#include "BankButton.h"
#include "MidiComm.h"
#include "MidiNote.h"
#include "MidiMessage.h"
#include "Button.h"


MidiComm midiComm;

//Create Bank select Buttons
BankButton button_A("Button A", 2, 90, 11, 1, &midiComm);
BankButton button_B("Button B", 3, 91, 10, 0, &midiComm);


////Create Push Buttons
Button button_1("Button 1", 4,36, &midiComm);
Button button_2("Button 2", 5,37, &midiComm);
Button button_3("Button 3", 6,38, &midiComm);
Button button_4("Button 4", 7,39, &midiComm);
Button button_5("Button 5", 8,40, &midiComm);

// Defaults
int StatusLed = 12;
int NotesPerBank = 5;

//Set midi message form.
MidiComm::Mode MidiMode = MidiComm::Mode::NoteOn;


void setup() {
	midiComm.NotesPerBank = NotesPerBank;
	midiComm.MidiMode = MidiMode;
	pinMode(StatusLed, OUTPUT);
	midiComm.Init();
	Serial.begin(115200);
}

// the loop function runs over and over again until power down or reset
void loop() {
	
	digitalWrite(StatusLed, HIGH);
	button_A.Monitor();
	button_B.Monitor();
	button_1.Monitor();
	button_2.Monitor();
	button_3.Monitor();
	button_4.Monitor();
	button_5.Monitor();
	
	//
	delay(50);

}

