#include "main.h"
#include <stdlib.h>

/**
 * word_count - counts the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int word_count(char *str)
{
	int count = 0, i = 0;

	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0')
		{
			count++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, l, wcount, len;

	if (str == NULL || *str == '\0')
		return (NULL);

	wcount = word_count(str);
	if (wcount == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wcount + 1));
	if (words == NULL)
		return (NULL);

	i = 0, l = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;

		j = i;
		while (str[j] && str[j] != ' ')
			j++;

		len = j - i;
		words[l] = malloc(sizeof(char) * (len + 1));
		if (words[l] == NULL)
		{
			for (k = 0; k < l; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}

		for (k = 0; k < len; k++)
			words[l][k] = str[i + k];
		words[l][k] = '\0';
		l++;
		i = j;
	}
	words[l] = NULL;
	return (words);
}
