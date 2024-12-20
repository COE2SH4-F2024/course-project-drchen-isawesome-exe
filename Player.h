#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{   
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef);

        ~Player(); // Destructor
        Player(const Player &p); // Copy Constructor
        Player& operator = (const Player& p); // Copy Assignment Constructor
        
        objPosArrayList* const getPlayerPos();

        void updatePlayerDir();
        void movePlayer(Food* food);

    private:
    
        objPosArrayList* playerPosList;

        enum Dir myDir;

        GameMechs* mainGameMechsRef;
        Food* foodRef;
};

#endif