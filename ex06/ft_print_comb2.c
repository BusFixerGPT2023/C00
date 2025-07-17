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

void show(int nb);
void showStatic (int nb);

void	ft_print_comb2(void)
{
	int num;

	num = 0;
	while (num <= 98)
	{
		show(num);
		num++;
	}
	
}

void	show(int nb)
{
	char n1;
	char n2;
	
	nb++;
	n2 = nb / 10 + '0';
	n1 = nb % 10 + '0';
	
	while (n2<= '9')
		{
			while (n1<='9')
			{
				showStatic (nb-1);
				write(1,&n2,1);
				write(1,&n1,1);
				if (!(n1 == '9' && n2 == '9' && nb == 99))	
					write(1,", ",2);
				n1++;
			}
			if (n1 == '9')
				n1 = '0';
			n2++;
		}
}

void showStatic (int nb)
{
	char n1;
	char n2;

	n2 = nb/10 + 48;
	n1 = nb%10 + 48;

	write(1,&n2,1);
	write(1,&n1,1);
	write(1," ",1);
}


int main()
{
	ft_print_comb2();
	return (0);
}
