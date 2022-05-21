#pragma once

#include <vector>
#include <string>

#include <ncurses.h>

#include "defines.h"
#include "terminal.h"

using namespace std;

enum class alignment {
    LEFT_TOP,    TOP,    RIGHT_TOP,
    LEFT,        MIDDLE, RIGHT,
    LEFT_BOTTOM, BOTTOM, RIGHT_BOTTOM,
    UNKNOWN
};

class option_render {
public:
    option_render(WINDOW* win, alignment ag, int x, int y, const vector<string>& cont, bool qtexit = false)
        : window(win), align(ag), p({x, y}), content(cont), q2e(qtexit), size(cont.size()) { }
    option_render(alignment ag, int x, int y, const vector<string>& cont, bool qtexit = false)
        : option_render(nullptr, ag, x, y, cont, qtexit) { }
    option_render(WINDOW* win, int x, int y, const vector<string>& cont, bool qtexit = false)
        :option_render(win, alignment::UNKNOWN, x, y, cont, qtexit) { }
    option_render(int x, int y, const vector<string>& cont, bool qtexit = false)
        : option_render(nullptr, x, y ,cont, qtexit) { }
    
    int get_option();
    
    void set_selector(const string& str);
    string get_selector() const { return selector; }
    
    void set_intrrupt(void (*fp)(WINDOW*)) { intrrupt = fp; }
private:
    static pos get_align(alignment align);

    WINDOW* window;
    alignment align; pos p;
    vector<string> content;
    bool q2e; int size;
    
    void (*intrrupt)(WINDOW*);
    
    int ind = 0;
    
    string selector = "=>";
    string blank    = "  ";
    
    void render() const;
};