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


#include "controller.h"
#include "defines.h"

#include <sys/types.h>
#include <signal.h>

#include <QDebug>
#include <QKeyEvent>

Controller::Controller(KeyMap *keyMap1, QWidget *parent) : QWidget(parent)
{
    keyMap = keyMap1;

    //setup a timer to keep toons from sleeping
    timer = new QTimer(this);
    timer->setInterval(60000);
    connect(timer, SIGNAL(timeout()), this, SLOT(keepToonsAwake()));
    timer->start();


    display = XOpenDisplay(NULL);

    xdo = xdo_new((char *) display);

    this->grabKeyboard();

    globalHotKey = new UGlobalHotkeys(this);
    globalHotKey->registerHotkey("`");
    connect(globalHotKey, &UGlobalHotkeys::activated, [&](size_t) {
            activateController();
    });
}

void Controller::setLeftWindow()
{
    xdo_select_window_with_click(xdo, &leftWindow);
    leftPID = xdo_get_pid_window(xdo, leftWindow);
}

void Controller::setRightWindow()
{
    xdo_select_window_with_click(xdo, &rightWindow);
    rightPID = xdo_get_pid_window(xdo, rightWindow);
}

void Controller::keyPressEvent(QKeyEvent *e)
{
    if(e->isAutoRepeat())
    {
        //ignore autorepeat keypresses
        return;
    }

    //check if it is any of the hotkeys and send the key if so
    int key = e->key();

    if (key == keyMap->getKey(lFKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "Up", 0);
        return;
    }
    else if (key == keyMap->getKey(rFKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "Up", 0);
        return;
    }
    else if (key == keyMap->getKey(lRKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "Right", 0);
        return;
    }
    else if (key == keyMap->getKey(rRKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "Right", 0);
        return;
    }
    else if (key == keyMap->getKey(lLKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "Left", 0);
        return;
    }
    else if (key == keyMap->getKey(rLKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "Left", 0);
        return;
    }
    else if (key == keyMap->getKey(lBKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "Down", 0);
        return;
    }
    else if (key == keyMap->getKey(rBKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "Down", 0);
        return;
    }
    else if (key == keyMap->getKey(lJKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "ctrl", 0);
        return;
    }
    else if (key == keyMap->getKey(rJKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "ctrl", 0);
        return;
    }
    else if (key == keyMap->getKey(lEKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, leftWindow, "Escape", 0);
        return;
    }
    else if (key == keyMap->getKey(rEKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_down(xdo, rightWindow, "Escape", 0);
        return;
    }
    else if (key == keyMap->getKey(lFreezeKey) && leftWindow != controllerWindow)
    {
        if(leftPID > 0)
        {
            kill(leftPID, SIGSTOP);
        }

        return;
    }
    else if (key == keyMap->getKey(rFreezeKey) && rightWindow != controllerWindow)
    {
        if(rightPID > 0)
        {
            kill(rightPID, SIGSTOP);
        }
        return;
    }
    else if (key == keyMap->getKey(mapKey) && leftWindow != controllerWindow)
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, leftWindow, "Alt", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, rightWindow, "Alt", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(pieKey) && leftWindow != controllerWindow)
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, leftWindow, "Delete", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, rightWindow, "Delete", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(lowPieKey) && leftWindow != controllerWindow)
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window(xdo, leftWindow, "Delete", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window(xdo, rightWindow, "Delete", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(homeKey) && leftWindow != controllerWindow)
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, leftWindow, "Home", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, rightWindow, "Home", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(endKey) && leftWindow != controllerWindow)
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, leftWindow, "End", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_down(xdo, rightWindow, "End", 0);
        }
        return;
    }
}

void Controller::keyReleaseEvent(QKeyEvent *e)
{
    if(e->isAutoRepeat())
    {
        //ignore autorepeat keypresses
        return;
    }

    //check if it is any of the hotkeys and stop sending the key if so
    int key = e->key();

    if (key == keyMap->getKey(lFKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "Up", 0);
        return;
    }
    else if (key == keyMap->getKey(rFKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "Up", 0);
        return;
    }
    else if (key == keyMap->getKey(lRKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "Right", 0);
        return;
    }
    else if (key == keyMap->getKey(rRKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "Right", 0);
        return;
    }
    else if (key == keyMap->getKey(lLKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "Left", 0);
        return;
    }
    else if (key == keyMap->getKey(rLKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "Left", 0);
        return;
    }
    else if (key == keyMap->getKey(lBKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "Down", 0);
        return;
    }
    else if (key == keyMap->getKey(rBKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "Down", 0);
        return;
    }
    else if (key == keyMap->getKey(lJKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "ctrl", 0);
        return;
    }
    else if (key == keyMap->getKey(rJKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "ctrl", 0);
        return;
    }
    else if (key == keyMap->getKey(lEKey) && leftWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, leftWindow, "Escape", 0);
        return;
    }
    else if (key == keyMap->getKey(rEKey) && rightWindow != controllerWindow)
    {
        xdo_send_keysequence_window_up(xdo, rightWindow, "Escape", 0);
        return;
    }
    else if (key == keyMap->getKey(lFreezeKey) && leftWindow != controllerWindow)
    {
        if(leftPID > 0)
        {
            kill(leftPID, SIGCONT);
        }
        return;
    }
    else if (key == keyMap->getKey(rFreezeKey) && rightWindow != controllerWindow)
    {
        if(rightPID > 0)
        {
            kill(rightPID, SIGCONT);
        }
        return;
    }
    else if (key == keyMap->getKey(mapKey))
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, leftWindow, "Alt", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, rightWindow, "Alt", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(pieKey))
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, leftWindow, "Delete", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, rightWindow, "Delete", 0);
        }
        return;
    }
    else if (key == keyMap->getKey(homeKey))
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, leftWindow, "Home", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, rightWindow, "Home", 0);

        }
        return;
    }
    else if (key == keyMap->getKey(endKey))
    {
        if(leftWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, leftWindow, "End", 0);
        }

        if(rightWindow != controllerWindow)
        {
            xdo_send_keysequence_window_up(xdo, rightWindow, "End", 0);
        }
        return;
    }
}

void Controller::updateKeys(KeyMap *keyMap1)
{
    keyMap = keyMap1;
}

void Controller::regainKeyboardFocus()
{
    this->grabKeyboard();
}

void Controller::activateController()
{
    xdo_activate_window(xdo, controllerWindow);

    //backup hack because xdo sometimes doesnt work for some reason
    emit activateWindow();
}

void Controller::getControllerWindow()
{
    if(!windowSet)
    {
        xdo_get_active_window(xdo, &controllerWindow);
        windowSet = true;
    }
}

void Controller::keepToonsAwake()
{
    xdo_send_keysequence_window(xdo, leftWindow, "Home", 0);
    xdo_send_keysequence_window(xdo, rightWindow, "Home", 0);
}
