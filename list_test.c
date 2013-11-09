#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define M_SIZE 12

char* months[M_SIZE] = {"January", "February", "March", "April",
                "May", "June", "July", "August", "September",
                "October", "November", "December"
                };

static void print_months(){
    int i;
    for(i = 0; i < M_SIZE; i++){
        printf("%s\n", months[i]);
    }
}

static int test_insert_back(){
    sll_node_t* list = NULL;
    int i;

    for(i = 0; i < M_SIZE; i++){
        sll_node_t* node = new_node();
        if(node == NULL){
            printf("Could not create a new node\n");
            return EXIT_FAILURE;
        }
        node->data = strdup(months[i]);
        node->size = strlen(months[i]);
        insert_back(&list, node);
    }
    clear_list(&list);
    if(list != NULL){
        printf("Expected empty list, actual list is not empty\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv){
    printf("Hello Single Link List\n");
    test_insert_back();
    return EXIT_SUCCESS;
}
