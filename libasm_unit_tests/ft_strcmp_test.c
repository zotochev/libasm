/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:10 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:12 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

void	ft_strcmp_test(void)
{
	int		count;
	int		lib_rv;
	int		sys_rv;
	char	**tests_cmp_1;
	char	**tests_cmp_2;

	count = 0;
	tests_cmp_1 = get_test_array_1();
	tests_cmp_2 = get_test_array_2();
	if (!tests_cmp_1 || !tests_cmp_2)
		return ;
	printf(">> ft_strcmp_tests\n");
	while (tests_cmp_1[count] && tests_cmp_2[count])
	{
		sys_rv = strcmp(tests_cmp_1[count], tests_cmp_2[count]);
		lib_rv = ft_strcmp(tests_cmp_1[count], tests_cmp_2[count]);
		if (sys_rv == lib_rv)
			printf("[%2d "GRN"ok"RESET"]", count);
		else
			printf("[%2d "RED"ng"RESET"]", count);
		count++;
	}
	printf("\n");
	free_array(&tests_cmp_1);
	free_array(&tests_cmp_2);
}
