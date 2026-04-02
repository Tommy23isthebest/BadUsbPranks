# Bad USB Prank Lab
A collection of Arduino and DigiSpark HID payloads. Plug in, walk away.
> **For use on your own devices or with explicit permission only.**
---
## Hardware
| Board | Chip | USB HID | Price |
|---|---|---|---|
| DigiSpark | ATtiny85 | ✅ | ~$2 |
| Arduino Leonardo | ATMEGA32U4 | ✅ | ~$10 |
| Arduino Pro Micro | ATMEGA32U4 | ✅ | ~$5 |
| Arduino Micro | ATMEGA32U4 | ✅ | ~$10 |
| ESP32 | Xtensa LX6 | ❌ (WiFi only) | ~$5 |
---
## Setup
### DigiSpark
1. Open Arduino IDE → **File > Preferences**
2. Paste into *Additional Boards Manager URLs*:
https://raw.githubusercontent.com/ArminJo/DigistumpArduino/master/package_digistump_index.json

3. **Tools > Board > Boards Manager** → search `Digistump` → install
4. **Tools > Board > Digistump AVR Boards > Digispark (Default - 16.5mhz)**
5. Hit **Upload** — when IDE says *"Plug in device now..."* plug in DigiSpark (8 second window)
> **Mac M1/M2/M3/M4 fix:** DigiSpark's uploader is x86 only.
> Install x86 Homebrew and libusb:
> ```bash
> arch -x86_64 /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
> arch -x86_64 /usr/local/bin/brew install libusb-compat
> ```
### Leonardo / Pro Micro / Micro
1. **Tools > Board > Arduino AVR Boards > Arduino Leonardo** (or Micro)
2. Select correct **Port**
3. Upload normally — no timing trick needed
---
## Payloads
### 🖱️ Mouse Teleporter
Warps the cursor to a random position on screen. Runs silently in the background, survives unplugging.
| Version | Board | Platform | Interval |
|---|---|---|---|
| Basic | Leonardo / DigiSpark | Mac | Every 2 min |
| Ramp | Leonardo / DigiSpark | Mac | 10 min → 2 min |
| Basic | Leonardo / DigiSpark | Windows | Every 2 min |
| Ramp | Leonardo / DigiSpark | Windows | 10 min → 2 min |
| Uninstaller | DigiSpark | Mac / Windows | Kills + removes script |
**Mac:** Uses macOS Quartz framework — no accessibility permission dialog.
**Windows:** Uses built-in `System.Windows.Forms` — no Python needed.
**Ramp schedule:** starts at 10 min, drops 1 min per jump, floors at 2 min and stays there.
To stop (Mac): `pkill -f .j.py`
To stop (Windows): Task Manager → kill hidden `powershell.exe`
---
### 🪟 Window Minimiser
Minimises the active window on an escalating timer. Subtle at first, relentless by the end.
| Version | Board | Platform | Schedule |
|---|---|---|---|
| Basic | DigiSpark | Mac / Windows | Every 5 min |
| Ramp | DigiSpark | Mac / Windows | 35 min → 5 min over 2 hrs |
**Mac:** Sends `Escape` (exit fullscreen) then `Cmd+M`
**Windows:** Sends `Win+Down`
---
## How the Mac payloads work
1. Plug in → wait 5 seconds
2. Open Spotlight (`Cmd+Space`) → type `Terminal` → Enter
3. Write a Python script to `/tmp/.j.py` via heredoc
4. Install dependencies silently with `pip`
5. Launch script with `nohup` in background
6. Minimise Terminal window
7. Script runs forever — even after unplugging
## How the Windows payloads work
1. Plug in → wait 5 seconds
2. Open Run dialog (`Win+R`) → type `powershell` → Enter
3. Write a `.ps1` script to `%TEMP%\j.ps1`
4. Launch it as a hidden PowerShell process
5. Terminal closes
6. Script runs forever — even after unplugging
---
## Dependencies
| Payload | Dependency | Installed by |
|---|---|---|
| DigiSpark sketches | `DigiKeyboard.h` | DigiSpark board package |
| Leonardo sketches | `Keyboard.h` | Arduino IDE (built-in) |
| Mac mouse teleporter | `pyobjc-framework-Quartz` | Sketch (auto pip install) |
| Windows mouse teleporter | `System.Windows.Forms` | Windows (built-in) |
---
## File Structure
bad-usb-pranks/
├── mac/
│ ├── mouse-teleporter/
│ │ ├── leonardo-basic/
│ │ ├── leonardo-ramp/
│ │ ├── digispark-basic/
│ │ ├── digispark-ramp/
│ │ └── digispark-uninstaller/
│ └── window-minimiser/
│ ├── digispark-basic/
│ └── digispark-ramp/
└── windows/
├── mouse-teleporter/
│ ├── leonardo-basic/
│ ├── leonardo-ramp/
│ ├── digispark-basic/
│ ├── digispark-ramp/
│ └── digispark-uninstaller/
└── window-minimiser/
├── digispark-basic/
└── digispark-ramp/

---
## Disclaimer
These payloads are provided for educational and entertainment purposes. Only deploy on hardware you own or have explicit permission to use. The author accepts no responsibility for misuse.
