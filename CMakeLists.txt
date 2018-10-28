cmake_minimum_required(VERSION 3.4)

add_library(MysteryList mysterylist.h mysterylist.cpp)
add_executable(test_mysterylist test_mysterylist.cpp)
target_link_libraries(test_mysterylist MysteryList)