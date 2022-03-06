#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 30
struct op
{
    char opstack[size];
    int top;
};
typedef struct op op;
int stkpref(char c)
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
    case ')':
        return 0;
    }
}
int inpref(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case ')':
        return 9;
    case '(':
        return 0;
    }
}
void push(char c, op *s)
{
    s->opstack[++s->top] = c;
}
char pop(op *s)
{
    char d = s->opstack[s->top--];
    return d;
}
void convertion(char in[], char pre[])
{
    op s;
    s.top = -1;
    int length = strlen(in) - 1;
    int j = 0;
    for (int i = length; i >= 0; i--)
    {
        char c = in[i];
        if (isalnum(i))
        {
            pre[j++] = c;
            continue;
        }
        if (s.top == -1 || inpref(c) > stkpref(s.opstack[s.top]))
        {
            push(c, &s);
            continue;
        }
        if (inpref(c) < stkpref(s.opstack[s.top]))
        {
            if (c == '(')
            {
                while (s.opstack[s.top] != ')')
                {
                    char e = pop(&s);
                    pre[j++] = e;
                }
                s.top--;
                continue;
            }
            while (s.top != -1 && inpref(c) < stkpref(s.opstack[s.top]))
            {
                char d = pop(&s);
                pre[j++] = d;
            }
            push(c, &s);
        }
    }
    while (s.top != -1)
    {
        char f = pop(&s);
        pre[j++] = f;
    }
    pre[j] = '\0';
    int pl = strlen(pre);
    for (int i = pl; i >= 0; i--)
    {
        printf("%c ", pre[i]);
    }
}
int main()
{
    char in[30], pre[20];
    printf("ENter the infix expreseion \n");
    scanf("%s", in);
    convertion(in, pre);
}