#include <ctype.h>
#include <stdio.h>
#define STACK_MAX_SIZE 20

int stack[STACK_MAX_SIZE];
top = -1;

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if (top == STACK_MAX_SIZE - 1)
        return;
    else
        stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return;
    else
        return stack[top--];
}

void evaluatePostfix(char *e)
{
    int a, b, val = 0;
    char ex;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            ex = *e;
            val = atoi(&ex);
            push(val);
            *e++;
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '%' || *e == '/')
        {
            b = pop();
            if (top == -1)
            {
                printf("Invalid postfix expression.\n");
                return;
            }
            a = pop();
            switch (*e)
            {
            case '+':
                val = a + b;
                break;
            case '-':
                val = a - b;
                break;
            case '*':
                val = a * b;
                break;
            case '/':
                val = a / b;
                break;
            case '%':
                val = a % b;
                break;
            }
            push(val);
            *e++;
        }
    }
    if (top >= 1)
    {
        printf("Invalid postfix expression.\n");
        return;
    }
    else
        printf("Result : % d\n", pop());
}
int main()
{
    char exp[20];
    char *e, x;
    printf("Enter the postfix expression : ");
    scanf("%s", exp);
    e = exp;
    evaluatePostfix(e);
}