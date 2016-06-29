## Toontown Controller

Linux controller for Toontown-like games.  This is specifically written for Toontown Rewritten but should work on any version that supports Linux and uses the same key mapping.

Please note: This program uses special X11 interfaces so it will probably not work on Wayland desktops.  It may work on Wayland if XWayland puts all three windows in the same server but it is untested.

### Screenshots

Colors, icons, and theme may be different depending on the user's platform and Qt theme.

![](https://raw.githubusercontent.com/madsciencecoder/Toontown-Controller/master/screenshots/controller-window.png)
![](https://raw.githubusercontent.com/madsciencecoder/Toontown-Controller/master/screenshots/preferences-window.png)

### Linux Packages

TODO: Make packages through openSUSE's OBS.

### Features

* Global hotkey to activate the controller (fixed to the ` key (above tab on full size US keyboards)
* Left and right controls to control 2 independent toons at once
* Independent controls for moving, jumping, leaving cranes/tables in CFO/CEO, and freezing the window (useful for avoiding some glitches)
* Combined controls for opening street maps, throwing pies/evidence in VP/CJ, throwing a low power pie/evidence in VP/CJ, opening gag menu, and opening toontasks menu
* Customizeable key mapping (besides activation hotkey)
* Timer that prevents toons from going to sleep (in most circumstances).  This may cause the gag menu to flash breifly depending on how fast it opens it.

### How to Compile

This program relies on Qt 5, libxdo, X11, and UGlobalHotkey.  UGlobalHotkey is provided as a git submodule so you will need to pull it manually or use git clone --recursive.

#### Linux based distros

##### Ubuntu / Debian

Required dependency packages: TODO

To build and install:
```
export QT_SELECT=qt5
qmake
make
sudo make install
```

##### OpenSuse

Required dependency packages: TODO

To build and install:
```
qmake-qt5
make
sudo make install
````

##### Fedora

Required dependency packages: TODO

To build and install:
```
qmake-qt5
make
sudo make install
````

##### Arch

Required dependency packages: `qt5-base xdotool`.

To build and install:
```
qmake
make
sudo make install
````

AUR package: TODO

### Icon source

The icon is from https://openclipart.org/detail/227918/video-game-controller-icon.
