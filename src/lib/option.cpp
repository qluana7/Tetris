#include "option.h"

int option_render::get_option() {
    int inp;
    render();
    while (true) {
        inp = getch();
        
        switch (inp)
        {
            case KEY_UP:
                if (ind == 0) ind = size - 1;
                else ind--;
                break;
            case KEY_DOWN:
                if (ind == size - 1) ind = 0;
                else ind++;
                break;
            case 'q':
                if (q2e) return -1;
                else break;
            case KEY_RESIZE:
                wait_for_resize(GAME_MIN_SIZE_COL, GAME_MIN_SIZE_ROW);
                break;
            case '\n': return ind;
            default: break;
        }
        
        render();
    }
}

void option_render::set_selector(const string& str) {
    selector = str;
    blank = string(selector.length(), ' ');
}

void option_render::render() const {
    intrrupt(window == nullptr ? stdscr : window);
    
    pos ap = get_align(align);
    ap.x += p.x; ap.y += p.y;
    
    for (int i = 0; i < size; i++) {
        string str = (i == ind ? selector : blank) + " " + content[i];
        
        mvwprintw(window == nullptr ? stdscr : window, ap.y + i, ap.x, str.c_str());
    }
}

pos option_render::get_align(alignment align) {
    if (align == alignment::UNKNOWN) return {0, 0};
    
    pos p = { 0, 0 };
    struct winsize ws = term_size();
    int a = static_cast<int>(align);
    if (a < 3);
    else if (a < 6) p.y = ws.ws_row / 2;
    else p.y = ws.ws_row;
    
    if (a % 3 == 0);
    else if (a % 3 == 1) p.x = ws.ws_col / 2;
    else p.x = ws.ws_col;
    
    return p;
}