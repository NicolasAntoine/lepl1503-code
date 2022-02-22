#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node{
    char val;
    struct node *next;
} node_t;

/*
* @return: 0 if equals, negative number if @b is greater,
* and positive number otherwise
*/
int compare(char a, char b) {
    return a-b;
}

/*
* @value: value to be inserted. If the value is already in the list, no element is added and the list is not modified
* @fun: comparison function which defines the order relationship of the list
* @head: first node of the list, head != NULL
* @return: 0 if success, -1 otherwise
*/
int insert(node_t **head, char val, int (*cmp)(char,char)) {

    if (*head == NULL){
        node_t * reponse = (node_t *) malloc(sizeof(node_t));
        if (reponse == NULL){
            return -1;
        }
        reponse->next=NULL;
        reponse->val = val;
        *head = reponse;

    } else {

        struct node * cell = *head;
        struct node * last = *head;

        while (last->next != NULL){
            last = last->next;
        }
        int i = 0;
        struct node * verif = *head;
        while (verif != NULL){
            if (cmp(verif->val, val) == 0){
                i = 1;
            }
            verif = verif->next;
        }
        if (i == 1){
            return 0;
        }
        while (cmp(cell->val,val) < 0 && cell->next != NULL) {
            cell = cell->next;
        }
        node_t * reponse = (node_t *) malloc(sizeof(node_t));
        if (reponse == NULL){
                return -1;
        }
        reponse->val = val;

        if (cmp(last->val, val) < 0){  //insertion en fin de liste
            last->next = reponse;
            reponse->next = NULL;
        }

        //printf("%c\n", cell->val);
        //printf("%c\n", val);

        if (cmp(cell->val,val) > 0){
            if (cell != *head){    //insertion au milieu
                struct node * prev = *head;
                //printf("prev = %c\n", prev->val);
                //printf("cell = %c\n", cell->val);
                while (prev != cell && prev->next != cell){
                    prev = prev->next;
                    //printf("prev = %c et cell = %c\n", prev->val, cell->val);
                }        
                prev->next = reponse;
                reponse->next = cell;
            } else {                    //insertion en début de liste
                reponse->next = *head;
                *head = reponse;
                return 0;
            } 
        }
    }
    return 0;
}


int main(int argc, char const *argv[])
{
    node_t ** first = (node_t *) malloc(sizeof(node_t));
    insert(first, 'a', compare);
    insert(first, 'b', compare);
    insert(first, 'c', compare);
    insert(first, 'e', compare);
    insert(first, 'd', compare);

    node_t * test = *first;
    while (test != NULL){
        printf("%c\n", test->val);
        test = test->next;
    }
    return 0;
}

