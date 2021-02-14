#include <stdio.h>
#include <string.h>

#define MAXLEN 25

char *infix_postfix_conversion(char *infix);
int infix_pre(char symbol);
int stack_pre(char symbol);

char *convert_to_pre_or_post(char *ary, int ch)
{
        do 
        { 
                char *a;
                switch(ch)
                {
                        case 1:
                                return infix_postfix_conversion(ary);
                                break;
                        case 2:
                                for (int i = 0, j = strlen(ary) - 1; i <= j && j >= i; i++, j--)
                                {
                                        char temp = ary[i]; 
                                        ary[i] = ary[j]; 
                                        ary[j] = temp;
                                }
#if 0
                                printf("hey%s\n", ary);
#endif
                                a = infix_postfix_conversion(ary);
#if 0
                                printf("%s\n", a);
#endif
                                for (int i = 0, j = strlen(a) - 1; i <= j && j >= i; i++, j--)
                                {
                                        char temp = a[i]; 
                                        a[i] = a[j]; 
                                        a[j] = temp;
                                }
#if 0
                                printf("%s\n", a);
#endif
                                return a;
                }
                printf("Do you want to continue? ");
        } while (getchar() == 'y');
}


char *infix_postfix_conversion(char *infix)
{
        char stack[MAXLEN];
        int top = 0;
        static char postfix[MAXLEN];

        stack[top] = '#';

        int i = 0, j = 0;
        while (i < strlen(infix))
        {
                while (stack_pre(stack[top]) > infix_pre(infix[i]))
                {
#if 0
                        printf("%c\n", stack[top]);
#endif
                        postfix[j++] = stack[top--];
                }
                if (stack_pre(stack[top]) == infix_pre(infix[i]))
                        --top;
                else
                        stack[++top] = infix[i];
                ++i;
        }

        while (top > 0)
        {
#if 0
                printf("%c\n", stack[top]);
#endif
                postfix[j++] = stack[top--];
        }
        postfix[j] = '\0';
        return postfix;
}


#if 1
int infix_pre(char symbol)
{
        switch(symbol)
        {
                case '+':
                case '-':
                        return 1;
                case '*':
                case '/':
                        return 3;
                case '^':
                        return 6;
              /*  case '#':
                        return 0;
                        */
                case ')':
                        return 0;
                case '(':
                        return 9;
                default:
                        return 7;
        }
}

int stack_pre(char symbol)
{
        switch(symbol)
        {
                case '+':
                case '-':
                        return 2;
                case '*':
                case '/':
                        return 4;
                case '^':
                        return 5;
                case '#':
                        return -1;
                case '(':
                        return 0;
                default:
                        return 8;
        }
}
#endif
/* 
int main(void)
{
        char ary[MAXLEN];

        printf("Infix expression: ");
        scanf("%[^\n]s", ary);
        
        do 
        { 
                getchar();
                int ch;
                char *a;

                printf("\t1. infix-postfix\n");
                printf("\t2. infix-prefix\n");
                printf("Your choice: ");
                scanf("%d", &ch); getchar();
                switch(ch)
                {
                        case 1:
                                printf("\t\t\t\tPostfix string: %s\n", infix_postfix(ary));
                                break;
                        case 2:
                                for (int i = 0, j = strlen(ary) - 1; i <= j && j >= i; i++, j--)
                                {
                                        char temp = ary[i]; 
                                        ary[i] = ary[j]; 
                                        ary[j] = temp;
                                }
                                printf("\t\t\t\tReversed string: %s\n", ary);
                                for (int i = 0, j = strlen(a = infix_postfix(ary)) - 1; i <= j && j >= i; i++, j--)
                                {
                                        char temp = a[i]; 
                                        a[i] = a[j]; 
                                        a[j] = temp;
                                }
                                printf("\t\t\t\tPrefix string: %s\n", a);
                }
                printf("Do you want to continue? ");
        } while (getchar() == 'y');
}
*/
