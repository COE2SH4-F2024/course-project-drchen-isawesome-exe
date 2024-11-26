#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    char input = 0;
    int score = 0;
    bool exitFlag = false;
    bool loseFlag = false;

    int boardSizeX = 30;
    int boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() // const // remove const??
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    if(input == ' '){
      exitFlag = true;  
    } 
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    this_input = input;
}

void GameMechs::clearInput()
{
    input = 0;
}
