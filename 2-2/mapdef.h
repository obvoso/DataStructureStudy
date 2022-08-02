#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

#include "linkedstack.h"

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동
	{1, 0},			// 오른쪽
	{0, 1},			// 아래쪽
	{-1, 0}			// 왼쪽
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2, S, E };

typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표
	int y;				// 현재 위치 y좌표
	int direction;		// 이동할 다음위치 방향
} MapPosition;

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif