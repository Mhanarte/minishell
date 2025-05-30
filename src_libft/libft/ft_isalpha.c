/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhanarte <mhanarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:15:28 by mhanarte          #+#    #+#             */
/*   Updated: 2024/11/22 14:59:10 by mhanarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int nb)
{
	if ((nb >= 65 && nb <= 90) | (nb >= 97 && nb <= 122))
		return (1024);
	else
		return (0);
}
