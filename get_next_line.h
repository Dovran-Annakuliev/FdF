/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:43:46 by rfork             #+#    #+#             */
/*   Updated: 2019/10/28 16:20:41 by rfork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
