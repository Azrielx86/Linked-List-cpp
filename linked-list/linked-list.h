#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <vector>

template <class _Tp>
class node {
private:
    _Tp _value;
    node<_Tp>* _next;
    node<_Tp>* _prev;
public:
    node(_Tp);
    _Tp getValue();
    node<_Tp>* getNext();
    node<_Tp>* getPrev();
    void setNext(node<_Tp>* next_node);
    void setPrev(node<_Tp>* prev_node);
};

template <class _Tp>
class linkedlist {
private:
    node<_Tp>* head;
    node<_Tp>* end;
    int size;
public:
    linkedlist<_Tp>();
    _Tp& operator[](int index);
    int getSize();
    int add_node_at_end(_Tp value);
    int add_node_at_head(_Tp value);
    int add_node_at_index(int index, _Tp value);
    void delete_node(int index);
    std::vector<_Tp> to_vector();
    void print_list();
    void print_list_reverse();
};

#endif