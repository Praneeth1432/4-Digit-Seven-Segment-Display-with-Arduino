#include <TM1637Display.h>
#define CLK_PIN 9 
#define DIO_PIN 8 
TM1637Display display(CLK_PIN, DIO_PIN);
int counter = 0;
void setup() {
  display.setBrightness(0x0f); 
  display.clear();           
  Serial.begin(9600);
  Serial.println("TM1637 Counter - Counting from 0000 to 9999 in repeating digits");
}

void loop() {
  int displayNumber = counter * 1111;
  display.showNumberDec(displayNumber, true);  
  Serial.print("Count: ");
  Serial.println(displayNumber);
  counter++;
  if (counter > 9) {
    counter = 0;
    Serial.println("Counter reset to 0000");
  }
  delay(1000);
} 