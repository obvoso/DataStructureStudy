#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define TRUE 1
#define FALSE 0

#define NUM_DIRECTIONS 4

typedef struct MapPositionType
{
	int x;				// 현재 위치 x좌표
	int y;				// 현재 위치 y좌표
	int direction;		// 이동할 다음위치 방향
} MapPosition;

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 위쪽으로 이동
	{1, 0},			// 오른쪽
	{0, 1},			// 아래쪽
	{-1, 0}			// 왼쪽
}; //왜쓰는지 모르겠는디.... 위 0 오른쪽 1 아래쪽 2 왼쪽 3

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2, S, E };

typedef struct StackNodeType
{
	struct MapPositionType mapPos;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

void	moveUp(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack);
void	moveDown(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack);
void	moveLeft(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack);
void	moveRight(int mazeArray[HEIGHT][WIDTH], MapPosition *startPos, LinkedStack *pStack);
int	validMapCheck(int mazeArray[HEIGHT][WIDTH], MapPosition *start, MapPosition *end);

#endif