/*
 * Name: Dylan Harvey
 * Date Submitted: 
 * Lab Section: 005
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T> * current = start; // Iterator set to start
  while(current != nullptr) {
    Node<T> * next = current->next;
    delete current;
    current = next;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  return (mySize == 0);
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> * newNode = new Node<T>(value); // Creates new node with given value
  newNode->next = start; // Point newNode->next to start
  start = newNode; // Set start ptr to newNode

  mySize++; // Increment Size
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> * newNode = new Node<T>(value); // Creates new node with given value

  if (start == nullptr) { // Checks if list is empty
    start = newNode;
  } else {
    Node<T> * current = start; // Iterator set to start
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode; // Point last node (current->next) to newNode;
  }
  
  mySize++; // Increment Size
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  if (j < 0 || j >= mySize) {
    return; // Invalid size, do nothing
  }

  if (j == 0) {
    insertStart(value);
    return;
  }

  if (j == mySize) {
    insertEnd(value);
    return;
  }
  
  Node<T> * newNode = new Node<T>(value); // Creates new node with given value
  Node<T> * current = start; // Iterator set to start

  for (int i = 0; i < j - 1; i++) {
    current = current->next; // position before j
  }

  newNode->next = current->next; // Point newNode->next to the position before j
  current->next = newNode; // Point current node's next to newNode;

  mySize++; // Increment Size
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  if (start == nullptr) { // Checks if list is empty
    return; // Do nothing
  }

  Node<T> * temp = start; // temp saving start/1st node
  start = start->next; // Move start to 2nd node
  delete temp; // Delete start/1st node

  mySize--; // Decrement Size
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  if (start == nullptr) { // Checks if list is empty, do nothing
    return;
  } else if (start->next == nullptr) { // If only one node, delete it
    delete start;
    start = nullptr;
  } else {
    Node<T> * current = start; // Iterator set to start
    while (current->next->next != nullptr) {
      current = current->next; // 2nd last node
    }

    delete current->next; // Delete last node
    current->next = nullptr; // Set new last node to nullptr/end
  }
  
  mySize--; // Decrement Size
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  if (j < 0 || j >= mySize) { // Invalid pos, do nothing
    return;
  }

  if (j == 0) {
    removeStart();
    return;
  }

  if (j == mySize) {
    removeEnd();
    return;
  }

  Node<T> * current = start; // Iterator set to start

  for (int i = 0; i < j; i++) {
    current = current->next; // position j
  }

  Node<T> * temp = current->next; // store next value
  delete current;
  current = temp;

  mySize--; // Decrement Size
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  if (start == nullptr) {
    return T(); // Default value
  }
  return start->value; // First Value
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  if (start == nullptr) {
    return T(); // Default value
  }

  Node<T> * current = start; // Iterator set to start
  while (current->next != nullptr) {
    current = current->next; // Last node
  }
  return current->value; // Last value
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  if (j < 0 || j >= mySize) {
    return T(); // Invalid pos, do nothing
  }

  // Unnesecary, no special case for first or last needed.
  // if (j == 0) {
  //   return getFirst();;
  // }

  // if (j == mySize) {
  //   return getLast();
  // }

  Node<T> * current = start; // Iterator set to start

  for (int i = 0; i < j; i++) {
    current = current->next; // Iterate to position j
  }

  return current->value; // Value at j
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T>* current = start;
  int position = 0;

  while (current != nullptr) {
    if (current->value == key) {
      return position; // return position if value found
    }
    current = current->next;
    position++;
  }
  
  return -1; // If not found, return -1
}

  // Old implementation of find(): Redid cuz this code kinda sucks
  // if (start == nullptr) { // Checks if list is empty
  //   return -1;
  // }

  // Node<T> * current = start; // Iterator set to start
  // int count = 0;

  // while (current->next != nullptr) {
  //   if (current->value == key) {
  //     break;
  //   }
  //   count++;
  //   current = current->next;
  // }
  
  // if (count+1 >= mySize)
  //   return -1;
  // else if (count+1 < mySize)
  //   return count;
  // else
  //   return -1;