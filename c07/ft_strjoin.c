#include <stdlib.h>

// Helper: Get length of a string
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

// Helper: Copy a string from src to dest
char *ft_strcpy(char *dest, char *src)
{
    while (*src)
        *dest++ = *src++;
    return dest;
}

// Main function
char *ft_strjoin(int size, char **strs, char *sep)
{
    int total_len = 0;
    int sep_len = ft_strlen(sep);
    char *result;
    char *ptr;
    int i;

    if (size == 0)
    {
        result = (char *)malloc(1);
        if (result)
            result[0] = '\0';
        return result;
    }

    // Calculate total required length
    for (i = 0; i < size; i++)
        total_len += ft_strlen(strs[i]);
    total_len += sep_len * (size - 1);

    result = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!result)
        return NULL;

    ptr = result;
    for (i = 0; i < size; i++)
    {
        ptr = ft_strcpy(ptr, strs[i]);
        if (i < size - 1)
            ptr = ft_strcpy(ptr, sep);
    }
    *ptr = '\0';

    return result;
}