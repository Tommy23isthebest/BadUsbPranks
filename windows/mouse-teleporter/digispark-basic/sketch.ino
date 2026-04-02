#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

// DigiSpark — Windows Mouse Jiggler (Standalone)
// Uses SetCursorPos via user32.dll — works reliably in hidden processes.
// Timing: 3 seconds while DigiSpark is plugged in, 120 seconds when unplugged.
// Survives unplugging — kill with the uninstaller sketch or Task Manager.

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.update();DigiKeyboard.print(c);DigiKeyboard.delay(10);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(80);}

void setup() {
  DigiKeyboard.delay(5000);

  // Win+R → PowerShell
  DigiKeyboard.sendKeyStroke(0x15, MOD_GUI_LEFT);
  DigiKeyboard.delay(1200);
  ptype(PSTR("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3500);

  // Write the script using a here-string
  pln(PSTR("$f=\"$env:TEMP\\j.ps1\""));
  pln(PSTR("@'"));

  // Load SetCursorPos from user32.dll — works from hidden/background processes
  pln(PSTR("Add-Type -TypeDefinition 'using System;using System.Runtime.InteropServices;public class M{[DllImport(\"user32.dll\")]public static extern bool SetCursorPos(int x,int y);}' -Language CSharp"));

  // 3s when DigiSpark is plugged in (VID_16C0), 120s when unplugged
  pln(PSTR("while(1){"));
  pln(PSTR(" if(Test-Path 'HKLM:\\SYSTEM\\CurrentControlSet\\Enum\\USB\\VID_16C0'){Start-Sleep 3}"));
  pln(PSTR(" else{Start-Sleep 120}"));
  pln(PSTR(" [M]::SetCursorPos((Get-Random -Min 0 -Max 2560),(Get-Random -Min 0 -Max 1600))"));
  pln(PSTR("}"));

  pln(PSTR("'@ | sc $f"));

  // Launch hidden — $f passed as separate array element so spaces in path are safe
  pln(PSTR("Start-Process powershell -ArgumentList \"-WindowStyle\",\"Hidden\",\"-File\",$f"));
  pln(PSTR("exit"));
}
void loop(){DigiKeyboard.delay(1);}
