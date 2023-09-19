#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int i = 1;
	int hdc = 1;

	if (ac == 3)
	{
		while (i <= atoi(av[1]))
		{
			if (atoi(av[1]) % i == 0 && atoi(av[2]) % i == 0)
				hdc = i;
			i++;
		}
		printf("%d", hdc);
	}
	printf("\n");
}