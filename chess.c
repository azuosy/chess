#include "chess.h"
#include <raylib.h>
#include <stdio.h>

Texture2D rook_black;
Texture2D rook_white;
Texture2D knight_black;
Texture2D knight_white;
Texture2D bishop_black;
Texture2D bishop_white;
Texture2D queen_black;
Texture2D queen_white;
Texture2D king_black;
Texture2D king_white;
Texture2D pawn_black;
Texture2D pawn_white;


void printboard(int board[SIZE_BOARD][SIZE_BOARD])
{
    for (int y = 0; y < SIZE_BOARD; y++)
    {
        for (int x = 0; x < SIZE_BOARD; x++)
        {
            printf("%d ",board[y][x]);
        }
        printf("\n");
    }
}

void putpieces(int board[SIZE_BOARD][SIZE_BOARD])
{
    int firstblack[SIZE_BOARD] = {ROOKBLACK, KNIGHTBLACK, BISHOPBLACK, QUEENBLACK, KINGBLACK, BISHOPBLACK, KNIGHTBLACK, ROOKBLACK};
    int secondblack[SIZE_BOARD] = {PAWNBLACK, PAWNBLACK, PAWNBLACK, PAWNBLACK, PAWNBLACK, PAWNBLACK, PAWNBLACK, PAWNBLACK};

    int firstwhite[SIZE_BOARD] = {ROOKWHITE, KNIGHTWHITE, BISHOPWHITE, QUEENWHITE, KINGWHITE, BISHOPWHITE, KNIGHTWHITE, ROOKWHITE};
    int secondwhite[SIZE_BOARD] = {PAWNWHITE, PAWNWHITE, PAWNWHITE, PAWNWHITE, PAWNWHITE, PAWNWHITE, PAWNWHITE, PAWNWHITE};

    for (int i = 0; i < SIZE_BOARD; i++)
    {
        board[0][i] = firstblack[i];
        board[1][i] = secondblack[i];

        board[7][i] = firstwhite[i];
        board[6][i] = secondwhite[i];
    }
}

void drawboard(void)
{
    int c = 1;
    for (int y = 0; y < CELL_SIZE*CELL_COUNT; y += CELL_SIZE)
    {
        for (int x = 0; x < CELL_SIZE*CELL_COUNT; x += CELL_SIZE)
        {
            Color currcolor = (c % 2 == 0 ? LIGHTGRAY : BROWN);
            DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, currcolor);
            c++;
        }
        c++;
    }
}

void drawpieces(int board[SIZE_BOARD][SIZE_BOARD])
{
    int y = 0;
    int x = 0;
    Texture2D currpiece;

    for (int i = 0; i < SIZE_BOARD; i++)
    {
        x = 0;

        for (int j = 0; j < SIZE_BOARD; j++)
        {
            switch (board[i][j])
            {            
                case (ROOKBLACK): currpiece = rook_black; break;
                case (ROOKWHITE): currpiece = rook_white; break;
                case (KNIGHTBLACK): currpiece = knight_black; break;
                case (KNIGHTWHITE): currpiece = knight_white; break;
                case (BISHOPBLACK): currpiece = bishop_black; break;
                case (BISHOPWHITE): currpiece = bishop_white; break;
                case (QUEENBLACK): currpiece = queen_black; break;
                case (QUEENWHITE): currpiece = queen_white; break;
                case (KINGBLACK): currpiece = king_black; break;
                case (KINGWHITE): currpiece = king_white; break;
                case (PAWNBLACK): currpiece = pawn_black; break;
                case (PAWNWHITE): currpiece = pawn_white; break;
                default: x+= CELL_SIZE; continue;
            }
            DrawTexture(currpiece, x, y, WHITE);

            x += CELL_SIZE;
        }
        y += CELL_SIZE;
    }
}

void loadtextures(void)
{
    rook_black = LoadTextureFromImage(LoadImage("images/rook_black.png"));
    rook_white = LoadTextureFromImage(LoadImage("images/rook_white.png"));
    knight_black = LoadTextureFromImage(LoadImage("images/knight_black.png"));
    knight_white = LoadTextureFromImage(LoadImage("images/knight_white.png"));
    bishop_black = LoadTextureFromImage(LoadImage("images/bishop_black.png"));
    bishop_white = LoadTextureFromImage(LoadImage("images/bishop_white.png"));
    queen_black = LoadTextureFromImage(LoadImage("images/queen_black.png"));
    queen_white = LoadTextureFromImage(LoadImage("images/queen_white.png"));
    king_black = LoadTextureFromImage(LoadImage("images/king_black.png"));
    king_white = LoadTextureFromImage(LoadImage("images/king_white.png"));
    pawn_black = LoadTextureFromImage(LoadImage("images/pawn_black.png"));
    pawn_white = LoadTextureFromImage(LoadImage("images/pawn_white.png"));
}

void unloadtextures(void)
{
    UnloadTexture(rook_black);
    UnloadTexture(rook_white);
    UnloadTexture(knight_black);
    UnloadTexture(knight_white);
    UnloadTexture(bishop_black);
    UnloadTexture(bishop_white);
    UnloadTexture(queen_black);
    UnloadTexture(queen_white);
    UnloadTexture(king_black);
    UnloadTexture(king_white);
    UnloadTexture(pawn_black);
    UnloadTexture(pawn_white);
}

int processclickonpiece(char timeplay, int board[SIZE_BOARD][SIZE_BOARD], Vector2 mouseposition) // -1 = false, else = true
{

    int positionpiece = board[(int) mouseposition.y / CELL_SIZE][(int) mouseposition.x / CELL_SIZE];

    if (positionpiece == 0) return -1;

    printf("timeplay: %c\n", timeplay);

    if (timeplay == 'W')
    {
        if (positionpiece % 2 == 0) {return positionpiece;}
    }
    else {if (positionpiece % 2 == 1) {return positionpiece;}}

    return -1;

}

int processclickforattackpiece(char timeattack, int board[SIZE_BOARD][SIZE_BOARD], Vector2 mouseposition) // -1 = false, else = true
{
    int positionpiece = board[(int) mouseposition.y / CELL_SIZE][(int) mouseposition.x / CELL_SIZE];

    if (timeattack == 'W')
    {
        if (positionpiece % 2 == 0 && positionpiece != 0) {return -1;} 
    }
    else {if (positionpiece % 2 == 1) {return -1;}}

    return positionpiece;
}   
