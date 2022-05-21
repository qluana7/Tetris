#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <ncurses.h>

#include "colors.h"
#include "winmgr.h"

using namespace std;

WINDOW* init();
void deinit();

void icolor();