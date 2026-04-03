#include <DigiKeyboard.h>

// TEST: SOUND — plays a Windows system beep via PowerShell
// Board: DigiSpark

void setup() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.print("powershell -w h -c \"[console]::beep(880,500)\"");
  DigiKeyboard.sendKeyStroke(KEY_RETURN);
}

void loop() {}
