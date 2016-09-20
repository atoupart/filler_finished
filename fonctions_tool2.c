/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_tool2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoupart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:09:38 by atoupart          #+#    #+#             */
/*   Updated: 2016/09/15 15:09:41 by atoupart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				find_point_player_hg(t_struct *s)
{
	s->y1 = 0;
	while (s->y1 < s->y)
	{
		s->x1 = 0;
		while (s->x1 < s->x)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1++;
		}
		s->y1++;
	}
	return (0);
}

int				find_point_player_bd(t_struct *s)
{
	s->y1 = s->y - 1;
	while (s->y1 >= 0)
	{
		s->x1 = s->x - 1;
		while (s->x1 >= 0)
		{
			if (s->plateau[s->y1][s->x1] == s->l_player)
				return (0);
			s->x1--;
		}
		s->y1--;
	}
	return (0);
}

int				find_point_opponent_hg(t_struct *s)
{
	s->y2 = 0;
	while (s->y2 < s->y)
	{
		s->x2 = 0;
		while (s->x2 < s->x)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2++;
		}
		s->y2++;
	}
	return (0);
}

int				find_point_opponent_bd(t_struct *s)
{
	s->y2 = s->y - 1;
	while (s->y2 >= 0)
	{
		s->x2 = s->x - 1;
		while (s->x2 >= 0)
		{
			if (s->plateau[s->y2][s->x2] == s->l_opponent ||\
				s->plateau[s->y2][s->x2] == s->l_opponent2)
				return (0);
			s->x2--;
		}
		s->y2--;
	}
	return (0);
}

int				look_around(t_struct *s, int y1, int x1)
{
	int k;

	k = 0;
	if (y1 - 1 >= 0)
		if (s->plateau[y1 - 1][x1] == '.' ||\
			s->plateau[y1 - 1][x1 + 1] == '.')
			k++;
	if (x1 - 1 >= 0)
		if (s->plateau[y1][x1 - 1] == '.' ||\
			s->plateau[y1 + 1][x1 - 1] == '.')
			k++;
	if (y1 - 1 >= 0 && x1 - 1 >= 0 && \
		s->plateau[y1 - 1][x1 - 1] == '.')
		k++;
	if (s->plateau[y1][x1 + 1] == '.' ||\
		s->plateau[y1 + 1][x1] == '.')
		k++;
	if (s->plateau[y1 + 1][x1 + 1] == '.')
		k++;
	return (k);
}