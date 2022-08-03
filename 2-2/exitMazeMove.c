#include "mapdef.h"

void	moveUp(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack)
{
	startPos->direction = 0;
	mazeArray[startPos->y][startPos->x] = VISIT;
	pushLSMapPosition(pStack, *startPos);
	startPos->y--;
	mazeArray[startPos->y][startPos->x] = VISIT;
}

void	moveDown(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack)
{
	startPos->direction = 2;
	mazeArray[startPos->y][startPos->x] = VISIT;
	pushLSMapPosition(pStack, *startPos);
	startPos->y++;
	mazeArray[startPos->y][startPos->x] = VISIT;
}

void	moveLeft(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack)
{
	startPos->direction = 3;
	mazeArray[startPos->y][startPos->x] = VISIT;
	pushLSMapPosition(pStack, *startPos);
	startPos->x--;
	mazeArray[startPos->y][startPos->x] = VISIT;
}

void	moveRight(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack)
{
	startPos->direction = 1;
	mazeArray[startPos->y][startPos->x] = VISIT;
	pushLSMapPosition(pStack, *startPos);
	startPos->x++;
	mazeArray[startPos->y][startPos->x] = VISIT;
}