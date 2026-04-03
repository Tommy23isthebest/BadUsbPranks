#include <DigiKeyboard.h>

// TEST: CLIPBOARD — replaces clipboard with a prank message via Terminal
// Board: DigiSpark
// After running, press Cmd+V anywhere to see the result.

void setup() {
  DigiKeyboard.delay(2000);

  // Cmd+Space → Spotlight → open Terminal
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("Terminal");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_RETURN);
  DigiKeyboard.delay(3000);

  DigiKeyboard.print("echo 'I already read that' | pbcopy");
  DigiKeyboard.sendKeyStroke(KEY_RETURN);
  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_W, MOD_GUI_LEFT);
}

void loop() {}
