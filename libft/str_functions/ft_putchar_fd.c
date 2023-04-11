/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:57:39 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 10:44:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * Function: ft_putchar_fd
 * ----------------------------
 *   Writes a char in the given file descriptor.
 *
 *   c: char to be writen. 
 *   fd: file descriptor.
 *  
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
