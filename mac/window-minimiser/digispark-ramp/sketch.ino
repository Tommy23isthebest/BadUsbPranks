#include <DigiKeyboard.h>

#define START_MS  2100000UL // 35 min
#define STEP      360000UL  // 6 min
#define MIN_MS    300000UL  // 5 min

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
