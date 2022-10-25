#include "minishell.h"



static int	ft_word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_strndup(char const *s, int len)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof (char) * (len + 1));
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	**ft_split(char **s, char c)
{
	int		word_len;
	int		counter;

	counter = 0;
	if (!s)
		return (0);
	*word_count = ft_word_count(s, ' ');
	s = (char **) malloc(sizeof (char **) * (*word_count));
	if (ps->result == NULL)
		return (0);
	while (counter < *word_count)
	{
		while (*s && *s == ' ')
			s++;
		word_len = ft_word_len(s, ' ');
		ps->result[counter] = ft_atoi(ft_strndup(s, word_len), ps);
		s = s + word_len;
		counter++;
	}

	return (s);
}
