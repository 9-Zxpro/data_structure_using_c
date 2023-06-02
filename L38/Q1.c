#include <stdio.h>

struct queue
{
    int data;
    // Lower values indicate higher priority
    int priority;
    struct queue *next;
};
typedef struct queue *PQueue;
PQueue head = NULL;
PQueue newNode(int d, int p)
{
    PQueue temp = (PQueue)nalloc(sizeof(struct queue));
    temp->data - d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}
void enqueue(int data, int priority)
{
    PQueue node = NULL, start = head;
    node = newNode(data, priority);
    if (node == NULL)
    {
        printf("Priority queue is overflow.\n");
    }
    else
    {
        if (head == NULL || priority < start->priority)
        {
            node->next = head;
            head - node;
        }
        else if (start->next == NULL)
        {
            if (start->priority <= priority)
            {
                start->next = node;
            }
            else
            {
                node->next = start;
                head = node;
            }
        }
        else
        {
            while (start->next != NULL && start->next->priority <= priority)
            {
                start - start->next;
            }
            node->next = start->next;
            start->next = node;
        }
    }
}

void dequeue()
{
    if (head == NULL)
    {
        printf("Priority queue is underflow.\n");
    }
    else
    {
        PQueue tmp = head;
        printf("Deleted value = %d\n", head->data);
        head = head->next;
        free(tmp);
    }
}

int isEmpty()
{
    if (head == NULL)
    {
        printf("Priority queue is empty.\n");
    }
    else
    {
        printf("Priority queue is not empty.\n");
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Priority queue is empty.\n");
    }
    else
    {
        PQueue temp = head;
        printf("Elements in the priority queue : ");
        while (temp != NULL)
        {
            printf("%d (%d) ", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("\n");
    }
}

void size()
{
    int count = 0;
    printf("Priority queue size : ");
    if (head == NULL)
    {
        printf("%d\n", count);
    }
    else
    {
        PQueue tmp = head;
        while (tmp != NULL)
        {
            ++count;
            tmp = tmp->next;
        }
    }
    printf("%d\n", count);
}