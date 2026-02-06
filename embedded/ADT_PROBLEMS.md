# Embedded C ADT Problems (Stack, Queue, Circular Queue, Linked Lists)

## Table of Contents
1. [Stack Problems](#stack-problems)
2. [Queue Problems](#queue-problems)
3. [Circular Queue Problems](#circular-queue-problems)
4. [Singly Linked List Problems](#singly-linked-list-problems)
5. [Doubly Linked List Problems](#doubly-linked-list-problems)
6. [Embedded C Interview Questions](#embedded-c-interview-questions)

---

## Stack Problems
1. **Fixed-Size Array Stack**  
   Implement `push`, `pop`, `peek`, `is_full`, `is_empty`. No dynamic allocation.
2. **Stack Overflow/Underflow Handling**  
   Return status codes; never crash.
3. **Min Stack**  
   Support `get_min()` in O(1) using two stacks.
4. **Reverse String Using Stack**  
   Use stack with fixed buffer.
5. **Balanced Parentheses**  
   Check `()[]{}` using stack.
6. **Stack via Linked List**  
   Implement `push/pop` with dynamic nodes.
7. **Postfix Expression Evaluation**  
   Evaluate integer postfix expression.
8. **Infix to Postfix Conversion**  
   Use operator precedence rules.
9. **Stack Memory Layout**  
   Show what happens to top pointer when pushing/popping.
10. **Stack in ISR-safe Mode**  
   Avoid dynamic allocation inside ISR.

---

## Queue Problems
1. **Fixed-Size Linear Queue**  
   Implement `enqueue`, `dequeue`, `front`, `rear`.
2. **Queue Overflow/Underflow**  
   Return error codes.
3. **Queue Using Two Stacks**  
   Implement enqueue/dequeue.
4. **Queue with Linked List**  
   Dynamic allocation, handle memory exhaustion.
5. **Circular Buffer Queue**  
   Compare with linear queue performance.
6. **Priority Queue (Simple)**  
   Insert in order; dequeue highest priority.
7. **Queue of Structures**  
   Enqueue/dequeue `struct` without memcpy bugs.
8. **Queue for UART RX**  
   Use ring buffer, no malloc.
9. **Multiple Producer/Consumer**  
   Discuss concurrency safety.
10. **Queue Length Tracking**  
   Maintain count safely.

---

## Circular Queue Problems
1. **Circular Queue with Modulo**  
   Implement wrap-around indexing.
2. **Full vs Empty Detection**  
   Using count vs one-empty-slot method.
3. **Overwrite-on-Full Mode**  
   Implement optional overwrite.
4. **Circular Queue of Bytes**  
   For UART/ADC streams.
5. **Peek N Elements**  
   Without dequeuing.
6. **Resize Circular Queue**  
   Reallocate and preserve order.
7. **Bulk Enqueue/Dequeue**  
   Use memcpy safely.
8. **Circular Queue Test Cases**  
   Edge cases: full, empty, wrap.

---

## Singly Linked List Problems
1. **Insert at Head/Tail**  
   Use pointer-to-pointer for head.
2. **Delete by Value**  
   Handle head deletion.
3. **Reverse Linked List**  
   Iterative and recursive.
4. **Detect Loop**  
   Floyd’s cycle detection.
5. **Find Middle**  
   Slow/fast pointers.
6. **Merge Two Sorted Lists**  
   Without extra nodes.
7. **Remove Duplicates**  
   From sorted list.
8. **Nth from End**  
   Two-pointer method.
9. **Split List**  
   Into two halves.
10. **List Memory Cleanup**  
   Free safely.

---

## Doubly Linked List Problems
1. **Insert at Head/Tail**  
   Update prev/next correctly.
2. **Delete Node**  
   Handle head/tail.
3. **Reverse List**  
   Swap prev/next.
4. **Insert After Node**  
   Update all links.
5. **Iterate Backwards**  
   From tail to head.
6. **LRU Cache (Simple)**  
   DLL + hashmap (conceptual).
7. **Sorted Insert**  
   Maintain sorted order.
8. **Merge Two DLLs**  
   In-place.
9. **Check Integrity**  
   Forward and backward traversal matches.
10. **Convert DLL to Circular DLL**  

---

## Embedded C Interview Questions
1. Why prefer circular queues in embedded systems?
2. How to avoid dynamic allocation in ISR?
3. What is the time complexity of push/pop in stack using array vs list?
4. How do you detect full vs empty in circular buffer?
5. What is the trade-off between one-empty-slot and count?
6. How to prevent memory leaks in linked lists?
7. Why can recursion be risky in embedded?
8. How to handle queue in multi-thread or ISR/main context?
9. What are typical error codes for ADT ops?
10. How do you test edge cases for stack/queue?
11. How to make linked list operations re-entrant?
12. Why is “malloc in loop” dangerous?
13. How to implement lock-free ring buffer?
14. How to handle node allocation failure?
15. What is the difference between stack memory and heap memory?

---

**End of ADT Problems**