#include <iostream>

using namespace std;

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    int val;
}Node;

typedef struct DEQ{
    Node *head;
    Node *tail;
}DEQ;

void HeadPushFront(DEQ *q , int x){
    Node *cur = (Node*) malloc(sizeof (Node));
    if(!q -> head)
    {
        q -> head = cur;
        q -> tail = cur;
    }
    else{
        q -> head ->prev = cur;
        cur -> next = q -> head;
        q -> head = cur;
    }
    cur -> prev = 0;
    cur -> val = x;
}

void TailPushBack(DEQ *q ,int x)
{
    Node *cur = (Node*) malloc(sizeof (Node));

    cur -> val = x;
    cur -> next = 0;
    cur -> prev = q -> tail;
    if(!q -> tail)
    {
        q -> head = cur;
        q -> tail = cur;
    }
    else
    {
        q -> tail -> next  = cur;
        q -> tail = cur;
    }

}

int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}
