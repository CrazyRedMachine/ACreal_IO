#ifndef WavepassReader_H
#define WavepassReader_H

#include "Arduino.h"
#include "RfidModule.h"

class WavepassReader : public RfidModule
{
public:
	bool is_real = true;
	WavepassReader();
	void setPins(int sensor, HardwareSerial* serialid);
	void read();
	void update();
	byte isCardPresent();
	void getUID(byte* uid);

private:
	byte card;        // 0 : no card 1:ISO15693 2:Felica
	byte uid[8];
	boolean pinset;   // pin init done flag
	boolean readcmd;  // read request from host flag
	byte readstatus;  // 0 : idle, 1 : looking for ISO15693, 2 : looking for Felica
};

#endif



