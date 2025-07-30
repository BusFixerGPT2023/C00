#include <stdlib.h>

int *ft_range(int min, int max)
{
    if (min >= max)
    {
        return NULL;
    }
    
    int rang = max - min;
    int *rg = NULL;
    rg = malloc(rang*(sizeof(int)));
    if (!rg)
        return NULL;
    for (int i = 0; i < rang; i++)
    {
        rg[i] = min;
        min ++;/* code */
    }
    return (rg);
}