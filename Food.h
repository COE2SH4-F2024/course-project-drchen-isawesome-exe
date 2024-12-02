#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food
{
    private:

        objPos foodPos;

    public:
        Food();

        Food(const Food& d);
		Food& operator = (const Food& d);

        void generateFood(objPosArrayList* playerPosListRef);
        objPos getFoodPos() const;
};



#endif