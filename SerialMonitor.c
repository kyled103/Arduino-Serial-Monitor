#define ARDUINO
#include "SerialMonitorData.h"

void setup()
{
	Serial.begin(9600);
	Serial.setTimeout(5);
	
	InitializePins();
}

void loop()
{
	if(Serial.available())
	{
		byte data = 0;

		while(Serial.available())
		{
			Serial.readBytes(&data, sizeof(byte));
		}
		
		short value = ParseData(data);
		byte buffer[2] = {0};
		memcpy(buffer, &value, sizeof(short));
		
		Serial.write(buffer, sizeof(short));
	}
}
