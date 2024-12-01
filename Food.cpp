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

//		Copy Constructor
Food::Food(const Food &d) {
	//DEEP COPY
    foodPos.setObjPos(d.foodPos.getObjPos().pos->x, d.foodPos.getObjPos().pos->y, d.foodPos.getSymbol());
}

//		Copy Assignment Operator
Food& Food::operator = (const Food& d) {
		this->foodPos = d.foodPos;
		return *this;
	
}

void Food::generateFood(objPosArrayList* playerPosListRef)
{
    int overlap = true;
    srand((unsigned int)time(NULL));

    do 
    {
        overlap = false;
        int randX = (rand() % (30-2)) + 1; // change to work with any board size
        int randY = (rand() % (15-2)) + 1; // change to work with any board size

        for(int i = 0; i < playerPosListRef->getSize(); i++)
        {
            if(playerPosListRef->getElement(i).getObjPos().pos->x == randX && playerPosListRef->getElement(i).getObjPos().pos->y == randY)
            {
                overlap = true;
            }
        }
        foodPos.setObjPos(randX, randY, 'o');
    } while(overlap == true);
    
}

objPos Food:: getFoodPos() const
{
    return foodPos;
}