/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:49 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:51 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

void	ft_write_test_00(void)
{
	int	sys_rv;
	int	lib_rv;
	int	sys_errno;
	int	lib_errno;

	lib_rv = ft_write(-1, "Hello", 5);
	lib_errno = errno;
	sys_rv = write(-1, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 0);
	else
		printf("[%2d "RED"ng"RESET"]", 0);
	lib_rv = ft_write(OPEN_MAX, "Hello", 5);
	lib_errno = errno;
	sys_rv = write(OPEN_MAX, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 1);
	else
		printf("[%2d "RED"ng"RESET"]", 1);
}

void	ft_write_test_01(void)
{
	int	sys_rv;
	int	lib_rv;
	int	sys_errno;
	int	lib_errno;

	lib_rv = ft_write(OPEN_MAX + 1, "Hello", 5);
	lib_errno = errno;
	sys_rv = write(OPEN_MAX + 1, "Hello", 5);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 2);
	else
		printf("[%2d "RED"ng"RESET"]", 2);
	lib_rv = ft_write(0, NULL, -1);
	lib_errno = errno;
	sys_rv = write(0, NULL, -1);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 3);
	else
		printf("[%2d "RED"ng"RESET"]", 3);
}

void	ft_write_test_02(void)
{
	int	fd[2];
	int	sys_rv;
	int	lib_rv;
	int	sys_errno;
	int	lib_errno;

	fd[0] = open("test_file_sys",
			O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
	fd[1] = open("test_file_lib",
			O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644);
	lib_rv = ft_write(fd[1], "Hello world!", 12);
	lib_errno = errno;
	sys_rv = write(fd[0], "Hello world!", 12);
	sys_errno = errno;
	if (lib_rv == sys_rv && lib_errno == sys_errno)
		printf("[%2d "GRN"ok"RESET"]", 4);
	else
		printf("[%2d "RED"ng"RESET"] sys/lib rv=%d/%d errno=%d/%d",
			4, sys_rv, lib_rv, sys_errno, lib_errno);
	printf("\n");
	close(fd[0]);
	close(fd[1]);
}

void	ft_write_test(void)
{
	printf(">> ft_write_tests\n");
	ft_write_test_00();
	ft_write_test_01();
	ft_write_test_02();
}
