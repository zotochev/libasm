/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_unit_tests.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:53:10 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:53:12 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_UNIT_TESTS_H
# define LIBASM_UNIT_TESTS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include "libasm.h"

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define RESET	"\x1B[0m"

void	ft_strlen_test(void);
void	ft_strcpy_test(void);
void	ft_strcmp_test(void);
void	ft_write_test(void);
void	ft_read_test(void);
void	ft_strdup_test(void);
char	**get_test_array_1(void);
char	**get_test_array_2(void);
void	free_array(char ***array);

#endif
