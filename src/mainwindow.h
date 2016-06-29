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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "keymap.h"
#include "controller.h"

#include <QMainWindow>
#include <QPushButton>
#include <QStringList>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void relaySettings(KeyMap *);
    void windowHasFocus();

public slots:
    void receiveSettings(KeyMap *);

private slots:
    void setSettings();
    void focusWindow();

private:
    QPushButton *leftControls;
    QPushButton *rightControls;
    QPushButton *settingsButton;

    void setupUi();
    void readSettings();
    void writeSettings();

    KeyMap *keyMap;
    Controller *controller;

protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // MAINWINDOW_H
