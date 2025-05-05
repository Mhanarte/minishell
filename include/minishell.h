/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanarte <mhanarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:58:32 by mhanarte          #+#    #+#             */
/*   Updated: 2025/05/01 18:09:50 by mhanarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/include_libft/libft.h"

typedef enum e_token_type
{
	WORD,        // Un mot classique (commande, argument, nom de fichier)
	PIPE,        // |
	REDIR_IN,    // <
	REDIR_OUT,   // >
	APPEND,      // >>
	HEREDOC,     // <<
	AND,         // &&
	OR,          // ||
	PAREN_LEFT,  // (
	PAREN_RIGHT, // )
	END          // Fin de la liste
}		t_token_type;

typedef struct s_token
{
	t_token_type type;    // Type du token
	char *content;        // Texte du token
	int quoted;           // Était-il entre quotes ?
	int expandable;       // Faut-il l'expanser ? (ex: $VAR)
	struct s_token *next; // Token suivant dans la liste
}		t_token;

// # ════════════════════════════════════════════════ #
// #                   🛠️ EXEC                        #
// # ════════════════════════════════════════════════ #

// # ════════════════════════════════════════════════ #
// #                   🛠️ EXIT                        #
// # ════════════════════════════════════════════════ #

// exit_code.c
void	minishell_error(char *str, int fd, char *color, int status);
void	free_token(t_token *token);

// # ════════════════════════════════════════════════ #
// #                   🛠️ PARSING                     #
// # ════════════════════════════════════════════════ #

// check_token.c
int		check_possible_token(t_token *token);
int		check_end_line(t_token *token);
int		check_between_token(t_token *token);
int		check_parenthesis(t_token *token);

// tokenisation.c
t_token	*tokenisation(char *line);
t_token	*add_token(t_token **lst, t_token_type type, char *content, int quoted,
			int expandable);
char	*extract_word(char *line, int *i, int *quoted, int *expandable);

// utils_tokenisation.c
int		is_invalid_line(char *line);
int		is_operator(char c);
int		check_unclosed_paren(char *line);
int		is_token_operator(t_token_type type);

// temp.c
void	print_token(t_token *token);
char	*get_token_type_name(t_token_type type);

// # ════════════════════════════════════════════════ #
// #                   🛠️ BUILT-IN                    #
// # ════════════════════════════════════════════════ #

#endif