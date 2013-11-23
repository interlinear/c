#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

sll_node_t* new_node(char* data, size_t size){
    sll_node_t* node =  malloc(sizeof(sll_node_t));
    node->data = strdup(data);
    node->size = size;
    node->next = NULL;
    return node;
}

sll_node_t* search(sll_node_t* head, sll_node_t* node){
    sll_node_t* cursor = head;
    int rc;
    while(cursor != NULL){
        if(cursor->size == node->size){
            rc = memcmp(cursor->data, node->data, node->size);
            if(0 == rc){
                printf("Found\n");
                return cursor;
            }
        }
        cursor = cursor->next;
    }
    printf("Not found\n");
    return NULL;
}

sll_node_t* search_data(sll_node_t* head, char* data, size_t size){
    sll_node_t* node = new_node(data, size);
    sll_node_t* found = search(head, node);
    clear_node(&node);
    return found;
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
    sll_node_t* cursor = list;
    while(cursor != NULL){
        printf("%s\n", cursor->data);
        cursor = cursor->next;
    }
}

void clear_node(sll_node_t** node){
    sll_node_t* aux = *node;
    *node = (*node)->next;
    free(aux->data);
    aux->data = NULL;
    free(aux);
}

void clear_list(sll_node_t** head){
    sll_node_t* cursor = *head;
    while(cursor != NULL){
        clear_node(&cursor);
    }
    *head = NULL;
}
