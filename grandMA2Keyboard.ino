#define LED_ERROR 11
#define LED_STATE 12
#define LED_RUN 13

#include <Keypad.h>

char hexaKeys[4][4] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F'},
};

//Pins for keypad 1
byte colPins[4] = {31, 33, 35, 37};
byte rowPins[4] = {36, 34, 32, 30};
//Pins for keypad 2
byte colPins2[4] = {39, 41, 43, 45};
byte rowPins2[4] = {44, 42, 40, 38};

//Creating Keypads
Keypad keypad1 = Keypad( makeKeymap(hexaKeys), rowPins, colPins, 4, 4);
Keypad keypad2 = Keypad( makeKeymap(hexaKeys), rowPins2, colPins2, 4, 4);

void setup() {
  //Setting up LEDs
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_STATE, OUTPUT);
  pinMode(LED_RUN, OUTPUT);

  //Resetting any LEDs
  digitalWrite(LED_ERROR, LOW);
  digitalWrite(LED_RUN, LOW);
  digitalWrite(LED_STATE, LOW);
  
  //Beginning Serial on Baudrate 115200
  Serial.begin(115200);
  Serial.println("grandMA2 onPC MIDI<->Controller Software");
  Serial.println("created by Gandalf1783");

  //Just a short animation so the user knows that the software is loading.

  digitalWrite(LED_RUN, HIGH);
  delay(250);
  digitalWrite(LED_STATE, HIGH);
  delay(250);
  digitalWrite(LED_ERROR, HIGH);
  delay(250);
  digitalWrite(LED_RUN, LOW);
  delay(250);
  digitalWrite(LED_STATE, LOW);
  delay(250);
  digitalWrite(LED_ERROR, LOW);
  delay(250);
  
  Serial.println("Loading...");
  
  //Setting LED_RUN to HIGH (indicates working and loaded product)
  digitalWrite(LED_RUN, HIGH);
  Serial.println("Done.");
}

void loop() {
  digitalWrite(LED_STATE, LOW);
  char customKey = keypad1.getKey();
  char customKey2 = keypad2.getKey();
  sendKeys1(customKey);
  sendKeys2(customKey2);
  delay(30);
}

void sendKeys1(char customKey) {
  if (customKey) {
    digitalWrite(LED_STATE, HIGH);
    switch (customKey) {
      case '0':
        Serial.write(B10010000);
        Serial.write(1);
        Serial.write(100);
        break;
      case '1':
        Serial.write(B10010000);
        Serial.write(2);
        Serial.write(100);
        break;
      case '2':
        Serial.write(B10010000);
        Serial.write(3);
        Serial.write(100);
        break;
      case '3':
        Serial.write(B10010000);
        Serial.write(4);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(4);
        Serial.write(0);
        break;
      case '4':
        Serial.write(B10010000);
        Serial.write(5);
        Serial.write(100);
        break;
      case '5':
        Serial.write(B10010000);
        Serial.write(6);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(6);
        Serial.write(0);
        break;
      case '6':
        Serial.write(B10010000);
        Serial.write(7);
        Serial.write(100);
        break;
      case '7':
        Serial.write(B10010000);
        Serial.write(8);
        Serial.write(100);
        break;
      case '8':
        Serial.write(B10010000);
        Serial.write(9);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(9);
        Serial.write(0);
        break;
      case '9':
        Serial.write(B10010000);
        Serial.write(10);
        Serial.write(100);
        break;
      case 'A':
        Serial.write(B10010000);
        Serial.write(11);
        Serial.write(100);
        break;
      case 'B':
        Serial.write(B10010000);
        Serial.write(12);
        Serial.write(100);
        break;
      case 'C':
        Serial.write(B10010000);
        Serial.write(13);
        Serial.write(100);
        break;
      case 'D':
        Serial.write(B10010000);
        Serial.write(14);
        Serial.write(100);
        break;
      case 'E':
        Serial.write(B10010000);
        Serial.write(15);
        Serial.write(100);
        break;
      case 'F':
        Serial.write(B10010000);
        Serial.write(16);
        Serial.write(100);
        break;
    }
  }
}

void sendKeys2(char customKey) {
  if (customKey) {
    digitalWrite(LED_STATE, HIGH);
    switch (customKey) {
      case '0':
        Serial.write(B10010000);
        Serial.write(17);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(17);
        Serial.write(0);
        break;
      case '1':
        Serial.write(B10010000);
        Serial.write(18);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(18);
        Serial.write(0);
        break;
      case '2':
        Serial.write(B10010000);
        Serial.write(19);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(19);
        Serial.write(0);
        break;
      case '3':
        Serial.write(B10010000);
        Serial.write(20);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(20);
        Serial.write(0);
        break;
      case '4':
        Serial.write(B10010000);
        Serial.write(21);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(21);
        Serial.write(0);
        break;
      case '5':
        Serial.write(B10010000);
        Serial.write(22);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(22);
        Serial.write(0);
        break;
      case '6':
        Serial.write(B10010000);
        Serial.write(23);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(23);
        Serial.write(0);
        break;
      case '7':
        Serial.write(B10010000);
        Serial.write(24);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(24);
        Serial.write(0);
        break;
      case '8':
        Serial.write(B10010000);
        Serial.write(25);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(25);
        Serial.write(0);
        break;
      case '9':
        Serial.write(B10010000);
        Serial.write(26);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(26);
        Serial.write(0);
        break;
      case 'A':
        Serial.write(B10010000);
        Serial.write(27);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(27);
        Serial.write(0);
        break;
      case 'B':
        Serial.write(B10010000);
        Serial.write(28);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(28);
        Serial.write(0);
        break;
      case 'C':
        Serial.write(B10010000);
        Serial.write(29);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(29);
        Serial.write(0);
        break;
      case 'D':
        Serial.write(B10010000);
        Serial.write(30);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(30);
        Serial.write(0);
        break;
      case 'E':
        Serial.write(B10010000);
        Serial.write(31);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(31);
        Serial.write(0);
        break;
      case 'F':
        Serial.write(B10010000);
        Serial.write(32);
        Serial.write(100);
        delay(200);
        Serial.write(B10010000);
        Serial.write(32);
        Serial.write(0);
        break;
    }
  }
}
