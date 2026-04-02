#include <DigiKeyboard.h>

void setup() {
  DigiKeyboard.delay(5000);
}

void loop() {
  DigiKeyboard.delay(300000); // every 5 minutes
  DigiKeyboard.sendKeyStroke(0x51, MOD_GUI_LEFT); // Win+Down
}
