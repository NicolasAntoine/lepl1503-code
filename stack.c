#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
    if (*head == NULL){
        return 1;
    }
    struct node * aide = *head;
    result = aide->name;
    *head = aide->next;
    free(aide);
    return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
    if (head == NULL){
        return 1;
    }
    struct node * nouv = (struct node *) malloc(sizeof(struct node));
    if (nouv == NULL){
        return 1;
    }
    char * var = (char *) malloc(strlen(value)+1);
    strncpy(var, value, strlen(value)+1);
    nouv->name = var;
    nouv->next = *head;
    *head = nouv;
    return 0;    
}