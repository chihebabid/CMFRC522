//============================================================================
// Name        : pigpioLED.cpp
// Author      : CA ABID
// Version     :
// Copyright   : 2021
// Description : Test sample using LCD driver
//============================================================================

#include "CMFRC522.h"
#include <pigpio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	if (gpioInitialise() < 0) {
		cout << "Failure..." << endl;
		exit(-1);
	}
	CMFRC522 mfrc522;
    mfrc522.PCD_Init();   // Initiate MFRC522
    while(1) {
        if (!mfrc522.PICC_IsNewCardPresent()) return; //Nvlle carte
        if (!mfrc522.PICC_ReadCardSerial()) return; //Lecture OK
        //Show UID on serial monitor
        std::cout << "UID tag :";
        stringstream content("");
        byte letter;
        for (uint8_t i = 0; i < mfrc522.uid.size; i++)
        {
            std::cout<<mfrc522.uid.uidByte[i] << (0x10 ? " 0" : " ");
            std::cout<<hex<<mfrc522.uid.uidByte[i];
            content<<mfrc522.uid.uidByte[i] << (0x10 ?" 0" : " ");
            content<<std::hex<<mfrc522.uid.uidByte[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
	
	gpioTerminate();
	return 0;
}

