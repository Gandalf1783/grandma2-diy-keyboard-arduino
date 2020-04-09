#include <Adafruit_NeoPixel.h>
#include <Keypad.h>

#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 1

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

uint32_t default_high = strip.Color(224, 114, 0);
uint32_t default_color = strip.Color(122, 78, 0);
const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'0', '1', '2', '3'},
  {'4', '5', '6', '7'},
  {'8', '9', 'A', 'B'},
  {'C', 'D', 'E', 'F'},
};
byte colPins[COLS] = {31, 33, 35, 37};
byte rowPins[ROWS] = {36, 34, 32, 30};
byte colPins2[COLS] = {39, 41, 43, 45};
byte rowPins2[ROWS] = {44, 42, 40, 38};
const int COUNT = ROWS * COLS;
boolean button[COUNT] = {
  false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false
};

boolean key1 = false;
boolean key2 = false;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Keypad customKeypad2 = Keypad( makeKeymap(hexaKeys), rowPins2, colPins2, ROWS, COLS);

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(115200);
  Serial.println("grandMA2 onPC Controller Ver.1.0");
  Serial.println("Initialising Devices...");

  //INIT DEVICES HERE

  pinMode(LED_BUILTIN, OUTPUT);
  strip.begin();
  strip.show();

  digitalWrite(12, HIGH);

  strip.clear();
  //Coloring Strip to default - Preparing for default operation
  strip.fill(default_high, 0, LED_COUNT);
  strip.show();

  waitForTestMode();

  Serial.println("Devices configured.");
  Serial.println("Starting...");
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  delay(1000);
  Serial.println("Ready.");

}

void loop() {
  char customKey = customKeypad.getKey();
  char customKey2 = customKeypad2.getKey();
  if (customKey) {
    digitalWrite(12, LOW);
  }
  if (customKey2) {
    digitalWrite(12, LOW);
  }
  delay(40);
  digitalWrite(12, HIGH);
  sendFirstMIDI(customKey);
  sendSecondMIDI(customKey2);
}

void waitForTestMode() {
  uint32_t period = 5 * 600L;       // 5 minutes
  for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    char customKey = customKeypad.getKey();
    char customKey2 = customKeypad2.getKey();

    if (customKey) {
      switch (customKey) {
        case 'F':
          key1 = true;
          break;
      }
    }
    if (customKey2) {
      switch (customKey2) {
        case 'F':
          key2 = true;
          break;
      }
    }

    if (key1 && key2) {

      Serial.println("TEST MODE");
      Serial.println("Setting up TestMode enviroment...");
      //Turning off LEDS
      digitalWrite(LED_BUILTIN, LOW);
      strip.clear();
      strip.show();
      //Array of booleans, index turns true if the button is pressed.
      boolean keypad1[16] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false
      };
      boolean keypad2[16] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false
      };

      delay(100);
      Serial.println("Press all keys. Reset Board or re-insert to exit Testmode.");
      //Repeating forever, waiting for keypresses

      while (true) {
        char customKey = customKeypad.getKey();
        char customKey2 = customKeypad2.getKey();
        if (customKey) {
          digitalWrite(12, LOW);
          Serial.println("Keyboard 1 was pressed");
          switch (customKey) {
            case '0':
              keypad1[0] = true;
            case '1':
              keypad1[1] = true;
              break;
            case '2':
              keypad1[2] = true;
              break;
            case '3':
              keypad1[3] = true;
              break;
            case '4':
              keypad1[4] = true;
              break;
            case '5':
              keypad1[5] = true;
              break;
            case '6':
              keypad1[6] = true;
              break;
            case '7':
              keypad1[7] = true;
              break;
            case '8':
              keypad1[8] = true;
              break;
            case '9':
              keypad1[9] = true;
              break;
            case 'A':
              keypad1[10] = true;
              break;
            case 'B':
              keypad1[11] = true;
              break;
            case 'C':
              keypad1[12] = true;
              break;
            case 'D':
              keypad1[13] = true;
              break;
            case 'E':
              keypad1[14] = true;
              break;
            case 'F':
              keypad1[15] = true;
              break;
          }
        }
        if (customKey2) {
          digitalWrite(12, LOW);
          Serial.println("Keyboard 2 was pressed");
          switch (customKey2) {
            case '0':
              keypad2[0] = true;
              break;
            case '1':
              keypad2[1] = true;
              break;
            case '2':
              keypad2[2] = true;
              break;
            case '3':
              keypad2[3] = true;
              break;
            case '4':
              keypad2[4] = true;
              break;
            case '5':
              keypad2[5] = true;
              break;
            case '6':
              keypad2[6] = true;
              break;
            case '7':
              keypad2[7] = true;
              break;
            case '8':
              keypad2[8] = true;
              break;
            case '9':
              keypad2[9] = true;
              break;
            case 'A':
              keypad2[10] = true;
              break;
            case 'B':
              keypad2[11] = true;
              break;
            case 'C':
              keypad2[12] = true;
              break;
            case 'D':
              keypad2[13] = true;
              break;
            case 'E':
              keypad2[14] = true;
              break;
            case 'F':
              keypad2[15] = true;
              break;
          }
        }
        //Setting up testComplete
        bool testComplete = true;
        //Checking if every key on keypad1 was pressed
        for (bool temp_bool : keypad1) {
          if (!temp_bool) {
            //setting testComplete to false when not
            testComplete = false;
          }
        }
        //Checking if every key on keypad 2 was pressed
        for (bool temp_bool : keypad2) {
          if (!temp_bool) {
            //setting testComplete to false when not
            testComplete = false;
          }
        }
        //When testComplete = true, while loop will exit and continue
        if (testComplete) {
          Serial.println("Button test complete...");
          break;
        }
        delay(40);
        digitalWrite(12, HIGH);
      } // END WHILE LOOP

      Serial.println("Turning on all LEDs. If ready, press any key.");
      delay(100);

      //Setting strip to white.
      strip.clear();
      uint32_t white = strip.Color(255, 255, 255);
      strip.fill(white, 0, LED_COUNT);
      strip.show();
      //Turning on onBoard LED
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(12, HIGH);

      while (true) {
        char customKey = customKeypad.getKey();
        char customKey2 = customKeypad2.getKey();
        //Wait until any key is pressed, if yes, break the loop.
        if (customKey || customKey2) {
          break;
        }
      }
      // Setting onBoard LED to off, and turning off LED-Strip
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(12, LOW);
      delay(500);
      Serial.println("Turning off all LEDs. If ready, press any key.");
      strip.clear();
      strip.show();

      while (true) {
        char customKey = customKeypad.getKey();
        char customKey2 = customKeypad2.getKey();
        //Waiting until any key is pressed, if yes, break the loop
        if (customKey || customKey2) {
          break;
        }
      }
      Serial.println("Done testing. Device is now under normal operation.");

      //Unsetting vars
      key1 = false;
      key2 = false;
      //Ending test program
    } else {
      key1 = false;
      key2 = false;
    }
  }
}






// ONLY MIDI SEND FUNCTIONS!!!






// NOTHING TO MODIFY HERE!

void sendFirstMIDI(char customKey) {
  if (customKey) {
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

void sendSecondMIDI(char customKey2) {

  if (customKey2) {
    switch (customKey2) {
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
