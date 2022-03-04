#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#define size 20
struct stack
{
    int val[size];
    int top;
};
typedef struct stack stack;
bool isoperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
        return true;
    default:
        return false;
    }
}
void push(stack *s, int d)
{
    s->val[++s->top] = d;
}
int pop(stack *s)
{
    return s->val[s->top--];
}
int calculation(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
    case '$':
        return pow(a, b);
    }
}
int val(char c[])
{
    stack s;
    s.top = -1;
    int i;
    int firstoperend;
    int secondoperend;
    char operetor;
    int res;
    for (i = 0; i < strlen(c); i++)
    {
        char temp = c[i];
        if (!isoperator(temp))
        {
            int d = temp - '0';
            push(&s, d);
        }
        else
        {
            secondoperend = pop(&s);
            firstoperend = pop(&s);
            operetor = temp;
            int res = calculation(firstoperend, secondoperend, operetor);
            push(&s, res);
        }
    }
    return s.val[s.top];
}
int main()
{
    char c[20];
    printf("Enter the postfix expression \n");
    scanf("%s", c);
    int res;
    res = val(c);
    printf("Anser is %d", res);
}