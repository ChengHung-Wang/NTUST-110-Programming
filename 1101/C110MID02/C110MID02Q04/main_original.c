#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char *ask(const char *prompt)
{
    char c, *input;
    input = (char *)malloc(sizeof(*input)); // allocate 1 byte
    size_t index = 0;

    fputs(prompt, stdout); // display the prompt

    // get a char `c`, check `c` is nither EOF nor '\n'
    while ((c = getchar()) != EOF && c != '\n')
    {
        if (!(input = (char *)realloc(input, index + 1)))
        {
            // allocation failed and input is NULL
            return input;
        }

        input[index++] = c;
    }
    input[index] = '\0'; // end the string with '\0'

    return input;
}
int indexOf(const char find, char *string)
{
    const int length = strlen(string);
    for (int index = 0; index < length; index++)
    {
        if (*string == find)
        {
            return index;
        }
        string++;
    }
    return -1;
}

int string_count(char *original_data, char *key)
{
    int count = 0;
    int key_len = strlen(key);
    char *pos_start = original_data, *pos_end = NULL;

    while (NULL !=
           (pos_end = strstr(pos_start, key)))
    {
        pos_start = pos_end + key_len;
        count++;
    }

    return count;
}

char *replace(char *original_data, char *replaced, char *to)
{
    int rep_len = strlen(replaced);
    int to_len = strlen(to);
    int counts = string_count(original_data, replaced);
    int m = strlen(original_data) + counts * (to_len - rep_len); /* 计算将要分配的内存的大小 */
    char *new_buf = NULL;

    new_buf = (char *)malloc(m + 1);
    if (NULL == new_buf)
    {
        printf("malloc error\n");
        return NULL;
    }

    memset(new_buf, 0, m + 1);

    char *pos_start = original_data, *pos_end = NULL, *pbuf = new_buf;
    int copy_len = 0;

    while (NULL != (pos_end = strstr(pos_start, replaced)))
    {
        copy_len = pos_end - pos_start;
        strncpy(pbuf, pos_start, copy_len);
        pbuf += copy_len;
        strncpy(pbuf, to, strlen(to));
        pbuf += to_len;
        pos_start = pos_end + rep_len;
    }
    strncpy(pbuf, pos_start, strlen(pos_start) + 1);

    return new_buf;
}

int main()
{
    char *result = NULL;
    char *one = ask(""), *two = ask(""), *three = ask("");
    result = replace(one, two, three);
    if (NULL != result)
    {
        printf("%s\n", result);
    }
    free(result);
    return 0;
}