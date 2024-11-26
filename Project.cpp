#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
// another include

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
   // myPlayer->movePlayer();
}

void DrawScreen(void)
{
    //  1. clear the current screen contents
    MacUILib_clearScreen();
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i, j, k;
    int itemPrinted = 0; // Flag to check if an item was printed
    for (i = 0; i < 10; i++) // 10 vertical #
    {
        for (j = 0; j < 20; j++) // 20 horizontal #
        {
            itemPrinted = 0;
            if ((i == 0 || i == 9) || (j == 0 || j == 19)) // checking if it's on the border
            {
                MacUILib_printf("#");
                itemPrinted = 1; // Mark that an item was printed
            }
            else
            {

                if (!itemPrinted)
                {
                    MacUILib_printf(" "); // Print space only if no item was printed
                }
            }
        }
        MacUILib_printf("\n");
    }
    

    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
