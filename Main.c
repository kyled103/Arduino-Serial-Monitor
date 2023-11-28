#include <Windows.h>
#include <stdio.h>
#include <stdint.h>

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

	if (SetDCB(com) == FALSE)
	{
		DWORD dwError = GetLastError();
		printf_s("Error setting DCB with %i.\n", dwError);
		system("Pause");

		goto Exit;
	}

	if (SetTimeouts(com) == FALSE)
	{
		DWORD dwError = GetLastError();
		printf_s("Error setting Timeouts with %i.\n", dwError);
		system("Pause");

		goto Exit;
	}
	
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
		BYTE outBuffer = D0;
		WriteFile(com, outBuffer, sizeof(outBuffer), NULL, NULL);

		SetCommMask(com, EV_RXCHAR);
		DWORD dwEventMask = 0;
		WaitCommEvent(com, &dwEventMask, NULL);

		SHORT inBuffer = 0;
		ReadFile(com, &inBuffer, sizeof(inBuffer), NULL, NULL);

		printf_s("%hi \n", inBuffer);
	}

Exit:
	return 0;
}
