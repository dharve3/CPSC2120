/*
 * Name: Dylan Harvey
 * Date Submitted: 10/--/2024
 * Lab Section: 005
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <cstdlib> // rand()
#include <vector>

#define DEBUG 1

// Helper function to merge the 2 sorted halves
template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right) {
    // std::cout << "DEBUG: Merging..." << std::endl;
    std::vector<T> result;
    int i = 0; int j = 0;

    // std::cout << "DEBUG: left.size() = " << left.size() << ", right.size() = " << right.size() << std::endl;

    while ((i < left.size()) && (j < right.size())) {
        if (left[i] < right[j]) {
            // std::cout << "DEBUG: i = " << i << ", left[i] = " << left[i] << std::endl;
            result.push_back(left[i]); // if left is less than right
            i++;
        } else {
            // std::cout << "DEBUG: j = " << j << ", left[j] = " << right[j] << std::endl;
            result.push_back(right[j]); // if right is less than left
            j++;
        }
    }

    // Add remaining elements from left, if any
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    // Add remaining elements from right, if any
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {
    // std::cout << "DEBUG: lst.size() = " << lst.size() << std::endl;
    if (lst.size() <= 1) 
        return lst; // base case
    
    int i;
    int mid = lst.size() / 2; // split lst
    // std::cout << "DEBUG: mid = " << mid << std::endl;
    std::vector<T> leftHalf, rightHalf;

    for (i = 0; i < lst.size(); i++) {
        // std::cout << "DEBUG: i = " << i << ", lst[i] = " << lst[i] << std::endl;
        if (i < mid) {
            // std::cout << "DEBUG: i < mid" << std::endl;
            leftHalf.push_back(lst[i]);
        } else if (i >= mid) {
            // std::cout << "DEBUG: i >= mid" << std::endl;
            rightHalf.push_back(lst[i]);
        }
    }

    // Recursivley sort
    std::vector<T> sortLeft = mergeSort(leftHalf);
    std::vector<T> sortRight = mergeSort(rightHalf);

    return merge(sortLeft, sortRight);
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst) {
    if (lst.size() <= 1)
        return lst; // Base case

    // Random pivot
    int pivotIndex = rand() % lst.size();
    T pivot = lst[pivotIndex];

    std::vector<T> left, right, sortLeft, sortRight, result;

    // Partition the vector into 3 parts: less, equal, or greater than the pivot
    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] < pivot)
            left.push_back(lst[i]);
        else if (lst[i] > pivot && lst[i] != pivot) // Dont accidentally add pivot twice
            right.push_back(lst[i]);
    }

    // Recursivley sort
    sortLeft = quickSort(left);
    sortRight = quickSort(right);

    // Concatenate all the remaining parts together
    result.insert(result.end(), sortLeft.begin(), sortLeft.end()); // Add sorted left
    result.push_back(pivot); // add pivot to the middle
    result.insert(result.end(), sortRight.begin(), sortRight.end()); // Add sorted right

    return result;
}