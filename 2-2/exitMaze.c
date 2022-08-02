#include "mapdef.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{

}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{

}

int	validMapCheck(int mazeArray[HEIGHT][WIDTH], MapPosition start, MapPosition end)
{
	int	h;
	int	w;
	int	s;
	int	e;

	h = 0;
	s = 0;
	e = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			if (mazeArray[h][w] == s)
				++s;
			if (mazeArray[h][w] == e)
				++e;
			++w;
		}
		++h;
	}
	if (s == 1 && e == 1)
		return (1);
	return (0);
}



int	main()
{
	LinkedStack *pStack;
	MapPosition start;
	MapPosition end;
	int	mazeArray[HEIGHT][WIDTH] = {
	{S, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0 ,0, 0, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, E} };
	pStack = createLinkedStack();
	if (!validMapCheck(mapArray, start, end))
	{
		printf("invalid Map\n");
		return (0);
	}
	findPath(mazeArray, )

}