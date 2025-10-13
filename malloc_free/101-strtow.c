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
 * word_len - returns the length of the next word
 * @str: string to evaluate
 *
 * Return: length of the word
 */
int word_len(char *str)
{
	int len = 0;

	while (str[len] && str[len] != ' ')
		len++;

	return (len);
}

/**
 * free_words - frees allocated memory on failure
 * @words: array of words
 * @count: number of allocated words
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
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
	int i = 0, j = 0, k, len, wcount;

	if (str == NULL || *str == '\0')
		return (NULL);

	wcount = word_count(str);
	if (wcount == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (wcount + 1));
	if (words == NULL)
		return (NULL);

	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '\0')
			break;

		len = word_len(str + i);
		words[j] = malloc(sizeof(char) * (len + 1));
		if (words[j] == NULL)
		{
			free_words(words, j);
			return (NULL);
		}

		for (k = 0; k < len; k++)
			words[j][k] = str[i + k];
		words[j][k] = '\0';
		j++;
		i += len;
	}
	words[j] = NULL;
	return (words);
}
