# Embedded C Operator Precedence Problems

## Table of Contents
1. [Practice Problems](#practice-problems)
2. [Embedded C Interview Questions](#embedded-c-interview-questions)

---

## Practice Problems

### 1) Expression Evaluation
Evaluate result and explain order:
```
int x = 5;
int y = 2;
int z = x + y * 3;
```

### 2) Unary vs Postfix
```
int a = 3;
int b = a++ + ++a;
```

### 3) Bitwise vs Logical
```
int r = 1 & 0 || 1;
```

### 4) Shift vs Add
```
int r = 1 << 2 + 1;
```

### 5) Dereference vs Increment
```
int *p = arr;
int v = *p++;
```

### 6) Ternary vs Assignment
```
int r = x > y ? x = 1 : y = 2;
```

### 7) Cast vs Dereference
```
int v = *(int*)ptr + 1;
```

### 8) AND vs Equality
```
if (a & b == 0) { ... }
```

### 9) Comma Operator
```
int r = (x = 1, y = 2, x + y);
```

### 10) sizeof with Unary
```
int r = sizeof *p + 1;
```

### 11) Bitwise Complement
```
int r = ~1 << 2;
```

### 12) Logical NOT with Comparison
```
if (!a == b) { ... }
```

### 13) Pointer Arithmetic
```
int *p = arr;
int v = *(p + 1) * 2;
```

### 14) Compound Assignment
```
x += y * z;
```

### 15) Function Pointer Call
```
int r = (*fp)(a, b) + 1;
```

---

## Embedded C Interview Questions
1. Why is `a & b == 0` a common bug?
2. What is the precedence of `*`, `++`, and `->`?
3. How does `&&` differ from `&` in evaluation?
4. What is sequence point and why it matters?
5. Explain `*p++` vs `(*p)++`.
6. Why prefer parentheses in bitwise expressions?
7. How does operator precedence affect register manipulation?
8. Is `x = y = z` safe? Explain.
9. What does `sizeof` evaluate at compile time?
10. How to avoid undefined behavior with increments?
11. Difference between `||` and `|`?
12. How does `?:` associate?
13. Why is `1 << 31` risky in C?
14. How does `volatile` affect expressions?
15. What is the precedence of `==` vs `&`?

---

**End of Operator Precedence Problems**