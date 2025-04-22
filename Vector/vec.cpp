// Declaration of a vector in C++
// In C++, a vector is a dynamic array, meaning that its size can
//  grow or shrink as needed during program execution. Vectors are
//  part of the C++ Standard Template Library (STL) and are declared using the following syntax:

// std::vector<data_type> vector_name;

//initialization of vector:----

std::vector<int> myVector;
//initialization with size
std::vector<int> myVector(5); // Creates a vector with 5 elements, each initialized to 0.
//initialization with size and value
std::vector<int> myVector(5, 10); // Creates a vector with 5 elements, each initialized to 10.
std::vector<int> numbers = {1, 2, 3, 4, 5};


// 3. Using a copy constructor:

// A copy constructor creates a new vector by copying the values from an existing vector.

std::vector<int> numbers1 = {1, 2, 3};
std::vector<int> numbers2(numbers1); // Copy the values of numbers1 to numbers2



// Using a range-based for loop:
// A range-based for loop can be used to initialize a vector with values from another container.

std::list<int> values = {1, 2, 3};
std::vector<int> numbers;

for (int value : values) {
  numbers.push_back(value);
}

// Using an array:

// An array can be used to initialize a vector.

int arr[] = {1, 2, 3};
std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int)); // Initialize a vector using the array arr


// Basic Vector Operations
// some of the basic vector operations in C++ are:

// Accessing Elements: You can access elements of a vector using either
//  its index or an iterator. Indexing uses square brackets [] and an index value, 
// while iterators provide a pointer-like interface to traverse the vector.

std::vector<int> numbers = {1, 2, 3, 4, 5};

int firstElement = numbers[0]; // Accessing the first element
int lastElement = numbers.back(); // Accessing the last element 

// Modifying Elements: You can modify the values of vector elements using
//  either indexing or iterators. Both methods allow you to change the value 
// at a specific position in the vector.

numbers[2] = 10; // Modifying the third element
numbers.front() = 20; // Modifying the first element

// Adding Elements: There are several ways to add new elements to a vector. 
// The most common methods are using the push_back() and insert() functions.

numbers.push_back(6); // Adding an element to the end
numbers.insert(numbers.begin() + 1, 7); // Inserting an element at position 1

// Removing Elements: You can remove elements from a vector using the erase() and pop_back() functions.

numbers.erase(numbers.begin() + 2); // Removing the third element
numbers.pop_back(); // Removing the last element

// Checking Size and Emptiness: The size() function returns the number 
// of elements in the vector, while the empty() function checks whether the vector is empty or not.

int vectorSize = numbers.size(); // Checking the size of the vector
bool isEmpty = numbers.empty(); // Checking if the vector is empty

// Resizing the Vector: You can resize a vector using the resize() function, 
// which can either increase or decrease the vector's capacity.

numbers.resize(10); // Resizing the vector to hold 10 elements

// Clearing the Vector: The clear() function removes all elements from the vector, effectively emptying it.
numbers.clear(); // Clearing the vector



// Allocators Function in Vector C++
// Allocators are objects that manage the dynamic allocation and deallocation 
// of memory for containers like vectors. In C++, vectors provide a single function 
// called get_allocator() that allows you to access the allocator associated with a 
// vector. This allocator can be used to allocate custom memory chunks or to modify 
// the allocator's behavior.