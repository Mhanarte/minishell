/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanarte <mhanarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:12:40 by mhanarte          #+#    #+#             */
/*   Updated: 2025/04/28 13:48:26 by mhanarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt(void)
{
	char	*input;

	input = readline(BOLD MAGENTA "➜ minishell: " RESET);
	if (!input)
		minishell_error("Exit\n", 2, RED, 0);
	if (*input)
		add_history(input);
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	*token;

	(void)argv;
	(void)envp;
	if (argc != 1)
		minishell_error("Wrong number of argument\n", 2, RED, 1);
	while (1)
	{
		input = prompt();
		token = tokenisation(input);
		if (!check_possible_token(token))
			print_token(token);
		free(token);
		free(input);
	}
	return (0);
}
