//https://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

Node *split(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast->next!=NULL && fast->next->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node *merge(Node *first, Node *second)
{
    if (first==NULL)
        return second;

    if (second==NULL)
        return first;

    if (first->data < second->data)
    {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}