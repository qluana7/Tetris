#include "winmgr.h"

void tetris(WINDOW* win) {
    const int T = 9;
    const int E = 8;
    const int R = 8;
    const int I = 3;
    const int S = 8;
    const int tot = 45;
    
    struct winsize ws = term_size();
    int spos = (ws.ws_col - tot) / 2;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::Z) + 10));
    mvwprintw(win, 1, spos, "████████╗");
    mvwprintw(win, 2, spos, "╚══██╔══╝");
    mvwprintw(win, 3, spos, "   ██║   ");
    mvwprintw(win, 4, spos, "   ██║   ");
    mvwprintw(win, 5, spos, "   ██║   ");
    mvwprintw(win, 6, spos, "   ╚═╝   ");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::Z) + 10));
    spos += T;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::L) + 10));
    mvwprintw(win, 1, spos, "███████╗");
    mvwprintw(win, 2, spos, "██╔════╝");
    mvwprintw(win, 3, spos, "█████╗  ");
    mvwprintw(win, 4, spos, "██╔══╝  ");
    mvwprintw(win, 5, spos, "███████╗");
    mvwprintw(win, 6, spos, "╚══════╝");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::L) + 10));
    spos += E;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::O) + 10));
    mvwprintw(win, 1, spos, "████████╗");
    mvwprintw(win, 2, spos, "╚══██╔══╝");
    mvwprintw(win, 3, spos, "   ██║   ");
    mvwprintw(win, 4, spos, "   ██║   ");
    mvwprintw(win, 5, spos, "   ██║   ");
    mvwprintw(win, 6, spos, "   ╚═╝   ");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::O) + 10));
    spos += T;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::S) + 10));
    mvwprintw(win, 1, spos, "██████╗ ");
    mvwprintw(win, 2, spos, "██╔══██╗");
    mvwprintw(win, 3, spos, "██████╔╝");
    mvwprintw(win, 4, spos, "██╔══██╗");
    mvwprintw(win, 5, spos, "██║  ██║");
    mvwprintw(win, 6, spos, "╚═╝  ╚═╝");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::S) + 10));
    spos += R;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::I) + 10));
    mvwprintw(win, 1, spos, "██╗");
    mvwprintw(win, 2, spos, "██║");
    mvwprintw(win, 3, spos, "██║");
    mvwprintw(win, 4, spos, "██║");
    mvwprintw(win, 5, spos, "██║");
    mvwprintw(win, 6, spos, "╚═╝");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::I) + 10));
    spos += I;
    
    wattron(win, COLOR_PAIR(static_cast<short>(BLOCK::T) + 10));
    mvwprintw(win, 1, spos, " ██████╗");
    mvwprintw(win, 2, spos, "██╔════╝");
    mvwprintw(win, 3, spos, "║█████═╗");
    mvwprintw(win, 4, spos, "╚════██║");
    mvwprintw(win, 5, spos, "██████╔╝");
    mvwprintw(win, 6, spos, "╚═════╝ ");
    wattroff(win, COLOR_PAIR(static_cast<short>(BLOCK::T) + 10));
    spos += S;
    
    string c = "Made by Lukince";
    mvwprintw(win, ws.ws_row - 1, (ws.ws_col - c.length()) / 2, c.c_str());
    
    refresh();
}

void wininit() {
    vector<string> opts {
        "   GAME",
        "LeaderBoard",
        "   EXIT"
    }; int mxl = 12;
    
    // GAME_MIN_SIZE_COL / 2 - mxl / 2 - 3, GAME_MIN_SIZE_ROW / 2 - opts.size() / 2
    auto optrd = option_render(alignment::MIDDLE, -(mxl / 2 + 2), -(opts.size() / 2), opts);
    optrd.set_selector(">");
    
    optrd.set_intrrupt(tetris);
    
    wait_for_resize(GAME_MIN_SIZE_COL, GAME_MIN_SIZE_ROW);
    int opt = optrd.get_option();
    
    if (opt == 0) gameinit();
}

void gameinit() {
    clear();
    refresh();
    
    struct winsize wsz = term_size();
    pos tsz = { 37, 21 };
    pos stp = { (wsz.ws_col - tsz.x) / 2, (wsz.ws_row - tsz.y) / 2 };
    WINDOW* TETRIS = newwin(tsz.y, tsz.x, stp.y, stp.x);
    
    mvwprintw(TETRIS, 0, 0, "Tetris 0.1v");
    
    wrefresh(TETRIS);
    
    WINDOW* sub = newwin(20, 10 * BLOCK_SIZE, stp.y + 1, stp.x);
    WINDOW* next = newwin(6, 6 * BLOCK_SIZE, stp.y + 1, stp.x + 23);
    
    wrefresh(sub);
    wrefresh(next);
    wrefresh(TETRIS);
    refresh();
    
    box(sub, 0, 0);
    box(next, 0, 0);
    
    /*
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 9; j++) {
            int n = (j % 2 ^ i % 2) + 1;
            wattron(sub, COLOR_PAIR(n));
            mvwprintw(sub, i + 1, j * BLOCK_SIZE + 1, "  ");
            wattroff(sub, COLOR_PAIR(n));
        }
    }
    */
   
    mvwprintw(TETRIS, 2, 21, "N");
    mvwprintw(TETRIS, 3, 21, "E");
    mvwprintw(TETRIS, 4, 21, "X");
    mvwprintw(TETRIS, 5, 21, "T");
    
    wrefresh(sub);
    wrefresh(next);
    wrefresh(TETRIS);
    refresh();
    
    pos p { 0, 0 };
    
    draw_block(sub, BLOCK::O, 0, { p.x, p.y });
    draw_block(sub, BLOCK::S, 1, { p.x + 4, p.y });
    draw_block(sub, BLOCK::T, 2, { p.x, p.y + 4 });
    draw_block(sub, BLOCK::Z, 3, { p.x + 4, p.y + 4 });
    draw_block(sub, BLOCK::J, 0, { p.x, p.y + 8 });
    draw_block(sub, BLOCK::L, 1, { p.x + 4, p.y + 8 });
    draw_block(sub, BLOCK::I, 0, { p.x + 2, p.y + 12 });
    
    wrefresh(sub);
    wrefresh(next);
    wrefresh(TETRIS);
    refresh();
    
    getch();
    
    start_game(sub, next);
    
    delwin(sub);
    delwin(next);
    delwin(TETRIS);
}