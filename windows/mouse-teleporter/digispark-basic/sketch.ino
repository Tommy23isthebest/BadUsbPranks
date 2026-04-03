#include <DigiKeyboard.h>
#include <avr/pgmspace.h>

// DigiSpark — Windows Persistent Mouse Jiggler
// Mouse moves every 3 seconds while DigiSpark is plugged in,
// every 2 minutes after it is unplugged.
// Uses WMI (gwmi Win32_PnPEntity) for live USB detection — works reliably.
//
// Board: Digispark (Default - 16.5mhz)
// UPLOAD: click Upload FIRST, plug in when Arduino IDE says "Plug in device now"

void ptype(const char* s){char c;while((c=pgm_read_byte(s++))){DigiKeyboard.update();DigiKeyboard.print(c);DigiKeyboard.delay(10);}}
void pln(const char* s){ptype(s);DigiKeyboard.sendKeyStroke(KEY_ENTER);DigiKeyboard.delay(80);}

void setup() {
  DigiKeyboard.delay(5000);

  DigiKeyboard.sendKeyStroke(0);                  // wake HID interface
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(0x15, MOD_GUI_LEFT); // Win+R
  DigiKeyboard.delay(1500);

  ptype(PSTR("powershell"));
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3500);

  // Script (decoded):
  // Add-Type -MemberDefinition '[DllImport("user32.dll")]...' -Name M -Namespace W
  // while(1){
  //   $p=[bool](gwmi Win32_PnPEntity|?{$_.DeviceID -match 'VID_16C0' -and $_.Status -eq 'OK'})
  //   if($p){Start-Sleep 3}else{Start-Sleep 120}
  //   [W.M]::SetCursorPos((Get-Random -Max 3840),(Get-Random -Max 2160))  // 4K range
  // }
  pln(PSTR("Start-Process powershell -WindowStyle Hidden -ArgumentList '-ExecutionPolicy','Bypass','-EncodedCommand','QQBkAGQALQBUAHkAcABlACAALQBNAGUAbQBiAGUAcgBEAGUAZgBpAG4AaQB0AGkAbwBuACAAJwBbAEQAbABsAEkAbQBwAG8AcgB0ACgAIgB1AHMAZQByADMAMgAuAGQAbABsACIAKQBdAHAAdQBiAGwAaQBjACAAcwB0AGEAdABpAGMAIABlAHgAdABlAHIAbgAgAGIAbwBvAGwAIABTAGUAdABDAHUAcgBzAG8AcgBQAG8AcwAoAGkAbgB0ACAAeAAsAGkAbgB0ACAAeQApADsAJwAgAC0ATgBhAG0AZQAgAE0AIAAtAE4AYQBtAGUAcwBwAGEAYwBlACAAVwA7AHcAaABpAGwAZQAoADEAKQB7ACQAcAA9AFsAYgBvAG8AbABdACgAZwB3AG0AaQAgAFcAaQBuADMAMgBfAFAAbgBQAEUAbgB0AGkAdAB5AHwAPwB7ACQAXwAuAEQAZQB2AGkAYwBlAEkARAAgAC0AbQBhAHQAYwBoACAAJwBWAEkARABfADEANgBDADAAJwAgAC0AYQBuAGQAIAAkAF8ALgBTAHQAYQB0AHUAcwAgAC0AZQBxACAAJwBPAEsAJwB9ACkAOwBpAGYAKAAkAHAAKQB7AFMAdABhAHIAdAAtAFMAbABlAGUAcAAgADMAfQBlAGwAcwBlAHsAUwB0AGEAcgB0AC0AUwBsAGUAZQBwACAAMQAyADAAfQA7AFsAVwAuAE0AXQA6ADoAUwBlAHQAQwB1AHIAcwBvAHIAUABvAHMAKAAoAEcAZQB0AC0AUgBhAG4AZABvAG0AIAAtAE0AYQB4ACAAMwA4ADQAMAApACwAKABHAGUAdAAtAFIAYQBuAGQAbwBtACAALQBNAGEAeAAgADIAMQA2ADAAKQApAH0A'"));
  pln(PSTR("exit"));
}
void loop(){DigiKeyboard.delay(1);}
