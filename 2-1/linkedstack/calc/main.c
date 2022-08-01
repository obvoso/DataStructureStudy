#include "stackcalc.h"
#include <stdio.h>
#include <stdlib.h>

ExprToken	*argInit(ExprToken token[], int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] >= '0' && av[i][1] <= '9')
		{
			token[i - 1].value = strtod(av[i], NULL);
			token[i - 1].type = 6;
		}
		else if (av[i][0] >= '0' && av[i][0] <= '9')
		{
			token[i - 1].value = strtod(av[i], NULL);
			token[i - 1].type = 6;
		}
		else if (av[i][0] == '*')
			token[i - 1].type = 2;
		else if (av[i][0] == '/')
			token[i - 1].type = 3;
		else if (av[i][0] == '+')
			token[i - 1].type = 4;
		else if (av[i][0] == '-')
			token[i - 1].type = 5;
		++i;
	}
	return (token);
}

void	calcExprTwo(ExprToken ret[], ExprToken token[], int i, int j)
{
	float	a;
	float	b;

	b = ret[j - 1].value;
	a = ret[j - 2].value;
	ret[j - 1].value = 0;
	ret[j - 2].value = 0;
	if (token[i].type == 2)
		ret[j - 2].value = a * b;
	else if (token[i].type == 3)
		ret[j - 2].value = a / b;
	else if (token[i].type == 4)
		ret[j - 2].value = a + b;
	else if (token[i].type == 5)
		ret[j - 2].value = a - b;
}

float	calcExpr(ExprToken token[], int ac)
{
	ExprToken	ret[ac - 1];
	int	i;
	int	j;
	float	a;
	float	b;

	i = 0;
	j = 0;
	if (ac == 2)
		return (token[0].value);
	while (i < ac - 1)
	{
		if (token[i].type == 6)
		{
			ret[j].value = token[i].value;
			j++;
		}
		else
		{
			calcExprTwo(ret, token, i, j);
			j--;
		}
		i++;
	}
	return (ret[0].value);
}

int	main(int ac, char **av)
{
	ExprToken	token[ac - 1];
	
	argInit(token, ac, av);
	printf("result : %f\n", calcExpr(token, ac));
}