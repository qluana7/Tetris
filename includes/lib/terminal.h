#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <cstring>
#include <string>

#include "defines.h"
#include "ncurses.h"

winsize term_size();

void wait_for_resize(int col, int row);