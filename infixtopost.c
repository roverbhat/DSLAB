#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 20
struct stack
{
    char arr[size];
    int top;
};
typedef struct stack stk;
int stkpref(char c)
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
int inpref(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    }
}
void push(stk *s, char c)
{
    s->arr[++s->top] = c;
}
char pop(stk *s)
{
    return s->arr[s->top--];
}
void inpost(char in[], char pos[])
{
    stk st;
    st.top = -1;
    int j = 0;
    for (int i = 0; i < strlen(in); i++)
    {
        char c = in[i];
        if (isalnum(c))
        {
            pos[j++] = c;
            continue;
        }
        if (st.top == -1 || inpref(c) > stkpref(st.arr[st.top]))
        {
            push(&st, c);
        }
        else if (stkpref(st.arr[st.top]) > inpref(c))
        {
            if (c == ')')
            {
                while (st.arr[st.top] != '(')
                {
                    char k = pop(&st);
                    pos[j++] = k;
                }
                st.top--;
                continue;
            }
            while (st.top != -1 && inpref(c) < stkpref(st.arr[st.top]))
            {
                char d = pop(&st);
                pos[j++] = d;
            }
            push(&st, c);
        }
    }
    while (st.top != -1)
    {
        char f = pop(&st);
        pos[j++] = f;
    }
    pos[j] = '\0';
}
int main()
{
    char in[20];
    char pos[20];
    printf("enter the infix expression \n");
    scanf("%s", in);
    inpost(in, pos);
    printf("%s", pos);
}