//============================================================================
// Name        : pigpioLED.cpp
// Author      : CA ABID
// Version     :
// Copyright   : 2021
// Description : Test sample using LCD driver
//============================================================================

#include "CMFRC522.h"
#include "pigpio.h"
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
    //std::this_thread::sleep_for(std::chrono::seconds(10));
	CMFRC522 mfrc522;
	mfrc522.PCD_Init();
    //mfrc522.PCD_Init();   // Initiate MFRC522
    //mfrc522.PCD_Reset();
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //std::cout<<"Initialization success"<<endl;
    mfrc522.PCD_DumpVersionToSerial();
    //std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (mfrc522.PCD_PerformSelfTest()) std::cout<<"Self test passed..."<<std::endl;
    exit(0);
    while(1) {
       if (mfrc522.PICC_IsNewCardPresent()) {
           std::cout << "New card is here..." << std::endl;
           if (mfrc522.PICC_ReadCardSerial()) {

               //Show UID on serial monitor
               std::cout << "UID tag :";
               stringstream content("");
               uint8_t letter;
               for (uint8_t i = 0; i < mfrc522.uid.size; i++) {
                   std::cout << mfrc522.uid.uidByte[i] << (0x10 ? " 0" : " ");
                   std::cout << hex << mfrc522.uid.uidByte[i];
                   content << mfrc522.uid.uidByte[i] << (0x10 ? " 0" : " ");
                   content << std::hex << mfrc522.uid.uidByte[i];
               }

           }
       }
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
	gpioTerminate();
	return 0;
}

