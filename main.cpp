#include <iostream>
#include "linked-list/linked-list.h"
#include "linked-list/linked-list.cpp"

#define CLEAR "clear"

void test();

int main(int, char**)
{
    char option;

    test();
    
    system(CLEAR);

    while (true)
    {
        std::cout << "Select an data type: " << std::endl;
        std::cout << "[1] int" << std::endl;
        std::cout << "[2] double" << std::endl;
        std::cout << "[3] string" << std::endl << std::endl;
        std::cout << "[q] quit" << std::endl;

        std::cin >> option;

        if (option == '1')
        {
        }
        else if (option == '2')
        {
        }
        else if (option == '3')
        {
        }
        else if (option == 'q') break;
        else std::cout << "Incorrect option!" << std::endl;

        system(CLEAR);
    }

    return 0;
}

void test()
{
    linkedlist<int> int_list;
    linkedlist<std::string> string_list;

    string_list.add_node_at_head("Mundo");
    string_list.add_node_at_head("Hola");
    string_list.add_node_at_end("Desde C++!");

    for (int i = 0; i <= 15; i++)
        int_list.add_node_at_end(i);

    int_list.add_node_at_head(555);
    int_list.add_node_at_index(4, 75);
    int_list.add_node_at_end(999);

    int_list.print_list();
    int_list.print_list_reverse();
    std::cout << "Valor en el índice 3: " << int_list[3] << std::endl;

    // string_list.print_list();

    std::cout << "Eliminado de nodos" << std::endl;
    int_list.delete_node(0);
    int_list.delete_node(int_list.getSize());
    int_list.delete_node(3);


    int_list.print_list();
    int_list.print_list_reverse();


    std::cout << "Nuevas adiciones de nodos" << std::endl;
    int_list.add_node_at_head(-1);
    int_list.add_node_at_end(16);
    int_list.add_node_at_index(5, 69);

    int_list.print_list();
    int_list.print_list_reverse();
}