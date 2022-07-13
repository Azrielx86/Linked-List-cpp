cmake_minimum_required(VERSION 3.0.0)
project(LinkedListCPP VERSION 0.1.0)

add_library(linked-list
    ./linked-list/linked-list.cpp
)

include(CTest)
enable_testing()

add_executable(LinkedListCPP main.cpp)
target_link_libraries(LinkedListCPP linked-list -lncurses)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
