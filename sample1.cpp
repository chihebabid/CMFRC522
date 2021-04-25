//============================================================================
// Name        : pigpioLED.cpp
// Author      : CA ABID
// Version     :
// Copyright   : 2021
// Description : Test sample using LCD driver
//============================================================================

#include "CMFRC522.h"
#include <iostream>
#include <pigpio.h>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]) {
	if (gpioInitialise() < 0) {
		cout << "Failure..." << endl;
		exit(-1);
	}

	
	gpioTerminate();
	return 0;
}

