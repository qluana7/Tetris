#pragma once

#include <vector>
#include <map>

#include <ncurses.h>

#include "defines.h"
#include "colors.h"

using namespace std;

struct block_render {
    block_render(vector<pos> rd) : render(rd) { }
    
    vector<pos> render;
    
    void draw(WINDOW* win, BLOCK b, pos p);
};

void draw_block(WINDOW* win, BLOCK b, int rot, pos p);