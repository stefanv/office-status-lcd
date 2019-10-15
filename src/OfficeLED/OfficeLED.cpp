#include <Arduino.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// degree symbol

byte eaccent[8] = {
  0b00010,
  0b00100,
  0b01110,
  0b10001,
  0b11111,
  0b10000,
  0b01110,
};

byte phone[8] = {
  0b11111,
  0b00000,
  0b10101,
  0b00000,
  0b10101,
  0b00000,
  0b10101,
};

void print_name() {
  lcd.print("St");
  lcd.write(byte(0));
  lcd.print("fan");
}

void print_phone() {
  lcd.write(byte(1));
  lcd.print(" 510-701-4153");
}

void print_status(String prefix, String line1, String line2) {
  lcd.clear();

  lcd.setCursor(0, 0);
  print_name();
  lcd.print(" " + prefix);

  lcd.setCursor(0, 1);
  lcd.print(line1);

  lcd.setCursor(0, 2);
  lcd.print(line2);

  lcd.setCursor(0, 3);
  print_phone();
}

/*********************************************************/
void setup()
{
  Wire.begin();
  Serial.begin(9600);

  lcd.begin();  //initialize the lcd
  lcd.createChar(0, eaccent);
  lcd.createChar(1, phone);

  print_status("is in", "the void", "");
}
/*********************************************************/

void loop(void)
{
  String input;
  int prevOffset = 0;
  int offset = 0;
  String lines[4];
  int i;

  if (Serial.available() > 0) {
    input = Serial.readStringUntil('\n');
    for (i = 0; i < 3; i++) {
      offset = input.indexOf("||", offset);
      lines[i] = input.substring(prevOffset, offset);
      offset += 2;
      prevOffset = offset;
    }
    print_status(lines[0], lines[1], lines[2]);
    Serial.println("LCD output set:");
    Serial.println("---");
    for (i = 0; i < 3; i++) {
      Serial.println(lines[i]);
    }
    Serial.println("---");
  }
}
// Scan for screen device loop
//
// void setup()
// {
//   Wire.begin();
//   Serial.begin(9600);
//   Serial.println("\nI2C Scanner");
// }
//
// void loop()
// {
//   char error, address;
//   int nDevices;
//   Serial.println("Scanning...");
//   nDevices = 0;
//   for(address = 1; address < 127; address++ )
//   {
//     // The i2c_scanner uses the return value of
//     // the Write.endTransmisstion to see if
//     // a device did acknowledge to the address.
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();
//     if (error == 0)
//     {
//       Serial.print("I2C device found at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.print(address,HEX);
//       Serial.println(" !");
//       nDevices++;
//     }
//     else if (error==4)
//     {
//       Serial.print("Unknow error at address 0x");
//       if (address<16)
//         Serial.print("0");
//       Serial.println(address,HEX);
//     }
//   }
//   if (nDevices == 0)
//     Serial.println("No I2C devices found\n");
//   else
//     Serial.println("done\n");
//   delay(5000); // wait 5 seconds for next scan
// }
