#include <iostream>
#include <type_traits>
#include "linked-list/linked-list.h"
#include "linked-list/linked-list.cpp"

#if defined(_WIN32) || defined(__CYGWIN__)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

template<class _Tp>
void action(linkedlist<_Tp>& list);

int main(int, char**)
{
    char option;
    int input_i;
    float input_f;
    std::string input_s;
    linkedlist<int> list_int;
    linkedlist<float> list_float;
    linkedlist<std::string> list_str;

    system(CLEAR);

    while (true)
    {
        system(CLEAR);
        if (list_int.getSize() > 0)
        {
            std::cout << "Int list:    ";
            list_int.print_list();
        }
        if (list_float.getSize() > 0)
        {
            std::cout << "Float list:  ";
            list_float.print_list();
        }
        if (list_str.getSize() > 0)
        {
            std::cout << "String list: ";
            list_str.print_list();
        }

        std::cout << "Select a list: " << std::endl;
        std::cout << "[1] int" << std::endl;
        std::cout << "[2] float" << std::endl;
        std::cout << "[3] string" << std::endl;
        std::cout << "\u001b[30m[q] quit\u001b[0m" << std::endl;

        std::cout << "option > ";
        std::cin >> option;

        if (option == '1')
        {
            action(list_int);
        }
        else if (option == '2')
        {
            action(list_float);
        }
        else if (option == '3')
        {
            action(list_str);
        }
        else if (option == 'q') break;
        else std::cout << "Incorrect option!" << std::endl;
    }

    return 0;
}

template<class _Tp>
void action(linkedlist<_Tp>& list)
{
    char option;
    _Tp input;
    system(CLEAR);

    std::cout << "Using list: ";
    const char* type = typeid(_Tp).name();
    switch (type[0])
    {
    case 'i':
        std::cout << "int";
        break;
    case 'f':
        std::cout << "float";
        break;
    default:
        std::cout << "string";
        break;
    }

    std::cout << std::endl << "Select Action: " << std::endl;
    std::cout << "[1] add" << std::endl;
    std::cout << "[2] delete" << std::endl;
    std::cout << "[3] clear" << std::endl;
    std::cout << "\u001b[30m[r] return\u001b[0m" << std::endl;

    std::cout << "option > ";
    std::cin >> option;
    std::cout << "\033[1A\33[2Kvalue > ";

    switch (option)
    {
    case '1':
        std::cin >> input;
        if (std::cin.fail())
        {
            std::cin.clear();
            break;
        }

        list.add_node_at_end(input);

        break;
    case '2':
        int index;
        std::cin >> index;
        if (std::cin.fail())
        {
            std::cin.clear();
            break;
        }
        list.delete_node(index);
        break;

    case '3':
        list.clear();
        break;

    case 'r':
        return;
    default:
        break;
    }
}