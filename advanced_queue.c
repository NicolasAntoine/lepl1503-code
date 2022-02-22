#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val){
  //noeud à ajouter
  struct node * nouv = (struct node *) malloc(sizeof(struct node));
  if (nouv == NULL){
    return -1;
  }
  nouv->value = val;

  if (q->size == 0){
    q->tail = nouv;
    nouv->next = q->tail;
    q->size++;
    return 0;
  }
  struct node * avance = q->tail->next;
  q->tail->next = nouv;
  nouv->next = avance;
  q->size++;
  return 0;
}


//HINT -> DO NOT FORGET TO FREE ALL THE UNUSED MEMORY

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q){
  struct node * removed = q->tail;
  int rep = q->tail->value;
  if (q->size == 1){
    q->tail = NULL;
    free(removed);
  } else {
    while (q->tail->next != removed){
      q->tail = q->tail->next;
    }
    q->tail->next = q->tail->next->next;
    free(removed); 
  }
  q->size--;
  return rep;
}