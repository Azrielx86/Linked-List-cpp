#ifndef LINKED_LIST_SRC
#define LINKED_LIST_SRC

#include <iostream>
#include <cstdlib>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct Linked_List
{
    Node* head;
    int size;

    const int& operator[](const int index);

    ~Linked_List();
} Linked_list;

Node* create_node(int value);
void init_list(Linked_list* list);
Node* traverse_list_to_end(Linked_List* list);
Node* traverse_list_to_index(Linked_List* list, int index);
Node* traverse_list_to_index(Linked_List* list, int index, bool prev);
int add_node_at_end(Linked_list* list, int value);
int add_node_at_head(Linked_list* list, int value);
int add_node_at_index(Linked_List* list, int value, int index);
void delete_node_at_index(Linked_list* list, int index);
void print_list(Linked_list& list);

// Example in main
// Linked_list list;

    // init_list(&list);

    // std::vector<int> vct;

    // // add_node_at_end(&list, 15);
    // // add_node_at_end(&list, 56);

    // for (int i = 0; i < 15; i++)
    // {
    //     add_node_at_end(&list, i);
    // }

    // // delete_node_at_index(&list, 5);

    // add_node_at_head(&list, 15);
    // add_node_at_index(&list, 66, 4);

    // delete_node_at_index(&list, 0);
    // delete_node_at_index(&list, list.size);
    // add_node_at_end(&list, 69);


    // print_list(list);

    // // std::cout << list[4] << std::endl;
    // // std::cout << traverse_list_to_index(&list, 4)->value << std::endl;

    // // for (int i = 0; i < list.size; i++)
    // // {
    // //     std::cout << list[i] << std::endl;
    // // }

#endif