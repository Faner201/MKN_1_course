#include <iostream>

using namespace std;

typedef struct Node{
    int val;
   struct Node* next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
}Queue;

void PushBack(Queue* q , int x )
{
    Node *cur = (Node*) malloc(sizeof (Node));
    cur -> val = x;
    cur -> next = NULL;

    if(!q -> head)
        q -> head = cur;
    else
        q -> tail -> next = cur;
    q -> tail = cur;
}

int PopBack(Queue *q)
{
    if(!q -> head)
        return  0;
    Node *cur = q -> head;
    q -> head = q -> head -> next;
    if(!q -> head)
        q -> tail = NULL;
    int index = cur -> val;
    free(cur);
    return index;

}

int QFront(Queue q){
    if(!q.head) return 0;
    return q.head -> val;
}

void print(Queue q)
{
    Node *cur = q.head;
    for(cur = q.head ; cur; cur = cur -> next)
    {
        printf("%d" , cur -> val);
    }
}

int size(Queue q)
{
    int count = 0;
    for(Node *cur = q.head; cur; cur = cur -> next)
        count++;
    return count;
}


int main() {



    return 0;
}
