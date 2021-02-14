#include "pre-post.h"

int ary[MAXLEN];
int top = -1;

int infix_postfix(char *buf)
{
        char ch;
        int num = 0;
        int i = 0;

#if 0
        /* verify if the expression is a postfix expression */
        printf("%s\n", buf);

        if (verify_expr(buf) != POSTFIX)
        {
                printf("Please, enter a postfix expression.\n");
                return FAILURE;
        }
#endif
        while ((ch = buf[i++]) != '\0')
        {
                /* group the numbers */
                if ((ch >= '0' && ch <= '9') || ch == ' ')
                {
                        if (ch == ' ')
                        {
                                push(num);
                                num = 0;
                        }
                        else
                        {
                                num = num * 10 + (ch - '0');
                                continue;
                        }
                }
                infix_postfix_eval(ch);
        }
        infix_postfix_eval('\n');
}

static void infix_postfix_eval(char ch)
{
        int ch1, ch2;
        switch(ch)
        {
                case '0' ... '9':
                        push(atoi(&ch));
                        break;
                case '+':       /* add */
                        push(pop() + pop());
                        break;
                case '-':       /* subtract */
                        ch1 = pop();
                        push(pop() - ch1);
                        break;
                case '*':       /* multiply */
                        push(pop() * pop());
                        break;
                case '/':       /* divide */
                        ch1 = pop();
                        if (ch1 != 0)
                                push(pop()/ch1);
                        else 
                        {
                                printf("Divide by zero\n");
                                return;
                        }
                        break;
                case '^':       /* find power */
                        ch1 = pop();
                        ch2 = pop();
                        push(mypow(ch2, ch1));
                        break;
                case '\n':      /* print the result obtained till now */
                        printf("\t%d\n", ary[top]);
                        break;
        }
}

/* mypow function */
static int mypow(int base, int pow)
{
        int num = base;
        for (int i = 0; i < pow-1; ++i)
                base = base * num;
#if 0
        printf("%d\n", base);
#endif
        return base;
}

/* push the number into stack */
static int push(int num)
{
        if (num == 0)
                return 0;
        ++top;
        ary[top] = num;
#if 0
        printf("push %d\n", ary[top]);
#endif
}

/* pop out a number from stack */
static int pop(void)
{
        if (top <= -1)
        {
                printf("Stack is empty!\n");
#if 1
                return 0;
#else
                exit(0);
#endif
        }
#if 0
        printf("pop %d\n", ary[top]);
#endif 
        return ary[top--];
}
