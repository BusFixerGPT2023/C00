/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulai <yulai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:06:30 by yulai             #+#    #+#             */
/*   Updated: 2025/07/29 23:55:25 by yulai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int tbl[10][10];
char str[11];
// int nnb;
// nnb = 0;

void changeval(int src[10][10], int x, int y, int dif)
{
	int i;
	
	i = 0;
	while (i < 10)
	{
		src[i][x]=src[i][x] + dif;
		i++;
	}
	i = 0;
	while (i < 10)
	{
		src[y][i]=src[y][i] + dif;
		i++;
	}
}

void changeval2(int src[10][10], int x, int y, int dif)
{
	int i;
	
	i = 0;
	while ((y + i < 10)&&(x + i < 10))
	{
		src[y + i][x + i] = src[y + i][x + i] + dif;
		i++;
	}
	while ((y - i >= 0)&&(x + i < 10))
	{
		src[y - i][x + i] = src[y - i][x + i] + dif;
		i++;
	}
	while ((y + i < 10)&&(x - i >= 0))
	{
		src[y + i][x - i]= src[y + i][x - i] + dif;
		i++;
	}
	while ((y - i >= 0)&&(x - i >= 0))
	{
		src[y - i][x - i] = src[y - i][x - i] + dif;
		i++;
	}
}

void inittbl(int tbl[10][10])
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			tbl[x][y]= 0;	
			y++;
		}
		y = 0;
		x++;
	}
}

void recurs(int col, int tbl[10][10], int *p)
{
	int count;
	int i;
	
	if (col == 10)
	{
		*p += 1;
		return;
	}

	i = 0;
	while (i < 10) 
	{
		if (tbl[i][col] == 0)
		{
			changeval(tbl,i,col,1);
			changeval2(tbl,i,col,1);
			recurs(col + 1,tbl, p);
			changeval(tbl,i,col,-1);
			changeval2(tbl,i,col,-1);
		}
		i++;
	}
	return;
}
int ft_ten_queens_puzzle(void)
{
	int nb = 0;

	inittbl(tbl);
	recurs(0,tbl,&nb);
	printf("%d",nb);
	return nb;
}

int main()
{
	ft_ten_queens_puzzle();
}