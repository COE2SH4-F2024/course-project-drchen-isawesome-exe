#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"

GameMechs::GameMechs() // default constructor
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    boardSizeX = 30;
    boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY) // constructor with set board size
{
    input = 0;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

GameMechs::GameMechs(const GameMechs &d) { // Copy Constructor
	//DEEP COPY
    input = d.input;
    score = d.score;
    exitFlag = d.exitFlag;
    loseFlag = d.loseFlag;

    boardSizeX = d.boardSizeX;
    boardSizeY = d.boardSizeY;
}

GameMechs& GameMechs::operator = (const GameMechs& d) { // Copy Assignment Operator
		this->input = d.input;
        this->score = d.score;
        this->exitFlag = d.exitFlag;
        this->loseFlag = d.loseFlag;

        this->boardSizeX = d.boardSizeX;
        this->boardSizeY = d.boardSizeY;
		return *this;
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
char GameMechs::getInput() 
{
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
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}
