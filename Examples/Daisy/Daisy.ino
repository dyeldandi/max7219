#include <max7219.h>

MAX7219 max7219(2);

void setup() {
  Serial.begin(9600);
  max7219.Begin();
}

void loop() {
  //Display HELLO right justified
  max7219.Clear();
  max7219.DisplayText("HELLOHELLO", MAX7219_JUSTIFY_RIGHT);
  delay(1000);

  //Display HELLO left justified
  max7219.Clear();
  max7219.DisplayText("HELLOHELLO", MAX7219_JUSTIFY_LEFT);
  delay(1000);


  //Display long text right justified
  max7219.Clear();
  max7219.DisplayText("HELLOLONGTEXTWONTFIT", MAX7219_JUSTIFY_RIGHT);
  delay(1000);

  //Display HELLO left justified
  max7219.Clear();
  max7219.DisplayText("HELLOLONGTEXTWONTFIT", MAX7219_JUSTIFY_LEFT);
  delay(1000);

  max7219.Clear();
  max7219.DisplayChar( 0, '0', 0);
  max7219.DisplayChar( 1, '1', 0);
  max7219.DisplayChar( 2, '2', 0);
  max7219.DisplayChar( 3, '3', 0);
  max7219.DisplayChar( 4, '4', 0);
  max7219.DisplayChar( 5, '5', 0);
  max7219.DisplayChar( 6, '6', 0);
  max7219.DisplayChar( 7, '7', 0);
  max7219.DisplayChar( 8, '8', 0);
  max7219.DisplayChar( 9, '9', 0);
  max7219.DisplayChar(10, 'A', 0);
  max7219.DisplayChar(11, 'b', 0);
  max7219.DisplayChar(12, 'c', 0);
  max7219.DisplayChar(13, 'd', 0);
  max7219.DisplayChar(14, 'R', 0);
  max7219.DisplayChar(15, 'F', 0);
  delay(1000);
}
