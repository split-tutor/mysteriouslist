// mysterylist.cpp - mysterious lists implementations
#include <iostream>
#include <stdlib.h>

#include "mysterylist.h"

List::List(std::initializer_list<int> elem)
{
    for (auto i : elem) {
        push_back(i);
    }
}

List::List(int* elem, int N)
{
    for (int i = 0; i < N; i++) {
        push_back(elem[i]);
    }
}

List::List(const List& l)
{
    for (int i = 0; i < l.length(); i++) {
        push_back(l[i]);
    }
}

List::~List()
{
    for (int i = 0; i < length(); i++)
        pop_back();
}

size_t List::length() const
{
    auto iter = hd;
    size_t len = 0;

    for (; iter; iter = iter->next)
        len++;

    return len;
}

void List::push_back(int val)
{
    if (!hd) {
        hd = new Node{val, nullptr};
    } else {
        auto iter = hd;
        for (; iter->next; iter = iter->next);
        iter->next = new Node{val, nullptr};
    }
}

int List::pop_back()
{
    if (!hd) {
        std::cout << "ERROR: Out of Bound\n";
        return 0;
    } else {
        auto prev = hd, curr = prev->next;
        for (; curr->next; prev = prev->next, curr = curr->next);
        prev->next = nullptr;
        int val = curr->val;
        delete curr;
        return val;
    }
}

int& List::operator[](size_t n)
{
    if (n >= length()) {
        std::cout << "ERROR: Out of Bound\n";
        exit(1);
    }

    Node* iter = hd;
    for (int i = 0; i < n; i++) {
        iter = iter->next;
    }

    return iter->val;
}

const int& List::operator[](size_t n) const
{
    if (n >= length()) {
        std::cout << "ERROR: Out of Bound\n";
        exit(1);
    }

    Node* iter = hd;
    for (int i = 0; i < n; i++) {
        iter = iter->next;
    }

    return iter->val;
}

std::ostream& operator<<(std::ostream& os, const List& l)
{
    os << '[';
    for (int i = 0; i < l.length() - 1; i++)
        os << l[i] << ", ";

    os << l[l.length() - 1] << ']';
    return os;
}
