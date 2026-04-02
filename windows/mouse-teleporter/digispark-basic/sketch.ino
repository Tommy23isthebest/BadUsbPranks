#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

// DigiSpark — Windows Mouse Jiggler (Standalone)
// Writes a hidden PowerShell script that teleports the mouse every 2 minutes.
// Survives unplugging — kill with: Stop-Process -Name powershell (in Task Manager)

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.print(c);delay(8);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(80);}

void setup() {
  DigiKeyboard.delay(5000);

  // Win+R → open Run dialog
  DigiKeyboard.sendKeyStroke(0x15, MOD_GUI_LEFT);
  DigiKeyboard.delay(1200);  // wait for Run dialog to appear

  ptype(PSTR("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3500);  // wait for PowerShell window to fully open

  // Write the script using a here-string (handles any chars safely)
  pln(PSTR("$f=\"$env:TEMP\\j.ps1\""));
  pln(PSTR("@'"));
  pln(PSTR("Add-Type -AssemblyName System.Windows.Forms"));
  pln(PSTR("while(1){"));
  pln(PSTR(" Start-Sleep 120"));
  pln(PSTR(" $x=Get-Random -Min 0 -Max 2560"));
  pln(PSTR(" $y=Get-Random -Min 0 -Max 1600"));
  pln(PSTR(" [System.Windows.Forms.Cursor]::Position=New-Object System.Drawing.Point($x,$y)"));
  pln(PSTR("}"));
  pln(PSTR("'@ | sc $f"));

  // Launch script hidden — path quoted to handle spaces in user profile
  pln(PSTR("Start-Process powershell -WindowStyle Hidden -ArgumentList \"-File\",\"`\"$f`\"\""));
  pln(PSTR("exit"));
}
void loop(){DigiKeyboard.delay(1);}
