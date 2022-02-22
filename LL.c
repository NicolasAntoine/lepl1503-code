#include <stdio.h>
#include <stdlib.h>

/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node {
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list {
  struct node *first;
  int size;
} list_t;


/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value) {
    node_t *ptr = (node_t*) malloc(sizeof(node_t));
    if (ptr == NULL){
        return NULL;
    }
    ptr->next = NULL;
    ptr->value = value;
    return ptr;
}

/*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value) {
    node_t* ptr = init_node(value);
    if (ptr == NULL || list == NULL){
        return 1;
    }
    ptr->next = list->first;
    list->first = ptr;
    list->size++;
    return 0;
}

int main(int argc, char const *argv[])
{
    //node_t *head = (node_t*) malloc(sizeof(node_t));
    //head->value = 1;
    //head->next = NULL;
    list_t *liste = {NULL, 0};
    add_node(liste, 1);
    //printf("%d\n", head->value);
    add_node(liste, 2);
    //printf("%d\n", head->value);
    add_node(liste, 3);
    //printf("%d\n", head->value);
    add_node(liste, 4);
    //printf("%d\n", head->value);
    add_node(liste, 5);
    //printf("%d\n", head->value);
    int a = 0;
    node_t* current = liste->first;
    while (a<liste->size){
        printf("%d\n", current->value);
        current = current->next;
        a++;
    }
    return 0;
}
