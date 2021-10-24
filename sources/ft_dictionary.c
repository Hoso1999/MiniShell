/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgaspary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:44:07 by vgaspary          #+#    #+#             */
/*   Updated: 2021/10/24 12:44:09 by vgaspary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dictionary_destructor(dictionary_t *dict)
{
	dictionary_t	*tmp;

	while (dict != NULL)
	{
		tmp = dict;
		dict = dict->next;
		ft_dictionary_del_key(tmp);
	}
}

dictionary_t	*ft_env_copy(char **env)
{
	int				envp_count;
	int				i;
	dictionary_t	*tmp;
	dictionary_t	*dict;

	dict = NULL;
	envp_count = ft_vecstrlen(env);
	i = 0;
	while (i < envp_count)
	{
		tmp = ft_dictionary_create(env[i]);
		if (tmp == NULL)
		{
			tmp = NULL;
			break ;
		}
		i++;
		ft_dictionaryadd_back(&dict, tmp);
	}
	return (dict);
}

int	ft_dictionarysize(dictionary_t *stack)
{
	dictionary_t	*ptr;
	int				q;

	q = 0;
	if (stack == NULL)
		return (0);
	while (stack != NULL)
	{
		stack = stack->next;
		q++;
	}
	return (q);
}

size_t	ft_joins_dict(char const *s2, size_t i, int count, char *subjoin)
{
	int	j;

	j = 0;
	while (s2[i] && i < count)
	{
		subjoin[j] = s2[i];
		i++;
		j++;
	}
	return (i);
}

int	ft_find_element(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || ft_strlen(str) < 2)
		return (-1);
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}
