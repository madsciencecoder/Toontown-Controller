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


#include "mainwindow.h"
#include "preferenceswindow.h"
#include "defines.h"

#include <QSettings>
#include <QDebug>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{ 
    this->installEventFilter(this);

    keyMap = new KeyMap();

    setupUi();
    readSettings();

    connect(settingsButton, SIGNAL(clicked(bool)), this, SLOT(setSettings()));

    controller = new Controller(keyMap);
    connect(leftControls, SIGNAL(clicked(bool)), controller, SLOT(setLeftWindow()));
    connect(rightControls, SIGNAL(clicked(bool)), controller, SLOT(setRightWindow()));
    connect(this, SIGNAL(relaySettings(KeyMap *)), controller,SLOT(updateKeys(KeyMap *)));
    connect(this, SIGNAL(windowHasFocus()), controller, SLOT(getControllerWindow()));
    connect(controller, SIGNAL(activateWindow()), this, SLOT(focusWindow()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupUi()
{
    this->setFixedSize(210, 40);

    leftControls = new QPushButton(this);
    rightControls = new QPushButton(this);
    settingsButton = new QPushButton(this);

    leftControls->setText("WASD");
    rightControls->setText("Arrows");

    settingsButton->setIcon(QIcon::fromTheme("preferences-other"));
    settingsButton->setToolTip("Settings");

    leftControls->setFixedSize(80, 30);
    rightControls->setFixedSize(80, 30);
    settingsButton->setFixedSize(30, 30);

    leftControls->move(5, 5);
    rightControls->move(90, 5);
    settingsButton->move(175, 5);


    leftControls->show();
    rightControls->show();
    settingsButton->show();
}

void MainWindow::readSettings()
{
    QSettings settings("TTR-Controls", "TTR-Controls");

    settings.beginGroup("MainWindow");
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    settings.endGroup();

    settings.beginGroup("KeyBindings");

    //check to see if custom bindings have been made
    if(settings.value("leftForwardKey").toString().isEmpty())
        keyMap->setKey(lFKey , Qt::Key_W);
    else
        keyMap->setKey(lFKey , settings.value("leftForwardKey").toInt());

    if(settings.value("rightForwardKey").toString().isEmpty())
        keyMap->setKey(rFKey , Qt::Key_Up);
    else
        keyMap->setKey(rFKey , settings.value("rightForwardKey").toInt());

    if(settings.value("leftRightKey").toString().isEmpty())
        keyMap->setKey(lRKey , Qt::Key_D);
    else
        keyMap->setKey(lRKey , settings.value("leftRightKey").toInt());

    if(settings.value("rightRightKey").toString().isEmpty())
        keyMap->setKey(rRKey , Qt::Key_Right);
    else
        keyMap->setKey(rRKey , settings.value("rightRightKey").toInt());

    if(settings.value("leftLeftKey").toString().isEmpty())
        keyMap->setKey(lLKey , Qt::Key_A);
    else
        keyMap->setKey(lLKey , settings.value("leftLeftKey").toInt());

    if(settings.value("rightLeftKey").toString().isEmpty())
        keyMap->setKey(rLKey , Qt::Key_Left);
    else
        keyMap->setKey(rLKey , settings.value("rightLeftKey").toInt());

    if(settings.value("leftBackwardKey").toString().isEmpty())
        keyMap->setKey(lBKey , Qt::Key_S);
    else
        keyMap->setKey(lBKey , settings.value("leftBackwardKey").toInt());

    if(settings.value("rightBackwardKey").toString().isEmpty())
        keyMap->setKey(rBKey , Qt::Key_Down);
    else
        keyMap->setKey(rBKey , settings.value("rightBackwardKey").toInt());

    if(settings.value("leftJumpKey").toString().isEmpty())
        keyMap->setKey(lJKey , Qt::Key_Shift);
    else
        keyMap->setKey(lJKey , settings.value("leftJumpKey").toInt());

    if(settings.value("rightJumpKey").toString().isEmpty())
        keyMap->setKey(rJKey , Qt::Key_Control);
    else
        keyMap->setKey(rJKey , settings.value("rightJumpKey").toInt());

    if(settings.value("leftEscKey").toString().isEmpty())
        keyMap->setKey(lEKey , Qt::Key_E);
    else
        keyMap->setKey(lEKey , settings.value("leftEscKey").toInt());

    if((settings.value("rightEscKey").toString().isEmpty()))
        keyMap->setKey(rEKey , Qt::Key_0);
    else
        keyMap->setKey(rEKey , settings.value("rightEscKey").toInt());

    if((settings.value("leftFreezeKey").toString().isEmpty()))
        keyMap->setKey(lFreezeKey , Qt::Key_Z);
    else
        keyMap->setKey(lFreezeKey , settings.value("leftFreezeKey").toInt());

    if((settings.value("rightFreezeKey").toString().isEmpty()))
        keyMap->setKey(rFreezeKey , Qt::Key_X);
    else
        keyMap->setKey(rFreezeKey , settings.value("rightFreezeKey").toInt());

    if(settings.value("mapKey").toString().isEmpty())
        keyMap->setKey(mapKey , Qt::Key_Alt);
    else
        keyMap->setKey(mapKey , settings.value("mapKey").toInt());

    if(settings.value("pieKey").toString().isEmpty())
        keyMap->setKey(pieKey , Qt::Key_Delete);
    else
        keyMap->setKey(pieKey , settings.value("pieKey").toInt());

    if(settings.value("lowpieKey").toString().isEmpty())
        keyMap->setKey(lowPieKey , Qt::Key_Q);
    else
        keyMap->setKey(lowPieKey , settings.value("lowPieKey").toInt());

    if(settings.value("homeKey").toString().isEmpty())
        keyMap->setKey(homeKey , Qt::Key_Home);
    else
        keyMap->setKey(homeKey , settings.value("homeKey").toInt());

    if(settings.value("endKey").toString().isEmpty())
        keyMap->setKey(endKey , Qt::Key_End);
    else
        keyMap->setKey(endKey , settings.value("endKey").toInt());

    if(settings.value("activateKey").toString().isEmpty())
        keyMap->setKey(activateKey , Qt::Key_QuoteLeft);
    else
        keyMap->setKey(activateKey , settings.value("activateKey").toInt());

    settings.endGroup();
}

void MainWindow::writeSettings()
{
    QSettings settings("TTR-Controls", "TTR-Controls");

    settings.beginGroup("MainWindow");
    settings.setValue("pos", pos());
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();

    event->accept();

}

void MainWindow::receiveSettings(KeyMap *keyMap1)
{
    keyMap = keyMap1;
    emit relaySettings(keyMap1);
}

void MainWindow::setSettings()
{
    PreferencesWindow *preferences = new PreferencesWindow(keyMap);

    connect(preferences, SIGNAL(sendSettings(KeyMap *)), this, SLOT(receiveSettings(KeyMap *)));
    connect(preferences, SIGNAL(releaseKeyboardFocus()), controller, SLOT(regainKeyboardFocus()));

    preferences->show();
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        emit windowHasFocus();
    }

    return QMainWindow::eventFilter(object, event);
}

void MainWindow::focusWindow()
{
    this->activateWindow();
}
