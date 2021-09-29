/*
** EPITECH PROJECT, 2019
** tab_realloc
** File description:
** tab_realloc
*/

#include<stdlib.h>

void tab_delete(void **tab)
{
    for (int x = 0; tab[x]; x += 1)
        free(tab[x]);
    free(tab);
}

void **tab_realloc(void **tab)
{
    void **new_tab = NULL;
    unsigned int i = 0;

    while (tab != NULL && tab[i] != NULL)
        i += 1;
    new_tab = malloc(sizeof(void *) * (i + 2));
    if (new_tab == NULL)
        return (NULL);
    for (unsigned int x = 0; x < i; x += 1)
        new_tab[x] = tab[x];
    new_tab[i] = NULL;
    new_tab[i + 1] = NULL;
    return (new_tab);
}