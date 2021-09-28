/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:00:24 by kipark            #+#    #+#             */
/*   Updated: 2021/09/28 22:58:47 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"utility.h"

typedef struct t_board_values {
	int	size_y;
	int	size_x;
	int	max_y;
	int	max_x;
	int	answer;
}	t_board_values;

int	vm(int a, int b, int c)
{
	int	min;

	min = 99999999;
	if (min > a)
		min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

void	set_dp_board(char **in_board, int **dp, t_board_values bv, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < bv.size_y)
		while (++j < bv.size_x)
			dp[i][j] = 0;
	i = 0;
	while (i < bv.size_y - 1)
	{
		j = 0;
		while (j < bv.size_x - 1)
		{	
			if (in_board[i][j] == map->empty)
			{
				dp[i + 1][j + 1] = 1;
			}
			++j;
		}
		++i;
	}
}

struct t_board_values	play_dp(int **dp, t_board_values bv)
{
	int	i;
	int	j;

	i = 1;
	while (i < bv.size_y)
	{
		j = 1;
		while (j < bv.size_x)
		{
			if (dp[i][j] == 1)
			{
				dp[i][j] = 1 + vm(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
				if (bv.answer < dp[i][j])
				{
					bv.answer = dp[i][j];
					bv.max_y = i;
					bv.max_x = j;
				}
			}
			++j;
		}
		++i;
	}
	return (bv);
}

void	**solution(char **in_board, int **dp, t_board_values bv, t_map *mapinfo)
{
	int	i;
	int	j;

	set_dp_board(in_board, dp, bv, mapinfo);
	bv = play_dp(dp, bv);
	i = 0;
	while (i < bv.answer)
	{
		j = 0;
		while (j < bv.answer)
		{
			in_board[bv.max_y - i - 1][bv.max_x - j - 1] = mapinfo->area;
			++j;
		}
		++i;
	}
}

void	find_square(char **map, t_map *mapinfo)
{
	t_board_values	bv;
	int				**dp_board;
	int				i;

	bv.size_y = mapinfo -> height + 1;
	bv.size_x = mapinfo -> width + 1;
	dp_board = (int **)malloc(sizeof(int *) * (bv.size_y));
	if (!dp_board)
		return ;
	i = 0;
	while (i < bv.size_y)
	{
		dp_board[i] = (int *)malloc(sizeof(int) * (bv.size_x));
		if (!dp_board[i])
			return ;
		++i;
	}
	solution(map, dp_board, bv, mapinfo);
	i = -1;
	while (++i < bv.size_y)
		free(dp_board[i]);
	free(dp_board);
}
