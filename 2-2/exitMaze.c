#include "mapdef.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	StackNode *popNode;

	while (startPos.x != endPos.x || startPos.y != endPos.y)
	{
		if (startPos.y - 1 >= 0 && mazeArray[startPos.y - 1][startPos.x] == NOT_VISIT)
			moveUp(mazeArray, &startPos, pStack);
		else if (startPos.x + 1 < WIDTH && mazeArray[startPos.y][startPos.x + 1] == NOT_VISIT)
			moveRight(mazeArray, &startPos, pStack);
		else if (startPos.y + 1 < HEIGHT && mazeArray[startPos.y + 1][startPos.x] == NOT_VISIT)
			moveDown(mazeArray, &startPos, pStack);
		else if (startPos.x - 1 >= 0 && mazeArray[startPos.y][startPos.x - 1] == NOT_VISIT)
			moveLeft(mazeArray, &startPos, pStack);
		else
			break;
	}
	if (startPos.x == endPos.x && startPos.y == endPos.y)
	{
		printf("find exit path\n");
		pushLSMapPosition(pStack, startPos);
		showPath(pStack, mazeArray);
	}
	else if (!isLinkedStackEmpty(pStack))
	{
		popNode = popLS(pStack);
		findPath(mazeArray, popNode->mapPos, endPos, pStack);
		free(popNode);
	}
	else 
		printf("doesn't found exit path\n");
	return ;
}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
	StackNode	*element;
	int			ret;
	
	element = (StackNode *)malloc(sizeof(StackNode));
	if (!element)
		return (FALSE);
	element->mapPos = data;
	ret = pushLS(pStack, *element);
	free(element);
	return (ret);
}

int	main()
{
	LinkedStack *pStack;
	MapPosition start;
	MapPosition end;
	int	mazeArray[HEIGHT][WIDTH] = {
	{0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0 ,0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, S, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, E} };

	pStack = createLinkedStack();
	memset(&start, -1, sizeof(MapPosition));
	memset(&end, -1, sizeof(MapPosition));
	if (!validMapCheck(mazeArray, &start, &end))
	{
		printf("invalid Map\n");
		return (0);
	}
	findPath(mazeArray, start, end, pStack);
}