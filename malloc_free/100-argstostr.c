#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, k = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* calculate total length of all arguments + newline after each */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			len++;
			j++;
		}
		len++; /* for '\n' */
	}

	str = malloc(sizeof(char) * (len + 1)); /* +1 for final '\0' */
	if (str == NULL)
		return (NULL);

	/* copy arguments into new string */
	for (i = 0; i < ac; i++)
	{
		j = 0;
		while (av[i][j])
		{
			str[k++] = av[i][j];
			j++;
		}
		str[k++] = '\n';
	}

	str[k] = '\0';
	return (str);
}
