#include <stdio.h>
#include <stdlib.h>
struct DLLNode
{
    struct DLLNode *prev;
    int data;
    struct DLLNode *next;
};
struct myStack
{
    struct DLLNode *head;
    struct DLLNode *mid;
    int count;
};
struct myStack *createMyStack()
{
    struct myStack *ms =
        (struct myStack *)malloc(sizeof(struct myStack));
    ms->count = 0;
    return ms;
};
void push(struct myStack *ms, int new_data)
{
    struct DLLNode *new_DLLNode =
        (struct DLLNode *)malloc(sizeof(struct DLLNode));
    new_DLLNode->data = new_data;
    new_DLLNode->prev = NULL;
    new_DLLNode->next = ms->head;
    ms->count += 1;
    if (ms->count == 1)
    {
        ms->mid = new_DLLNode;
    }
    else
    {
        ms->head->prev = new_DLLNode;
        if (ms->count & 1)
            ms->mid = ms->mid->prev;
    }
    ms->head = new_DLLNode;
}
int pop(struct myStack *ms)
{
    if (ms->count == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct DLLNode *head = ms->head;
    int item = head->data;
    ms->head = head->next;
    if (ms->head != NULL)
        ms->head->prev = NULL;
    ms->count -= 1;
    if (!((ms->count) & 1))
        ms->mid = ms->mid->next;
    free(head);
    return item;
}
int findMiddle(struct myStack *ms)
{
    if (ms->count == 0)
    {
        printf("Stack is empty now\n");
        return -1;
    }
    return ms->mid->data;
}
int main()
{
    struct myStack *ms = createMyStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
    printf("Item popped is %d\n", pop(ms));
    printf("Item popped is %d\n", pop(ms));
    printf("Middle Element is %d\n", findMiddle(ms));
    return 0;
}
