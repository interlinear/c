#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

#define M_SIZE 12

static char* months[M_SIZE] = {"January", "February", "March", "April",
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
        sll_node_t* node = new_node(months[i], strlen(months[i]));
        insert_back(&list, node);
    }
    clear_list(&list);
    if(list != NULL){
        printf("Expected empty list, actual list is not empty\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static int test_search(){
    sll_node_t* list = NULL;
    int i;

    for(i = 0; i < M_SIZE/2; i++){
        sll_node_t* node = new_node(months[i], strlen(months[i]));
        insert_back(&list, node);
    }
    printf("Looking for %s in\n", months[M_SIZE-1]);
    print_list(list);
    sll_node_t* found = search_data(list, months[M_SIZE-1],
            strlen(months[M_SIZE-1]));
    int rc_negative = found == NULL;

    printf("Looking for %s in\n", months[3]);
    print_list(list);
    found = search_data(list, months[3], strlen(months[3]));
    int rc_positive = found != NULL;

    clear_list(&list);
    if(list != NULL){
        printf("Expected empty list, actual list is not empty\n");
        return EXIT_FAILURE;
    }
    if(!rc_negative || !rc_positive){
        printf("search failed\n");
    }
    return EXIT_SUCCESS;
}

int main(int argc, char **argv){
    printf("Hello Single Link List\n");
    test_insert_back();
    test_search();
    return EXIT_SUCCESS;
}
