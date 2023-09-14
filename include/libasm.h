/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsung <rsung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:02:31 by rsung             #+#    #+#             */
/*   Updated: 2023/07/04 15:54:24 by rsung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *str);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(size_t fd, const char *buf, size_t len);
size_t	ft_read(size_t fd, char *buf, size_t len);
char	*ft_strdup(const char *str);

#endif
