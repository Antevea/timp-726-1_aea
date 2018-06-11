#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;

node *find_my_number(int num)
{
    node *tmp = head;
    for (int i = 1; i < num; i++)
    {
        tmp = tmp-> next;
        if (tmp == NULL)
            break;
    }

    return tmp;
}

node *find_me(int val)
{
    node *tmp = head;
    while (tmp -> value != val && tmp != NULL)
    {
        if (tmp == NULL)
        {
            return NULL;
        }
        tmp = tmp->next;
    }
    if (tmp == NULL) return -1;
    return tmp;
}

int init(node *insert_value)
{
    node *tmp = malloc(sizeof(node));
    tmp -> value = insert_value;
    tmp -> next = NULL;
    tmp -> prev = NULL;
    head = tmp;
    tail = tmp;
    return (tmp);
}

void prepend(node *tmp, int value)
{
    if (tmp==NULL||tmp==head)
    {
        node *temp = malloc(sizeof(node));
        temp->value=value;
        temp->prev=NULL;
        temp->next=head;
        head=temp;
        temp->next->prev=temp;
    }
    else
    {
        node *temp = malloc(sizeof(node));
        temp->value=value;
        temp->prev=tmp->prev;
        temp->next=tmp;
        tmp->prev=temp;
        temp->prev->next=temp;
    }
}

int append(node *tmp, int value)
{
    if (tmp==NULL||tmp==tail)
    {
        node *temp = malloc(sizeof(node));
        temp->value=value;
        temp->next=NULL;
        temp->prev=tail;
        temp->prev->next=temp;
        tail=temp;
        return temp;
    }
    else
    {
        node *temp = malloc(sizeof(node));
        temp->value=value;
        temp->next=tmp->next;
        temp->prev=tmp;
        tmp->next->prev=temp;
        tmp->next=temp;
        return temp;
    }
}

int isEmpty()
{
    if ((head == NULL) && (tail == NULL))
        return 1;
    else
        return 0;
}

void print (node *head)
{
    while (head)
    {
        printf ("%d ", head -> value);
        head = head -> next;
    }
    printf ("\n");
}

int push (int insert)
{
    if (isEmpty()==1)
        init (insert);
    else
    {
        node *tmp = malloc(sizeof(node));
        tmp->value=insert;
        tmp->prev=tail;
        tmp->next=NULL;
        tail=tmp;
        tmp->prev->next=tmp;
        return tmp;
    }
}

int destroy()
{
    if(isEmpty())
    {
        node *tmp = head;
        node *temp = NULL;
        do
        {
            temp = tmp->next;
            tmp->value = NULL;
            free(tmp);
            tmp = temp;
        } while (temp != NULL);
        head = NULL;
        tail = NULL;
    }
}

int dont_delete_me(node *tmp)
{
    if (tmp == head && tmp == tail && tmp != NULL)
    {
        destroy();
    }

    if (tmp != head && tmp != tail && tmp != NULL)
    {
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        free(tmp);
    }

    if (tmp == head && tmp != NULL)
    {
        head = tmp->next;
        tmp->next->prev = NULL;
        free(tmp);
    }

    if (tmp == tail && tmp != NULL)
    {
        tail = tmp->prev;
        tmp->prev->next = NULL;
        free(tmp);
    }
    return tmp;
}

int main()
{
    int n = 0;
    int insert_me = 0;
    int k = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%i", &insert_me);
        push(insert_me);
    }
    print(head);
    scanf("%i", &k);
    dont_delete_me(find_my_number(k));
    print(head);
    scanf("%i", &k);
    dont_delete_me(find_me(k));
    print(head);
    scanf("%i%*c%i", &k, &insert_me);
    append(find_my_number(k), insert_me);
    print(head);
    //dont_delete_me(find_me(k));
    scanf("%i%*c%i", &k, &insert_me);
    prepend(find_my_number(k), insert_me);
    print(head);
    return 0;
}
