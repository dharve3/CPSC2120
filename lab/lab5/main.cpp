/*
 * Name: Dylan Harvey
 * Date Submitted: 10/--/2024
 * Lab Section: 005
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"
#include <iostream>
#include <fstream>

void testStringset(Stringset& words);
void loadStringset(Stringset& words, string filename);
vector<string> spellcheck(const Stringset& words, string word);

int main() {
    Stringset wordlist;
    testStringset(wordlist);
    return 0;
}

void testStringset(Stringset& words) {
    string choice;
    string word;
    do {
        cout << "I: insert word" << endl;
        cout << "F: find word" << endl;
        cout << "R: remove word" << endl;
        cout << "P: print words in stringset" << endl;
        cout << "Q: quit" << endl;
        cin >> choice;
        switch (choice[0]) {
            case 'I':

            case 'i':
            cout << "Enter word to insert: ";
            cin >> word;
            words.insert(word);
            break;

            case 'F':

            case 'f':
            cout << "Enter word to find: ";
            cin >> word;
            if (words.find(word)) {
                cout << word << " in stringset" << endl;
            } else {
                cout << word << " not in stringset" << endl;
            }
            break;

            case 'R':

            case 'r':
            cout << "Enter word to remove: ";
            cin >> word;
            words.remove(word);
            break;

            case 'P':

            case 'p':
            vector<list<string>> t = words.getTable();
            int numWords = words.getNumElems();
            int tSize = words.getSize();
            for(int i=0; i<tSize; ++i)
            {
                list<string>::iterator pos;
                for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                {
                    cout << *pos << endl;
                }
            }
            cout << "Words: " << numWords << endl;
        }
    } while (choice[0] != 'Q' && choice[0] != 'q');
}

void loadStringset(Stringset& words, string filename) {
    ifstream file(filename);
    string word;

    // Check if file opened successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    // Read each word from the file and insert into the Stringset
    while (file >> word) {
        words.insert(word);
    }

    file.close();
}

vector<string> spellcheck(const Stringset& words, string word) {
    vector<string> alternatives;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    // For each character in the word, try replacing with every other letter
    for (int i = 0; i < word.length(); i++) {
        char original = word[i];
        for (char c : alphabet) {
            if (c != original) {
                string new_word = word;
                new_word[i] = c;

                // Check if the new word exists in the Stringset
                if (words.find(new_word)) {
                    alternatives.push_back(new_word);
                }
            }
        }
    }

    return alternatives;
}