# Electric-Water-Heater

Developed an electric water heater to control the water temperature according to a setpoint temperature with C programming language on Atmel AVR Atmega32 as microcontroller. The Water Heater measures the water temperature every 100ms using a temperature sensor. Depending on the measured temperature, a heating element should be turned ON to increase the water temperature if the average of the last 10 water temperature readings is less than the set temperature by 5 degrees and a cooling element should be turned ON to decrease the water temperature if the average readings is greater than the set temperature by 5 degrees. By default, a 2 seven segment display is used to show the current water temperature.

If power is connected to the heater,the electric water heater is in OFF state, and a “ON/OFF” button press switches the heater from OFF to ON state accordingly. There are “Up” or “Down” buttons to change the required water temperature (setpoint). The first “Up” or “Down” button press, enters the water heater to the temperature setting mode. 
After entering temperature setting mode, a single “Up” button press increase the set temperature by 5 degrees, whilst a single “Down” button press decrease the set temperature by 5 degrees. Noticing that The minimum and maximum possible set temperature is 35 and 75 degrees respectively. Also, the internal EEPROM should save the set temperature once set.

While the electric water heater is in the temperature setting mode, the 2 seven segment displays should blink every 1 second and show the set temperature. What's more, the water heater should exit the temperature setting mode if the “Up” and “Down” buttons are not pressed for 5 seconds.

A LED is used to blink every 1 second as long as the heating element is ON, and should only be on if the cooling element is ON.
