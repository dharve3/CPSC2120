# Study Guide for Exam 1

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
- Asymptotic notation provides a way to describe the performance of algorithms in terms of their input size n, focusing on how they behave as n approaches infinity. There are three common types of asymptotic notation:
1. Big-O `O(n)`
   - Describes an upper bound on the time complexity of an algorithm. It gives the worst-case scenario — the longest time it might take for an algorithm to complete as a function of the input size.
     - Formal Definition: A function `f(n)` is in `O(g(n))` if there exists constants `c > 0` and `n0 >= 0` such that for all `n >= n0`, `f(n) <= c*g(n)`.
     - Example: If an algorithm has a time complexity of `f(n) = 5n + 3`, its Big-O is `O(n)` because for sufficently large n, the linear term n dominates.
2. big-Ω `Ω(n)`
   - Describes a lower bound on the time complexity of an algorithm, representing the best-case scenario — the shortest time the algorithm might take.
     - Formal Definition: 
     - Example: 
3. Θ `Θ(n)`
   - Describes a tight bound, meaning both an upper and lower bound, on the time complexity of an algorithm. It is used when the algorithm's time complexity is both `O(g(n))` and `Ω(g(n))`
     - Formal Definition: 
     - Example: 

## Be able to determine the run-time order of a fragment of code or function containing nested and/or sequential loops with or without recursion
   4. Analyze loops and recursion for time complexity. Nested loops multiply their complexity, sequential loops sum up.
   5. Example: Two nested loops → `O(n^2)`.

## Understand best-case vs. worst-case vs. average-case (typical single case) vs. amortized (on a sequence of operations including average and worst-case) analysis
   6. Best-case: The minimal time complexity.
   7. Worst-case: The maximal time complexity.
   8. Average-case: The expected time complexity for random inputs.
   9. Amortized: Average time per operation over a sequence of operations.

## Understand how the following algorithms operate (in general) and their properties (time/space complexity, best/worst/average case, stable vs. unstable sort, etc.)
   10. Linear/Sequential Search
      - Scans each element until it finds the target or reaches the end.
      - Time Complexity: `O(n)`.
   11. Binary Search
      - Requires a sorted array. Divides the array in half and eliminates one half each time.
      - Time Complexity: `O(log n)`.
   12. Seleciton Sort
      - Repeatedly finds the minimum element and moves it to the sorted portion.
      - Time Complexity: `O(n^2)`.
   13. Insertion Sort
      - Builds the sorted array one element at a time by inserting elements into the correct position.
      - Time Complexity: `O(n^2)`, best case: `O(n)`.
   14. Bubble Sort
      - Repeatedly swaps adjacent elements if they are in the wrong order.
      - Time Complexity: `O(n^2)`.
   15. Shell Sort
      - A generalized version of insertion sort that allows elements to be moved farther apart.
      - Time Complexity: Depends on gap sequence.
   16. Merge Sort
      - A divide-and-conquer algorithm that splits the array, sorts each half, and merges them.
      - Time Complexity`: O(n log n)`.
   17. Quicksort
      - A divide-and-conquer algorithm that selects a pivot, partitions the array, and recursively sorts the partitions.
      - Time Complexity: Best/Avg: `O(n log n)`, Worst: `O(n^2)`.
   18. Heapsort
       - Builds a max heap and repeatedly extracts the largest element.
       - Time Complexity: `O(n log n)`.
   19. Bucket Sort
       - Distributes elements into buckets and sorts each bucket individually.
       - Time Complexity: Best: `O(n + k)`.
   20. Counting Sort
       - Counts the occurrence of each element and builds the output array.
       - Time Complexity: `O(n + k)`.
   21. Radix Sort
       - Sorts numbers digit by digit using a stable sorting algorithm (like counting sort).
       - Time Complexity: `O(nk)`.

## Understand the properties of sorting algorithms:
    22. Best/Worst/Average Case
    23. Stable vs. Unstable
        - A stable sort maintains the relative order of equal elements.
    24. In-place vs. Out-of-place
        - In-place sorts use constant extra space, while out-of-place sorts need additional memory.
    25. Adaptive (Best-case < Average-case)
        - Some algorithms perform faster when the input is already partially sorted.
    26. Iterative vs. Recursive
        - Whether the algorithm uses loops or recursion to sort.
    27. Stepwise Refinement / Incremental Construction / Divide and Conquer
    28. Deterministic vs. Randomized
        - Deterministic algorithms follow a fixed sequence of steps, while randomized algorithms make decisions based on random choices.
    29. Comparison (only compares key vs. key in data) vs. Non-Comparison Sorting
    30. Simplicity of Implementation / Analysis

## Be able to implement the divide-and-conquer algorithms discussed: binary search, merge sort, and quicksort.