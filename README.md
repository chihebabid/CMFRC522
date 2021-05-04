# CMFRC522
A C++ library, based on pigpio library, to use RC522 Rfid reader for Raspberry Pi.

## Requirements
Pigpio library

## Connecting the hardware

Connecting RC522 module to SPI is pretty easy. You can use
[this neat website](http://pi.gadgetoid.com/pinout) for reference.

| Board pin name | Board pin | Physical RPi pin | RPi pin name |
|----------------|-----------|------------------|--------------|
| SDA            | 1         | 24               | GPIO8, CE0   |
| SCK            | 2         | 23               | GPIO11, SCKL |
| MOSI           | 3         | 19               | GPIO10, MOSI |
| MISO           | 4         | 21               | GPIO9, MISO  |
| GND            | 6         | 6, 9, 20, 25     | Ground       |
| RST            | 7         | 22               | GPIO25       |
| 3.3V           | 8         | 1                | 3V3          |

Another pin can be configured instead of GPIO25

## Not yet tested, I've just transformed the code based on pigpio library
## 
