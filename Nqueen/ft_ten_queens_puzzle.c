/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulai <yulai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:06:30 by yulai             #+#    #+#             */
/*   Updated: 2025/07/31 03:05:22 by yulai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	g_tbl[10][10] = {0};

void	changeval(int src[10][10], int x, int y, int dif)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		src[x][i] = src[x][i] + dif;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		src[i][y] = src[i][y] + dif;
		i++;
	}
	i = 0;
	while ((y + i < 10) && (x + i < 10))
	{
		src[x + i][y + i] = src[x + i][y + i] + dif;
		i++;
	}
	src[x][y] = src[x][y] + dif * 100;
}

void	changeval2(int src[10][10], int x, int y, int dif)
{
	int	i;

	i = 0;
	while ((y - i >= 0) && (x + i < 10))
	{
		src[y - i][x + i] = src[y - i][x + i] + dif;
		i++;
	}
	i = 0;
	while ((y + i < 10) && (x - i >= 0))
	{
		src[y + i][x - i] = src[y + i][x - i] + dif;
		i++;
	}
	i = 0;
	while ((y - i >= 0) && (x - i >= 0))
	{
		src[y - i][x - i] = src[y - i][x - i] + dif;
		i++;
	}
}

void	ft_write(int tbl[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (tbl[j][i] >= 100)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	recurs(int col, int tbl[10][10])
{
	int	i;
	int	c;

	c = 0;
	if (col == 10)
	{
		ft_write(tbl);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (tbl[i][col] == 0)
		{
			changeval(tbl, i, col, 1);
			changeval2(tbl, col, i, 1);
			c += recurs(col + 1, tbl);
			changeval(tbl, i, col, -1);
			changeval2(tbl, col, i, -1);
		}
		i++;
	}
	return (c);
}

int	ft_ten_queens_puzzle(void)
{
	int	nb;

	nb = recurs(0, g_tbl);
	return (nb);
}

// int main()
// {
// 	int n = ft_ten_queens_puzzle();
// 	printf("%d",n);
// }