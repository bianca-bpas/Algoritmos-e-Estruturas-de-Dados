#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct Link{
    int element;
    struct Link *next;
}Link;

typedef struct Queue{
    Link *front;
    Link *rear;
    int size;
}Queue;

Link* create_link(int it, Link *nextval);
Link* create_link(Link *nextval);
Queue* create_queue();
void enqueue(Queue *q, int it);
int dequeue(Queue *q);
void imprime(Queue *q);

int main(){
    Queue *fila = create_queue();
    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);
    imprime(fila);

    return 0;
}

Link* create_link(int it, Link *nextval){
    Link *n = new Link;
    n->element = it;
    n->next = nextval;
    return n;
}

Link* create_link(Link *nextval){
    Link *n = new Link;
    n->next = nextval;
    return n;
}

Queue* create_queue(){
    Queue *q = new Queue;
    q->front = q->rear = create_link(NULL);
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int it) {
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue *q) {
  if (q->size == 0) {
    return -1;
  } else {
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if (q->front->next == NULL) { // Check for last element
      q->rear = q->front; // Update rear to point to the only element (front)
    }
    q->size--;
    return it;
  }
}


void imprime(Queue *q) {
  Link *atual = q->front;
  while (atual->next != NULL) {
    cout << "Valor do item: " << atual->element << endl;
    atual = atual->next;
  }
}
