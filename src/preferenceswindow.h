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


#ifndef PREFERENCESWINDOW_H
#define PREFERENCESWINDOW_H

#include "keymap.h"
#include "keymapbutton.h"
#include "keyhelper.h"

#include <QDialog>
#include <QPushButton>
#include <QLabel>


class PreferencesWindow : public QDialog
{
    Q_OBJECT
public:
    explicit PreferencesWindow(KeyMap *, QWidget *parent = 0);

signals:
    void sendSettings(KeyMap *);
    void releaseKeyboardFocus();

public slots:
    void setLeftForwardKey(int);
    void setRightForwardKey(int);
    void setLeftRightKey(int);
    void setRightRightKey(int);
    void setLeftLeftKey(int);
    void setRightLeftKey(int);
    void setLeftBackwardKey(int);
    void setRightBackwardKey(int);
    void setLeftJumpKey(int);
    void setRightJumpKey(int);
    void setLeftEscKey(int);
    void setRightEscKey(int);
    void setLeftFreezeKey(int);
    void setRightFreezeKey(int);
    void setMapKey(int);
    void setPieKey(int);
    void setLowPieKey(int);
    void setHomeKey(int);
    void setEndKey(int);
    void setActivateKey(int);
    void keyboardFocusReleased();

private slots:
    void settingsSaved();

private:
    KeyMapButton *leftForwardBox;
    KeyMapButton *rightForwardBox;
    KeyMapButton *leftRightBox;
    KeyMapButton *rightRightBox;
    KeyMapButton *leftLeftBox;
    KeyMapButton *rightLeftBox;
    KeyMapButton *leftBackwardBox;
    KeyMapButton *rightBackwardBox;
    KeyMapButton *leftJumpBox;
    KeyMapButton *rightJumpBox;
    KeyMapButton *leftEscBox;
    KeyMapButton *rightEscBox;
    KeyMapButton *mapBox;
    KeyMapButton *pieBox;
    KeyMapButton *lowPieBox;
    KeyMapButton *homeBox;
    KeyMapButton *endBox;
    KeyMapButton *activateBox;
    KeyMapButton *leftFreezeBox;
    KeyMapButton *rightFreezeBox;
    QPushButton *okBox;
    QPushButton *cancelBox;

    QLabel *leftToonLabel;
    QLabel *rightToonLabel;
    QLabel *forwardLabel;
    QLabel *rightLabel;
    QLabel *leftLabel;
    QLabel *backwardLabel;
    QLabel *jumpLabel;
    QLabel *escLabel;
    QLabel *mapLabel;
    QLabel *pieLabel;
    QLabel *lowPieLabel;
    QLabel *homeLabel;
    QLabel *endLabel;
    QLabel *activateLabel;
    QLabel *freezeLabel;

    KeyMap *keyMap;
    KeyHelper *keyHelper;

    void setupUi();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // PREFERENCESWINDOW_H
