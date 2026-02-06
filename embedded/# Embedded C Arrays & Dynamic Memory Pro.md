# Embedded C Arrays & Dynamic Memory Problems

## Table of Contents
1. [Array Problems](#array-problems)
2. [Dynamic Memory Problems](#dynamic-memory-problems)
3. [Embedded C Interview Questions](#embedded-c-interview-questions)

---

## Array Problems
1. **Initialize Fixed Buffer**  
   Fill with zero using loop (no memset).
2. **Reverse Array In-Place**  
   Two-pointer method.
3. **Rotate Array**  
   Right/left by k steps.
4. **Find Max/Min**  
   Single pass.
5. **Move Zeros to End**  
   Preserve order.
6. **Remove Duplicates (Sorted)**  
   In-place.
7. **Merge Two Sorted Arrays**  
   Output to third buffer.
8. **Binary Search**  
   On sorted array.
9. **Find Missing Number**  
   1..N array.
10. **Second Largest Element**  
    Without sorting.
11. **Subarray Sum**  
    Fixed window size.
12. **Count Frequency**  
    For range-limited values.
13. **Array of Structs**  
    Sort by field.
14. **Static 2D Array**  
    Row/column traversal.
15. **Pointer Arithmetic**  
    Access array using pointers only.

---

## Dynamic Memory Problems
1. **Allocate 1D Array**  
   Use `malloc`, check for NULL.
2. **Allocate 2D Array (Contiguous)**  
   Single block + row pointers.
3. **Allocate 2D Array (Jagged)**  
   Row sizes differ.
4. **Reallocate Array**  
   Grow/shrink with `realloc`.
5. **Safe Realloc Pattern**  
   Use temp pointer.
6. **Deep Copy Struct**  
   With dynamic fields.
7. **Dynamic String Copy**  
   Allocate exact size.
8. **Create Buffer Pool**  
   Fixed blocks, manual free list.
9. **Memory Leak Fixing**  
   Identify lost pointers.
10. **Avoid Fragmentation**  
    Use pool allocator.
11. **Stack vs Heap Usage**  
    Decide by size/lifetime.
12. **Align Allocations**  
    Use `posix_memalign`.
13. **Dynamic Array of Strings**  
    `char**` allocation.
14. **Freeing Multi-Level Arrays**  
    Reverse order.
15. **Error Handling on Allocation Fail**  
    Roll back partial allocations.

---

## Embedded C Interview Questions
1. When should you avoid dynamic memory in embedded?
2. What are common causes of heap fragmentation?
3. How to safely use `realloc`?
4. What happens if `malloc` fails?
5. How to size stack and heap for a task?
6. Why is VLA risky in embedded?
7. How to implement a simple memory pool?
8. What is the difference between `calloc` and `malloc`?
9. How to detect memory leaks without OS tools?
10. How to ensure 2D array is contiguous?
11. What is the cost of pointer arithmetic vs index?
12. Why is `sizeof(arr)` different in function parameters?
13. How to pass arrays with size safely?
14. How to avoid buffer overflow?
15. When to use static allocation over dynamic?

---

**End of Arrays & Dynamic Memory Problems**