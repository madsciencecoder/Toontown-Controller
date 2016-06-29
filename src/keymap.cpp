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


#include "keymap.h"

int KeyMap::getKey(int i)
{
    return keyMap[i];
}

void KeyMap::setKey(int i, int keyCode)
{
    keyMap[i] = keyCode;
}
