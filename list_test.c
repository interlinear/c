#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define M_SIZE 12

char* months[M_SIZE] = {"January", "February", "March", "April",
                "May", "June", "July", "August", "September",
                "October", "November", "December"
                };
static void print_months();

int main(int argc, char **argv){
    printf("Hello Single Link List\n");
    sll_node_t* list = NULL;
    int i;

    print_months();

    for(i = 0; i < M_SIZE; i++){
        sll_node_t* node = new_node();
        if(node == NULL){
            printf("Could not create a new node\n");
            exit(EXIT_FAILURE);
        }
        node->data = strdup(months[i]);
        node->size = strlen(months[i]);
        insert_back(&list, node);
    }
    clear_list(&list);
    if(list == NULL){
        printf("List is empty\n");
    }
    return EXIT_SUCCESS;
}

static void print_months(){
    int i;
    for(i = 0; i < M_SIZE; i++){
        printf("%s\n", months[i]);
    }
}
