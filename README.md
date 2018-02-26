# 2.8-Touch
This project demonstrates the use of a 2.8" SPI TFT 240x320 Touch Display module with an Arduino Uno.\
The display is 3.3V only therefore output signals from the Uno are stepped down using a simple 1k/1k
voltage divider.\
ON and OFF buttons are drawn to the display. When a touch is detected withing a button's perimeter
a LED is switched appropriately.\
Wiring:\
Uno 3 --1k-- T_IRQ (voltage divider not required)\
Uno 4 --1k-- T_DO\
Uno 5 --1k/1k-- T_DIN\
Uno 6 --1k/1k-- T_CS\
Uno 7 --1k/1k-- T_CLK\
3V3 --100R-- LED\
Uno 13 --1k/1k-- SCK\
Uno 11 --1k/1k-- MOSI\
Uno 9 --1k/1k-- DC\
3V3 --1k-- RST\
Uno 10 --1k/1k-- CS\
0V ---- GND\
3V3 ---- Vcc\
Note: MISO is left unconnected.\
An independent 3.3V supply was used rather than the one provided by the Uno, which may not be up to the task.
