#include "main.h"

vector<string> logs;

int main() {
    WINDOW* mw = init();
    
    wininit();
    // gameinit();
    
    deinit();
    
    for (const string& str : logs) cout << str << "\n";
    
    return 0;
}

WINDOW* init() {
    setlocale(LC_CTYPE, "");
    
    WINDOW* win = initscr();
    
    if (curs_set(0) == ERR) logs.push_back("WARN : Cannot set cursor visible.");
    
    noecho(); cbreak();
    keypad(stdscr, true);
    start_color();
    
    use_default_colors();
    use_colors();
    
    if (!has_colors()) logs.push_back("WARN : Cannot use color in your terminal.");
    
    return win;
}

void deinit() {
    endwin();
}