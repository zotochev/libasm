/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:28 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:32 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

void	ft_strdup_test(void)
{
	int		count;
	char	*lib_rv;
	char	*sys_rv;
	char	**tests;

	count = 0;
	tests = get_test_array_1();
	printf(">> ft_strdup_tests\n");
	while (tests[count])
	{
		sys_rv = strdup(tests[count]);
		lib_rv = ft_strdup(tests[count]);
		if (0 == strcmp(sys_rv, lib_rv))
			printf("[%2d "GRN"ok"RESET"]", count);
		else
			printf("[%2d "RED"ng"RESET"]", count);
		count++;
		free(sys_rv);
		free(lib_rv);
	}
	printf("\n");
	free_array(&tests);
}
