/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:26:04 by victofer          #+#    #+#             */
/*   Updated: 2023/06/19 10:32:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

typedef struct s_test{
	int		test;
}			t_test;

void	modify_struct(t_test *test)
{
	test->test = 42;
}

int	main(void)
{
	t_test	*test;

	test = malloc(sizeof(t_test));
	test->test = 0;
	printf("Before %i\n", test->test);
	modify_struct(test);
	printf("After %i\n", test->test);
	return (0);
}
