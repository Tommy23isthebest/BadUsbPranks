#include <DigiKeyboard.h>

#define START_MS  2100000UL
#define STEP      360000UL
#define MIN_MS    300000UL

unsigned long interval = START_MS;

void waitMs(unsigned long ms) {
  while (ms > 60000) { DigiKeyboard.delay(60000); ms -= 60000; }
  DigiKeyboard.delay(ms);
}

void setup() {
  DigiKeyboard.delay(5000);
}

void loop() {
  waitMs(interval);
  DigiKeyboard.sendKeyStroke(0x51, MOD_GUI_LEFT);
  if (interval > MIN_MS) interval -= STEP;
}
