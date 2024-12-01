#include <iostream>
#include <stdlib.h>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h" 
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

GameMechs* gm;
Player* player;
Food* food;

// objPosArrayList* objArray;


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
    food = new Food();

    // food->generateFood(player->getPlayerPos());

    food->generateFood(player->getPlayerPos()); 

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
        player->updatePlayerDir();
    }

    player->movePlayer(food);
    gm->clearInput();
}

void DrawScreen(void)
{
    //  1. clear the current screen contents
    MacUILib_clearScreen();
    //  2. Iterate through each character location on the game board
    //     using the nested for-loop row-scanning setup.
    int i, j, k;
    // objPos obj1(3, 4, '@');
    int itemPrinted = 0; // Flag to check if an item was printed

    for (i = 0; i < gm->getBoardSizeY(); i++) // vertical #...rn its actually 15 and 30
    {
        for (j = 0; j < gm->getBoardSizeX(); j++) // horizontal #
        {
            itemPrinted = 0;
            if ((i == 0 || i == gm->getBoardSizeY()-1) || (j == 0 || j == gm->getBoardSizeX()-1)) // checking if it's on the border
            {
                MacUILib_printf("#");
                itemPrinted = 1; // Mark that an item was printed
            }

            /// WHAT WE HAD BEFORE
            // else if(i == player->objArray->getHeadElement().pos->y && j == player->getPlayerPos().pos->x)
            // {
            //     MacUILib_printf("%c", player->getPlayerPos().symbol); 
            //     itemPrinted = 1;
            // }
            /// 

            for(k=0;k<player->getPlayerPos()->getSize();k++){ //look through every element of array list and print 
            if(i == player->getPlayerPos()->getElement(k).pos->y && j == player->getPlayerPos()->getElement(k).pos->x)
            {
                MacUILib_printf("%c", player->getPlayerPos()->getElement(k).symbol); 
                itemPrinted = 1;
            }
            }
            //else
            if(i == food->getFoodPos().pos->y && j == food->getFoodPos().pos->x) // generating the food
            {
                MacUILib_printf("%c", food->getFoodPos().symbol);
                itemPrinted = 1;
            }

            if (!itemPrinted)
            {
                MacUILib_printf(" "); // Print space only if no item was printed
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d \n",gm->getScore());
    // MacUILib_printf("food pos: %d, %d", food->getFoodPos().pos->x, food->getFoodPos().pos->y);


    if(gm->getLoseFlagStatus() == true)
        MacUILib_printf("You lost :(");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    // MacUILib_clearScreen();    

    MacUILib_uninit();

    delete [] gm;
    delete [] food;
    delete [] player;
}
