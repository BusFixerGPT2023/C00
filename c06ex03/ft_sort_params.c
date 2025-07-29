/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulai <yulai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:57:25 by yulai             #+#    #+#             */
/*   Updated: 2025/07/30 01:45:44 by yulai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;
	
	i = 0;
	while (!src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void replace(char *str[], int a, int b)
{
	char *strt;

	ft_strcpy(strt, str[a]);
	ft_strcpy(str[a], str[b]);
	ft_strcpy(str[b], strt);
}

void ft_sort_argv(char *argv[], int argc)
{
	int	n;
	int	i;
	int j;
	char nm;
	
	i = 0;
	j = i + 1;
	n = argc;
	while (i < argc - 1)
	{
		j = i + 1;
		nm = argv[i];
		while (j < argc - 1)
		{
			if (nm > argv[j])
			{
				
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	n;
	int	i;

	i = 1;
	ft_sort_argv(argv, argc);
	n = argc;
	while (n > 1)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		n--;
		i++;
	}

	return (0);
}
