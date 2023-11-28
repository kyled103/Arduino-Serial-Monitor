enum PIN
{
	D0 = 1,
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
	D8,
	D9,
	D10,
	D11,
	D12,
	D13,
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
};

#ifdef ARDUINO
void InitializePins()
{
	for (byte i = 0; i < 14; i++)
	{
		pinMode(i, OUTPUT);
	}
}

short ParseData(byte data)
{
	short value = 0;

	switch (data)
	{
		case D0:
			value = digitalRead(0);
			break;

		case D1:
			value = digitalRead(1);
			break;

		case D2:
			value = digitalRead(2);
			break;

		case D3:
			value = digitalRead(3);
			break;

		case D4:
			value = digitalRead(4);
			break;

		case D5:
			value = digitalRead(5);
			break;

		case D6:
			value = digitalRead(6);
			break;

		case D7:
			value = digitalRead(7);
			break;

		case D8:
			value = digitalRead(8);
			break;

		case D9:
			value = digitalRead(9);
			break;

		case D10:
			value = digitalRead(10);
			break;

		case D11:
			value = digitalRead(11);
			break;

		case D12:
			value = digitalRead(12);
			break;

		case D13:
			value = digitalRead(13);
			break;

		case A0:
			value = analogRead(0);
			break;

		case A1:
			value = analogRead(1);
			break;

		case A2:
			value = analogRead(2);
			break;

		case A3:
			value = analogRead(3);
			break;

		case A4:
			value = analogRead(4);
			break;

		case A5:
			value = analogRead(5);
			break;

		default:
			value = 0xFFFF;
			break;
	}

	return value;
}
#endif