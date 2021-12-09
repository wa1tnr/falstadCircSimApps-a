#if 0

ONLY FOR:
  https://www.falstad.com/circuit/avr8js/ 

#define PB_SWITCH 8
#define INDICATOR_LED 9
void setup_OLD(void) {
  pinMode(PB_SWITCH, INPUT);
  pinMode(INDICATOR_LED, OUTPUT);
}
void loop_OLD(void) {
  int buttonState = digitalRead(PB_SWITCH);
  if (buttonState) digitalWrite(INDICATOR_LED, 1);
  if (!buttonState) digitalWrite(INDICATOR_LED,0);
}


#endif

#if 0

The Circuit:

$ 1 0.000005 382.76258214399064 50 5 50 5e-11
207 176 176 96 176 4 pin\s8
418 208 224 96 224 0 1 40 5 0 0 0.5 pin\s9
r 208 224 272 224 0 180
162 272 224 384 224 2 default-led 1 0 0 0.01
g 384 224 432 224 0 0
g 336 176 368 176 0 0
R 176 112 176 48 0 0 40 5 0 0 0.5
r 176 112 176 176 0 100000
x 245 39 337 42 4 14 Java\sthe\sHutt\sii
s 240 176 336 176 0 1 true
w 176 176 240 176 0
o 0 64 0 4099 5 0.00009765625 0 2 0 3
#endif

// active code for above circuit:

#define GETTER 8
#define BLINKING 9

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Welcome to the machine.");
  pinMode(GETTER, INPUT); // pb Switch
  pinMode(BLINKING, OUTPUT);
}

void cpl(int LED_A) {
    bool pinState = digitalRead(LED_A);
    pinState = !pinState;
    digitalWrite(LED_A, pinState);
}
bool trap = 0;

void action(void) {
    cpl(BLINKING);
    trap = -1; // ran once
}

void look_at(int getter, bool getting) {
    bool state = getting;
    if (state) {
      if (!trap) action();
    }
    if (!state) trap = 0; // reset
}

void loop() {
    bool getting = (bool) digitalRead(GETTER);
    getting = !getting; // want it inverted
    look_at(GETTER, getting);  // pin, state
}
// END.

