#include "linked-list.h"

template <class _Tp>
node<_Tp>::node(_Tp _value) : _value(_value)
{
    _next = NULL;
    _prev = NULL;
}

template <class _Tp>
_Tp node<_Tp>::getValue()
{
    return _value;
}

template <class _Tp>
node<_Tp>* node<_Tp>::getNext()
{
    return _next;
}

template <class _Tp>
node<_Tp>* node<_Tp>::getPrev()
{
    return _prev;
}

template <class _Tp>
void node<_Tp>::setNext(node<_Tp>* next_ptr)
{
    _next = next_ptr;
}

template <class _Tp>
void node<_Tp>::setPrev(node<_Tp>* prev_ptr)
{
    _prev = prev_ptr;
}

template <class _Tp>
linkedlist<_Tp>::linkedlist()
{
    this->size = 0;
    this->head = NULL;
    this->end = NULL;
}

template <class _Tp>
linkedlist<_Tp>::~linkedlist()
{
    this->clear();
    this->head = NULL;
    this->end = NULL;
}

template <class _Tp>
_Tp& linkedlist<_Tp>::operator[](int index)
{
    node<_Tp>* pos = this->head;
    for (int i = 0; i < index; i++)
    {
        pos = pos->getNext();
    }

    static _Tp value = pos->getValue();

    return value;
}

template <class _Tp>
int linkedlist<_Tp>::getSize()
{
    return this->size;
}

template <class _Tp>
int linkedlist<_Tp>::add_node_at_end(_Tp value)
{
    node<_Tp>* new_node = new node<_Tp>(value);

    if (this->size == 0 && this->head == NULL)
    {
        this->head = new_node;
        this->end = new_node;
        this->size++;
    }
    else
    {
        node<_Tp>* end = this->end;
        end->setNext(new_node);
        new_node->setPrev(end);
        this->end = new_node;
        this->size++;
    }

    return 0;
}

template <class _Tp>
int linkedlist<_Tp>::add_node_at_head(_Tp value)
{
    node<_Tp>* new_node = new node<_Tp>(value);

    if (this->size == 0 && this->head == NULL)
    {
        this->head = new_node;
        this->end = new_node;
    }
    else
    {
        node<_Tp>* head = this->head;
        head->setPrev(new_node);
        new_node->setNext(head);
        this->head = new_node;
    }
    this->size++;
    return 0;
}

template <class _Tp>
int linkedlist<_Tp>::add_node_at_index(int index, _Tp value)
{
    if (this->size < index) return -1;

    node<_Tp>* new_node = new node<_Tp>(value);
    node<_Tp>* pos = this->head;

    for (int i = 0; i < index - 1; i++)
        pos = pos->getNext();

    new_node->setNext(pos->getNext());
    pos->getNext()->setPrev(new_node);
    pos->setNext(new_node);
    new_node->setPrev(pos);
    this->size++;

    return 0;
}

template <class _Tp>
void linkedlist<_Tp>::delete_node(int index)
{
    node<_Tp>* node_to_delete;
    if (this->size < 0) return;
    if (index > this->size) return;
    if (index == 0)
    {
        node_to_delete = this->head;
        this->head = this->head->getNext();
    }
    else if (index == this->size - 1)
    {
        node_to_delete = this->end;
        this->end = node_to_delete->getPrev();
        this->end->setNext(NULL);
    }
    else
    {
        node<_Tp>* pos = this->head;
        for (int i = 0; i < index - 1; i++)
            pos = pos->getNext();

        node_to_delete = pos->getNext();
        pos->setNext(node_to_delete->getNext());
        node_to_delete->getNext()->setPrev(pos);
    }

    this->size--;
    delete node_to_delete;
}

template <class _Tp>
std::vector<_Tp> linkedlist<_Tp>::to_vector()
{
    std::vector<_Tp> list;

    node<_Tp>* pos = this->head;
    for (int i = 0; i < this->size; i++)
    {
        list.push_back(pos->getValue());
        pos = pos->getNext();
    }

    return list;
}

template <class _Tp>
void linkedlist<_Tp>::clear()
{
    while (this->size > 0)
        delete_node(this->size - 1);

    this->head = NULL;
    this->end = NULL;
}

template <class _Tp>
void linkedlist<_Tp>::print_list()
{
    if (this->size <= 0) return;
    node<_Tp>* pos = this->head;
    for (int i = 0; i < this->size; i++)
    {
        std::cout << "[" << pos->getValue() << "] ";
        // std::cout << "[" << this[i] << "] ";
        pos = pos->getNext();
    }
    std::cout << std::endl;
}

template <class _Tp>
void linkedlist<_Tp>::print_list_reverse()
{
    if (this->size <= 0) return;
    node<_Tp>* pos = this->end;
    for (int i = this->size; i > 0; i--)
    {
        std::cout << "[" << pos->getValue() << "] ";
        pos = pos->getPrev();
    }
    std::cout << std::endl;
}