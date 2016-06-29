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


#include "keymapbutton.h"

#include <QString>
#include <QKeyEvent>
#include <QFocusEvent>

KeyMapButton::KeyMapButton(QWidget *parent) : QPushButton(parent)
{
    hasChanged = false;

    keyHelper = new KeyHelper();
    connect(this, SIGNAL(clicked(bool)), this, SLOT(setKey()));
}

void KeyMapButton::focusOutEvent(QFocusEvent *event)
{
    if(hasChanged || oldText.isEmpty())
    {
        event->accept();
    }
    else
    {
        this->setText(oldText);
        event->accept();
    }
    emit releaseKeyboardFocus();
}

void KeyMapButton::keyPressEvent(QKeyEvent *event)
{
    hasChanged = true;
    this->setText(keyHelper->getFriendlyName(event->key()));

    emit sendKeyCode(event->key());

    this->clearFocus();

    event->accept();
}

void KeyMapButton::setKey()
{
    hasChanged = false;
    oldText = this->text();

    this->setText("Press Key");

    this->grabKeyboard();
}
