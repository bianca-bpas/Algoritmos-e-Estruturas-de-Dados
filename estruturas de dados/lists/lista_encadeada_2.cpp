#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NODE{
    int value;
    struct NODE *next;
}NODE;

typedef struct LINKED_LIST{
    NODE *head;
    NODE *current;
    int list_size;
}LINKED_LIST;

void initLinkedList(LINKED_LIST *ll) {
  ll->head = NULL;
  ll->current = ll->head;
  ll->list_size = 0;
}

void insert(int value, LINKED_LIST *ll){
    NODE *ptr = (NODE*) malloc(sizeof(NODE));
    if (ptr == NULL){
        cout << "Erro de alocação de nó" << endl;
        return;
    } else {
        ptr->value = value;
        ptr->next = NULL;
        ll->current = ptr;
        ll->head->next = ll->current;
        ll->list_size++;
    }
}

void print(LINKED_LIST *ll){
    NODE *ptr = ll->current;
    if (ptr == NULL){
        cout << "Lista vazia!" << endl;
        return;
    } else {
        while(ptr != NULL){
            cout << ptr->value << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main(){
    LINKED_LIST lista1;
    initLinkedList(&lista1);
    insert(10, &lista1);
    print(&lista1);

    return 0;
}