#include "Food.h"
#include <stdlib.h>
#include <time.h>
#include "objPos.h"
#include "GameMechs.h"

Food::Food() // constructor
{
    foodPos.setObjPos(5, 5, 'o'); 
}

Food::Food(const Food &d) { // Copy Constructor
	//DEEP COPY
    foodPos.setObjPos(d.foodPos.getObjPos().pos->x, d.foodPos.getObjPos().pos->y, d.foodPos.getSymbol());
}

Food& Food::operator = (const Food& d) { // Copy Assignment Operator
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
        int randX = (rand() % (30-2)) + 1; // generate random x and  y position for food
        int randY = (rand() % (15-2)) + 1; 

        for(int i = 0; i < playerPosListRef->getSize(); i++)
        { // check for overlap
            if(playerPosListRef->getElement(i).getObjPos().pos->x == randX && playerPosListRef->getElement(i).getObjPos().pos->y == randY)
            {
                overlap = true;
            }
        }
        foodPos.setObjPos(randX, randY, 'o');
    } while(overlap == true); // do-while loop to ensure food is not generated on top of snake
}

objPos Food:: getFoodPos() const
{
    return foodPos;
}