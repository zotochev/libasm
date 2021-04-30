/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_test_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 20:52:59 by mscot             #+#    #+#             */
/*   Updated: 2021/04/21 20:53:01 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_unit_tests.h"

char	**get_test_array_1(void)
{
	char	**array;

	array = malloc(sizeof(char *) * 100);
	if (NULL == array)
		return (NULL);
	array[0] = strdup("");
	array[1] = strdup("Hello");
	array[2] = strdup("Hel\0lo");
	array[3] = strdup("\0");
	array[4] = strdup("1234567890");
	array[5] = strdup("");
	array[6] = strdup("a");
	array[7] = NULL;
	return (array);
}

char	**get_test_array_2(void)
{
	char	**array;

	array = malloc(sizeof(char *) * 100);
	if (NULL == array)
		return (NULL);
	array[0] = strdup("");
	array[1] = strdup("Hello");
	array[2] = strdup("Hel\0lo");
	array[3] = strdup("\0");
	array[4] = strdup("1234567890");
	array[5] = strdup(" ");
	array[6] = strdup("");
	array[7] = NULL;
	return (array);
}

void	free_array(char ***array)
{
	int	count;

	count = 0;
	while ((*array)[count])
	{
		free((*array)[count]);
		count++;
	}
	free(*array);
}
