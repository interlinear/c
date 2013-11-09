#include <stdlib.h>
#include <stdio.h>
#include "list.h"

sll_node_t* new_node(){
    sll_node_t* node =  malloc(sizeof(sll_node_t));
    node->data = NULL;
    node->size = 0;
    node->next = NULL;
    printf("Created node %p\n", node);
    return node;
}

sll_node_t* search(sll_node_t* head, sll_node_t* node){
    return NULL;
}

sll_node_t* pop(sll_node_t * head, sll_node_t *node){
    return NULL;
}

int insert_front(sll_node_t *head, sll_node_t *node){
    return -1;
}

int insert_back(sll_node_t** head, sll_node_t* node){
    if(*head == NULL){
        *head = node;
        return 0;
    }
    sll_node_t* cursor = *head;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = node;
    return 0;
}

int pop_front(sll_node_t *head){
    return -1;
}

int pop_back(sll_node_t *head){
    return -1;
}

int print_list(sll_node_t* list){

}

void clear_list(sll_node_t** head){
    sll_node_t* cursor = *head;
    while(cursor != NULL){
        printf("Traversing list.\n");
        free(cursor->data);
        cursor->data = NULL;
        sll_node_t* aux = cursor;
        cursor = cursor->next;
        free(aux);
        aux = NULL;
    }
    *head = NULL;
}
