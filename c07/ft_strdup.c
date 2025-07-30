#include <stdlib.h>

int ft_strlen(char *str)
{
    int i =0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char   *ft_strdup(char *src)
{
    int len = ft_strlen(src);
    char *copy = NULL;
    copy = malloc((len+1)*sizeof(char));

    if (!copy)
        exit(0);

    for (int i = 0; i <= len; i++)
    {
        copy[i] = src[i];
    }
    return copy;

}