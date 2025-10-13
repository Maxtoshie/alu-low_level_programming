#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, l1 = 0, l2 = 0;
	char *str;

	/* handle NULL strings */
	if (s1 != NULL)
		while (s1[l1] != '\0')
			l1++;

	if (s2 != NULL)
		while (s2[l2] != '\0')
			l2++;

	str = malloc(l1 + l2 + 1);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
		str[i] = s1[i];
	for (i = 0; i < l2; i++)
		str[l1 + i] = s2[i];

	str[l1 + l2] = '\0';

	return (str);
}
