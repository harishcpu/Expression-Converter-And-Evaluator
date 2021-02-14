#include "pre-post.h"

int main(void)
{
        char buf[MAXLEN];
        int choice;

        do
        {
                /* scan the infix expression */
                printf("Enter an " BOLDRED "infix" RESET " expression: ");
                scanf("%[^\n]s", buf);
#if 0
        int i = 0;
        char ch, num = 0;
        while ((ch = getchar()) != EOF)
        {
                if (ch == '\n')
                {
                        buf[i++] = num;
                        printf("%d\n", buf[i - 1]);
                        num = 0;
                        break;
                }
                else if (ch >= '0' && ch <= '9')
                {
                        num = num * 10 + (ch - '0');
                        continue;
                }
                else if (ch == ' ')
                {
                        buf[i++] = num;
                        printf("%d\n", buf[i - 1]);
                        num = 0;
                }
                buf[i++] = ch;
        }
        if (num != 0)
                buf[i] = num;
        buf[i] = '\0';
#endif
#if 0
        printf("%s\n", buf);
#endif
                printf("\n" BOLDMAGENTA "Convert" RESET " to and " BOLDBLUE "Evaluate" RESET " in\nOptions: \n");
                printf("\t1. Infix-to-postfix\n");
                printf("\t2. Infix-to-prefix\n");
                printf("Your choice: ");
                scanf("%d", &choice);
                putchar('\n');

        /* convert the infix expression to pre/post-fix expression */
                char *a = convert_to_pre_or_post(buf, choice);
#if 1
                printf("\t\tAfter converting: ");


                char ary[MAXLEN];
                int i = 0;
                while (*a != '\0')
                {
                        if (isoperator(*a))
                        {
                                ary[i++] = ' ';
                                ary[i++] = *a;
                                ary[i++] = ' ';
                                ++a;
                                continue;
                        }
                        ary[i++] = *a;
                        ++a;
                }
                        ary[i] = *a;

                printf("%s\n", ary);
#endif 
                printf("\t\t" BOLDRED "Result" RESET " of the evaluation: ");
                /* evaluate the result */
                if (isdigit(*ary))
                        infix_postfix(ary);
                else
                        infix_prefix(ary);

                printf("You want to continue?...(enter/n) ");
                putchar(getchar());

        } while (getchar() != 'n');

        return 0;
}
