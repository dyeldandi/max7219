# max7219
## A library for the MAX7219 7 segment 8 digit display with decimals.


![MAX8219 Connected to Arduino UNO](https://github.com/JemRF/max7219/blob/master/pictures/MAX7219%20and%20Arduino.jpg)

## An easy to use library that allows you to write to the display, using the DisplayText method. 

DisplayText(Text, Justification)
 - Text : The text you want to display (8 characters or less, plus up to 8 decimals)
 - Justification : Left or right justified. LEFT(MAX7219_JUSTIFY_LEFT=0) or RIGHT(MAX7219_JUSTIFY_RIGHT=1). 

e.g.:
```
max7219.DisplayText("HELLO", MAX7219_JUSTIFY_LEFT);
```
## Including decimals in the text will automatically take care of decimals like this:

e.g.
```
max7219.DisplayText("96.78F", MAX7219_JUSTIFY_RIGHT);
```
## Write to specific digits on the display using the DisplayChar method:
```
DisplayChar(Digit, Char, Decimal)
```
 - Digit : represents the digit number 0-7 (Rightmost Digit = 7, Leftmost Digit = 0)
 - Char : The character to display
 - Decimal : A flag to illuminate the decimal (true/false)

e.g.
```
max7219.DisplayChar(5, 'L', false);
```
## Create your own fonts and symbols

A font library is included but can be modified by editing the max7219.h file.

```
*********************************************************************************************************
* LED Segments:         a
*                     ----
*                   f|    |b
*                    |  g |
*                     ----
*                   e|    |c
*                    |    |
*                     ----  o dp
*                       d
*   Register bits:
*      bit:  7  6  5  4  3  2  1  0
*           dp  a  b  c  d  e  f  g
*********************************************************************************************************
* Example : The letter 'I' is represented by illuminating LED's 'b' and 'c' (refer above diagram)
*           Therfore the binary representation of 'I' is as follows
*
*           abcdefg
*           0110000
* 
*           The table below contains all the binary values for the desired font. New font characters
*           can be added or altered as required. 
*           
*           The DP bit is used to switch on the decimal place LED. DP is not included in the below table
*           but is added in the register within the libary depending on the content being displayed.  
*********************************************************************************************************

static const struct {
	char   ascii;
	char   segs;
} MAX7219_Font[] = {
  {'A',0b1110111},{'B',0b1111111},{'C',0b1001110},{'D',0b1111110},{'E',0b1001111},{'F',0b1000111},       
  {'G',0b1011110},{'H',0b0110111},{'I',0b0110000},{'J',0b0111100},{'L',0b0001110},{'N',0b1110110},       
  {'O',0b1111110},{'P',0b1100111},{'R',0b0000101},{'S',0b1011011},{'T',0b0001111},{'U',0b0111110},       
  {'Y',0b0100111},{'[',0b1001110},{']',0b1111000},{'_',0b0001000},{'a',0b1110111},{'b',0b0011111},       
  {'c',0b0001101},{'d',0b0111101},{'e',0b1001111},{'f',0b1000111},{'g',0b1011110},{'h',0b0010111},       
  {'i',0b0010000},{'j',0b0111100},{'l',0b0001110},{'n',0b0010101},{'o',0b1111110},{'p',0b1100111},       
  {'r',0b0000101},{'s',0b1011011},{'t',0b0001111},{'u',0b0011100},{'y',0b0100111},{'-',0b0000001},
  {' ',0b0000000},{'0',0b1111110},{'1',0b0110000},{'2',0b1101101},{'3',0b1111001},{'4',0b0110011},
  {'5',0b1011011},{'6',0b1011111},{'7',0b1110000},{'8',0b1111111},{'9',0b1111011},{'\0',0b0000000},
  };
```

## Connect multiple MAX7219 in daisy chain configuration
Call constructor with the number of your MAX7219 in the chain
```
MAX7219 max7219(2);
```

Use DisplayText and DisplayChar like you have a longer display

```
  max7219.DisplayText("HELLOHELLO", MAX7219_JUSTIFY_LEFT);
```

```
  max7219.DisplayChar(11, 'b', 0);
```

If you are using modules like on the image above, which can be found on Banggood, Aliexpress, etc, you may find that they have a reverse voltage protection diode right after input VCC, and output VCC is behind this diode. This means you'll see a voltage drop on output VCC and it won't be enough to power consequent modules. 

In that case you can either replace the diode with 0Ohm 1206 SMD resistor on all the modules starting from the second and keep the diode on first. But if you connect many modules the current across that diode may get too high. 

Or you can replace the diodes with a 0Ohm resistor on all the modules, including the first one, but in that case you'll need to replace the 0805 10KOhm current setting resistor with something like 20KOhm, otherwise MAX7219 will soon overheat and shut down.

## Use hardware SPI

Uncomment 
```
//#define MAX7219_USE_SPI 1
```
in max7219.h and connect your MAX7219 to SPI pins:

* MAX7219 CLK to Arduino SCK
* MAX7219 DIN to Arduino MOSI
* MAX7219 LOAD(CS) to Arduino any unused pin and change MAX_CS in max7219.h

