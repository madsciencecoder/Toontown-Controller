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


#include "preferenceswindow.h"
#include "defines.h"

#include <QGridLayout>
#include <QSettings>
#include <QCloseEvent>

#include <QDebug>

PreferencesWindow::PreferencesWindow(KeyMap *keyMap1, QWidget *parent) : QDialog(parent)
{
    keyMap = keyMap1;
    keyHelper = new KeyHelper();

    setupUi();
}

void PreferencesWindow::setupUi()
{
    this->setWindowTitle("TTR Controls 2 - Settings");

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);

    leftForwardBox = new KeyMapButton(this);
    rightForwardBox = new KeyMapButton(this);
    leftRightBox = new KeyMapButton(this);
    rightRightBox = new KeyMapButton(this);
    leftLeftBox = new KeyMapButton(this);
    rightLeftBox = new KeyMapButton(this);
    leftBackwardBox = new KeyMapButton(this);
    rightBackwardBox = new KeyMapButton(this);
    leftJumpBox = new KeyMapButton(this);
    rightJumpBox = new KeyMapButton(this);
    leftEscBox = new KeyMapButton(this);
    rightEscBox = new KeyMapButton(this);
    leftFreezeBox = new KeyMapButton(this);
    rightFreezeBox = new KeyMapButton(this);
    mapBox = new KeyMapButton(this);
    pieBox = new KeyMapButton(this);
    lowPieBox = new KeyMapButton(this);
    homeBox = new KeyMapButton(this);
    endBox = new KeyMapButton(this);
    activateBox = new KeyMapButton(this);
    okBox = new QPushButton(this);
    cancelBox = new QPushButton(this);

    leftToonLabel = new QLabel(this);
    rightToonLabel = new QLabel(this);
    forwardLabel = new QLabel(this);
    rightLabel = new QLabel(this);
    leftLabel = new QLabel(this);
    backwardLabel = new QLabel(this);
    jumpLabel = new QLabel(this);
    escLabel = new QLabel(this);
    freezeLabel = new QLabel(this);
    mapLabel = new QLabel(this);
    pieLabel = new QLabel(this);
    lowPieLabel = new QLabel(this);
    homeLabel = new QLabel(this);
    endLabel = new QLabel(this);
    activateLabel = new QLabel(this);

    leftToonLabel->setText("Left Toon");
    rightToonLabel->setText("Right Toon");
    forwardLabel->setText("Forward");
    rightLabel->setText("Right");
    leftLabel->setText("Left");
    backwardLabel->setText("Backward");
    jumpLabel->setText("Jump");
    escLabel->setText("Leave Table or Crane");
    freezeLabel->setText("Freeze Game");
    mapLabel->setText("Map");
    pieLabel->setText("Throw Pie");
    lowPieLabel->setText("Throw Low Pie");
    homeLabel->setText("Gags");
    endLabel->setText("Toontasks");
    activateLabel->setText("Activate Controller");

    leftForwardBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lFKey)));
    rightForwardBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rFKey)));
    leftRightBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lRKey)));
    rightRightBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rRKey)));
    leftLeftBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lLKey)));
    rightLeftBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rLKey)));
    leftBackwardBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lBKey)));
    rightBackwardBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rBKey)));
    leftJumpBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lJKey)));
    rightJumpBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rJKey)));
    leftEscBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lEKey)));
    rightEscBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rEKey)));
    leftFreezeBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lFreezeKey)));
    rightFreezeBox->setText(keyHelper->getFriendlyName(keyMap->getKey(rFreezeKey)));
    mapBox->setText(keyHelper->getFriendlyName(keyMap->getKey(mapKey)));
    pieBox->setText(keyHelper->getFriendlyName(keyMap->getKey(pieKey)));
    lowPieBox->setText(keyHelper->getFriendlyName(keyMap->getKey(lowPieKey)));
    homeBox->setText(keyHelper->getFriendlyName(keyMap->getKey(homeKey)));
    endBox->setText(keyHelper->getFriendlyName(keyMap->getKey(endKey)));
    //activateBox->setText(keyHelper->getFriendlyName(keyMap->getKey(activateKey)));
    activateBox->setText("BackTick (Above Tab)");

    okBox->setText("Save");
    okBox->setIcon(QIcon::fromTheme("document-save"));
    cancelBox->setText("Cancel");
    cancelBox->setIcon(QIcon::fromTheme("edit-delete"));

    //disable activate hotkey until implemented
    activateBox->setDisabled(true);

    layout->addWidget(leftToonLabel, 0, 1);
    layout->addWidget(rightToonLabel, 0, 2);

    layout->addWidget(forwardLabel, 1, 0);
    layout->addWidget(leftForwardBox, 1, 1);
    layout->addWidget(rightForwardBox, 1, 2);

    layout->addWidget(rightLabel, 2, 0);
    layout->addWidget(leftRightBox, 2, 1);
    layout->addWidget(rightRightBox, 2, 2);

    layout->addWidget(leftLabel, 3, 0);
    layout->addWidget(leftLeftBox, 3, 1);
    layout->addWidget(rightLeftBox, 3, 2);

    layout->addWidget(backwardLabel, 4, 0);
    layout->addWidget(leftBackwardBox, 4, 1);
    layout->addWidget(rightBackwardBox, 4, 2);

    layout->addWidget(jumpLabel, 5, 0);
    layout->addWidget(leftJumpBox, 5, 1);
    layout->addWidget(rightJumpBox, 5, 2);

    layout->addWidget(escLabel, 6, 0);
    layout->addWidget(leftEscBox, 6, 1);
    layout->addWidget(rightEscBox, 6, 2);

    layout->addWidget(freezeLabel, 7, 0);
    layout->addWidget(leftFreezeBox, 7, 1);
    layout->addWidget(rightFreezeBox, 7, 2);

    layout->addWidget(mapLabel, 8, 0);
    layout->addWidget(mapBox, 8, 1, 1, 2);

    layout->addWidget(pieLabel, 9, 0);
    layout->addWidget(pieBox, 9, 1, 1, 2);

    layout->addWidget(lowPieLabel, 10, 0);
    layout->addWidget(lowPieBox, 10, 1, 1, 2);

    layout->addWidget(homeLabel, 11, 0);
    layout->addWidget(homeBox, 11, 1, 1, 2);

    layout ->addWidget(endLabel, 12, 0);
    layout->addWidget(endBox, 12, 1, 1, 2);

    layout->addWidget(activateLabel, 13, 0);
    layout->addWidget(activateBox, 13, 1, 1, 2);

    layout->addWidget(okBox, 14, 1);
    layout->addWidget(cancelBox, 14, 2);

    connect(okBox, SIGNAL(clicked(bool)), this, SLOT(settingsSaved()));
    connect(cancelBox, SIGNAL(clicked(bool)), this, SLOT(deleteLater()));

    connect(leftForwardBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftForwardKey(int)));
    connect(rightForwardBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightForwardKey(int)));
    connect(leftRightBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftRightKey(int)));
    connect(rightRightBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightRightKey(int)));
    connect(leftLeftBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftLeftKey(int)));
    connect(rightLeftBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightLeftKey(int)));
    connect(leftBackwardBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftBackwardKey(int)));
    connect(rightBackwardBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightBackwardKey(int)));
    connect(leftJumpBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftJumpKey(int)));
    connect(rightJumpBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightJumpKey(int)));
    connect(leftEscBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLeftEscKey(int)));
    connect(rightEscBox,SIGNAL(sendKeyCode(int)),this,SLOT(setRightEscKey(int)));
    connect(leftFreezeBox, SIGNAL(sendKeyCode(int)), this, SLOT(setLeftFreezeKey(int)));
    connect(rightFreezeBox, SIGNAL(sendKeyCode(int)), this, SLOT(setRightFreezeKey(int)));
    connect(mapBox,SIGNAL(sendKeyCode(int)),this,SLOT(setMapKey(int)));
    connect(pieBox,SIGNAL(sendKeyCode(int)),this,SLOT(setPieKey(int)));
    connect(lowPieBox,SIGNAL(sendKeyCode(int)),this,SLOT(setLowPieKey(int)));
    connect(homeBox, SIGNAL(sendKeyCode(int)), this, SLOT(setHomeKey(int)));
    connect(endBox, SIGNAL(sendKeyCode(int)), this, SLOT(setEndKey(int)));
    connect(activateBox,SIGNAL(sendKeyCode(int)),this,SLOT(setActivateKey(int)));

    connect(leftForwardBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightForwardBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftRightBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightRightBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftLeftBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightLeftBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftBackwardBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightBackwardBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftJumpBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightJumpBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftEscBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(rightEscBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(leftFreezeBox, SIGNAL(releaseKeyboardFocus()), this, SLOT(keyboardFocusReleased()));
    connect(rightFreezeBox, SIGNAL(releaseKeyboardFocus()), this, SLOT(keyboardFocusReleased()));
    connect(mapBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(pieBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(lowPieBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
    connect(homeBox, SIGNAL(releaseKeyboardFocus()), this, SLOT(keyboardFocusReleased()));
    connect(endBox, SIGNAL(releaseKeyboardFocus()), this, SLOT(keyboardFocusReleased()));
    connect(activateBox,SIGNAL(releaseKeyboardFocus()),this,SLOT(keyboardFocusReleased()));
}

void PreferencesWindow::settingsSaved()
{
    //check to make sure there are no duplicated hotkeys


    QSettings settings("TTR-Controls", "TTR-Controls");

    settings.beginGroup("KeyBindings");
    settings.setValue("leftForwardKey",keyMap->getKey(lFKey));
    settings.setValue("rightForwardKey",keyMap->getKey(rFKey));
    settings.setValue("leftRightKey",keyMap->getKey(lRKey));
    settings.setValue("rightRightKey",keyMap->getKey(rRKey));
    settings.setValue("leftLeftKey",keyMap->getKey(lLKey));
    settings.setValue("rightLeftKey",keyMap->getKey(rLKey));
    settings.setValue("leftBackwardKey",keyMap->getKey(lBKey));
    settings.setValue("rightBackwardKey",keyMap->getKey(rBKey));
    settings.setValue("leftJumpKey",keyMap->getKey(lJKey));
    settings.setValue("rightJumpKey",keyMap->getKey(rJKey));
    settings.setValue("leftEscKey",keyMap->getKey(lEKey));
    settings.setValue("rightEscKey",keyMap->getKey(rEKey));
    settings.setValue("leftFreezeKey",keyMap->getKey(lFreezeKey));
    settings.setValue("rightFreezeKey",keyMap->getKey(rFreezeKey));
    settings.setValue("mapKey",keyMap->getKey(mapKey));
    settings.setValue("pieKey",keyMap->getKey(pieKey));
    settings.setValue("lowPieKey",keyMap->getKey(lowPieKey));
    settings.setValue("activateKey",keyMap->getKey(activateKey));
    settings.setValue("homeKey",keyMap->getKey(homeKey));
    settings.setValue("endKey",keyMap->getKey(endKey));
    settings.endGroup();

    emit sendSettings(keyMap);

    this->deleteLater();
}

void PreferencesWindow::setLeftForwardKey(int key)
{
    keyMap->setKey(lFKey, key);
}

void PreferencesWindow::setRightForwardKey(int key)
{
    keyMap->setKey(rFKey, key);
}

void PreferencesWindow::setLeftRightKey(int key)
{
    keyMap->setKey(lRKey, key);
}

void PreferencesWindow::setRightRightKey(int key)
{
    keyMap->setKey(rRKey, key);
}

void PreferencesWindow::setLeftLeftKey(int key)
{
    keyMap->setKey(lLKey, key);
}

void PreferencesWindow::setRightLeftKey(int key)
{
    keyMap->setKey(rLKey, key);
}

void PreferencesWindow::setLeftBackwardKey(int key)
{
    keyMap->setKey(lBKey, key);
}

void PreferencesWindow::setRightBackwardKey(int key)
{
    keyMap->setKey(rBKey, key);
}
void PreferencesWindow::setLeftJumpKey(int key)
{
    keyMap->setKey(lJKey, key);
}

void PreferencesWindow::setRightJumpKey(int key)
{
    keyMap->setKey(rJKey, key);
}

void PreferencesWindow::setLeftEscKey(int key)
{
    keyMap->setKey(lEKey, key);
}

void PreferencesWindow::setRightEscKey(int key)
{
    keyMap->setKey(rEKey, key);
}

void PreferencesWindow::setLeftFreezeKey(int key)
{
    keyMap->setKey(lFreezeKey, key);
}

void PreferencesWindow::setRightFreezeKey(int key)
{
    keyMap->setKey(rFreezeKey, key);
}

void PreferencesWindow::setMapKey(int key)
{
    keyMap->setKey(mapKey, key);
}

void PreferencesWindow::setPieKey(int key)
{
    keyMap->setKey(pieKey, key);
}

void PreferencesWindow::setLowPieKey(int key)
{
    keyMap->setKey(lowPieKey, key);
}

void PreferencesWindow::setHomeKey(int key)
{
    keyMap->setKey(homeKey, key);
}

void PreferencesWindow::setEndKey(int key)
{
    keyMap->setKey(endKey, key);
}

void PreferencesWindow::setActivateKey(int key)
{
    keyMap->setKey(activateKey, key);
}

void PreferencesWindow::closeEvent(QCloseEvent *event)
{
    this->deleteLater();
    event->accept();
}

void PreferencesWindow::keyboardFocusReleased()
{
    emit releaseKeyboardFocus();
}
