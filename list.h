#ifndef __SINGLE_LINK_LIST__
#define __SINGLE_LINK_LIST__
#include <inttypes.h>

struct Node {
  uint32_t size;
  char *data;
  struct Node* next;
};

typedef struct Node sll_node_t;

sll_node_t* new_node();
sll_node_t* pop(sll_node_t * head, sll_node_t *node);
sll_node_t* search(sll_node_t* head, sll_node_t* node);

int insert_front(sll_node_t *head, sll_node_t *node);
int insert_back(sll_node_t **head, sll_node_t *node);

int pop_front(sll_node_t *head);
int pop_back(sll_node_t *head);

int print_list(sll_node_t* list);
void clear_list(sll_node_t** head);

#endif
