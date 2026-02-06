# Pointer Practice Problems for Interview

## Table of Contents
1. [Basic Pointer Problems](#basic-pointer-problems)
2. [Double Pointer Problems](#double-pointer-problems)
3. [Triple Pointer Problems](#triple-pointer-problems)
4. [Interview Q&A](#interview-qa)
5. [Common Mistakes](#common-mistakes)
6. [Tips & Tricks](#tips--tricks)

---

## Basic Pointer Problems

### Problem 1: Swap Two Integers Using Pointers
**Goal**: Exchange values of two integers using pointers  
**Input**: Two integers  
**Output**: Swapped values  

```c
void swap(int *a, int *b)
{
    // TODO: Implement swap using pointers
    // Hint: Use XOR swap or temporary variable
}
```

**Sample Test**:
```
Before: x=10, y=20
After: x=20, y=10
```

---

### Problem 2: Find String Length Using Pointers
**Goal**: Calculate string length without using strlen()  
**Input**: `char *str`  
**Output**: Length of string  

```c
int string_length(char *str)
{
    // TODO: Use pointer arithmetic to find length
    // Hint: Increment pointer until null terminator
}
```

**Sample Test**:
```
Input: "Hello"
Output: 5
```

---

### Problem 3: Reverse Array In-Place Using Two Pointers
**Goal**: Reverse array without extra space  
**Input**: Integer array and size  
**Output**: Reversed array  

```c
void reverse_array(int *arr, int size)
{
    // TODO: Use two pointers from start and end
    // Move them towards each other, swapping elements
}
```

**Sample Test**:
```
Before: [1, 2, 3, 4, 5]
After:  [5, 4, 3, 2, 1]
```

---

### Problem 4: Allocate Dynamic 2D Array
**Goal**: Create dynamically allocated 2D array  
**Input**: Number of rows and columns  
**Output**: `int**` pointing to allocated array  

```c
int** create_2d_array(int rows, int cols)
{
    // TODO: Allocate array of pointers
    // Then allocate each row
}

void free_2d_array(int **arr, int rows)
{
    // TODO: Free each row first, then array of pointers
}
```

**Sample Test**:
```
Create 3x4 matrix
Allocate: 3 pointers + 12 integers
Free: Reverse order
```

---

### Problem 5: Remove Duplicates from Sorted Array
**Goal**: Remove duplicates in-place, return new length  
**Input**: Sorted array  
**Output**: New length after removing duplicates  

```c
int remove_duplicates(int *arr, int size)
{
    // TODO: Use slow and fast pointer technique
    // Similar to sliding window
}
```

**Sample Test**:
```
Input:  [1, 1, 2, 2, 3, 4, 4, 5]
Output: 5 (array becomes [1, 2, 3, 4, 5, _, _, _])
```

---

### Problem 6: Find Middle Element Using Slow-Fast Pointer
**Goal**: Find middle element using pointer technique  
**Input**: Array and size  
**Output**: Middle element  

```c
int find_middle(int *arr, int size)
{
    // TODO: Use slow (moves 1) and fast (moves 2) pointer
    // When fast reaches end, slow is at middle
}
```

**Sample Test**:
```
Input:  [1, 2, 3, 4, 5]
Output: 3 (index 2)
```

---

### Problem 7: Merge Two Sorted Arrays
**Goal**: Merge two sorted arrays into one  
**Input**: Two sorted arrays  
**Output**: New merged sorted array (dynamically allocated)  

```c
int* merge_sorted_arrays(int *arr1, int size1, int *arr2, int size2, int *result_size)
{
    // TODO: Use three pointers, allocate result array
    // Compare and merge in O(n+m) time
}
```

**Sample Test**:
```
Input:  [1, 3, 5] and [2, 4, 6]
Output: [1, 2, 3, 4, 5, 6]
```

---

### Problem 8: Pointer to Pointer - Modify String
**Goal**: Change pointer in calling function  
**Input**: Pointer to string pointer  
**Output**: Pointer modified to new string  

```c
void change_string(char **str)
{
    // TODO: Allocate new string and change what pointer points to
    // *str now points to new memory
}
```

**Sample Test**:
```
Before: message = "Original"
After:  message = "Changed" (different memory)
```

---

### Problem 9: Function Pointer - Simple Calculator
**Goal**: Use array of function pointers  
**Input**: Two numbers and operation choice  
**Output**: Result of operation  

```c
typedef int (*operation_func)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

void calculator_demo()
{
    // TODO: Create array of function pointers
    operation_func ops[4] = {add, subtract, multiply, divide};
    // Use ops[choice](a, b) to call function
}
```

**Sample Test**:
```
10 + 5 = 15
10 - 5 = 5
10 * 5 = 50
10 / 5 = 2
```

---

### Problem 10: Deep Copy vs Shallow Copy
**Goal**: Understand difference with dynamic memory  
**Input**: Person structure  
**Output**: Copied structure  

```c
typedef struct Person {
    char *name;
    int age;
} Person;

Person* shallow_copy(Person *p)
{
    // TODO: Copy struct but not the dynamic memory
    // Both point to same name!
}

Person* deep_copy(Person *p)
{
    // TODO: Copy struct AND allocate new memory for name
    // Complete independence
}

void free_person(Person *p)
{
    // TODO: Free the person structure properly
}
```

**Common Issue**: Shallow copy leads to double-free or use-after-free!

---

### Problem 11: Void Pointer - Generic Swap
**Goal**: Swap any data type using void pointers  
**Input**: Any two values, size of type  
**Output**: Values swapped  

```c
void generic_swap(void *a, void *b, size_t size)
{
    // TODO: Use void pointers and temporary buffer
    // Works for int, float, struct, anything!
}
```

**Sample Test**:
```
Swap 10, 20 (int) → 20, 10
Swap 3.14, 2.71 (float) → 2.71, 3.14
```

---

### Problem 12: Array Rotation Using Pointer Arithmetic
**Goal**: Rotate array right by k positions  
**Input**: Array, size, k  
**Output**: Rotated array  

```c
void rotate_array(int *arr, int size, int k)
{
    // TODO: Use pointer arithmetic to rotate
    // [1,2,3,4,5], k=2 → [4,5,1,2,3]
}
```

---

### Problem 13: Dynamic String Concatenation
**Goal**: Concatenate two strings, return new allocated string  
**Input**: Two strings  
**Output**: New concatenated string (dynamically allocated)  

```c
char* string_concat(const char *str1, const char *str2)
{
    // TODO: Allocate memory for result and copy both strings
    // Don't forget null terminator!
}
```

**Sample Test**:
```
Input:  "Hello " and "World"
Output: "Hello World"
```

---

### Problem 14: Pointer to Array vs Array of Pointers
**Goal**: Understand the difference  

```c
void demonstrate_pointer_array_difference()
{
    // int (*ptr)[5];      // Pointer to array of 5 ints
    // int *ptr[5];        // Array of 5 int pointers
    // 
    // ptr[0] means different things!
    // TODO: Show examples with different behaviors
}
```

**Difference**:
```
int (*ptr)[5]:  ptr+1 advances by 5*sizeof(int) bytes
int *ptr[5]:    ptr[0]+1 advances by sizeof(int) bytes
```

---

### Problem 15: Memory Leak Detection
**Goal**: Find and fix leaks  

```c
void leaky_function()
{
    int *arr = (int*)malloc(10 * sizeof(int));
    arr = (int*)malloc(20 * sizeof(int));  // LEAK! Lost first pointer
    // TODO: Fix the leak - free first allocation or use temp pointer
}
```

---

## Double Pointer Problems

### Problem 16: Allocate Array of Strings
**Goal**: Create array of dynamically allocated strings  
**Input**: Number of strings, max length  
**Output**: `char**` with allocated strings  

```c
char** allocate_string_array(int num_strings, int max_length)
{
    // TODO: Allocate array of char pointers
    // Then allocate each string separately
    // Returns: strings[0], strings[1], ... strings[n-1]
}

void free_string_array(char **arr, int num_strings)
{
    // TODO: Free each string, then array
}
```

**Memory Layout**:
```
strings (char**)
├── strings[0] → "Hello" (malloc'd)
├── strings[1] → "World" (malloc'd)
└── strings[2] → "Test" (malloc'd)
```

---

### Problem 17: Allocate Array via Double Pointer
**Goal**: Modify pointer in calling function  
**Input**: Pointer to int pointer, size  
**Output**: Pointer now points to allocated array  

```c
void allocate_array(int **ptr, int size)
{
    // TODO: Allocate memory and assign to *ptr
    // This modifies the pointer in the calling function
    // *ptr = malloc(size * sizeof(int));
}
```

**Usage**:
```c
int *array = NULL;
allocate_array(&array, 10);  // array now points to allocated memory
// Use array...
free(array);
```

---

### Problem 18: Sort Array of Strings
**Goal**: Sort strings alphabetically  
**Input**: Array of strings  
**Output**: Sorted array (in-place)  

```c
void sort_strings(char **strings, int count)
{
    // TODO: Use bubble sort or other algorithm with string comparison
    // Hint: Use strcmp() for comparison
    // Swap pointers, not strings!
}
```

**Sample Test**:
```
Input:  ["zebra", "apple", "mango"]
Output: ["apple", "mango", "zebra"]
```

---

### Problem 19: Create Jagged 2D Array
**Goal**: 2D array with varying column counts  
**Input**: Rows, array of column counts  
**Output**: Jagged array  

```c
int** create_jagged_array(int rows, int *col_counts)
{
    // TODO: Each row has different number of columns
    // Row 0: col_counts[0] columns
    // Row 1: col_counts[1] columns
    // etc.
}

void free_jagged_array(int **arr, int rows)
{
    // TODO: Free each row (different sizes!), then array
}
```

**Example**:
```
rows=3
col_counts=[3, 2, 4]

arr[0] → [_, _, _]     (3 elements)
arr[1] → [_, _]        (2 elements)
arr[2] → [_, _, _, _]  (4 elements)
```

---

### Problem 20: Transpose Matrix
**Goal**: Transpose matrix using double pointer  
**Input**: Matrix (rows × cols)  
**Output**: New transposed matrix (cols × rows)  

```c
int** transpose_matrix(int **matrix, int rows, int cols)
{
    // TODO: Create new matrix and transpose
    // element[i][j] becomes element[j][i]
    return NULL;
}
```

**Sample Test**:
```
Input:  3×2 matrix          Output: 2×3 matrix
[1, 2]                      [1, 3, 5]
[3, 4]                      [2, 4, 6]
[5, 6]
```

---

### Problem 21: Split String by Delimiter
**Goal**: Split string into array of substrings  
**Input**: String and delimiter  
**Output**: Array of substrings, count via output parameter  

```c
char** split_string(const char *str, char delimiter, int *count)
{
    // TODO: Split string and return array of substrings
    // Allocate memory for each substring
    // Set *count to number of parts
}
```

**Sample Test**:
```
Input:  "apple,banana,cherry", ','
Output: ["apple", "banana", "cherry"], count=3
```

---

### Problem 22: Add Row to Matrix (Realloc)
**Goal**: Dynamically add row to existing 2D array  
**Input**: Matrix pointer pointer, current rows, cols, new row data  
**Output**: Matrix extended with new row  

```c
void add_row_to_matrix(int ***matrix, int *rows, int cols, int *new_row)
{
    // TODO: Reallocate matrix to add one more row
    // Update *rows
    // Copy new_row data
}
```

**Why Triple Pointer?** Because we're modifying the 2D array pointer (`**matrix`), we need triple pointer!

---

## Triple Pointer Problems

### Problem 23: 3D Dynamic Array
**Goal**: Allocate 3D array dynamically  
**Input**: Depth, rows, columns  
**Output**: 3D array (triple pointer)  

```c
int*** create_3d_array(int depth, int rows, int cols)
{
    // TODO: Allocate 3D array
    // arr[d][r][c] should be accessible
    // Memory layout:
    // int*** → array of int** → array of int* → array of int
    return NULL;
}

void free_3d_array(int ***arr, int depth, int rows)
{
    // TODO: Free in nested loops
    // Free innermost first, then work outward
}
```

**Memory Allocation**: 1 + depth + depth*rows + depth*rows*cols allocations!

---

### Problem 24: Array of Matrices
**Goal**: Create array of 2D matrices  
**Input**: Number of matrices, rows, columns  
**Output**: Triple pointer to matrices  

```c
int*** create_matrix_array(int num_matrices, int rows, int cols)
{
    // TODO: Allocate multiple matrices
    // matrices[0] → first matrix (int**)
    // matrices[1] → second matrix (int**)
    // etc.
}
```

**Usage**:
```c
matrices[0][0][0] = value;  // First element of first matrix
matrices[1][2][3] = value;  // Element at [2][3] of second matrix
```

---

### Problem 25: Replace Matrix Using Triple Pointer
**Goal**: Replace entire 2D array from within function  
**Input**: Triple pointer to matrix, new dimensions  
**Output**: Old matrix freed, new matrix allocated  

```c
void replace_matrix(int ***matrix, int *rows, int *cols, int new_rows, int new_cols)
{
    // TODO: Free old matrix
    // TODO: Allocate new matrix with new dimensions
    // Update *rows and *cols
    // Modify **matrix to point to new matrix
}
```

**Why Triple Pointer?** We're modifying the double pointer (`**matrix`) itself!

---

### Problem 26: Array of String Arrays
**Goal**: Create grouped strings (3D string array)  
**Input**: Number of groups, array of group sizes, max string length  
**Output**: Array of string arrays  

```c
char*** create_grouped_strings(int num_groups, int *strings_per_group, int max_length)
{
    // TODO: Allocate array of string arrays
    // groups[0] → array of strings (group 1)
    // groups[1] → array of strings (group 2)
    // etc.
    // groups[i][j] → jth string of ith group
}

void free_grouped_strings(char ***groups, int num_groups, int *strings_per_group)
{
    // TODO: Free all levels
}
```

**Example**: groups[2][3] = total 2 groups, 3rd group has multiple strings

---

### Problem 27: Add Layer to 3D Array (Quadruple Pointer!)
**Goal**: Dynamically add new layer to 3D array  
**Input**: Quadruple pointer to 3D array, rows, columns  
**Output**: 3D array extended with new layer  

```c
void add_layer_to_3d_array(int ****arr, int *depth, int rows, int cols)
{
    // TODO: Reallocate array of int** to add one more layer
    // Update *depth
    // Why quadruple pointer? Need to modify triple pointer!
}
```

**Why 4 Pointers?** 
- `int***` is the object we're reallocating
- We need to modify it → need `int****`

---

### Problem 28: Clone 3D Array
**Goal**: Deep copy entire 3D array  
**Input**: Original 3D array, dimensions  
**Output**: New 3D array with same values  

```c
int*** clone_3d_array(int ***original, int depth, int rows, int cols)
{
    // TODO: Deep copy entire 3D array
    // Allocate new array and copy all values
    return NULL;
}
```

---

### Problem 29: Generic 2D Array with Void Pointer
**Goal**: 2D array that can hold any type  
**Input**: Rows, columns, element size  
**Output**: Generic 2D array  

```c
void** create_generic_2d_array(int rows, int cols, size_t element_size)
{
    // TODO: Use void** for generic 2D array
    // Each void* points to array of elements
}
```

---

### Problem 30: Pointer Chain - Linked Structure
**Goal**: Linked list where each node contains a 2D array  
**Input**: Matrix data, dimensions  
**Output**: Node inserted at beginning  

```c
typedef struct Node {
    int **data;      // 2D array
    int rows;
    int cols;
    struct Node *next;
} Node;

void insert_node_with_matrix(Node ***head, int **matrix, int rows, int cols)
{
    // TODO: Create new node with matrix
    // Insert at beginning
    // Modify head → need triple pointer!
}

void free_node_list(Node **head)
{
    // TODO: Free entire linked list with matrices
}
```

---

## Interview Q&A

### Q1: What is a pointer?
**Answer**: A variable that stores memory address of another variable. Declared with `*`.
```c
int x = 10;
int *ptr = &x;  // ptr holds address of x
```

---

### Q2: What's the difference between `*ptr++` and `(*ptr)++`?
**Answer**: Due to operator precedence:
- `*ptr++` → `*(ptr++)` → dereference old pointer, then increment pointer
- `(*ptr)++` → increment the value pointed to

---

### Q3: When would you use double pointer?
**Answer**:
1. **Return multiple values** from a function
2. **Allocate memory** inside a function and modify pointer in caller
3. **Array of strings** or dynamic 2D arrays
4. **Pass-by-reference** to pointer (modify pointer itself)
5. **Implement data structures** like linked lists, trees (sometimes)

---

### Q4: Explain deep copy vs shallow copy
**Answer**:
- **Shallow Copy**: Copy the struct, but pointers still point to same memory
  - Leads to: double-free, use-after-free bugs
- **Deep Copy**: Copy the struct AND allocate new memory for pointed data
  - Completely independent copies

```c
// Shallow copy - DANGEROUS
Person copy = original;  // Both name pointers point to same memory!

// Deep copy - SAFE
Person copy = deep_copy(&original);  // New name allocated
```

---

### Q5: What's the difference between `int *ptr[5]` and `int (*ptr)[5]`?
**Answer**:
- `int *ptr[5]` → **Array of 5 pointers to int**
  - `ptr[0]` is an `int*`
  - `ptr[0] + 1` moves by sizeof(int)
  
- `int (*ptr)[5]` → **Pointer to array of 5 ints**
  - `ptr` points to array of 5 ints
  - `ptr + 1` moves by 5*sizeof(int)

---

### Q6: How do you allocate a 2D array dynamically?
**Answer**: Two approaches:

```c
// Method 1: Array of pointers (flexible row sizes)
int **arr = (int**)malloc(rows * sizeof(int*));
for(int i = 0; i < rows; i++)
    arr[i] = (int*)malloc(cols * sizeof(int));

// Method 2: Single allocation (contiguous)
int **arr = (int**)malloc(rows * sizeof(int*));
int *data = (int*)malloc(rows * cols * sizeof(int));
for(int i = 0; i < rows; i++)
    arr[i] = data + i * cols;
```

---

### Q7: What causes memory leaks with pointers?
**Answer**:
1. Allocating memory but forgetting to free
2. Losing pointer reference before freeing
3. Reallocating without freeing old memory
4. Not freeing in reverse allocation order

```c
// LEAK
int *arr = malloc(10 * sizeof(int));
arr = malloc(20 * sizeof(int));  // Lost first pointer!
free(arr);  // Only freed second allocation

// FIX
int *arr = malloc(10 * sizeof(int));
int *temp = malloc(20 * sizeof(int));
free(arr);
arr = temp;
free(arr);
```

---

### Q8: Explain the null pointer
**Answer**: A pointer with value NULL (or 0)
- Indicates pointer doesn't point to valid memory
- Always check before dereferencing
- Used as sentinel value

```c
int *ptr = NULL;
if(ptr != NULL) {
    *ptr = 10;  // Safe
}
```

---

### Q9: What's pointer arithmetic?
**Answer**: Moving pointer by adding/subtracting integers
- `ptr + n` moves by `n * sizeof(type)` bytes
- Very useful with arrays

```c
int arr[] = {10, 20, 30};
int *ptr = arr;
ptr++;  // Moves by sizeof(int), now points to 20
*(ptr) = 25;  // Changes 20 to 25
```

---

### Q10: How do you free a double-allocated 2D array?
**Answer**: **Reverse order of allocation**

```c
// Allocated as:
int **arr = malloc(rows * sizeof(int*));
for(...) arr[i] = malloc(cols * sizeof(int));

// Free as:
for(int i = 0; i < rows; i++) free(arr[i]);
free(arr);
```

---

### Q11: What's the purpose of `const` with pointers?
**Answer**: Three forms with different meanings:

```c
const int *ptr;      // Pointer to const int (can't modify *ptr)
int * const ptr;     // Const pointer to int (can't modify ptr)
const int * const ptr; // Const pointer to const int (can't modify either)
```

---

### Q12: Explain function pointers
**Answer**: Pointer to a function - allows dynamic function calls

```c
int (*func_ptr)(int, int) = &add;  // Pointer to function taking 2 ints
result = func_ptr(5, 3);           // Call via pointer

// Useful for callbacks, plugins, vtables
```

---

### Q13: What's a dangling pointer?
**Answer**: Pointer pointing to memory that's been freed

```c
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 10;  // DANGER! ptr points to freed memory
```

**Fix**: Set to NULL after freeing
```c
free(ptr);
ptr = NULL;
```

---

### Q14: How do you implement a simple linked list?
**Answer**: Use pointers to connect nodes

```c
typedef struct Node {
    int data;
    struct Node *next;  // Self-referential pointer
} Node;

// To insert at head, need pointer to pointer!
void insert_head(Node **head, int data) {
    Node *new = malloc(sizeof(Node));
    new->data = data;
    new->next = *head;
    *head = new;         // Modify the pointer in caller
}
```

---

### Q15: What's the `void*` pointer?
**Answer**: Generic pointer - can point to any type
- Loses type information
- Must be cast before dereferencing

```c
void *generic = malloc(100);
int *int_ptr = (int*)generic;
char *char_ptr = (char*)generic;

*int_ptr = 42;      // Safe after casting
```

---

## Common Mistakes

### ❌ Uninitialized Pointer
```c
int *ptr;
*ptr = 10;  // CRASH! ptr points to random address
```
✓ **Fix**: Initialize to NULL or allocate memory
```c
int *ptr = NULL;
ptr = malloc(sizeof(int));
*ptr = 10;
```

---

### ❌ Dereferencing NULL
```c
int *ptr = NULL;
printf("%d", *ptr);  // CRASH!
```
✓ **Fix**: Check before dereferencing
```c
if(ptr != NULL)
    printf("%d", *ptr);
```

---

### ❌ Using After Free
```c
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 10;  // DANGEROUS!
```
✓ **Fix**: Set to NULL after free
```c
free(ptr);
ptr = NULL;
```

---

### ❌ Double Free
```c
free(ptr);
free(ptr);  // CRASH!
```
✓ **Fix**: Check if allocated
```c
free(ptr);
ptr = NULL;  // Prevent double free
```

---

### ❌ Array Out of Bounds
```c
int arr[5];
arr[10] = 20;  // Buffer overflow!
```
✓ **Fix**: Always check bounds
```c
if(index >= 0 && index < size)
    arr[index] = 20;
```

---

### ❌ Forgetting Null Terminator
```c
char str[5];
strcpy(str, "Hello");  // str needs 6 chars ("Hello\0")
```
✓ **Fix**: Allocate enough space
```c
char str[6];
strcpy(str, "Hello");  // 5 + 1 for null terminator
```

---

### ❌ Comparing Pointers Incorrectly
```c
const char *str1 = "Hello";
const char *str2 = "Hello";
if(str1 == str2)  // WRONG! Compares addresses, not content
```
✓ **Fix**: Use strcmp
```c
if(strcmp(str1, str2) == 0)  // Compares content
```

---

### ❌ Losing Pointer in Loop
```c
int *ptr = malloc(100);
for(int i = 0; i < 10; i++) {
    ptr = malloc(50);  // LEAK! Lost previous allocation
}
```
✓ **Fix**: Use array or keep reference
```c
int *ptrs[10];
for(int i = 0; i < 10; i++) {
    ptrs[i] = malloc(50);
}
for(int i = 0; i < 10; i++) free(ptrs[i]);
```

---

### ❌ Modifying const Pointer
```c
const int *ptr = &x;
*ptr = 10;  // COMPILE ERROR! (Good!)

int * const ptr2 = &x;
ptr2 = &y;  // COMPILE ERROR! (Good!)
```

---

### ❌ Not Freeing in Reverse Order
```c
int **arr = malloc(rows * sizeof(int*));
for(int i = 0; i < rows; i++)
    arr[i] = malloc(cols * sizeof(int));

// WRONG:
free(arr);  // Freed array pointer before freeing rows!
for(int i = 0; i < rows; i++)
    free(arr[i]);  // CRASH! arr is invalid

// CORRECT:
for(int i = 0; i < rows; i++)
    free(arr[i]);
free(arr);
```

---

## Tips & Tricks

### 1. **Draw Memory Diagrams**
Before writing code, draw how memory is organized. Especially helpful for 2D/3D arrays and linked structures.

### 2. **Use Conventions**
```c
int *ptr;      // Pointer comes with type
int* ptr;      // vs pointer with the variable
```
Choose one style and stick with it.

### 3. **Allocate What You Need**
```c
int *ptr = malloc(10 * sizeof(int));  // ✓ Good
int *ptr = malloc(10 * sizeof(*ptr));  // ✓ Better (self-documenting)
int *ptr = malloc(10);  // ✗ Wrong (10 bytes, not 10 ints!)
```

### 4. **Check Allocation Success**
```c
int *ptr = malloc(sizeof(int));
if(ptr == NULL) {
    printf("Memory allocation failed\n");
    return -1;
}
```

### 5. **Use Address-of (&) Consistently**
```c
int x;
int *ptr = &x;       // ✓ Address of x

int *arr = malloc(10 * sizeof(int));
int **ptr_to_ptr = &arr;  // ✓ Address of ptr
```

### 6. **Remember Operator Precedence**
```c
*ptr.member      // ✗ Error: tries to dereference member
(*ptr).member    // ✓ Correct
ptr->member      // ✓ Shorthand (preferred)
```

### 7. **Use Valgrind to Detect Memory Leaks**
```bash
gcc -g -o program program.c
valgrind --leak-check=full ./program
```

### 8. **Function Pointers for Flexibility**
```c
typedef int (*compare_func)(const void*, const void*);

void sort_array(void *arr, int size, compare_func cmp) {
    // Generic sort using comparison function
}
```

### 9. **Avoid Pointer Tricks in Interview**
- Stick to clear, readable code
- Avoid XOR swap or other tricks unless asked
- Clarity > Cleverness

### 10. **Think About Edge Cases**
- NULL pointers
- Empty arrays
- Single element
- Large allocations (can fail!)
- Pointers to pointers (confusion)

---

## Practice Checklist

- [ ] Implement Problem 1-7 (basic pointers)
- [ ] Implement Problem 8-15 (intermediate)
- [ ] Implement Problem 16-22 (double pointers)
- [ ] Implement Problem 23-30 (triple pointers)
- [ ] Answer Q1-Q15 from memory
- [ ] Fix all common mistakes in code
- [ ] Run with Valgrind to check for leaks
- [ ] Explain each solution to someone else

---

## Compilation and Testing

```bash
# Compile with debugging symbols
gcc -g -o pointer_practice pointer_practice.c -Wall -Wextra

# Run
./pointer_practice

# Check for memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./pointer_practice

# Compile with address sanitizer
gcc -fsanitize=address -g -o pointer_practice pointer_practice.c
./pointer_practice
```

---

**Good luck with your interview! 💪**
