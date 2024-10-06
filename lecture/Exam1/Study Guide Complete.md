# Study Guide for Exam 1 <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->
1. [Programming Review/Concepts](#be-able-to-briefly-define-describe-or-use-the-following-programming-concepts)
2. [Data Structures/Implementation](#be-able-to-describe-implement-or-use-the-following-data-structures)
3. [Big-O, Big-Ω, and Θ Notation](#be-able-to-describe-the-asymptotic-order-of-mathematical-functions-using-big-o-big-ω-and-θ-notation)
4. [Run-time order of code](#be-able-to-determine-the-run-time-order-of-a-fragment-of-code-or-function-containing-nested-andor-sequential-loops-with-or-without-recursion)
5. [Best-case, Worst-case, Average-case, and Amortized](#understand-best-case-vs-worst-case-vs-average-case-typical-single-case-vs-amortized-on-a-sequence-of-operations-including-average-and-worst-case-analysis)
6. [Algorithms, Operation, and Properties](#understand-how-the-following-algorithms-operate-in-general-and-their-properties-timespace-complexity-bestworstaverage-case-stable-vs-unstable-sort-etc)
7. [Properties of Sorting Algorithms](#understand-the-properties-of-sorting-algorithms)
8. [Binary Search, Merge Sort, and Quicksort Implementation](#be-able-to-implement-the-divide-and-conquer-algorithms-discussed-binary-search-merge-sort-and-quicksort)
9. [Addendum: Key Differences Between Merge Sort and Quicksort](#addendum-key-differences-between-merge-sort-and-quicksort)

## Be able to briefly define, describe, or use the following programming concepts:
1. Recursion
   - Recursion is a technique in which a function calls itself to solve smaller instances of a problem. Each recursive call reduces the problem's complexity until a base case is reached, which halts further recursion. It’s essential to design recursive functions with:
   - Base case: A condition that stops recursion.
   - Recursive case: The part where the function calls itself with a reduced version of the original problem.
   - Example:
   ```cpp
   int factorial(int n) {
       if (n == 0) return 1; // base case
       return n * factorial(n - 1); // recursive case
   }
   ```
2. Classes
   - A class is a blueprint for creating objects in object-oriented programming. It encapsulates data (attributes) and functions (methods) that operate on the data.
   - Example:
   ```cpp
   class Dog {
   public:
       string name;
       void bark() {
           cout << name << " says Woof!";
       }
   };
   ```
3. Public vs. Private Members
   - Public members are accessible from outside the class.
   - Private members are only accessible within the class or by friend functions.
   - Example:
   ```cpp
   class Person {
   public:
       string name;  // public, accessible anywhere
   private:
       int age;  // private, only accessible inside class
   };
   ```
4. Friend Functions
   - A friend function is a function that is not a member of a class but has access to its private and protected members.
   - Example:
   ```cpp
   class Box {
       int width;
   public:
       Box() : width(0) {}
       friend void printWidth(Box &box);  // Declared as a friend
   };

   void printWidth(Box &box) {
       cout << "Width: " << box.width;  // Accessing private member
   }
   ```
5. Implementation vs. Header File
   - In C++, code is often separated into two files:
     - Header file (`.h`): Contains class declarations, prototypes, and inline functions.
     - Implementation file (`.cpp`): Contains the actual function definitions.
   - Example:
     - header file: `MyClass.h`
     - implementation file: `MyClass.cpp`
6. Pass-by-Value vs. Pass-by-Reference
   - Pass-by-value creates a copy of the argument in the function, changes to the copy don’t affect the original.
   - Pass-by-reference allows functions to modify the original variable, as the memory address is passed.
   - Example:
   ```cpp
   void passByValue(int x) { x = 10; }
   void passByReference(int &x) { x = 10; }
   ```
7. `const` Modifier
   - The `const` keyword in C++ defines variables or objects that should not be modified after they are initialized. It can also be used in function declarations to prevent them from modifying the passed argument or class members.
   - Example:
   ```cpp
   void printData(const int &data) {
       cout << data;  // 'data' cannot be modified
   }
   ```
8. Initalizer List
   - An initializer list allows you to initialize class members before the constructor body executes. It’s often used for const members or references that must be initialized when an object is created.
   - Example:
   ```cpp
   class MyClass {
       const int x;
   public:
       MyClass(int val) : x(val) {}  // x initialized using initializer list
   };
   ```
9. Default Constructor
   - A default constructor is a constructor that takes no parameters. If no constructor is provided, C++ automatically creates a default constructor.
   - Example:
   ```cpp
   class Example {
   public:
       Example() {
           cout << "Default Constructor";
       }
   };
   ```
10. Parameterized Constructor
    - A parameterized constructor is a constructor that takes arguments to initialize class members with specific values.
    - Example:
    ```cpp
    class Example {
    public:
        Example(int a, int b) {
            // constructor code
        }
    };
    ```
11. Copy Constructor
    - The copy constructor creates a new object as a copy of an existing object. By default, C++ creates a shallow copy, but it can be customized for deep copying.
    - Example:
    ```cpp
    class Example {
    public:
        Example(const Example &other) {
            // copy constructor
        }
    };
    ```
12. Shallow Copy vs Deep Copy
    - Shallow copy duplicates the object but not the resources it owns (like dynamically allocated memory). Both copies will point to the same memory.
    - Deep copy duplicates both the object and its owned resources, so each object has its own copy of the data.
    - Example:
    ```cpp
    class Example {
        int *data;
    public:
        Example(const Example &other) {
            data = new int(*other.data);  // deep copy
        }
    };
    ```
13. Destructor
    - A destructor is a special function called when an object is destroyed. It is used to release any resources the object holds, such as memory.
    - Example:
    ```cpp
    class MyClass {
        ~MyClass() {
            delete ptr;  // clean up dynamically allocated memory
        }
    };
    ```
14. Dynamic Allocation (`new`/`delete`)
    - In C++, dynamic allocation allows memory to be allocated at runtime using new. Memory must be manually deallocated using delete to prevent memory leaks.
    - Example:
    ```cpp
    int *ptr = new int(5);  // dynamically allocate memory
    delete ptr;  // free memory
    ```
15. "Rule of Three" / "Big 5"
    - The Rule of Three states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three. The Big Five includes:
        1. Destructor
        2. Copy constructor
        3. Copy assignment operator
        4. Move constructor
        5. Move assignment operator
    - Example:
    ```cpp
    class Example {
        ~Example() { /* destructor */ }
        Example(const Example &other) { /* copy constructor */ }
        Example& operator=(const Example &other) { /* copy assignment */ }
    };
    ```
16. Operator Functions
    - Operator overloading allows you to define how operators work for user-defined types. For example, you can redefine + to add two objects of a class.
    - Example:
    ```cpp
    class Complex {
    public:
        Complex operator+(const Complex &other) {
            return Complex(real + other.real, imag + other.imag);
        }
    };
    ```
17. Inheritance
    - Inheritance allows a class (derived class) to inherit members and methods from another class (base class). It’s a key feature of object-oriented programming for code reuse and establishing hierarchies.
    - Example:
    ```cpp
    class Animal {
    public:
        void eat() { cout << "Eating"; }
    };

    class Dog : public Animal {
    public:
        void bark() { cout << "Barking"; }
    };
    ```

## Be able to describe, implement, or use the following data structures:
1. Arrays
   - Fixed-size, contiguous blocks of memory where elements are accessed using indices. Size must be known at compile-time for static arrays.
   - Example:
   ```cpp
   int arr[5];  // Declaring an array of 5 integers
   arr[0] = 10; // Accessing the first element
   ```
   - Key Points:
     - Fixed size
     - Direct access (O(1) access time)
     - Inefficient for insertions and deletions (O(n) time for shifting elements)
2. Vectors
   - A vector is a dynamic array that can resize itself when elements are added or removed. Unlike arrays, vectors can grow or shrink in size, making them more flexible. They are part of the C++ Standard Template Library (STL).
   - Example:
   ```cpp
   #include <vector>

   std::vector<int> vec;  // Declaring a vector of integers
   vec.push_back(10);     // Adding an element
   vec[0] = 20;           // Accessing an element
   ```
   - Key Points:
     - Dynamic resizing
     - Efficient for random access (O(1))
     - Slower than arrays for large insertions or deletions in the middle (O(n) for shifting elements)
     - Uses amortized constant time to grow the underlying array when capacity is exceeded
3. Linked Lists (singly / doubly / circular)
   - Singly Linked List:
     - A singly linked list is a sequence of nodes where each node contains a data element and a pointer to the next node in the sequence. Unlike arrays, linked lists do not store elements in contiguous memory locations. The size of a linked list can grow dynamically, and insertions/deletions are more efficient than arrays.
     - Example:
     ```cpp
     struct Node {
         int data;
         Node* next;
     };

     Node* head = nullptr;  // Initially, the list is empty

     // Insert a node at the beginning
     void insertAtHead(int value) {
         Node* newNode = new Node();
         newNode->data = value;
         newNode->next = head;
         head = newNode;
     }
     ```
     - Key Points:
       - Dynamic size
       - Inefficient for random access (O(n))
       - Efficient insertions/deletions at the beginning (O(1))
   - Doubly Linked List:
     - A doubly linked list is similar to a singly linked list but with an additional pointer in each node that points to the previous node. This allows traversal in both directions (forward and backward).
     - Example:
     ```cpp
     struct Node {
         int data;
         Node* next;
         Node* prev;
     };

     Node* head = nullptr;

     // Insert a node at the beginning
     void insertAtHead(int value) {
         Node* newNode = new Node();
         newNode->data = value;
         newNode->next = head;
         newNode->prev = nullptr;
         if (head != nullptr) {
             head->prev = newNode;
         }
         head = newNode;
     }
     ```
     - Key Points:
       - Can traverse in both directions (forward/backward)
       - Slightly more memory overhead due to an extra pointer
       - Efficient insertions/deletions at both ends (O(1))
   - Circular Linked List:
     - A circular linked list is a variation of a linked list where the last node points back to the first node, forming a circle. Circular linked lists can be either singly or doubly linked.
     - Example:
     ```cpp
     struct Node {
         int data;
         Node* next;
     };

     Node* head = nullptr;

     // Insert at the end of the circular list
     void insertAtEnd(int value) {
         Node* newNode = new Node();
         newNode->data = value;
        
         if (head == nullptr) {
             head = newNode;
             newNode->next = head;  // Points to itself
         } else {
             Node* temp = head;
             while (temp->next != head) {
                 temp = temp->next;
             }
             temp->next = newNode;
             newNode->next = head;  // Complete the circle
         }
     }
     ```
     - Key Points:
       - The last node points to the first node
       - Useful in applications requiring circular iteration
       - Similar efficiency characteristics as singly/doubly linked lists
4. Stacks
   - A stack is a data structure that follows the Last In, First Out (LIFO) principle, meaning the last element added to the stack is the first one to be removed. Operations typically include:
     - push: Add an element to the top.
     - pop: Remove the top element.
     - top/peek: View the top element.
   - Example:
   ```cpp
   #include <stack>

   std::stack<int> s;
   s.push(10);   // Push an element
   s.push(20);
   int top = s.top();  // View the top element (20)
   s.pop();     // Remove the top element
   ```
   - Key Points:
     - LIFO structure
     - Used in applications like expression evaluation, recursion, and backtracking
     - Time complexity: O(1) for push, pop, and peek operations
5. Queues
   - A queue is a data structure that follows the First In, First Out (FIFO) principle, meaning the first element added to the queue is the first one to be removed. Operations typically include:
     - enqueue: Add an element to the end.
     - dequeue: Remove the front element.
     - front: View the front element.
   - Example:
   ```cpp
   #include <queue>

   std::queue<int> q;
   q.push(10);    // Enqueue an element
   q.push(20);
   int front = q.front();  // View the front element (10)
   q.pop();      // Dequeue the front element
   ```
   - Key Points:
     - FIFO structure
     - Used in scheduling algorithms, breadth-first search, and buffering
     - Time complexity: O(1) for enqueue, dequeue, and front operations

## Be able to describe the asymptotic order of mathematical functions using big-O, big-Ω and Θ notation
Asymptotic notation provides a way to describe the performance of algorithms in terms of their input size n, focusing on how they behave as n approaches infinity. There are three common types of asymptotic notation:
1. Big-O `O(n)`
   - Describes an upper bound on the time complexity of an algorithm. It gives the **worst-case** scenario — the longest time it might take for an algorithm to complete as a function of the input size.
     - Formal Definition: A function `f(n)` is in `O(g(n))` if there exists constants `c > 0` and `n0 >= 0` such that for all `n >= n0`, `f(n) <= c*g(n)`.
     - Example: If an algorithm has a time complexity of `f(n) = 5n + 3`, its Big-O is `O(n)` because for sufficently large n, the linear term n dominates.
2. big-Ω `Ω(n)`
   - Describes a lower bound on the time complexity of an algorithm, representing the **best-case** scenario — the shortest time the algorithm might take.
     - Formal Definition: A function `f(n)` is in `Ω(g(n))` if there exists constants `c > 0` and `n0 >= 0` such that for all `n >= n0`, `f(n) >= c*g(n)`.
     - Example: If an algorithm always requires at least n steps, we say it has a lower bound of `Ω(n)`.
3. Θ `Θ(n)`
   - Describes a tight bound, meaning both an upper and lower bound, on the time complexity of an algorithm, representing the **average-case** scenario. It is used when the algorithm's time complexity is both `O(g(n))` and `Ω(g(n))`
     - Formal Definition: A function `f(n)` is in `Θ(g(n))` if there exists constants `c1 >0`, `c2 > 0`, and `n0 >= 0` such that for all `n >= n0`, `c1*g(n) <= f(n) <= c2*g(n)`.
     - Example: If an algorithm's time complexity is `f(n) = 3n + 2`, its Θ notation is `Θ(n)`, becasue the function grows linearly for large n.

## Be able to determine the run-time order of a fragment of code or function containing nested and/or sequential loops with or without recursion
When analyzing the run-time complexity of a code fragment, the goal is to express the number of operations as a function of the input size n. Here are key strategies:
1. Sequential Code:
   - The time complexity of a sequence of independent statements is the time complexity of the most significant (largest) statement.
   - Example:
   ```cpp
   int sum = 0;                    // O(1)
   for (int i = 0; i < n; i++) {   // O(n)
       sum += i;
   }
   ```
   - In this case, the loop dominates, so the time complexity is `O(n)`.
2. Nested Loops:
   - The time complexity of nested loops is the product of the sizes in each loop.
   - Example:
   ```cpp
   for (int i = 0; i < n; i++) {      // O(n)
       for (int j = 0; j < n; j++) {  // O(n)
           // O(1) operation
       }
   }
   ```
   - This code has two loops, each iterating n times, so the time complexity is `O(n^2)`.
3. Recursion:
   - For recursive functions, use a recurrence relation to express the time complexity. 
   - For example, the time complexity of the following recursive function:
   ```cpp
   int fib(int n) {
       if (n <= 1) {
           return n;       // O(1)
       } else {
           return fib(n-1) + fib(n-2);   // O(2^n)
       }
   }
   ```
   - The recurrence relation is `T(n) = T(n-1) + T(n-2) + O(1)`, and its solution is `O(2^n)`.
4. Divide and Conquer Algorithms:
   - For divide-and-conquer algorithms like mergesort or quicksort, the time complexity can be analyzed using recurrence relations like the Master Theorem.

## Understand best-case vs. worst-case vs. average-case (typical single case) vs. amortized (on a sequence of operations including average and worst-case) analysis
1. Best-case:
   - This describes the minimum time an algorithm can take for the most favorable input. Best-case analysis helps in understanding how an algorithm performs in optimal situations.
   - Example: Example: In a sorted array, a linear search might find the element on the first comparison, giving `O(1)` time complexity.
2. Worst-case: The maximal time complexity.
   - This describes the maximum time an algorithm can take for the least favorable input. It is the most common form of analysis since it provides an upper bound on the running time.
   - Example: In an unsorted array, the worst-case time complexity for linear search is `O(n)` if the element is at the last position or not present at all.
3. Average-case: The expected time complexity for random inputs.
   - This describes the expected time an algorithm will take over all possible inputs, assuming all inputs are equally likely. It requires calculating the average running time based on different input distributions.
   - Example: The average case for linear search is `O(n/2)`, which simplifies to `O(n)`.
4. Amortized: Average time per operation over a sequence of operations.
   - This type of analysis considers the total cost of a sequence of operations over time and averages it out. It is often used when occasional costly operations happen, but most operations are cheap. The amortized cost per operation becomes low even if an individual operation can be expensive.
   - Example: Consider a dynamic array (like a vector). The push_back operation takes `O(1)` most of the time, but when the array needs to resize, it takes `O(n)`. Over a large number of operations, the amortized time complexity is still `O(1)` because the costly resize happens only occasionally.

## Understand how the following algorithms operate (in general) and their properties (time/space complexity, best/worst/average case, stable vs. unstable sort, etc.)
1. Linear/Sequential Search
   - Operation: Iterate through the array sequentially, comparing each element to the target.
   - Time Complexity:
     - Best case: `Ω(1)` - Target is found at the first position.
     - Worst case: `O(n)` - Target is found at the last position or not at all.
     - Average case: `Θ(n)` - Target is found in the middle on average.
   - Space Complexity: `O(1)` - Requires constant space.
   - In-place: Yes
   - Stable: N/A / Yes
   - Adaptive: No
2. Binary Search
   - Operation: Works only on sorted arrays. Repeatedly divide the search interval in half, comparing the middle element with the target.
   - Time Complexity:
     - Best case: `Ω(1)` - Middle element is target
     - Worst case: `O(log n)` - Dividing array by half each time
     - Average case: `Θ(log n)`
   - Space Complexity: `O(1)` iterative, `O(log n)` recursive (call stack).
   - In-place: Yes
   - Stable: N/A / Yes
   - Adaptive: No
3. Selection Sort
   - Operation: Repeatedly selects the minimum (or maximum) element and places it in the correct position.
   - Time Complexity:
     - Best case: `Ω(n^2)` - Always requires `n(n-1)/2` comparisons.
     - Worst case: `O(n^2)`
     - Average case: `Θ(n^2)`
   - Space Complexity: `O(1)`
   - In-place: Yes
   - Stable: NO - Says yes in the slides?? Swaps adjacent elements, so this is false.
   - Adaptive: No
4. Insertion Sort
   - Operation: Build the sorted array one element at a time, inserting each new element in its correct position.
   - Time Complexity:
     - Best case: `Ω(n)` - If already sorted
     - Worst case: `O(n^2)`
     - Average case: `Θ(n^2)`
   - Space Complexity: `O(1)`
   - In-place: Yes
   - Stable: Yes
   - Adaptive: Yes - Efficent for nearly sorted arrays
5. Bubble Sort
   - Operation: Repeatedly swap adjacent elements if they are in the wrong order. Bubble the largest unsorted element to the end of the array.
   - Time Complexity:
     - Best case: `Ω(n)`
     - Worst case: `O(n^2)`
     - Average case: `Θ(n^2)`
   - Space Complexity: `O(1)`
   - In-place: Yes
   - Stable: Yes
   - Adaptive: Yes - Optimizations like early stopping
6. Shell Sort
   - Operation: Generalization of insertion sort that starts by sorting elements far apart and gradually reduces the gap between compared elements.
   - Time Complexity:
     - Best case: `Ω(n log n)`
     - Worst case: `O(n^2)` - Worst case gap size; `O(n (log n)^2)` - Best case gap size
     - Average case: `Θ(n^(3/2))` - Most common gap size; `Θ(n (log n)^2)` - Best case gap size
   - Space Complexity: `O(1)` gap size
   - In-place: Yes
   - Stable: No
   - Adaptive: Yes
7. Merge Sort
   - Operation: Divide the array into halves, recursively sort them, and then merge the sorted halves.
   - Time Complexity:
     - Best case: `Ω(n log n)`
     - Worst case: `O(n log n)`
     - Average case: `Θ(n log n)`
   - Space Complexity: `O(n)` - Due to storage needed for merging
   - In-place: No
   - Stable: Yes
   - Adaptive: No
8. Quicksort
   - Operation: Select a pivot, partition the array into two halves based on the pivot, and recursively sort the two halves.
   - Time Complexity:
     - Best case: `Ω(n log n)` - Balanced paritioning
     - Worst case: `O(n^2)` - If the pivot is always the smallest or largest element
     - Average case: `Θ(n log n)`
   - Space Complexity: `O(log n)` - Avg for recursive call stack
   - In-place: Yes
   - Stable: No
   - Adaptive: No
9. Heapsort
   - Operation: Convert the array into a max-heap, and repeatedly extract the largest element, restoring the heap property after each extraction.
   - Time Complexity:
     - Best case: `Ω(n log n)`
     - Worst case: `O(n log n)`
     - Average case: `Θ(n log n)`
   - Space Complexity: `O(1)`
   - In-place: Yes
   - Stable: No
   - Adaptive: No
10. Bucket Sort
    - Operation: Distribute elements into buckets, sort each bucket (using a different sorting algorithm, often insertion sort), and then concatenate the buckets.
    - Time Complexity:
      - Best case: `Ω(n + k)` - K is the number of buckets
      - Worst case: `O(n^2)` - If all elements end up in one bucket and another sort is used
      - Average case: `Θ(n + k)`
    - Space Complexity: `O(n)`
    - In-place: No
    - Stable: Yes
    - Adaptive: No
11. Counting Sort
    - Operation: Count the occurrences of each unique element and use the counts to place elements in the correct position in the output array.
    - Time Complexity:
      - Best case: `Ω(n + k)`
      - Worst case: `O(n + k)`
      - Average case: `Θ(n + k)`
    - Space Complexity: `O(k)`
    - In-place: No
    - Stable: Yes
    - Adaptive: No
12. Radix Sort
    - Operation: Sort numbers digit by digit starting from the least significant digit, using a stable sort (like counting sort) at each digit level.
    - Time Complexity:
      - Best case: `Ω(n * k)`
      - Worst case: `O(n * k)`
      - Average case: `Θ(n * k)`
    - Space Complexity: `O(k)`
    - In-place: No
    - Stable: Yes
    - Adaptive: No

## Understand the properties of sorting algorithms:
1. Best/Worst/Average Case
   - Best Case: Describes the minimum time an algorithm takes to complete. This happens when the input data is in an optimal state (e.g., already sorted for insertion sort).
     - Example: Insertion Sort has a best-case time complexity of `Ω(n)` when the input is already sorted.
   - Worst Case: Describes the maximum time the algorithm will take, usually in the least favorable conditions (e.g., reverse sorted data).
     - Example: Quicksort has a worst-case time complexity of `O(n^2)` when the pivot is poorly chosen.
   - Average Case: Describes the time complexity for a typical, random input.
     - Example: Merge Sort consistently has `Θ(n log n)` average case.
2. Stable vs. Unstable
   - Stable Sorting: A sorting algorithm is stable if it maintains the relative order of elements with equal keys (i.e., elements that compare equal stay in their original order).
     - Example: Stable: Merge Sort, Insertion Sort
     - Unstable: Quicksort, Heapsort
   - Why it matters: Stability is important when the order of other attributes is significant, especially when sorting multi-field records.
3. In-place vs. Out-of-place
   - In-place Sorting: A sorting algorithm is in-place if it requires only a constant amount of extra memory (i.e., `O(1)` auxiliary space).
     - Example: In-place: Quicksort, Heapsort
     - Out-of-place: Merge Sort (uses `O(n)` additional space for merging)
   - Why it matters: In-place sorting is important when memory is constrained.
4. Adaptive (Best-case < Average-case)
   - Adaptive Sorting: A sorting algorithm is adaptive if its time complexity improves when the input data has some specific properties (e.g., partially sorted data).
     - Example: Insertion Sort is adaptive, as it runs in `O(n)` for an already sorted array.
     - Non-Adaptive: Algorithms like Quicksort or Merge Sort do not improve in the best case and have the same complexity for all input scenarios.
5. Iterative vs. Recursive
   - Iterative: The algorithm uses loops to repeatedly process the data.
     - Example: Selection Sort, Insertion Sort are iterative.
   - Recursive: The algorithm uses recursive calls to divide the problem into smaller subproblems.
     - Example: Merge Sort, Quicksort use recursive approaches.
   - Why it matters: Recursive algorithms can have higher space requirements due to recursion stacks, but they can be easier to conceptualize for divide-and-conquer approaches.
6. Stepwise Refinement / Incremental Construction / Divide and Conquer
   - Stepwise Refinement: This involves solving a problem by breaking it into smaller steps and gradually refining the solution.
     - Example: Insertion Sort builds the sorted array step-by-step by placing each new element in its correct position.
   - Divide and Conquer: Divides the input into smaller subproblems, solves each subproblem, and then combines the results.
     - Example: Merge Sort and Quicksort follow this strategy by breaking the array into smaller sections, sorting them, and merging or combining them.
   - Incremental Construction: Constructs the solution by adding elements one by one.
     - Example: Shell Sort uses incremental steps to refine the array before applying insertion sort.
7. Deterministic vs. Randomized
   - Deterministic Sorting: The behavior of the sorting algorithm is fully determined by the input; it always follows the same sequence of steps for a given input.
     - Example: Merge Sort, Heapsort, and Insertion Sort are deterministic.
   - Randomized Sorting: These algorithms introduce randomness into the process, and the exact sequence of steps might vary even with the same input.
     - Example: Randomized Quicksort randomly selects the pivot, which helps avoid worst-case scenarios.
8. Comparison (only compares key vs. key in data) vs. Non-Comparison Sorting
   - Comparison Sorting: These algorithms make decisions based on comparing keys. The minimum time complexity for comparison-based sorting is `O(n log n)` due to the information-theoretic lower bound.
     - Example: Merge Sort, Quicksort, Heapsort are comparison sorts.
   - Non-Comparison Sorting: These algorithms do not rely on comparisons between elements but instead use other properties of the data (like digit values).
     - Example: Counting Sort, Radix Sort, Bucket Sort.
   - Why it matters: Non-comparison sorts can achieve linear time complexity (`O(n)`) under certain conditions (e.g., small range of input values), but they usually require additional space.
9. Simplicity of Implementation / Analysis
   - Simple to Implement: Algorithms like Insertion Sort or Selection Sort are generally easier to implement and understand, making them useful for small datasets or educational purposes.
   - Complex to Implement: Algorithms like Merge Sort and Quicksort, though efficient, require more complex logic, particularly for dividing and merging or partitioning data.
   - Simplicity in Analysis: Simple algorithms often have straightforward time and space complexity, while complex algorithms like Quicksort or Heapsort require deeper analysis due to recursive structure or partition strategies.

## Be able to implement the divide-and-conquer algorithms discussed: binary search, merge sort, and quicksort.
***Note: Labs also help a lot here, so look there for your specific examples!***
1. Binary Search
   - Binary search is an efficient algorithm for finding a target value within a sorted array. It works by repeatedly dividing the search interval in half, comparing the target value to the middle element.
   - Steps:
     1. Start with two pointers, low and high, which represent the current search range.
     2. Compute the middle index (mid) of the array.
     3. Compare the middle element with the target:
        - If the middle element is the target, return its index.
        - If the target is smaller, search in the left half (`low` to `mid - 1`).
        - If the target is larger, search in the right half (`mid + 1` to `high`).
     4. Repeat until the target is found or the search range is empty.
   - Time Complexity:
     - Best case: `Ω(1)` - Target is found at the middle on the first comparison
     - Worst/Average case: `O(log n)` - Halving the search space each time
   - Implementation:
   ```cpp
   int binarySearch(int arr[], int low, int high, int target) {
       if (low <= high) {
           int mid = low + (high - low) / 2;  // Find the middle index
 
           // Check if the target is at the mid index
           if (arr[mid] == target)
               return mid;
           
           // If target is smaller, search in the left half
           if (arr[mid] > target)
               return binarySearch(arr, low, mid - 1, target);
 
           // If target is larger, search in the right half
           return binarySearch(arr, mid + 1, high, target);
       }
       
       // Return -1 if the target is not found
       return -1;
   }
   ```
2. Merge Sort
   - Merge sort is a classic example of the divide-and-conquer strategy. It recursively divides the array into two halves, sorts them, and then merges the sorted halves.
   - Steps:
     1. Divide the array into two halves.
     2. Recursively sort the left half and the right half.
     3. Merge the two sorted halves into one sorted array.
   - Time Complexity:
     - Best/Worst/Average case: `Θ(n log n)` (because each level of recursion does `O(n)` merging, there are `log n` levels).
   - Space Complexity:
     - Space complexity: `O(n)` (because of the auxiliary array used for merging).
   - Implementation:
   ```cpp
   void merge(int arr[], int left, int mid, int right) {
       int n1 = mid - left + 1;
       int n2 = right - mid;
       
       // Create temp arrays
       int L[n1], R[n2];
       
       // Copy data to temp arrays L[] and R[]
       for (int i = 0; i < n1; i++)
           L[i] = arr[left + i];
       for (int j = 0; j < n2; j++)
           R[j] = arr[mid + 1 + j];
       
       // Merge the temp arrays back into arr[left..right]
       int i = 0, j = 0, k = left;
       while (i < n1 && j < n2) {
           if (L[i] <= R[j]) {
               arr[k] = L[i];
               i++;
           } else {
               arr[k] = R[j];
               j++;
           }
           k++;
       }
       
       // Copy the remaining elements of L[], if any
       while (i < n1) {
           arr[k] = L[i];
           i++;
           k++;
       }

       // Copy the remaining elements of R[], if any
       while (j < n2) {
           arr[k] = R[j];
           j++;
           k++;
       }
   }

   void mergeSort(int arr[], int left, int right) {
       if (left < right) {
           int mid = left + (right - left) / 2;
           
           // Recursively sort the first and second halves
           mergeSort(arr, left, mid);
           mergeSort(arr, mid + 1, right);
           
           // Merge the two halves
           merge(arr, left, mid, right);
       }
   }
   ```
3. Quicksort
   - Quicksort is another divide-and-conquer sorting algorithm, which works by selecting a "pivot" element and partitioning the array so that elements smaller than the pivot go to the left, and elements greater than the pivot go to the right. It then recursively sorts the left and right partitions.
   - Steps: 
     1. Choose a pivot element (can be any element, but typically the last element).
     2. Partition the array into two subarrays: elements less than the pivot and elements greater than the pivot.
     3. Recursively apply quicksort to the subarrays.
   - Time Complexity:
     - Best/Average case: `Θ(n log n)` (when the pivot divides the array evenly).
     - Worst case: `O(n^2)` (when the pivot divides the array poorly, e.g., when the array is already sorted and the pivot is always the smallest or largest element).
   - Space Complexity:
     - Space complexity: `O(log n)` for recursive stack space, but in the worst case (if not optimized), it could be `O(n)`.
   - Implementation:
   ```cpp
   int partition(int arr[], int low, int high) {
       int pivot = arr[high];  // Choose the last element as the pivot
       int i = low - 1;  // Index of smaller element
       
       for (int j = low; j <= high - 1; j++) {
           // If the current element is smaller than or equal to the pivot
           if (arr[j] <= pivot) {
               i++;
               // Swap arr[i] and arr[j]
               std::swap(arr[i], arr[j]);
           }
       }
       
       // Swap the pivot element with the element at i+1
       std::swap(arr[i + 1], arr[high]);
       return (i + 1);
   }

   void quickSort(int arr[], int low, int high) {
       if (low < high) {
           // Partition the array and get the pivot index
           int pi = partition(arr, low, high);
           
           // Recursively sort elements before and after the partition
           quickSort(arr, low, pi - 1);
           quickSort(arr, pi + 1, high);
       }
   }
   ```
## Addendum: Key Differences between Merge Sort and Quicksort:
- Merge Sort is stable and has a worst-case time complexity of `O(n log n)` but requires `O(n)` additional space.
- Quicksort is faster in practice due to lower constant factors and is in-place, but it has a worst-case time complexity of `O(n^2)`, although this is rare with good pivot selection.