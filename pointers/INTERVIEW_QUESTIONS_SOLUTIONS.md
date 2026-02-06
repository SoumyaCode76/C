// ...existing code...

---

## Solutions (Coding Problems)

### Problem 1: Swap Two Integers Using Pointers
```c
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

### Problem 2: Find String Length Using Pointers
```c
int string_length(char *str)
{
    char *p = str;
    while (*p) p++;
    return (int)(p - str);
}
```

### Problem 3: Reverse Array In-Place Using Two Pointers
```c
void reverse_array(int *arr, int size)
{
    int *l = arr;
    int *r = arr + size - 1;
    while (l < r) {
        int t = *l;
        *l++ = *r;
        *r-- = t;
    }
}
```

### Problem 4: Allocate Dynamic 2D Array
```c
int** create_2d_array(int rows, int cols)
{
    int **a = (int**)malloc(rows * sizeof(int*));
    if (!a) return NULL;
    for (int i = 0; i < rows; i++) {
        a[i] = (int*)malloc(cols * sizeof(int));
        if (!a[i]) {
            for (int j = 0; j < i; j++) free(a[j]);
            free(a);
            return NULL;
        }
    }
    return a;
}

void free_2d_array(int **arr, int rows)
{
    for (int i = 0; i < rows; i++) free(arr[i]);
    free(arr);
}
```

### Problem 5: Remove Duplicates from Sorted Array
```c
int remove_duplicates(int *arr, int size)
{
    if (size == 0) return 0;
    int slow = 0;
    for (int fast = 1; fast < size; fast++) {
        if (arr[fast] != arr[slow]) {
            arr[++slow] = arr[fast];
        }
    }
    return slow + 1;
}
```

### Problem 6: Find Middle Element Using Slow-Fast Pointer
```c
int find_middle(int *arr, int size)
{
    int slow = 0, fast = 0;
    while (fast < size && fast + 1 < size) {
        slow++;
        fast += 2;
    }
    return arr[slow];
}
```

### Problem 7: Merge Two Sorted Arrays
```c
int* merge_sorted_arrays(int *a, int n, int *b, int m, int *out_n)
{
    *out_n = n + m;
    int *r = (int*)malloc((*out_n) * sizeof(int));
    if (!r) return NULL;
    int i=0,j=0,k=0;
    while (i<n && j<m) r[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i<n) r[k++] = a[i++];
    while (j<m) r[k++] = b[j++];
    return r;
}
```

### Problem 8: Pointer to Pointer - Modify String Pointer
```c
void change_string(char **str)
{
    const char *msg = "Updated";
    *str = (char*)malloc(strlen(msg) + 1);
    if (*str) strcpy(*str, msg);
}
```

### Problem 9: Function Pointer - Calculator
```c
void calculator_demo()
{
    operation_func ops[4] = {add, subtract, multiply, divide};
    int a = 8, b = 4;
    printf("%d %d %d %d\n", ops[0](a,b), ops[1](a,b), ops[2](a,b), ops[3](a,b));
}
```

### Problem 10: Deep Copy vs Shallow Copy
```c
Person* shallow_copy(Person *p)
{
    Person *c = (Person*)malloc(sizeof(Person));
    if (!c) return NULL;
    *c = *p;
    return c;
}

Person* deep_copy(Person *p)
{
    Person *c = (Person*)malloc(sizeof(Person));
    if (!c) return NULL;
    c->age = p->age;
    c->name = (char*)malloc(strlen(p->name) + 1);
    if (!c->name) { free(c); return NULL; }
    strcpy(c->name, p->name);
    return c;
}

void free_person(Person *p)
{
    if (!p) return;
    free(p->name);
    free(p);
}
```

### Problem 11: Generic Swap
```c
void generic_swap(void *a, void *b, size_t size)
{
    unsigned char *pa = a, *pb = b;
    while (size--) {
        unsigned char t = *pa;
        *pa++ = *pb;
        *pb++ = t;
    }
}
```

### Problem 12: Rotate Array Right by k
```c
static void rev(int *a, int l, int r)
{
    while (l < r) { int t=a[l]; a[l++]=a[r]; a[r--]=t; }
}

void rotate_array(int *arr, int size, int k)
{
    if (size == 0) return;
    k %= size;
    rev(arr, 0, size - 1);
    rev(arr, 0, k - 1);
    rev(arr, k, size - 1);
}
```

### Problem 13: Dynamic String Concatenation
```c
char* string_concat(const char *s1, const char *s2)
{
    size_t n1 = strlen(s1), n2 = strlen(s2);
    char *r = (char*)malloc(n1 + n2 + 1);
    if (!r) return NULL;
    memcpy(r, s1, n1);
    memcpy(r + n1, s2, n2 + 1);
    return r;
}
```

### Problem 14: Pointer to Array vs Array of Pointers
```c
void demonstrate_pointer_array_difference()
{
    int a[5] = {1,2,3,4,5};
    int (*p1)[5] = &a;     // pointer to array
    int *p2[5];            // array of pointers
    for (int i=0;i<5;i++) p2[i] = &a[i];
    printf("%d %d\n", (*p1)[0], *p2[0]);
}
```

### Problem 15: Memory Leak Fix
```c
void leaky_function()
{
    int *arr = (int*)malloc(10 * sizeof(int));
    if (!arr) return;
    int *tmp = (int*)realloc(arr, 20 * sizeof(int));
    if (!tmp) { free(arr); return; }
    arr = tmp;
    free(arr);
}
```

// ...existing code...

---

## Interview Q&A (Answers)

1. **Why use pointers to return multiple values?**  
   C passes by value; pointers let you modify caller memory.

2. **When use double pointers?**  
   To modify a pointer in a function or manage 2D arrays.

3. **Deep vs shallow copy?**  
   Shallow copies pointer addresses; deep allocates new memory and copies data.

4. **Pointer arithmetic increments by?**  
   Size of the pointed type (e.g., `int*` adds `sizeof(int)`).

5. **Dangling pointer?**  
   A pointer to freed memory; set to `NULL` after free.

6. **Why prefer `const char *`?**  
   Prevents accidental modification of string literals.

7. **`malloc` vs `calloc`?**  
   `calloc` zero-initializes, `malloc` does not.

8. **How to avoid memory leaks?**  
   Pair every allocation with a free, and clean up on error paths.

9. **Function pointers use case?**  
   Callback tables, state machines, ISR dispatch.

10. **Why `sizeof` on array differs in function?**  
    Array decays to pointer in function parameters.

11. **`*p++` vs `(*p)++`?**  
    `*p++` increments pointer; `(*p)++` increments value.

12. **Null pointer dereference?**  
    Undefined behavior; must check for `NULL`.

13. **Why use `volatile` with pointers?**  
    For memory-mapped I/O to prevent compiler optimization.

14. **How to allocate 2D array?**  
    Either row-by-row (jagged) or contiguous block.

15. **How to free 3D array?**  
    Free innermost arrays, then middle, then outer pointer.
