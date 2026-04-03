#include <DigiKeyboard.h>

// TEST: NOTIFY — pops up a fake "Critical Error" dialog for 5 seconds
// Board: DigiSpark

void setup() {
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  DigiKeyboard.print("mshta javascript:new ActiveXObject(\"WScript.Shell\").Popup(\"A critical system error has occurred\",5,\"Critical Error\",16);close()");
  DigiKeyboard.sendKeyStroke(KEY_RETURN);
}

void loop() {}
