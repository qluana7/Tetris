#include "blocks.h"

static map<BLOCK, vector<block_render>> blk_rends {
    { BLOCK::I,
        vector<block_render> {
            block_render({ { 2, 0 }, { 2, 1 }, { 2, 2 }, { 2, 3 } }),
            block_render({ { 0, 2 }, { 1, 2 }, { 2, 2 }, { 3, 2 } })
        }
    },
    { BLOCK::J,
        vector<block_render> {
            block_render({ { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 2 } }),
            block_render({ { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 0 } }),
            block_render({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } }),
            block_render({ { 0, 1 }, { 0, 2 }, { 1, 1 }, { 2, 1 } })
        }
    },
    { BLOCK::L,
        vector<block_render> {
            block_render({ { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 } }),
            block_render({ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 2, 1 } }),
            block_render({ { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 } }),
            block_render({ { 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 2 } })
        }
    },
    { BLOCK::O,
        vector<block_render> {
            block_render({ { 1, 1 }, { 1, 2 }, { 2, 1 }, { 2, 2 } })
        }
    },
    { BLOCK::S,
        vector<block_render> {
            block_render({ { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 } }),
            block_render({ { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 2 } }),
            block_render({ { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 } }),
            block_render({ { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 2 } })
        }
    },
    { BLOCK::T,
        vector<block_render> {
            block_render({ { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 1 } }),
            block_render({ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 1 } }),
            block_render({ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 } }),
            block_render({ { 0, 1 }, { 1, 1 }, { 1, 2 }, { 2, 1 } })
        }
    },
    { BLOCK::Z,
        vector<block_render> {
            block_render({ { 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 } }),
            block_render({ { 0, 2 }, { 1, 1 }, { 1, 2 }, { 2, 1 } }),
            block_render({ { 1, 0 }, { 1, 1 }, { 2, 1 }, { 2, 2 } }),
            block_render({ { 0, 2 }, { 1, 1 }, { 1, 2 }, { 2, 1 } })
        }
    }
};

void block_render::draw(WINDOW* win, BLOCK b, pos p) {
    if (win == nullptr) return;
    
    auto attr = COLOR_PAIR(static_cast<short>(b));
    
    wattron(win, attr);
    
    for (auto rd : render) {
        mvwprintw(win, p.y + rd.x + 1, p.x * BLOCK_SIZE + rd.y * BLOCK_SIZE + 1, "🭗 ");
    }
    
    wattroff(win, attr);
}

void draw_block(WINDOW* win, BLOCK b, int rot, pos p) {
    if (win == nullptr) return;
    
    vector<block_render> br = blk_rends[b];
    br[rot % static_cast<int>(br.size())].draw(win, b, p);
}