#pragma once

#include <ncurses.h>

#include "defines.h"

struct B_COL {
    short col;
    short r, g, b;
};

// I : 0x00ffff
#define BLK_I B_COL { static_cast<short>(BLOCK::I), 0,    1000, 1000 }
// J : 0x0000ff
#define BLK_J B_COL { static_cast<short>(BLOCK::J), 0,    0,    1000 }
// L : 0xff7f00
#define BLK_L B_COL { static_cast<short>(BLOCK::L), 1000, 500,  0    }
// O : 0xffff00
#define BLK_O B_COL { static_cast<short>(BLOCK::O), 1000, 1000, 0    }
// S : 0x00ff00
#define BLK_S B_COL { static_cast<short>(BLOCK::S), 0,    1000, 0    }
// T : 0x800080
#define BLK_T B_COL { static_cast<short>(BLOCK::T), 500,  0,    500  }
// Z : 0xff0000
#define BLK_Z B_COL { static_cast<short>(BLOCK::Z), 1000, 0,    0    }

void use_colors();