// mysterylist.h - mysterious lists interfaces

#include <iostream>

struct Node {
    int val;
    Node* next;

    ~Node() { std::cout << "Node::~Node()\n"; } 
};

struct List {
    Node* hd = nullptr; // default value

    List() = delete; // Delete default constructor
    List(std::initializer_list<int> elem);
    List(int* elem, int N);
    List(const List& l);
    List(List&& l) = default;
    ~List();

    size_t length() const;
    void push_back(int val);
    int pop_back();

    int& operator[](size_t n);
    const int& operator[](size_t n) const;
};

std::ostream& operator<<(std::ostream& os, const List& l);
