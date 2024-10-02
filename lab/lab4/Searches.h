/*
 * Name: Dylan Harvey
 * Date Submitted: 10/02/2024
 * Lab Section: 005
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>

// Iterates the entire vector to search
template <class T>
int linearSearch(std::vector<T> data, T target) {
    for (int i = 0; i < data.size(); i++)
        if (data[i] == target)
            return i;
    return -1; // target not found
}

// Expects sorted data, splits in half to search
template <class T>
int binarySearch(std::vector<T> data, T target) {
    int low = 0;
    int mid;
    int high = data.size();

    while (low <= high) {
        mid = low + (high - low) / 2; // split the data

        if (data[mid] == target) // if target is at mid
            return mid;
        
        if (data[mid] < target) // if target is greater than mid, ignore left half
            low = mid + 1;
        
        else // if target is smaller, ignore right half
            high = mid - 1;
    }
    return -1; // target not found
}
