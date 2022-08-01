#include "stackcalc.h"
#include <stdio.h>
#include <stdlib.h>

ExprToken	*argInit(ExprToken token[], int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] >= '0' && av[i][i] <= '9')
		{
			token[i].value = strtod(av[i], NULL);
			token[i].type = 6;
		}
		else if (av[i][1] >= '0' && av[i][i] <= '9')
		{
			token[i].value = strtod(av[i], NULL);
			token[i].type = 6;
		}
		else if (av[i][0] == '*')
			token[i].type = 2;
		else if (av[i][0] == '/')
			token[i].type = 3;
		else if (av[i][0] == '+')
			token[i].type = 4;
		else if (av[i][0] == '-')
			token[i].type = 5;
		++i;
	}
	return (token);
}

float	calcExpr(ExprToken token[], int ac)
{
	ExprToken	ret[ac];
	int	i;
	int	j;
	float	a;
	float	b;

	i = 0;
	j = 0;
	if (ac == 1)
		return (token[0].value);
	while (i < ac)
	{
		if (token[i].type == 6)
		{
			ret[j] = token[i];
			j++;
			i++;
		}
		else
		{
			a = ret[j].value;
			b = ret[j - 1].value;
			ret[j].value = 0;
			ret[j - 1].value = 0;
			if (token[i] == 2)
				ret[j - 1] = 
		}
	}
}

int	main(int ac, char **av)
{
	ExprToken	token[ac];
	
	argInit(token, ac, av);
	printf("result : %f\n", calcExpr(token, ac));
}