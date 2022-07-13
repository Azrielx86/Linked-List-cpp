# Double linked list example in C++

There is an example of a double linked list that supports multiple types like int, float, double, string, etc.

For this example, it creates three lists: int, float and string.

## Compilation

I know that it don't need cmake (it's like killing a fly with a bazooka).

With cmake

    mkdir build && cd build
    cmake ..
    cmake --build .

With clang or gcc

    clang++ **/*.cpp -o linked-lists
or

    g++ **/*.cpp -o linked-lists

## Menus

Main menu

    Select a list: 
    [1] int
    [2] float
    [3] string
    [q] quit
    option > 

Action to list

    Using list: int
    Select Action: 
    [1] add
    [2] delete
    [3] clear
    [r] return
    option >

Example with data added

    Int list:    [15] [56] [76] [96] [21] [212] 
    Float list:  [43.1] [54] [65.3] [76.4] 
    String list: [Hello] [World] [from] [C++!] 
    Select a list: 
    [1] int
    [2] float
    [3] string
    [q] quit
    option > 