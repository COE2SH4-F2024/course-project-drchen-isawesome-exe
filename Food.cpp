#include "Food.h"
#include <stdlib.h>
#include <time.h>
#include "objPos.h"
#include "GameMechs.h"

Food::Food()
{
    foodPos.setObjPos(0, 0, 'o');
}

Food::~Food()
{
    
}

void Food::generateFood(objPos blockOff)
{
    srand((unsigned int)time(NULL));
    do {
        int randX = (rand() % (30-1)) + 1; // change to work with any board size
        int randY = (rand() % (15-1)) + 1; // change to work with any board size

        foodPos.setObjPos(randX, randY, 'o');
    } while(foodPos.pos->x == blockOff.pos->x && foodPos.pos->y == blockOff.pos->y);
}

objPos Food:: getFoodPos() const
{
    return foodPos;
}