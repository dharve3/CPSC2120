# Study Guide for Exam 1

1. Be able to briefly define, describe, or use the following programming concepts:
   1. Recursion
      - A function calls itself to solve smaller instances of the same problem. A recursive function has a base case (stopping condition) and a recursive case (where the function calls itself).
      - Example: Calculating factorial `n! = n * (n-1)!`.
   2. Classes
      - A blueprint for creating objects. It encapsulates data (attributes) and functions (methods) to operate on that data.
      - Example: A `Car` class with attributes like `color`, `speed`, and methods like `accelerate()`.
   3. Public vs. Private Members
      - Public members are accessible from outside the class, while private members can only be accessed by class methods. `Protected` is accessible in derived classes.
      - Example: `private int age; public void setAge(int age)`.
   4. Friend Functions
      - Functions that are not members of the class but have access to its private and protected members. They are declared using the keyword `friend`.
      - Example: Granting a standalone function access to a class’s private members.
   5. Implementation vs. Header File
      - Header files (`.h`) declare class prototypes, methods, and functions. Implementation files (`.cpp`) define how the declared methods work.
      - Example: `Car.h` vs `Car.cpp`.
   6. Pass-by-Value vs. Pass-by-Reference
      - Pass-by-value copies the argument's value into a function, meaning changes inside the function do not affect the original variable.
      - Pass-by-reference passes a variable’s memory address, so changes in the function affect the original variable.
      - Example: `void func(int x)` vs. `void func(int &x)`.
   7. `const` Modifier
      - The `const` keyword ensures a variable’s value cannot be changed. It can be applied to variables, pointers, and member functions.
      - Example: `const int a = 10; void print() const;`
   8. Initalizer List
      - Used to initialize data members of a class before the body of the constructor executes. It is mandatory when initializing `const` members.
      - Example: `Car::Car(int maxSpeed) : speed(maxSpeed) {}`.
   9.  Default Constructor
       - A constructor that takes no parameters and initializes objects with default values.
       - Example: `Car::Car() { speed = 0; }`.
   10. Parameterized Constructor
       - A constructor that takes parameters and allows initializing objects with specific values.
       - Example: `Car::Car(int s) { speed = s; }`.
   11. Copy Constructor
       - A constructor used to create a copy of an object from another object of the same type.
       - Example: `Car(const Car &other) { speed = other.speed; }`.
   12. Shallow Copy vs Deep Copy
       - Shallow copy duplicates the reference to the memory but not the memory itself, while deep copy creates a new copy of the memory.
       - Example: Shallow copy of pointers just copies the address, deep copy allocates new memory.
   13. Destructor
       - A class method that is automatically called when an object goes out of scope to free up resources.
       - Example: `~Car() { delete[] tires; }`.
   14. Dynamic Allocation (`new`/`delete`)
       - Memory is allocated dynamically at runtime using new and deallocated using delete to prevent memory leaks.
       - Example: `int* ptr = new int[10]; delete[] ptr;`.
   15. "Rule of Three" / "Big 5"
       - If a class requires a custom destructor, copy constructor, or assignment operator, it should usually implement all three. The "Big Five" includes these plus move constructor and move assignment operator.
   16. Operator Functions
       - Special functions to overload operators like +, -, =, to work with objects of a class.
       - Example: `Car operator+(const Car &c);`.
   17. Inheritance
       - A mechanism where one class (derived) inherits properties and behaviors from another class (base).
       - Example: `class SportsCar : public Car {}`.

2. Be able to describe, implement, or use the following data structures:
   1. Arrays
      - Fixed-size, contiguous blocks of memory where elements are accessed using indices. Size must be known at compile-time for static arrays.
      - Example: `int arr[10];`.
   2. Vectors
      - A dynamic array provided by C++ Standard Library (STL) that can resize itself when new elements are added.
      - Example: `std::vector<int> vec;`.
   3. Linked Lists (singly / doubly / circular)
      - Singly: A sequence of nodes where each node points to the next node.
      - Doubly: Nodes point to both next and previous nodes.
      - Circular: The last node points back to the first node.
      - Example: `class Node { Node* next; };`.
   4. Stacks
      - A Last-In-First-Out (LIFO) data structure where elements are added and removed from the top.
      - Example: `std::stack<int> s;`.
   5. Queues
      - A First-In-First-Out (FIFO) data structure where elements are added at the back and removed from the front.
      - Example: `std::queue<int> q;`.

3. Be able to describe the asymptotic order of mathematical functions using big-O, big-Ω and Θ notation
   1. Big-O `O(n)`
      - Big-O (O) describes the worst-case time complexity.
   2. big-Ω `Ω(n)`
      - Big-Ω (Ω) describes the best-case time complexity.
   3. Θ `Θ(n)`
      - Theta (Θ) describes both the upper and lower bounds (tight bound).

4. Be able to determine the run-time order of a fragment of code or function containing nested and/or sequential loops with or without recursion
   1. Analyze loops and recursion for time complexity. Nested loops multiply their complexity, sequential loops sum up.
   2. Example: Two nested loops → `O(n^2)`.

5. Understand best-case vs. worst-case vs. average-case (typical single case) vs. amortized (on a sequence of operations including average and worst-case) analysis
   1. Best-case: The minimal time complexity.
   2. Worst-case: The maximal time complexity.
   3. Average-case: The expected time complexity for random inputs.
   4. Amortized: Average time per operation over a sequence of operations.

6. Understand how the following algorithms operate (in general) and their properties (time/space complexity, best/worst/average case, stable vs. unstable sort, etc.)
   1. Linear/Sequential Search
      - Scans each element until it finds the target or reaches the end.
      - Time Complexity: `O(n)`.
   2. Binary Search
      - Requires a sorted array. Divides the array in half and eliminates one half each time.
      - Time Complexity: `O(log n)`.
   3. Seleciton Sort
      - Repeatedly finds the minimum element and moves it to the sorted portion.
      - Time Complexity: `O(n^2)`.
   4. Insertion Sort
      - Builds the sorted array one element at a time by inserting elements into the correct position.
      - Time Complexity: `O(n^2)`, best case: `O(n)`.
   5. Bubble Sort
      - Repeatedly swaps adjacent elements if they are in the wrong order.
      - Time Complexity: `O(n^2)`.
   6. Shell Sort
      - A generalized version of insertion sort that allows elements to be moved farther apart.
      - Time Complexity: Depends on gap sequence.
   7. Merge Sort
      - A divide-and-conquer algorithm that splits the array, sorts each half, and merges them.
      - Time Complexity`: O(n log n)`.
   8. Quicksort
      - A divide-and-conquer algorithm that selects a pivot, partitions the array, and recursively sorts the partitions.
      - Time Complexity: Best/Avg: `O(n log n)`, Worst: `O(n^2)`.
   9.  Heapsort
       - Builds a max heap and repeatedly extracts the largest element.
       - Time Complexity: `O(n log n)`.
   10. Bucket Sort
       - Distributes elements into buckets and sorts each bucket individually.
       - Time Complexity: Best: `O(n + k)`.
   11. Counting Sort
       - Counts the occurrence of each element and builds the output array.
       - Time Complexity: `O(n + k)`.
   12. Radix Sort
       - Sorts numbers digit by digit using a stable sorting algorithm (like counting sort).
       - Time Complexity: `O(nk)`.

7.  Understand the properties of sorting algorithms:
    1.  Best/Worst/Average Case
    2.  Stable vs. Unstable
        - A stable sort maintains the relative order of equal elements.
    3.  In-place vs. Out-of-place
        - In-place sorts use constant extra space, while out-of-place sorts need additional memory.
    4.  Adaptive (Best-case < Average-case)
        - Some algorithms perform faster when the input is already partially sorted.
    5.  Iterative vs. Recursive
        - Whether the algorithm uses loops or recursion to sort.
    6.  Stepwise Refinement / Incremental Construction / Divide and Conquer
    7.  Deterministic vs. Randomized
        - Deterministic algorithms follow a fixed sequence of steps, while randomized algorithms make decisions based on random choices.
    8.  Comparison (only compares key vs. key in data) vs. Non-Comparison Sorting
    9.  Simplicity of Implementation / Analysis

8. Be able to implement the divide-and-conquer algorithms discussed: binary search, merge sort, and quicksort.