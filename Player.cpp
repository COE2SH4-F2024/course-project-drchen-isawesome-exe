#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    playerPos.symbol = '@';

    // more actions to be included
}


Player::~Player()
{
    delete[] mainGameMechsRef;
    // delete any heap members here
}

objPos Player::getPlayerPos() const {
    // return the reference to the playerPos arrray list
    return playerPos;
    }

void Player::updatePlayerDir()
{
        // PPA3 input processing logic

    if(mainGameMechsRef->getInput() != 0)  // if not null character... MIGHT NOT NEED THIS CONDITION SINCE ITS IN THE MAIN FUNCTION TOO!
    {
        switch(mainGameMechsRef->getInput())
        {                 

            // Add more key processing here
            case 'a':
            default:
                if(myDir!=RIGHT){
                myDir = LEFT;
                break;
            case 'd':
                if(myDir!=LEFT){
                myDir = RIGHT;
                }
                break;
            case 'w':
                if(myDir!=DOWN){
                    myDir = UP;
                }
                break;
            case 's':
                if(myDir!=UP){
                myDir = DOWN;
                }
                break;

        }

        mainGameMechsRef->setInput(0);
    }

}
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    if(playerPos.pos->x > mainGameMechsRef->getBoardSizeX()){
        playerPos.pos->x = 1;
    }
    if(playerPos.pos->x < 1){
        playerPos.pos->x = mainGameMechsRef->getBoardSizeX();
    }

    if(playerPos.pos->y > mainGameMechsRef->getBoardSizeY()){
        playerPos.pos->y = 1;
    }
    if(playerPos.pos->y < 1){
        playerPos.pos->y = mainGameMechsRef->getBoardSizeY();
    }

    switch(myDir){
        case LEFT:
        // default:
            playerPos.pos->x--;
            break;
        case RIGHT:
            playerPos.pos->x++;
            break;
        case DOWN:
            playerPos.pos->y++;
            break;
        case UP:
            playerPos.pos->y--;
            break;
        case STOP:
            break;
    }
}

// More methods to be added

