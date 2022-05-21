#pragma once

#define BLOCK_SIZE 2
#define GAME_MIN_SIZE_COL 52
#define GAME_MIN_SIZE_ROW 24

enum class BLOCK : short
{ I = 101, J, L, O, S, T, Z };

struct pos {
    int x, y;
};

struct game_result {
    // Do Something
};