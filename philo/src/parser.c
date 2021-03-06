/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:27:15 by omoudni           #+#    #+#             */
/*   Updated: 2022/07/18 20:47:52 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	putstr_error(char *error)
{
	if (error)
		while (*error)
			write(2, (void *)error++, 1);
	return (1);
}

int	digitize(UINT (*t)[5], char **av)
{
	int	i;
	int	len;

	i = 0;
	len = len_tab(av + 1);
	while (i < 4)
	{
		if (phil_atoi(av[i + 1], &((*t)[i])))
			return (1);
		i++;
	}
	if (len == 5)
		if (phil_atoi(av[i + 1], &((*t)[i])))
			return (1);
	return (0);
}

int	phil_atoi(char *str, UINT *val_to_fill)
{
	long unsigned int	res;
	int					ils[3];

	res = 0;
	ils[0] = 0;
	ils[1] = 0;
	ils[2] = 1;
	if (!str || !str[ils[0]])
		return (1);
	if (str[(ils[0])] == '+')
		(ils[0])++;
	while (str[(ils[0])])
	{
		if (str[(ils[0])] == '-' || !(str[(ils[0])] > 47 && str[(ils[0])] < 58))
			return (1);
		if (str[(ils[0])] != '0')
			ils[2] = 0;
		res = res * 10 + (str[(ils[0])] - 48);
		(ils[0])++;
		if (!(ils[2]))
			(ils[1])++;
	}
	if (ils[1] > 10 || res > UIMAX)
		return (1);
	return ((*val_to_fill) = (UINT)res, 0);
}
