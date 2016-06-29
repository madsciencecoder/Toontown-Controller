#/*
# * Copyright (c) 2016 Joshua Snyder
# * Distributed under the GNU GPL V2. For full terms see the file LICENSE
# *
# * This file is part of Toontown Controller.
# *
# * Toontown Controller is free software: you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation, either version 2 of the License, or
# * (at your option) any later version.
# *
# * Toontown Controller is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# *
# * You should have received a copy of the GNU General Public License
# * along with Toontown Controller.  If not, see <http://www.gnu.org/licenses/>.
# */


#-------------------------------------------------
#
# Project created by QtCreator 2016-06-18T17:50:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = toontown-controller
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/preferenceswindow.cpp \
    src/keymapbutton.cpp \
    src/keyhelper.cpp \
    src/controller.cpp \
    src/keymap.cpp

HEADERS  += src/mainwindow.h \
    src/preferenceswindow.h \
    src/keymap.h \
    src/keymapbutton.h \
    src/keyhelper.h \
    src/controller.h \
    src/defines.h

LIBS += -lxdo -lX11

include(libraries/UGlobalHotkey/uglobalhotkey.pri)

RESOURCES += \
    src/resources.qrc

DISTFILES += LICENSE
unix:!mac {
    isEmpty(PREFIX):PREFIX = /usr
    BINDIR = $$PREFIX/bin
    INSTALLS += target
    target.path = $$BINDIR
    DATADIR = $$PREFIX/share
    PKGDATADIR = $$DATADIR/toontown-controls
    DEFINES += DATADIR=\\\"$$DATADIR\\\" \
        PKGDATADIR=\\\"$$PKGDATADIR\\\"
    INSTALLS += desktop \
        icon8 \
        icon16 \
        icon32 \
        icon64 \
        icon128 \
        icon256 \
        iconsvg
    desktop.path = $$DATADIR/applications
    desktop.files += toontown-controller.desktop
    icon8.path = $$DATADIR/icons/hicolor/8x8/apps
    icon8.files += icons/8x8/toontown-controller.png
    icon16.path = $$DATADIR/icons/hicolor/16x16/apps
    icon16.files += icons/16x16/toontown-controller.png
    icon32.path = $$DATADIR/icons/hicolor/32x32/apps
    icon32.files += icons/32x32/toontown-controller.png
    icon64.path = $$DATADIR/icons/hicolor/64x64/apps
    icon64.files += icons/64x64/toontown-controller.png
    icon128.path = $$DATADIR/icons/hicolor/128x128/apps
    icon128.files += icons/128x128/toontown-controller.png
    icon256.path = $$DATADIR/icons/hicolor/256x256/apps
    icon256.files += icons/256x256/toontown-controller.png
    iconsvg.path = $$DATADIR/icons/hicolor/scalable/apps
    iconsvg.files += icons/scalable/toontown-controller.svg
}
