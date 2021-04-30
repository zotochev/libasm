/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:51:56 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:51:59 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

static void	ft_read_test_00(void)
{
	int	sys_rv;
	int	lib_rv;
	int	sys_errno;
	int	lib_errno;

	lib_rv = ft_read(-1, "Hello", 5);
	lib_errno = errno;
	sys_rv = read(-1, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 0);
	else
		printf("[%2d "RED"ng"RESET"]", 0);
	lib_rv = ft_read(OPEN_MAX, "Hello", 5);
	lib_errno = errno;
	sys_rv = read(OPEN_MAX, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 1);
	else
		printf("[%2d "RED"ng"RESET"]", 1);
}

static void	ft_read_test_01(void)
{
	int	sys_rv;
	int	lib_rv;
	int	sys_errno;
	int	lib_errno;

	lib_rv = ft_read(OPEN_MAX + 1, "Hello", 5);
	lib_errno = errno;
	sys_rv = read(OPEN_MAX + 1, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 2);
	else
		printf("[%2d "RED"ng"RESET"]", 2);
	lib_rv = ft_read(0, NULL, -1);
	lib_errno = errno;
	sys_rv = read(0, NULL, -1);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 3);
	else
		printf("[%2d "RED"ng"RESET"]", 3);
}

static void	ft_read_test_02(void)
{
	int		fd[2];
	int		rv[2];
	int		errno_value[2];
	char	buffer_lib[101];
	char	buffer_sys[101];

	fd[0] = open("test_file_sys", O_RDONLY);
	fd[1] = open("test_file_lib", O_RDONLY);
	rv[1] = ft_read(fd[1], buffer_lib, 12);
	buffer_lib[rv[1]] = '\0';
	errno_value[1] = errno;
	rv[0] = read(fd[0], buffer_sys, 12);
	buffer_sys[rv[0]] = '\0';
	errno_value[0] = errno;
	if (rv[1] == rv[0] && errno_value[0] == errno_value[1]
		&& !strcmp(buffer_lib, buffer_sys))
		printf("[%2d "GRN"ok"RESET"]", 4);
	else
		printf("[%2d "RED"ng"RESET"] sys/lib rv=%d/%d errno=%d/%d [%s]/[%s]",
			4, rv[0], rv[1], errno_value[0],
			errno_value[1], buffer_sys, buffer_lib);
	printf("\n");
	close(fd[0]);
	close(fd[1]);
}

void	ft_read_test(void)
{
	printf(">> ft_read_tests\n");
	ft_read_test_00();
	ft_read_test_01();
	ft_read_test_02();
}
