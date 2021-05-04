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
//#define PIGPIO 1
int main(int argc, char *argv[]) {
	/*if (gpioInitialise() < 0) {
		cout << "Failure..." << endl;
		exit(-1);
	}*/
    //std::this_thread::sleep_for(std::chrono::seconds(10));
	CMFRC522 mfrc522;


   // mfrc522.PCD_Init();   // Initiate MFRC522
    //mfrc522.PCD_Reset();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Initialization success"<<endl;
    mfrc522.PCD_Init();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //mfrc522.PCD_PerformSelfTest();// std::cout<<"Self test passed..."<<std::endl;
    //exit(0);
    while(1) {
        if (mfrc522.isNewCardPresent()==0) {
            std::cout << "New card is here..." << std::endl;
            mfrc522.RC522_Anticoll(mfrc522._id);
            for (uint8_t i = 0; i < 8; i++) {
                std::cout<<std::hex<<int(mfrc522._id[i])<<" ";
            }
        }
    }
	gpioTerminate();
	return 0;
}

