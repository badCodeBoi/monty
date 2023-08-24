#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
char *get_next_word(char *str, char *delims);
int get_word_count(char *str, char *delims);
int get_word_length(char *str, char *delims);

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 * @delims: Delimiter characters.
 *
 * Return: An array of pointers to the extracted words.
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delim - Checks if a character is a delimiter.
 * @ch: The character to be checked.
 * @delims: Delimiter characters.
 *
 * Return: 1 if @ch is a delimiter, 0 otherwise.
 */
int is_delim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Computes the length of a word.
 * @str: The string containing the word.
 * @delims: Delimiter characters.
 *
 * Return: The length of the word.
 */
int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1;

	while (*str)
	{
		if (is_delim(*str, delims))
		{
			if (!pending)
				return (wLen);
		}
		else
		{
			pending = 0;
			wLen++;
		}
		str++;
	}
	return (wLen);
}

/**
 * get_word_count - Computes the number of words in a string.
 * @str: The string to be analyzed.
 * @delims: Delimiter characters.
 *
 * Return: The number of words.
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1;

	while (*str)
	{
		if (is_delim(*str, delims))
		{
			pending = 1;
		}
		else
		{
			if (pending)
			{
				wc++;
				pending = 0;
			}
		}
		str++;
	}
	return (wc);
}

/**
 * get_next_word - Retrieves the next word in a string.
 * @str: The string to be analyzed.
 * @delims: Delimiter characters.
 *
 * Return: A pointer to the start of the next word.
 */
char *get_next_word(char *str, char *delims)
{
	while (*str)
	{
		if (is_delim(*str, delims))
			str++;
		else
			return (str);
	}
	return (str);
}
