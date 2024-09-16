/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:16:06 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/06 17:29:14 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	int c = '1';
	ft_isdigit(c);
	printf("%d\n",ft_isdigit(c));
	printf("%d\n",isdigit(c));
	return(0);
}
*/
