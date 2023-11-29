#include <Windows.h>
#include <stdio.h>

#include "SerialMonitorData.h"
#include "SerialMonitorConnect.h"

int main()
{
	SHORT nPort = 0;
	printf_s("Which port to connect to: ");
	scanf_s("%hi", &nPort);

	char sPort[6] = { 0 };
	sprintf_s(sPort, sizeof(sPort), "COM%i", nPort);

	HANDLE com = ConnectToPort(sPort);
	if (com == INVALID_HANDLE_VALUE)
	{
		DWORD dwError = GetLastError();
		printf_s("Error connecting to %s with %i.\n", sPort, dwError);
		system("Pause");

		goto Exit;
	}
	printf_s("Connected to %s.\n", sPort);

	if (SetDCB(com) == FALSE)
	{
		DWORD dwError = GetLastError();
		printf_s("Error setting DCB with %i.\n", dwError);
		system("Pause");

		goto Exit;
	}
	printf_s("Set DCB Params.\n");

	if (SetTimeouts(com) == FALSE)
	{
		DWORD dwError = GetLastError();
		printf_s("Error setting Timeouts with %i.\n", dwError);
		system("Pause");

		goto Exit;
	}
	printf_s("Set Timeouts.\n");

	SetConsoleTitle("Arduino Serial Monitor");

	while (TRUE)
	{
		HANDLE temp = ConnectToPort(sPort);
		DWORD dwConnectionStatus = GetLastError();

		// Check for Disconnection
		if (dwConnectionStatus == ERROR_FILE_NOT_FOUND)
		{
			printf_s("Lost connection with %s.\n", sPort);
			system("Pause");

			goto Exit;
		}

		// Pin to Read From
		BYTE outBuffer = p_A0;
		WriteFile(com, &outBuffer, 1, NULL, NULL);

		SetCommMask(com, EV_RXCHAR);
		DWORD dwEventMask = 0;
		WaitCommEvent(com, &dwEventMask, NULL);

		SHORT inBuffer = 0;
		ReadFile(com, &inBuffer, sizeof(inBuffer), NULL, NULL);
		printf_s("%hi \n", inBuffer);
	}

Exit:
	if (com == INVALID_HANDLE_VALUE)
	{
		CloseHandle(com);
	}

	return 0;
}
