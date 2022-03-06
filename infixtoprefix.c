//this program consits alot of bugs refer the another program 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 20
struct operator
{
    char op[20];
    int top;
};
typedef struct operator op;
struct exp
{
    char pre[size][size];
    int top;
};
typedef struct exp exp;
int inputprecedece(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    }
}
int stackprecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    }
}
void pushexp(char c[], exp *s)
{
    s->top++;
    strcpy(s->pre[s->top], c);
}
void pushop(char c, op *s)
{
    s->op[++s->top] = c;
}
char popop(op *s)
{
    char c = s->op[s->top--];
    return c;
}
void popexp(exp *s, char c[])
{
    strcpy(c, s->pre[s->top--]);
}
void infixtoprefix(char infix[], char prefix[])
{
    // printf("recieved %s\n",infix);
    int length = strlen(infix) - 1;
    op opstack;
    opstack.top = -1;
    exp expstack;
    expstack.top = -1;
    for (int i = 0; i <= length; i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            char temp[2];
            temp[0] = c;
            temp[1] = '\0';
            pushexp(temp, &expstack);
            continue;
        }
        if (opstack.top == -1 || inputprecedece(c) > stackprecedence(opstack.op[opstack.top]))
        {
            pushop(c, &opstack);
            continue;
        }
        else if (stackprecedence(c) > inputprecedece(c))
        {
            while (opstack.top != -1 && inputprecedece(c) < stackprecedence(opstack.op[opstack.top]))
            {
                char operator= popop(&opstack);
                char exp[10];
                char op1[10];
                char op2[10];
                popexp(&expstack, op2);
                popexp(&expstack, op1);
                exp[0]=operator;
                strcat(exp,op1);
                strcat(exp,op2);
                pushexp(exp,&expstack);
            }
            pushop(c,&opstack);
        }
    }
    while (opstack.top != -1)
    {
         char operator= popop(&opstack);
                char exp[10];
                char op1[10];
                char op2[10];
                popexp(&expstack, op2);
                popexp(&expstack, op1);
                exp[0]=operator;
                strcat(exp,op1);
                strcat(exp,op2);
                pushexp(exp, &expstack);
    }
    strcpy(prefix,expstack.pre[expstack.top--]);
    printf("%s",prefix);
}
int main()
{
    char infix[20];
    char prefix[20];
    printf("Enter the prefix expression\n");
    scanf("%s", infix);
    infixtoprefix(infix, prefix);
}