#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
     List* List =  malloc (sizeof(List));
     List->head = NULL;
     List->tail = NULL;
     List->current = NULL;
     return List;

}

void * firstList(List * list) {
    if (!list->head) return NULL;
    int *dato = (int*) list->head->data;
    list->current = list->head;
    return dato;

}

void * nextList(List * list) {
  if (list->current == NULL) return NULL;
    if (list->current->next != NULL ){
      
      list->current = list->current->next;
      int *dato = (int*) list->current->data;
      return dato;
    }
    return NULL;
    
}

void * lastList(List * list) {
    if (!list->tail) return NULL;
    int *dato = (int*) list->tail->data;
    list->current = list->tail;
    return dato;
}

void * prevList(List * list) {
  if (list->current == NULL) return NULL;
    if (list->current->prev != NULL ){
      
      list->current = list->current->prev;
      int *dato = (int*) list->current->data;
      return dato;
    }
    return NULL;
}

void pushFront(List * list, const void * data) {
    Node * aux = createNode(data);
    aux->next = list->head;
    if(list->head != NULL)
      list->head->prev = aux;
    list->head = aux;
    aux->prev=NULL;

    
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
    Node * nuebo = createNode(data);

    if (list->current->next == NULL){
      list->tail->next = nuebo;
      nuebo->prev = list->tail;
      list->tail = nuebo;
    }
    nuebo->next = list->current->next;
    list->current->next->prev = nuebo;
    list->current->next = nuebo;
    nuebo->prev = list->current;


}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    int *dato = (int*) list->current->data;
    if (list->current->prev == NULL){
      free(list->current);
      return dato;
    }
    if (list->current->next == NULL){
      free(list->current);
      return NULL;
    }

    
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}