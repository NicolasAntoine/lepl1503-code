#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h> 

struct node {
    struct node *next;
    int hash;

};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head) {
    if (head == NULL){
        return NULL;
    }
    struct node * first = NULL;
    struct node * current;
    int i = 0;
    while(head!=NULL){
        if (i%2 == 0){
            struct node * temp = (struct node *) malloc(sizeof(struct node));
            if (temp == NULL){
                return NULL;
            }
            memcpy(temp, head, sizeof(struct node));
            if (first == NULL){
                first = temp;
                first->next = NULL;
                current = first;
            } else {
                current->next = temp;
                current = current->next;
            }
        }
        head = head->next;
        i++;
    }
    return first;
}



int main(int argc, char const *argv[])
{
    return 0;
}
