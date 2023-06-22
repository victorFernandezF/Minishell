/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:13:23 by victofer          #+#    #+#             */
/*   Updated: 2023/06/22 18:22:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *strndup(char *str, int nb)
{
    int     i;
    char    *res;

    res = malloc(nb * sizeof(char));
    i = -1;
    while (++i < nb)
        res[i] = str[i];
    res[i] = '\0';
    return res;
}

char** splitString(char* str) {
    char** result = malloc(strlen(str) * sizeof(char*));
    int i = 0, j = 0, k = 0, in_quotes = 0;
    while (str[i]) {
        if (str[i] == '/')
            in_quotes = !in_quotes;
        if (!in_quotes && str[i] == ' ') {
            result[k++] = strndup(&str[j], i - j);
            j = i + 1;
        }
        i++;
    }
    result[k++] = strndup(&str[j], i - j);
    result[k] = NULL;
    return result;
}

int main(void)
{
    int     i;
    char    *str; 
    char    **split;

    str = "esto /dentro de comillas/ fuera";
    split = splitString(str);
    i = -1;
    while (split[++i])
        printf("%s\n", split[i]);
    return 0;
}
