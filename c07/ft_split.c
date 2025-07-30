#include <stdlib.h>

// Check if character is in charset
int is_sep(char c, char *charset)
{
    int i = 0;
    while (charset[i])
    {
        if (charset[i] == c)
            return 1;
        i++;
    }
    return 0;
}

// Get string length
int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

// Count how many substrings will be in the result
int count_words(char *str, char *charset)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        if (str[i])
            count++;
        while (str[i] && !is_sep(str[i], charset))
            i++;
    }
    return count;
}

// Copy a word from str to a new allocated string
char *copy_word(char *start, int len)
{
    char *word = (char *)malloc(len + 1);
    int i;
    if (!word)
        return NULL;
    for (i = 0; i < len; i++)
        word[i] = start[i];
    word[i] = '\0';
    return word;
}

// Main function
char **ft_split(char *str, char *charset)
{
    int i = 0, j = 0, start = 0;
    int word_count = count_words(str, charset);
    char **result = (char **)malloc(sizeof(char *) * (word_count + 1));

    if (!result)
        return NULL;

    while (str[i])
    {
        while (str[i] && is_sep(str[i], charset))
            i++;
        start = i;
        while (str[i] && !is_sep(str[i], charset))
            i++;
        if (i > start)
        {
            result[j] = copy_word(&str[start], i - start);
            if (!result[j++])
            {
                // Free previously allocated memory on failure
                while (--j >= 0) free(result[j]);
                free(result);
                return NULL;
            }
        }
    }
    result[j] = NULL;
    return result;
}