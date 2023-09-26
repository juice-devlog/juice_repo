#include "pipex.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int string_check(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int malloc_count(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (string_check(s[i], c) == 1))
			i++;
		if (s[i])
		{
			count++;
			i++;
		}
		while (s[i] && (string_check(s[i], c) == 0))
			i++;
	}
	return (count);
}

char **ft_free(char **word)
{
	int i;

	i = 0;
	while (word[i])
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (0);
}

char *word_input(char const *s, char c)
{
	int i;
	char *temp;
	int count;
	int j;

	j = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0' && string_check(s[i], c) == 0)
	{
		i++;
		count++;
	}
	temp = (char *)malloc(sizeof(char) * count + 1);
	if (!temp)
		return (0);
	while (s[j] != '\0' && string_check(s[j], c) == 0)
	{
		temp[j] = s[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char **ft_split(char const *s, char c)
{
	char **temp;
	int count;
	int size;

	count = 0;
	size = malloc_count(s, c);
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (0);
	while (*s)
	{
		while (*s && string_check(*s, c) == 1)
			s++;
		if (*s)
		{
			temp[count++] = word_input(s, c);
			if (temp[count - 1] == 0)
				return (ft_free(temp));
			s++;
		}
		while (*s && (string_check(*s, c) == 0))
			s++;
	}
	temp[count] = 0;
	return (temp);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int count;
	char *temp;

	count = ft_strlen(s1);
	count += ft_strlen(s2);
	temp = (char *)malloc(sizeof(char) * count + 1);
	if (!temp)
		return (0);
	while (*s1)
	{
		*temp = *s1;
		s1++;
		temp++;
	}
	while (*s2)
	{
		*temp = *s2;
		s2++;
		temp++;
	}
	*temp = '\0';
	return ((temp - count));
}
