#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList;
    objPos listPos;

    listPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
    listPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
    listPos.symbol = '*'; 

    playerPosList->insertHead(listPos);
}

Player::~Player()
{
    delete[] mainGameMechsRef;
}

// Player::Player(const Player &p) { //Copy Constructor
// 	//DEEP COPY
//     playerPosList = new objPosArrayList;
//     myDir = STOP;

//     playerPosList = new objPosArrayList;
//     objPos listPos; //free at some point

//     listPos.pos->x = mainGameMechsRef -> getBoardSizeX()/2;
//     listPos.pos->y = mainGameMechsRef -> getBoardSizeY()/2;
//     listPos.symbol = '*'; 
// }

//		Copy Assignment Operator
// Food& Food::operator = (const Food& d) {
// 		this->foodPos = d.foodPos;
// 		return *this;
	
// }

objPosArrayList* const Player::getPlayerPos() 
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    switch(mainGameMechsRef->getInput())
    {                 
        case 'a':
        default:
            if(myDir!=RIGHT){
                myDir = LEFT;
            }
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

void Player::movePlayer(Food* food)
{
    // the following eight objPos objects determine the position of the new head element
    // depending on what direction the snake is going in and if the snake is wrapping around the board

    objPos caseLeft;
    caseLeft.pos->x = playerPosList->getHeadElement().pos->x-1;
    caseLeft.pos->y = playerPosList->getHeadElement().pos->y;
    caseLeft.symbol = playerPosList->getHeadElement().symbol;

    objPos caseLeftWrap;
    caseLeftWrap.pos->x = mainGameMechsRef->getBoardSizeX()-2;
    caseLeftWrap.pos->y = playerPosList->getHeadElement().pos->y;
    caseLeftWrap.symbol = playerPosList->getHeadElement().symbol;

    objPos caseRight;
    caseRight.pos->x = playerPosList->getHeadElement().pos->x+1;
    caseRight.pos->y = playerPosList->getHeadElement().pos->y;
    caseRight.symbol = playerPosList->getHeadElement().symbol;

    objPos caseRightWrap;
    caseRightWrap.pos->x = 1;
    caseRightWrap.pos->y = playerPosList->getHeadElement().pos->y;
    caseRightWrap.symbol = playerPosList->getHeadElement().symbol;

    objPos caseDown;
    caseDown.pos->x = playerPosList->getHeadElement().pos->x;
    caseDown.pos->y = playerPosList->getHeadElement().pos->y+1;
    caseDown.symbol = playerPosList->getHeadElement().symbol;

    objPos caseDownWrap;
    caseDownWrap.pos->x = playerPosList->getHeadElement().pos->x;
    caseDownWrap.pos->y = 1;
    caseDownWrap.symbol = playerPosList->getHeadElement().symbol;

    objPos caseUp;
    caseUp.pos->x = playerPosList->getHeadElement().pos->x;
    caseUp.pos->y = playerPosList->getHeadElement().pos->y-1;
    caseUp.symbol = playerPosList->getHeadElement().symbol;

    objPos caseUpWrap;
    caseUpWrap.pos->x = playerPosList->getHeadElement().pos->x;
    caseUpWrap.pos->y = mainGameMechsRef->getBoardSizeY()-2;
    caseUpWrap.symbol = playerPosList->getHeadElement().symbol;

    switch(myDir){
        case LEFT:

            for(int i = 1; i < playerPosList->getSize(); i++)
            {
                if(playerPosList->getElement(i).pos->x == playerPosList->getHeadElement().pos->x && playerPosList->getElement(i).pos->y == playerPosList->getHeadElement().pos->y)
                {
                    mainGameMechsRef->setLoseFlag();
                    mainGameMechsRef->setExitTrue();
                }
            }
            if(mainGameMechsRef->getLoseFlagStatus() == true)
                break;
            
            if(playerPosList->getHeadElement().pos->x == 1)
            {
                playerPosList->insertHead(caseLeftWrap);
            } else {
                playerPosList->insertHead(caseLeft);
            }
            if (playerPosList->getHeadElement().pos->x == food->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == food->getFoodPos().pos->y)
            {
                food->generateFood(playerPosList);
                mainGameMechsRef->incrementScore();
                break;
            } else {
                playerPosList->removeTail();
                break;
            }

        case RIGHT:
                    // check for lose condition
            for(int i = 1; i < playerPosList->getSize(); i++)
            {
                if(playerPosList->getElement(i).pos->x == playerPosList->getHeadElement().pos->x && playerPosList->getElement(i).pos->y == playerPosList->getHeadElement().pos->y)
                {
                    mainGameMechsRef->setLoseFlag();
                    mainGameMechsRef->setExitTrue();
                }
            }

            if(mainGameMechsRef->getLoseFlagStatus() == true)
                break;

            if(playerPosList->getHeadElement().pos->x >= mainGameMechsRef->getBoardSizeX()-2){
                playerPosList->insertHead(caseRightWrap);
            } else {  
                playerPosList->insertHead(caseRight);
            }
            if (playerPosList->getHeadElement().pos->x == food->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == food->getFoodPos().pos->y)
            {
                food->generateFood(playerPosList);
                mainGameMechsRef->incrementScore();
                break;
            } else {
                playerPosList->removeTail();
                break;
            }

        case DOWN:
                    // check for lose condition
            for(int i = 1; i < playerPosList->getSize(); i++)
            {
                if(playerPosList->getElement(i).pos->x == playerPosList->getHeadElement().pos->x && playerPosList->getElement(i).pos->y == playerPosList->getHeadElement().pos->y)
                {
                    mainGameMechsRef->setLoseFlag();
                    mainGameMechsRef->setExitTrue();
                }
            }

            if(mainGameMechsRef->getLoseFlagStatus() == true)
                break;

            if(playerPosList->getHeadElement().pos->y >= mainGameMechsRef->getBoardSizeY()-2){
                playerPosList->insertHead(caseDownWrap);
            } else {
                playerPosList->insertHead(caseDown);
            }
            if (playerPosList->getHeadElement().pos->x == food->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == food->getFoodPos().pos->y)
            {
                food->generateFood(playerPosList);
                mainGameMechsRef->incrementScore();
                break;
            } else {
                playerPosList->removeTail();
                break;
            }

        case UP:
                    // check for lose condition
            for(int i = 1; i < playerPosList->getSize(); i++)
            {
                if(playerPosList->getElement(i).pos->x == playerPosList->getHeadElement().pos->x && playerPosList->getElement(i).pos->y == playerPosList->getHeadElement().pos->y)
                {
                    mainGameMechsRef->setLoseFlag();
                    mainGameMechsRef->setExitTrue();
                }
            }

            if(mainGameMechsRef->getLoseFlagStatus() == true)
                break;
                
            if(playerPosList->getHeadElement().pos->y == 1){
                playerPosList->insertHead(caseUpWrap);
            } else {
                playerPosList->insertHead(caseUp);
            }
            if (playerPosList->getHeadElement().pos->x == food->getFoodPos().pos->x && playerPosList->getHeadElement().pos->y == food->getFoodPos().pos->y)
            {
                food->generateFood(playerPosList);
                mainGameMechsRef->incrementScore();
                break;
            } else {
                playerPosList->removeTail();
                break;
            }

        case STOP:
            break;
    }
}


