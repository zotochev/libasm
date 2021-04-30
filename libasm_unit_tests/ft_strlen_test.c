/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:38 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:52:39 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

void	ft_strlen_test(void)
{
	int		count;
	char	**tests;

	count = 0;
	tests = get_test_array_1();
	printf(">> ft_strlen_tests\n");
	while (tests[count])
	{
		if (strlen(tests[count]) == ft_strlen(tests[count]))
			printf("[%2d "GRN"ok"RESET"]", count);
		else
			printf("[%2d "RED"ng"RESET"]", count);
		count++;
	}
	printf("\n");
	free_array(&tests);
}
