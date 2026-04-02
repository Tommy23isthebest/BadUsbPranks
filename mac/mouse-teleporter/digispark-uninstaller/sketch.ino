#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.print(c);delay(8);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(50);}

void setup() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0x2C, MOD_GUI_LEFT);
  DigiKeyboard.delay(1200);
  ptype(PSTR("Terminal"));
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);
  pln(PSTR("pkill -f .j.py;rm -f /tmp/.j.py"));
  DigiKeyboard.delay(500);
  pln(PSTR("python3 -m pip uninstall pyobjc-framework-Quartz -y -q 2>/dev/null"));
  DigiKeyboard.delay(3000);
  pln(PSTR("osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}
void loop(){DigiKeyboard.delay(1);}
