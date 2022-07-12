#include "linked-list.h"

const int& Linked_List::operator[](const int index)
{
    static int value;
    if (index > this->size) value = -1;

    Node* pos = this->head;
    for (int i = 0; i <= index; i++)
    {
        if (pos->next->next == NULL) value = -1;
        pos = pos->next;
    }
    value = pos->value;
    return value;
}

Linked_List::~Linked_List()
{
    for (int i = size; i >= 0; i--)
    {
        delete_node_at_index(this, i);
    }
}

Node* create_node(int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void init_list(Linked_list* list)
{
    list->head = NULL;
    list->size = 0;
}

Node* traverse_list_to_end(Linked_List* list)
{
    if (list->size == 0 && list->head == NULL) return NULL;

    Node* pos = list->head;
    while (true)
    {
        if (pos->next != NULL)
            pos = pos->next;
        else
            return pos;
    }
}

Node* traverse_list_to_index(Linked_List* list, int index)
{
    if (list->size == 0 && list->head == NULL) return NULL;

    Node* pos = list->head;
    for (int i = 0; i < index; i++)
    {
        if (pos->next == NULL) return NULL;
        pos = pos->next;
    }

    return pos;
}

Node* traverse_list_to_index(Linked_List* list, int index, bool prev)
{
    if (list->size == 0 && list->head == NULL) return NULL;

    Node* pos = list->head;
    for (int i = 0; i < index - 1; i++)
    {
        if (pos->next->next == NULL) return NULL;
        pos = pos->next;
    }

    return pos;
}

int add_node_at_end(Linked_list* list, int value)
{
    Node* new_node = create_node(value);
    if (new_node == NULL) return 1;

    if (list->size == 0 && list->head == NULL)
    {
        list->head = new_node;
        list->size++;
    }
    else
    {

        Node* end = traverse_list_to_end(list);
        end->next = new_node;
        list->size++;
    }

    return 0;
}

int add_node_at_head(Linked_list* list, int value)
{
    Node* new_node = create_node(value);
    if (new_node == NULL) return 1;

    if (list->size == 0 && list->head == NULL)
    {
        list->head = new_node;
        list->size++;
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
        list->size++;
    }

    return 0;
}

int add_node_at_index(Linked_List* list, int value, int index)
{
    if (index <= 0) return 1;
    if (index > list->size) return 1;
    if (index == 0) { add_node_at_head(list, value); return 0; }
    if (index == list->size) { add_node_at_end(list, value);  return 0; }

    Node* new_node = create_node(value);
    if (new_node == NULL) return 1;

    Node* pos = traverse_list_to_index(list, index, true);
    new_node->next = pos->next;
    pos->next = new_node;

    return 0;
}

void delete_node_at_index(Linked_list* list, int index)
{
    Node* deleted;
    if (index == 0)
    {
        deleted = list->head;
        list->head = list->head->next;
    }
    else if (index == list->size)
    {
        Node* prev = traverse_list_to_index(list, list->size, true);
        deleted = prev->next;
        prev->next = NULL;
    }
    else
    {
        Node* prev = traverse_list_to_index(list, list->size, true);
        deleted = prev->next;
        prev->next = deleted->next;
    }

    list->size--;
    free(deleted);
}

void print_list(Linked_list& list)
{
    for (int i = 0; i < list.size; i++)
        std::cout << "[" << list[i] << "]-";

    std::cout << "\b " << std::endl;
}