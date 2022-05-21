#include "terminal.h"

struct winsize term_size() {
    struct winsize sz;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz);
    
    return sz;
}

void wait_for_resize(int col, int row) {
    while (true) {
        struct winsize ws = term_size();
        
        if (ws.ws_col >= col && ws.ws_row >= row) break;
        
        WINDOW* win = newwin(ws.ws_row, ws.ws_col, 0, 0);
        box(win, 0, 0);
        
        std::string cstr(30, '\0');
        std::string rstr(30, '\0');
        sprintf(cstr.data(), "Current Size : %d x %d", ws.ws_col, ws.ws_row);
        sprintf(rstr.data(), "Minimum Size : %d x %d", col, row);
        
        mvwprintw(win, ws.ws_row / 2 - 1, ws.ws_col / 2 - strlen(cstr.c_str()) / 2, cstr.c_str());
        mvwprintw(win, ws.ws_row / 2, ws.ws_col / 2 - strlen(rstr.c_str()) / 2, rstr.c_str());
        
        refresh();
        wrefresh(win);
        
        getch();
        
        delwin(win);
    }
    
    clear();
}