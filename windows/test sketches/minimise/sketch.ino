#include <DigiKeyboard.h>

// TEST: MINIMISE — presses Win+M to minimise all windows
// Board: DigiSpark

void setup() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_M, MOD_GUI_LEFT);
}

void loop() {}
