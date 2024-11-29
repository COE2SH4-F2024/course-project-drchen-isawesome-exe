#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList;
    objPos listPos; //free at some point

    // playerPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    // playerPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    // playerPos.symbol = '@'; 

    listPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    listPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    listPos.symbol = '*'; 

    // objPos listPos2;
    // listPos2.pos->x = mainGameMechsRef -> getBoardSizeX()/2+1;
    // listPos2.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    // listPos2.symbol = '@';

    playerPosList->insertHead(listPos);
    // playerPosList->insertHead(listPos2);

    // more actions to be included
}

Player::~Player()
{
    delete[] mainGameMechsRef;
    // delete any heap members here
}

objPosArrayList* const Player::getPlayerPos() {
    // return the reference to the playerPos arrray list
    // return playerPos;
    return playerPosList;
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

    // if(playerPos.pos->x > mainGameMechsRef->getBoardSizeX()){
    //     playerPos.pos->x = 1;
    // }
    // if(playerPos.pos->x < 1){
    //     playerPos.pos->x = mainGameMechsRef->getBoardSizeX();
    // }

    // if(playerPos.pos->y > mainGameMechsRef->getBoardSizeY()){
    //     playerPos.pos->y = 1;
    // }
    // if(playerPos.pos->y < 1){
    //     playerPos.pos->y = mainGameMechsRef->getBoardSizeY();
    // }

    if(playerPosList->getHeadElement().pos->x > mainGameMechsRef->getBoardSizeX()){
        playerPosList->getHeadElement().pos->x = 1;
    }
    if(playerPosList->getHeadElement().pos->x < 1){
        playerPosList->getHeadElement().pos->x = mainGameMechsRef->getBoardSizeX();
    }

    if(playerPosList->getHeadElement().pos->y > mainGameMechsRef->getBoardSizeY()){
        playerPosList->getHeadElement().pos->y = 1;
    }
    if(playerPosList->getHeadElement().pos->y < 1){
        playerPosList->getHeadElement().pos->y = mainGameMechsRef->getBoardSizeY();
    }\

    // the following four objPos objects determine the position of the new head element
    // depending on what direction the snake is going in

    objPos caseLeft;
    caseLeft.pos->x = playerPosList->getHeadElement().pos->x-1;
    caseLeft.pos->y = playerPosList->getHeadElement().pos->y;
    caseLeft.symbol = playerPosList->getHeadElement().symbol;
    // caseLeft.symbol = '-';

    objPos caseRight;
    caseRight.pos->x = playerPosList->getHeadElement().pos->x+1;
    caseRight.pos->y = playerPosList->getHeadElement().pos->y;
    caseRight.symbol = playerPosList->getHeadElement().symbol;
    // caseRight.symbol = '-';

    objPos caseDown;
    caseDown.pos->x = playerPosList->getHeadElement().pos->x;
    caseDown.pos->y = playerPosList->getHeadElement().pos->y+1;
    caseDown.symbol = playerPosList->getHeadElement().symbol;
    // caseDown.symbol = '-';

    objPos caseUp;
    caseUp.pos->x = playerPosList->getHeadElement().pos->x;
    caseUp.pos->y = playerPosList->getHeadElement().pos->y-1;
    caseUp.symbol = playerPosList->getHeadElement().symbol;
    // caseUp.symbol = '-';

    switch(myDir){
        case LEFT:
        // default:
            playerPosList->insertHead(caseLeft);
            playerPosList->removeTail();
            break;
        case RIGHT:
            playerPosList->insertHead(caseRight);
            playerPosList->removeTail();
            break;
        case DOWN:
            playerPosList->insertHead(caseDown);
            playerPosList->removeTail();
            break;
        case UP:
            playerPosList->insertHead(caseUp);
            playerPosList->removeTail();
            break;
        case STOP:
            break;
    }
}

// More methods to be added

