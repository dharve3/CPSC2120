/*
 * Name: Dylan Harvey
 * Date Submitted: 10/--/2024
 * Lab Section: 005
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const {
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const {
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const {
    return size;
}

void Stringset::insert(string word) {
    //Implement this function
}

bool Stringset::find(string word) const {
    //Implement this function
}

void Stringset::remove(string word) {
    //Implement this function
}