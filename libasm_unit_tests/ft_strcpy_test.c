/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:19 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:21 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

void	ft_strcpy_test(void)
{
	int		count;
	char	*rv[2];
	char	buffer_lib[100];	
	char	buffer_sys[100];	
	char	**tests;

	count = 0;
	tests = get_test_array_1();
	printf(">> ft_strcpy_tests\n");
	while (tests[count])
	{
		rv[0] = strcpy(buffer_sys, tests[count]);
		rv[1] = ft_strcpy(buffer_lib, tests[count]);
		if (0 == strcmp(rv[0], rv[1]) && 0 == strcmp(buffer_sys, buffer_lib))
			printf("[%2d "GRN"ok"RESET"]", count);
		else
			printf("[%2d "RED"ng"RESET"]", count);
		count++;
	}
	printf("\n");
	free_array(&tests);
}
