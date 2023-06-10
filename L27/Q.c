#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STACK_MAX_SIZE 20

char stack[STACK_MAX_SIZE];

int top = -1;

// Return 1 if stack is empty else return 0.
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Push the character into stack
void push(char x)
{
    if (top == STACK_MAX_SIZE - 1)
    {
        printf("Stack is in overflow");
        return;
    }
    else
    {
        stack[++top] = x;
    }
}

// pop a character from stack
char pop()
{
    char sign;
    if (top == -1)
        printf("stack is in underflow");
    else
        sign = stack[top--];
    return sign;
}

// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is "*' or '/' or '%'
int priority(char x)
{
    if (x == '*' || x == '/' || x == '%')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '(')
        return 0;
}

// 0utput Format
// if expression is correct then output will be Postfix Expression : <postfix notation»
// If expression contains invalid operators then output will be "Invalid symbols in infix expression. Only alphanumberic and { ‘+, '-','*', 'X%', '/' } are allowed."
// If the expression contains unbalanced paranthesis the output will be “Invalid infix expression : unbalanced parenthesis."
void convertInfix(char *e)
{
    char tmp, rpn[STACK_MAX_SIZE];
    int count = -1;
    while (*e != '\0')
    {
        if (*e == '(')
        {
            push(*e);
            e++;
        }
        else if (*e == ')')
        {
            while ((top != -1) && (stack[top] != '('))
            {
                rpn[++count] = pop();
            }
            if (top == -1)
            {
                printf("Invalid infix expression : unbalanced parenthesis.\n");
                return;
            }
            tmp = pop();
            *e++;
        }
        else if (isalpha(*e))
        {
            rpn[++count] = *e;
            *e++;
        }
        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/' || *e == '%')
        {
            while ((top != -1) && (stack[top] != '(') && (priority(stack[top]) > priority(*e)))
            {
                rpn[++count] = pop();
            }
            push(*e);
            *e++;
        }
        else if (!isalpha(*e))
        {
            printf("Invalid symbols in infix expression. Only alphanumeric and { '+', '-','*', '%c', '/' } are allowed.\n", '%');
            return;
        }
    }
    while (top != -1 && stack[top] != '(')
    {
        rpn[++count] = pop();
        if (stack[top] == '(')
        {
            printf("Invalid infix expression : unbalanced parenthesis.\n");
            return;
        }
    }
    printf("Postfix expression : ");
    for (int i = 0; i <= count; i++)
    {
        printf("%c", rpn[i]);
    }
    printf("\n");
}