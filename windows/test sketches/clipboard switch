#include <DigiKeyboard.h>

// TEST: CLIPBOARD — replaces clipboard contents with a prank message
// Board: DigiSpark
// After running, press Ctrl+V anywhere to see the result.

void setup() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.print("powershell -w h -c \"Set-Clipboard 'I already read that'\"");
  DigiKeyboard.sendKeyStroke(KEY_RETURN);
}

void loop() {}
