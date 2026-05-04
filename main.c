#include <raylib.h>
#include "chess.h"

int main()
{
    char timeplay = 'W';
    bool hasselected = false;
    Vector2 firstclick = {0, 0};
    int chessboard[SIZE_BOARD][SIZE_BOARD] = {EMPTY};
    putpieces(chessboard);
    printboard(chessboard);

    SetTargetFPS(10);
    InitWindow(CELL_SIZE*CELL_COUNT, CELL_SIZE*CELL_COUNT, "CHESS");
    loadtextures();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        drawboard();
        drawpieces(chessboard);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
        {
            Vector2 mousepos = GetMousePosition();
            enum Pieces pieceselected;

            if (!hasselected)
            {
                firstclick = mousepos;
                if ( (pieceselected = processclickonpiece(timeplay, chessboard, firstclick)) == -1) hasselected = false;
                else hasselected = true;
            }
            else 
            {
                Vector2 secondclick = mousepos;
                enum Pieces piecesorsquareforattack;

                if ( (piecesorsquareforattack = processclickforattackpiece(timeplay, chessboard, secondclick)) != -1) 
                {
                    chessboard[(int) firstclick.y / CELL_SIZE][(int) firstclick.x / CELL_SIZE] = EMPTY; 
                    chessboard[(int) secondclick.y / CELL_SIZE][(int) secondclick.x / CELL_SIZE] = pieceselected; 
                    printboard(chessboard);

                    if (timeplay == 'W') timeplay = 'B';
                    else if (timeplay == 'B') timeplay = 'W';
                }
                
                hasselected = false;
            
            }
        }


        EndDrawing();
    }

    unloadtextures();

    return 0;
}
