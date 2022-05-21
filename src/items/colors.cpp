#include "colors.h"

#include <iostream>

// 1 ~ 10
#define alpha 8
#define galp(clr) ((clr) / 10 * alpha)

void use_color(B_COL col);

void use_colors() {
    use_color(BLK_I); use_color(BLK_J);
    use_color(BLK_L); use_color(BLK_O);
    use_color(BLK_S); use_color(BLK_T);
    use_color(BLK_Z);

#define GREYCOLOR 100

    init_color(20, GREYCOLOR, GREYCOLOR, GREYCOLOR);
    init_pair(1, -1, 20);
    init_pair(2, -1, COLOR_BLACK);
}

void use_color(B_COL col)
{
    init_color(col.col, galp(col.r), galp(col.g), galp(col.b));
    init_pair(col.col, -1, col.col);
    init_pair(col.col + 10, col.col, -1);
}