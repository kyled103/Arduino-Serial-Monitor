enum PIN
{
	p_D0 = 1,
	p_D1,
	p_D2,
	p_D3,
	p_D4,
	p_D5,
	p_D6,
	p_D7,
	p_D8,
	p_D9,
	p_D10,
	p_D11,
	p_D12,
	p_D13,
	p_A0,
	p_A1,
	p_A2,
	p_A3,
	p_A4,
	p_A5,
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
		case p_D0:
			value = digitalRead(0);
			break;

		case p_D1:
			value = digitalRead(1);
			break;

		case p_D2:
			value = digitalRead(2);
			break;

		case p_D3:
			value = digitalRead(3);
			break;

		case p_D4:
			value = digitalRead(4);
			break;

		case p_D5:
			value = digitalRead(5);
			break;

		case p_D6:
			value = digitalRead(6);
			break;

		case p_D7:
			value = digitalRead(7);
			break;

		case p_D8:
			value = digitalRead(8);
			break;

		case p_D9:
			value = digitalRead(9);
			break;

		case p_D10:
			value = digitalRead(10);
			break;

		case p_D11:
			value = digitalRead(11);
			break;

		case p_D12:
			value = digitalRead(12);
			break;

		case p_D13:
			value = digitalRead(13);
			break;

		case p_A0:
			value = analogRead(PIN_A0);
			break;

		case p_A1:
			value = analogRead(PIN_A1);
			break;

		case p_A2:
			value = analogRead(PIN_A2);
			break;

		case p_A3:
			value = analogRead(PIN_A3);
			break;

		case p_A4:
			value = analogRead(PIN_A4);
			break;

		case p_A5:
			value = analogRead(PIN_A5);
			break;

		default:
			value = 0xFFFF;
			break;
	}

	return value;
}
#endif
