
Debian
====================
This directory contains files used to package dreamledgerd/dreamledger-qt
for Debian-based Linux systems. If you compile dreamledgerd/dreamledger-qt yourself, there are some useful files here.

## dreamledger: URI support ##


dreamledger-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install dreamledger-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dreamledger-qt binary to `/usr/bin`
and the `../../share/pixmaps/dreamledger128.png` to `/usr/share/pixmaps`

dreamledger-qt.protocol (KDE)

