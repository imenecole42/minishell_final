/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imraoui <imraoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:43:11 by imraoui           #+#    #+#             */
/*   Updated: 2023/02/21 17:33:12 by imraoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include "libft.h"

# ifndef  BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

size_t	ft_strlen1(const char *str);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strchr1( char *s, int c);
char	*ft_select_g1(char *str);
char	*ft_select_g2(char *str);
char	*get_read_line(int fd, char *str);
char	*get_next_line(int fd);
#endif
