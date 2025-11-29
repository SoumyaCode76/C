# Multithreading in C - Complete Learning Guide

## 📚 Study Plan (2 Days Before Interview)

### Day 1: Fundamentals & Core Concepts
**Morning Session (2-3 hours):**
1. ✅ **Lesson 1**: Basic Thread Creation (`01_basic_thread.c`)
2. ✅ **Lesson 2**: Multiple Threads (`02_multiple_threads.c`)
3. ✅ **Lesson 3**: Race Conditions (`03_race_condition.c`)
4. ✅ **Lesson 4**: Mutex Basics (`04_mutex_basics.c`)

**Afternoon Session (2-3 hours):**
5. ✅ **Lesson 5**: Producer-Consumer (`05_producer_consumer.c`)
6. ✅ **Lesson 6**: Deadlock Prevention (`06_deadlock_example.c`)

### Day 2: Advanced Patterns & Interview Prep
**Morning Session (2-3 hours):**
7. ✅ **Lesson 7**: Thread Pool (`07_thread_pool.c`)
8. ✅ **Lesson 8**: Interview Questions (`08_interview_questions.c`)

**Afternoon Session (2-3 hours):**
- Review all code
- Practice explaining concepts out loud
- Review quick reference below

---

## 🚀 Quick Start

### Compile Any Program:
```bash
cd /workspaces/C/multithreading
gcc -pthread <filename>.c -o <output_name>
./<output_name>
```

### Example:
```bash
gcc -pthread 01_basic_thread.c -o basic_thread
./basic_thread
```

---

## 🔑 Key Concepts Quick Reference

### 1. **pthread_create()**
```c
pthread_t thread_id;
pthread_create(&thread_id, NULL, function_name, argument);
```
- Creates a new thread
- Returns 0 on success

### 2. **pthread_join()**
```c
pthread_join(thread_id, NULL);
```
- Waits for thread to finish
- Blocking call

### 3. **Mutex (Mutual Exclusion)**
```c
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_lock(&mutex);    // Acquire lock
// Critical section here
pthread_mutex_unlock(&mutex);  // Release lock
```
- Protects shared data
- Only ONE thread can hold lock at a time

### 4. **Condition Variables**
```c
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_cond_wait(&cond, &mutex);    // Wait for signal
pthread_cond_signal(&cond);          // Wake one thread
pthread_cond_broadcast(&cond);       // Wake all threads
```
- Used for thread coordination
- Always use with mutex

### 5. **Common Patterns**
- **Producer-Consumer**: Bounded buffer with condition variables
- **Thread Pool**: Reusable worker threads with task queue
- **Read-Write Lock**: Multiple readers OR single writer
- **Barrier**: All threads must reach point before proceeding

---

## 💡 Interview Tips

### Questions You'll Likely Get:

1. **"Explain race condition"**
   - Multiple threads accessing shared data without sync
   - Can lead to incorrect results
   - Solution: Use mutex or other synchronization

2. **"What causes deadlock?"**
   - Thread A waits for lock held by Thread B
   - Thread B waits for lock held by Thread A
   - Prevention: Lock ordering, avoid nested locks

3. **"Mutex vs Semaphore?"**
   - Mutex: Binary (0 or 1), has ownership
   - Semaphore: Counting (0 to N), no ownership
   - Mutex for mutual exclusion, Semaphore for signaling

4. **"Why use thread pool?"**
   - Avoid thread creation overhead
   - Control resource usage
   - Better for many small tasks

5. **"Explain Producer-Consumer"**
   - Classic sync problem
   - Producer adds to buffer, Consumer removes
   - Use mutex + condition variables

### Coding Problems You Might Get:
- Print numbers in sequence with multiple threads → **Lesson 8, Problem 1**
- Implement thread-safe counter → **Lesson 4**
- Design producer-consumer → **Lesson 5**
- Detect/fix race condition → **Lesson 3**

---

## 📊 Lesson Overview

| Lesson | Topic | Key Concepts | Difficulty |
|--------|-------|--------------|------------|
| 1 | Basic Threads | pthread_create, pthread_join | ⭐ Easy |
| 2 | Multiple Threads | Array of threads, thread IDs | ⭐ Easy |
| 3 | Race Conditions | Shared data problems | ⭐⭐ Medium |
| 4 | Mutex Basics | pthread_mutex_lock/unlock | ⭐⭐ Medium |
| 5 | Producer-Consumer | Condition variables | ⭐⭐⭐ Hard |
| 6 | Deadlock | Detection & prevention | ⭐⭐⭐ Hard |
| 7 | Thread Pool | Real-world pattern | ⭐⭐⭐ Hard |
| 8 | Interview Qs | Common problems | ⭐⭐⭐ Hard |

---

## 🎯 Must-Know for Interview

### Critical Functions:
```c
pthread_create()        // Create thread
pthread_join()          // Wait for thread
pthread_mutex_init()    // Initialize mutex
pthread_mutex_lock()    // Lock mutex
pthread_mutex_unlock()  // Unlock mutex
pthread_cond_wait()     // Wait on condition
pthread_cond_signal()   // Signal condition
```

### Key Points to Remember:
1. ✅ Always pair lock with unlock
2. ✅ Use while (not if) with condition variables
3. ✅ Unlock mutex before long operations
4. ✅ Initialize mutexes before use
5. ✅ Join threads to prevent zombies
6. ✅ Check return values of pthread functions

---

## 🐛 Common Mistakes to Avoid

1. **Forgetting to unlock mutex** → Deadlock
2. **Not checking return values** → Hidden errors
3. **Using if instead of while** → Spurious wakeups
4. **Holding lock too long** → Poor performance
5. **Not initializing mutex** → Undefined behavior
6. **Race in passing arguments** → Use heap or wait

---

## 📝 Practice Exercise

Try implementing this without looking:
```
Problem: Create 3 threads that print "A", "B", "C" 
10 times in sequence (ABCABCABC...)
```

Hint: Use mutex + condition variable + turn counter

---

## 🔗 Compile All at Once

```bash
cd /workspaces/C/multithreading
for file in *.c; do
    gcc -pthread "$file" -o "${file%.c}"
done
```

---

## ✅ Pre-Interview Checklist

- [ ] Can explain race condition with example
- [ ] Can explain deadlock and how to prevent it
- [ ] Know difference between mutex and semaphore
- [ ] Can implement producer-consumer
- [ ] Understand condition variables
- [ ] Can explain thread pool benefits
- [ ] Know pthread_create and pthread_join
- [ ] Can write thread-safe code

---

## 📚 Additional Resources

### Man Pages:
```bash
man pthread_create
man pthread_mutex_lock
man pthread_cond_wait
```

### Compile with Warnings:
```bash
gcc -pthread -Wall -Wextra -g <file>.c -o <output>
```

---

## 🎓 Good Luck!

Remember:
- **Understand, don't memorize**
- **Run and modify the examples**
- **Explain concepts out loud**
- **Practice coding problems**

You've got this! 💪
