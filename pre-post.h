#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include "colors.h"
#include <string.h>

#define INFIX 0
#define PREFIX 1
#define POSTFIX 2

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define FAILURE 1

#define MAXLEN 25

static void infix_postfix_eval(char ch);
static int push(int data);
static int pop(void);
static int mypow(int base, int pow);

int verify_expr(char *buf);
int isPostfix(char *buf);
int isPrefix(char *buf);

int isoperator(char c);
int isoperand(char c);

int infix_postfix(char *buf);
int infix_prefix(char *buf);
char *convert_to_pre_or_post(char *ary, int ch);

extern int reverse_words(char *a);

#endif
