#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int value;
    struct queue *next;
}queue;

queue *head = NULL;
queue *tail = NULL;

int isEmpty()//....пустота......
{
    if (head == NULL && tail == NULL)
        return 1;
    else
        return 0;
}

void init(int insert)//инициализация
{
    queue *tmp = malloc(sizeof(queue));
    tmp -> value = insert;
    tmp -> next = NULL;
    head = tmp;
    tail = tmp;
}

void push_me(int insert) //satisfaction
{
    if (isEmpty() == 1)
        init(insert);
    else {
        queue *tmp = malloc(sizeof(queue));
        tmp -> value = insert;
        tmp -> next = NULL;
        tail -> next = tmp;
        tail = tmp;
    }
}

void pop()//удалить последнего
{
    queue *tmp = head;
    if (isEmpty() == 1)
        printf("queue is empty!");
    else
    {
        if (head == tail) destroy();
        else
        {
            head = tmp -> next;
            free(tmp);
        }
    }
}

void print_queue()//напечатать очередь
{
    queue *tmp = head;
    if (isEmpty() == 0)
    {
        while (tmp != NULL) {
            printf("%i ", tmp -> value);
            tmp = tmp -> next;
        }
        printf("\n");
    }
    else printf("Очередь пуста!\n");
}

int destroy()//уничтожить очередь
{
    if(isEmpty())
    {
        queue *tmp = head;
        queue *temp = NULL;
        do
        {
            temp = tmp -> next;
            tmp -> value = NULL;
            free(tmp);
            tmp = temp;
        } while (temp != NULL);
        head = NULL;
        tail = NULL;
    }
}

int main()
{
    int n = 0;
    int insert_me = 0;
    int k = 0;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%i", &insert_me);
        push_me(insert_me);
    }
    print_queue();
    pop();
    print_queue();
    destroy();
    return 0;
}
