//============================================================================
// Name        : pigpioLED.cpp
// Author      : CA ABID
// Version     : 0.2
// Copyright   : 2021
// Description : Test sample using CMFRC522 class : detect the presence of a new card
//               and print its serial number
//               To compile this program, use g++ sample1.cpp -lpigpio -lpthread
//============================================================================

#include "CMFRC522.h"
#include "pigpio.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	CMFRC522 mfrc522;
    // Initializes PCD
    mfrc522.PCD_Init();
    while(1) {
        if (mfrc522.isNewCardPresent()==0) { // Detect whether a new card is present
            std::cout << "New card is here..." << std::endl;
            mfrc522.RC522_Anticoll(mfrc522._id);
            for (uint8_t i = 0; i < 8; i++) {
                std::cout<<std::hex<<int(mfrc522._id[i])<<" ";
            }
        }
    }
}

