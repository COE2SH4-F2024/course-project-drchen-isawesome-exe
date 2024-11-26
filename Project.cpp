#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h" 


// class Player
// {
    
//     public:
//         enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

//         Player(GameMechs* thisGMRef){
//             mainGameMechsRef = thisGMRef;
//             myDir = STOP;

//             playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
//             playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
//             playerPos.symbol = '*';
//         }
       
        // ~Player(){
        //     delete[] mainGameMechsRef;
        // }

        // objPos getPlayerPos() const; // Upgrade this in iteration 3.       
        // void updatePlayerDir();
        // void movePlayer();

        // More methods to be added here
        // objPos const getPlayerPos() {
        //     return playerPos;
        // }

    // private:
    //     objPos playerPos; // Upgrade this in iteration 3.       
    //     enum Dir myDir;

    //     // Need a reference to the Main Game Mechanisms
    //     GameMechs* mainGameMechsRef;
// };

Player* player;


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

GameMechs* gm;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(gm->getExitFlagStatus() == false)  
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

    gm = new GameMechs();
    player = new Player(gm);

}

void GetInput(void)
{
    if(MacUILib_hasChar())
        gm->setInput(MacUILib_getChar());
}

void RunLogic(void)
{
    if(gm->getInput() != 0)  // if not null character
    {
        if(gm->getInput() == 27) 
            gm->setExitTrue(); // exit is ESC
    }
    // myPlayer->movePlayer();

    gm->clearInput();
}

void DrawScreen(void)
{
    //  1. clear the current screen contents
    MacUILib_clearScreen();
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i, j, k;
    objPos obj1(3, 4, '@');
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
            else if(i == obj1.pos->x && j == obj1.pos->y)
            {
                MacUILib_printf("%c", obj1.symbol);
                itemPrinted = 1;
            }
            {

                if (!itemPrinted)
                {
                    MacUILib_printf(" "); // Print space only if no item was printed
                }
            }
        }
        MacUILib_printf("\n");
    }


}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    delete [] gm;
}
