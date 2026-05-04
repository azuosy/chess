#ifndef CHESS_H
#define CHESS_H

#include <stdio.h>
#include <raylib.h>

#define SIZE_BOARD 8
#define CELL_SIZE 60
#define CELL_COUNT 8

extern Texture2D rook_black;
extern Texture2D rook_black;
extern Texture2D knight_black;
extern Texture2D knight_white;
extern Texture2D bishop_black;
extern Texture2D bishop_white;
extern Texture2D queen_black;
extern Texture2D queen_white;
extern Texture2D king_black;
extern Texture2D king_white;
extern Texture2D pawn_black;
extern Texture2D pawn_white;


enum Pieces {
    EMPTY = 0,
    PAWNBLACK = 1,
    PAWNWHITE = 2,
    ROOKBLACK = 3,
    ROOKWHITE = 4,
    KNIGHTBLACK = 5,
    KNIGHTWHITE = 6,
    BISHOPBLACK = 7,
    BISHOPWHITE = 8,
    QUEENBLACK = 9,
    QUEENWHITE = 10,
    KINGBLACK = 11,
    KINGWHITE = 12
};

void printboard(int board[SIZE_BOARD][SIZE_BOARD]);
void putpieces(int board[SIZE_BOARD][SIZE_BOARD]);
void drawboard(void);
void drawpieces(int board[SIZE_BOARD][SIZE_BOARD]);
void loadtextures(void);
void unloadtextures(void);
int processclickonpiece(char timeplay,int board[SIZE_BOARD][SIZE_BOARD], Vector2 mouseposition);
int processclickforattackpiece(char timeattack, int board[SIZE_BOARD][SIZE_BOARD], Vector2 mouseposition);

#endif
