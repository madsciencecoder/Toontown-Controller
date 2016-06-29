/*
 * Copyright (c) 2016 Joshua Snyder
 * Distributed under the GNU GPL V2. For full terms see the file LICENSE
 *
 * This file is part of Toontown Controller.
 *
 * Toontown Controller is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * Toontown Controller is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Toontown Controller.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "keymap.h"
#include "uglobalhotkeys.h"

#include <QWidget>
#include <QDataStream>
#include <QCursor>
#include <qcoreevent.h>
#include <QVariant>
#include <QUrl>
#include <QTextStream>
#include <QTimer>

extern "C"
{
    #include <xdo.h>
    #include <X11/Xlib.h>
}

class UGlobalHotkeys;

class Controller : public QWidget
{
    Q_OBJECT

public:
    Controller(KeyMap *, QWidget *parent = 0);

signals:
    void activateWindow();

public slots:
    void setLeftWindow();
    void setRightWindow();
    void updateKeys(KeyMap *);
    void regainKeyboardFocus();
    void getControllerWindow();

private slots:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void activateController();
    void keepToonsAwake();

private:
    xdo_t *xdo = NULL;
    Window leftWindow = 0;
    Window rightWindow = 0;
    Window controllerWindow = 0;
    Display *display = NULL;
    bool windowSet = false;
    unsigned int leftPID = 0;
    unsigned int rightPID = 0;

    QTimer *timer;

    KeyMap *keyMap;
    UGlobalHotkeys *globalHotKey;
};

#endif // CONTROLLER_H
