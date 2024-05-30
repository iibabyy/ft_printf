/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:14:21 by ibaby             #+#    #+#             */
/*   Updated: 2024/05/19 21:37:09 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

char	*ft_strtrim2(char const *s1, char sep)
{
	char	*str;
	size_t	end;
	size_t	start;

	if (!s1)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && s1[start] == sep)
		start++;
	while (end > start && s1[end] == sep)
		end--;
	str = ft_substr(s1, start, (end - start + 1));
	return (str);
}

void	ft_split_2(const char *s, char **split, char sep, int words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i] == sep)
		i++;
	while (j < words)
	{
		start = i;
		while (s[i] != sep && s[i])
			i++;
		split[j] = malloc(sizeof(char) * (i - start + 1));
		ft_memmove(split[j], (s + start), (i - start));
		split[j][i - start] = '\0';
		while (s[i] == sep)
			i++;
		j++;
	}
}

char	**ft_split(const char *s, char sep)
{
	int		words;
	char	**split;

	words = count_words(s, sep);
	if (s[ft_strlen(s) - 1] == sep)
		words--;
	if (words < 0 || *s == '\0')
		return (split = malloc(sizeof(char *) * 1), split[0] = NULL, split);
	split = malloc(sizeof(char *) * (words + 1));
	ft_split_2(s, split, sep, words);
	return (split[words] = NULL, split);
}

/*int main()
{
	char	**split;
	int		i;

	split = ft_split("ggggggggggg", 'g');
	i = 0;
	while (split[i])
		ft_putstr_fd(split[i], 1);
	return (0);
}
*/

/*
#include <stdio.h>
#include <unistd.h>

static void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	ft_print_tabstr(char **tabstr)
{
	int	i;

	i = 0;
	while (tabstr[i] != NULL)
	{
		ft_print_result(tabstr[i]);
		if (tabstr[i + 1])
			write(1, "\n", 1);
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
}

static void	check_split(char *s, char c)
{
	char	**tabstr;

	if (!(tabstr = ft_split(s, c)))
		ft_print_result("NULL");
	else
		ft_print_tabstr(tabstr);
}

int	main(int argc, const char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	if ((arg = atoi(argv[1])) == 1)
		check_split("          ", ' ');
	else if (arg == 2)
		check_split("lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	else if (arg == 3)
	{
		check_split("   lorem   ipsum dolor     sit amet,
			consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	}
	else if (arg == 4)
		check_split("lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse lectus
			tortor, dignissim sit amet, adipiscing nec, ultricies sed,
			dolor. Cras elementum ultricies diam. Maecenas ligula massa,
			varius a, semper congue, euismod non, mi.", 'i');
	else if (arg == 5)
		check_split("lorem ipsum dolor sit amet,
			consectetur adipiscing elit. Sed non risus. Suspendisse lectus
			tortor, dignissim sit amet, adipiscing nec, ultricies sed,
			dolor. Cras elementum ultricies diam. Maecenas ligula massa,
			varius a, semper congue, euismod non, mi.", 'z');
	return (0);
}
*/