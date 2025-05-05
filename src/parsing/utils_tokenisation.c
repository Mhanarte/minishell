/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanarte <mhanarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:20:07 by mhanarte          #+#    #+#             */
/*   Updated: 2025/05/01 18:09:42 by mhanarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	if (c == '|' || c == '&' || c == '<' || c == '>' || c == '(' || c == ')')
		return (1);
	return (0);
}

int	is_token_operator(t_token_type type)
{
	if (type == PIPE || type == OR || type == AND)
		return (1);
	return (0);
}

int	check_unclosed_quotes(char *line)
{
	int	i;
	int	in_single;
	int	in_double;

	i = 0;
	in_single = 0;
	in_double = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (line[i] == '\"' && !in_single)
			in_double = !in_double;
		i++;
	}
	return (in_single || in_double);
}

int	check_unclosed_paren(char *line)
{
	int	i;
	int	in_single;
	int	in_double;
	int	parent_left;
	int	parent_right;
	int	wrong;

	wrong = 0;
	i = 0;
	in_single = 0;
	in_double = 0;
	parent_left = 0;
	parent_right = 0;
	while (line[i])
	{
		if (line[i] == '\'' && !in_double)
			in_single = !in_single;
		else if (line[i] == '\"' && !in_single)
			in_double = !in_double;
		else if (line[i] == '(' && !in_double && !in_single)
			parent_left++;
		else if (line[i] == ')' && !in_double && !in_single
			&& parent_left > parent_right)
			parent_right++;
		else if (line[i] == ')')
			wrong++;
		i++;
	}
	if (parent_right != parent_left || wrong)
		return (1);
	return (0);
}

int	is_invalid_line(char *line)
{
	if (!line || !*line)
		return (0);
	if (check_unclosed_quotes(line))
		return (ft_printf("Quote must be enclosed by an other same quote\n",
				RED, 2));
	if (check_unclosed_paren(line))
		return (ft_printf("Parenthesis must be enclosed by an other parenthesis\n",
				RED, 2));
	return (0);
}
