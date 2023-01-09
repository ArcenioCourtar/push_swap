/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:42:07 by acourtar          #+#    #+#             */
/*   Updated: 2022/11/22 15:22:20 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	section_counter(char const *s, char c);
static int	write_sections(char const *s, char c, char **array);
static char	*fill_array(char const *start, char const *end, int *i);
static int	free_mem(char **array);

// Split string 's' using char 'c' as delimiter character.
// Returns a char** which points to the addresses of all the smaller strings.
// The last pointer will be a NULL pointer as to mark the end of the list.
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		sections;
	int		succes;

	sections = section_counter(s, c);
	array = malloc((sections + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[sections] = NULL;
	succes = write_sections(s, c, array);
	if (succes == 0)
		return (NULL);
	return (array);
}

// Counts the num of sections in 's' for the top level allocation of 'array'.
static int	section_counter(char const *s, char c)
{
	int			sections;
	const char	*start;

	start = s;
	sections = 0;
	if (ft_strlen(s) > 0 && s[0] != c && s[1] == '\0')
		return (1);
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (start < s)
				sections++;
			start = s + 1;
		}
		s++;
	}
	if (start < s)
		sections++;
	return (sections);
}

// Do the boundary checking from section_counter again,
// allocate and write a new string at the second level of 'array'.
static int	write_sections(char const *s, char c, char **array)
{
	const char	*start;
	int			i;

	start = s;
	i = -1;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (start < s)
				array[i] = fill_array(start, s, &i);
			start = s + 1;
			if (i >= 0 && array[i] == NULL)
				return (free_mem(array));
		}
		s++;
	}
	if (start < s)
		array[i] = fill_array(start, s, &i);
	if (i >= 0 && array[i] == NULL)
		return (free_mem(array));
	return (1);
}

// Allocate space and write part of the string using ft_substr().
// Malloc protection is inside of ft_substr();
static char	*fill_array(char const *start, char const *end, int *i)
{
	char	*str;

	*i += 1;
	str = ft_substr(start, 0, end - start);
	return (str);
}

// Free all previously assigned memory sections of the array in case the
// malloc() in fill_array() has failed.
static int	free_mem(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
