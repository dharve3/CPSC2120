/*
 * Name: Dylan Harvey
 * Date Submitted: 10/16/2024
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
    // if (find(word))
    //     return; // If word already exists, do nothing
    // Decided against this implementataion since this hashes the word twice per insert operation

    // Get the hash value for the word
    size_t hashValue = hash<string>{}(word) % size;

    // Check if the word already exists in the linked list at table[hashValue]
    for (const string& s : table[hashValue]) {
        if (s == word) {
            return; // If word already exists, do nothing
        }
    }

    // Insert the word into the hash table
    table[hashValue].push_back(word);
    num_elems++;

    // Check for resizing - PUT IN HELPER FUNC?
    if (num_elems == size) {
        int newSize = size * 2;
        vector<list<string>> newTable(newSize);

        // Rehash all existing words into the new table
        for (int i = 0; i < size; i++) {
            for (const string& s : table[i]) {
                size_t newHashValue = hash<string>{}(s) % newSize;
                newTable[newHashValue].push_back(s);
            }
        }

        // Replace the old table and update size
        table = newTable;
        size = newSize;
    }


}

bool Stringset::find(string word) const {
    // Get the hash value for the word
    size_t hashValue = hash<string>{}(word) % size;

    // Check the linked list at table[hashValue] for the word
    for (const string &s : table[hashValue]) {
        if (s == word) {
            return true; // Word found
        }
    }

    return false; // Word not found
}

void Stringset::remove(string word) {
    // Get the hash value for the word
    size_t hashValue = hash<string>{}(word) % size;

    // Find and remove the word from the linked list at table[hashValue]
    for (auto it = table[hashValue].begin(); it != table[hashValue].end(); ++it) {
        if (*it == word) {
            table[hashValue].erase(it); // Remove the word
            num_elems--;
            return; // No need to continue iterating if word is removed
        }
    }
}