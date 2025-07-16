/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulai <yulai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:47:07 by yulai             #+#    #+#             */
/*   Updated: 2025/07/16 22:36:17 by yulai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int n3;
	n3 = 90;
	show(n3);
}

void show(int nb)
{
	int n1;
	int n2;

	n1 = nb / 10;
	n2 = nb % 10;
	printf("%d %d",n1,n2);
	while (n1<= '9')
		{
			while (n2<='9')
			{
				write(1,&n1,1);
				write(1,&n2,1);
				write(1," ",1);
				n2++;
			}
			if (n2 = '9')
				n2 = '0';
				
			n1++;
		}
}

int main()
{
	ft_print_comb2();
	return (0);
}