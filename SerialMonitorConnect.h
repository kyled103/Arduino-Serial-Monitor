#include <Windows.h>

HANDLE ConnectToPort(char* port)
{
	HANDLE com = CreateFile(port, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	
	return com;
}

BOOL SetDCB(HANDLE com)
{
	DCB dcb = { sizeof(DCB) };

	dcb.BaudRate = CBR_9600;
	dcb.ByteSize = 8;
	dcb.StopBits = ONESTOPBIT;
	dcb.Parity = NOPARITY;

	return SetCommState(com, &dcb);
}

BOOL SetTimeouts(HANDLE com)
{
	COMMTIMEOUTS timeouts = { 0 };

	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;

	return SetCommTimeouts(com, &timeouts);
}