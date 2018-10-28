// test_mysterious.cpp - test mysterious list implementations

#include <iostream>

#include "mysterylist.h"

int main()
{
    int elem[] = {1, 2, 3, 4, 5}; 
    List l{elem, 5};

    std::cout << "l.pop_back(): " << l.pop_back()
              << "\nl.pop_back(): " << l.pop_back()
              << "\nl.length(): " << l.length()
              << "\nl: " << l << '\n';

    return 0;
}