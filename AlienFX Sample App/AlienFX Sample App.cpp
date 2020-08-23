// AlienFX Sample App.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../AlienFX_SDK/AlienFX_SDK.h"
#include <iostream>
int main()
{
	int isInit = AlienFX_SDK::Functions::AlienFXInitialize(AlienFX_SDK::Functions::vid);
	std::cout << "PID: " << std::hex << isInit << std::endl;
	if (isInit != -1)
	{
		//bool ready = AlienFX_SDK::Functions::IsDeviceReady();

		bool result = AlienFX_SDK::Functions::Reset(false);
		if (!result) {
			std::cout << "\nReset faled with " << std::hex << GetLastError();
			return 1;
		}
		//result = AlienFX_SDK::Functions::IsDeviceReady();
		//std::cout << "\nReady: " << result; 
		//AlienFX_SDK::Functions::SetColor(AlienFX_SDK::Index::AlienFX_Macro, 25, 134, 245);

		//AlienFX_SDK::Functions::SetColor(AlienFX_SDK::Index::AlienFX_leftZone, 225, 0, 0); //r
		//AlienFX_SDK::Functions::SetColor(AlienFX_SDK::Index::AlienFX_leftMiddleZone, 0, 0, 255); //b
		//AlienFX_SDK::Functions::SetColor(AlienFX_SDK::Index::AlienFX_rightMiddleZone, 0, 255, 0); // g - right
		//AlienFX_SDK::Functions::SetColor(AlienFX_SDK::Index::AlienFX_rightZone, 0, 255, 255); // right middle
		for (int i = 0; i < 15; i++) { // let's test all lights...
			std::cout << "Set zone " << i << std::endl;
			AlienFX_SDK::Functions::SetColor(i, 0, 255, 0); 
			AlienFX_SDK::Functions::UpdateColors();
			Sleep(500);
			// need to call Reset after each Update!
			AlienFX_SDK::Functions::Reset(false);
			std::cin.get();
		}
		AlienFX_SDK::Functions::AlienFXClose();
	}

	//std::cin.get();
	return 0;
}

