#include "pre-post.h"

int verify_expr(char *buf)
{
        if (isPostfix(buf) == TRUE)
                /* post-fix */
                return POSTFIX;
        else if (isPrefix(buf) == TRUE)
                /* pre-fix */
                return PREFIX;
        else    /* in-fix */
                return INFIX;
}

int isPrefix(char *buf)
{
        int i = 0;
        if (isoperator(buf[i++]))
        {
                if (isoperand(buf[++i]))
                {
                        ++i;
                        if (isoperand(buf[++i]))
                                return POSTFIX;
                }
        }
}

int isPostfix(char *buf)
{
        int i = 0;
        if (isoperand(buf[i++]))
        {
                if (isoperand(buf[++i]))
                {
                        ++i;
                        if (isoperator(buf[++i]))
                                return PREFIX;
                }
        }
}

int isoperator(char c)
{
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
                return TRUE;
        else
                return FALSE;
}

int isoperand(char c)
{
        if (isdigit(c))
                return TRUE;
        else
                return FALSE;
}
