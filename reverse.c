#include "pre-post.h"

/* reverse_a_string: reverses or rotates the given string */
int reverse_a_string(char *a, int begin, int end)
{
        char temp;
        while (begin < end)
        {
                temp = a[begin];
                a[begin] = a[end];
                a[end] = temp;
                ++begin;
                --end;
        }
}

/* reverse_words: reverses the words in an array of chars, space is the delimiter */
int reverse_words(char *a)
{
        int begin = 0;
        int end = 0;
        int len = strlen(a);

        /* find then begining and ending indeces of each word 
         * and reverse the words */
        while (end <= len)
        {
                if (a[end] == ' ' || a[end] == '\0')
                {
                        reverse_a_string(a, begin, end - 1);
                        begin = end + 1;
                }
                ++end;
        }
        /* reverse the whole string again */
        reverse_a_string(a, 0, len - 1);
}
