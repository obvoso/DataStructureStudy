#include "mapdef.h"
#include <stdio.h>
#include <stdlib.h>

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	h = 0, w = 0;

	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			printf("%d ", mazeArray[h][w]);
			++w;
		}
		printf("\n");
		++h;
	}
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode *popNode;

	while (!isLinkedStackEmpty(pStack))
	{
		popNode = popLS(pStack);
		mazeArray[popNode->mapPos.y][popNode->mapPos.x] = 5;
		free(popNode);
	}
	printMaze(mazeArray);
}

int	validMapCheck(int mazeArray[HEIGHT][WIDTH], MapPosition *start, MapPosition *end)
{
	int	h = 0, w = 0, s = 0, e = 0;

	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			if (mazeArray[h][w] == S)
			{
				start->x = w;
				start->y = h;
				++s;
			}
			if (mazeArray[h][w] == E)
			{
				end->x = w;
				end->y = h;
				mazeArray[h][w] = NOT_VISIT;
				++e;
			}
			++w;
		}
		++h;
	}
	if (s == 1 && e == 1)
		return (1);
	return (0);
}