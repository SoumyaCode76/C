# Struct, Union, and Memory Layout for Embedded C Interview

## Table of Contents
1. [Struct Problems](#struct-problems)
2. [Union Problems](#union-problems)
3. [Memory Layout & Alignment](#memory-layout--alignment)
4. [Size Calculation Without sizeof](#size-calculation-without-sizeof)
5. [Bit-Fields](#bit-fields)
6. [Interview Q&A](#interview-qa)
7. [Advanced Problems](#advanced-problems)
8. [Common Mistakes](#common-mistakes)
9. [Tips & Tricks](#tips--tricks)

---

## Struct Problems

### Problem 1: Basic Struct Definition and Access
**Goal**: Define struct and access members  
**Input**: Structure data  
**Output**: Demonstrate accessing members  

```c
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void problem_1() {
    // TODO: Create employee instance
    // TODO: Initialize all members
    // TODO: Print all members
    // Question: How much memory does Employee take?
}
```

**Key Points**:
- Struct groups related data
- Members stored sequentially in memory
- Can have padding between members

---

### Problem 2: Nested Structures
**Goal**: Use struct within struct  
**Input**: Nested data structure  
**Output**: Access nested members  

```c
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[50];
    Date joining_date;
} Employee;

void problem_2() {
    // TODO: Create employee with nested date
    // TODO: Access nested members: emp.joining_date.day
    // Question: Why is nesting useful?
}
```

**Memory Layout**:
```
Employee struct:
├── id (4 bytes)
├── name[50] (50 bytes)
└── Date joining_date (12 bytes if no padding)
Total: varies due to alignment
```

---

### Problem 3: Array of Structures
**Goal**: Work with multiple structures  
**Input**: Array of structs  
**Output**: Process array  

```c
typedef struct {
    int id;
    int age;
    float gpa;
} Student;

void problem_3() {
    // TODO: Create array of 10 students
    // TODO: Calculate average GPA
    // TODO: Find oldest student
    // Question: Memory layout of array?
}
```

**Common Task**: Sorting array of structs

---

### Problem 4: Struct Pointers
**Goal**: Use pointers with structs  
**Input**: Pointer to struct  
**Output**: Modify through pointer  

```c
typedef struct {
    int x;
    int y;
} Point;

void update_point(Point *p, int new_x, int new_y) {
    // TODO: Update point through pointer
    // Use (*p).x = new_x  OR  p->x = new_x
}

void problem_4() {
    // TODO: Create point on heap
    // TODO: Pass pointer to function
    // TODO: Verify changes
}
```

**Key Operators**:
- `(*p).member` - dereference then access
- `p->member` - arrow operator (preferred)

---

### Problem 5: Dynamic Struct Allocation
**Goal**: Allocate struct on heap  
**Input**: Struct data  
**Output**: Allocated structure  

```c
typedef struct {
    char *name;
    int age;
    char *email;
} Person;

Person* create_person(const char *name, int age, const char *email) {
    // TODO: Allocate Person struct
    // TODO: Allocate memory for name string
    // TODO: Allocate memory for email string
    // TODO: Copy data
    // Question: How many malloc calls needed?
}

void free_person(Person *p) {
    // TODO: Free name, email, then struct
    // Question: What order should we free?
}

void problem_5() {
    // TODO: Create persons dynamically
    // TODO: Work with them
    // TODO: Free properly
}
```

---

### Problem 6: Self-Referential Struct (Linked List)
**Goal**: Create struct that points to itself  
**Input**: Linked list data  
**Output**: Functional linked list  

```c
typedef struct Node {
    int data;
    struct Node *next;  // Self-referential
} Node;

void problem_6() {
    // TODO: Create linked list manually
    // Node 1 (data=10) → Node 2 (data=20) → Node 3 (data=30) → NULL
    // TODO: Traverse and print
    // TODO: Find node
    // TODO: Delete node
}
```

**Key Point**: Forward declaration needed for self-reference

---

### Problem 7: Struct in Array of Pointers
**Goal**: Create array of pointers to structs  
**Input**: Multiple struct instances  
**Output**: Array for generic access  

```c
typedef struct {
    int id;
    char name[30];
} Item;

void problem_7() {
    // TODO: Create array of pointers: Item *items[5]
    // TODO: Allocate each item
    // TODO: Initialize and use
    // TODO: Free all items
}
```

**Memory Layout**:
```
items[5]:        Stack
├── items[0] ──> Item (on heap)
├── items[1] ──> Item (on heap)
├── items[2] ──> Item (on heap)
├── items[3] ──> Item (on heap)
└── items[4] ──> Item (on heap)
```

---

### Problem 8: Typedef Struct vs Named Struct
**Goal**: Understand different declaration styles  
**Input**: Various struct declaration methods  
**Output**: Know which to use when  

```c
// Style 1: Named struct (old C style)
struct Employee {
    int id;
    char name[50];
};
struct Employee e1;

// Style 2: typedef struct (modern)
typedef struct {
    int id;
    char name[50];
} Employee;
Employee e2;

// Style 3: Named struct with typedef
typedef struct Employee {
    int id;
    char name[50];
} Employee;
Employee e3;

void problem_8() {
    // TODO: Demonstrate all three styles
    // Question: Which is preferred in embedded C?
}
```

**Best Practice**: Use typedef for cleaner code

---

### Problem 9: Struct Comparison
**Goal**: Compare entire structs  
**Input**: Two struct instances  
**Output**: Equality result  

```c
typedef struct {
    int x;
    int y;
} Point;

void problem_9() {
    // TODO: Compare point1 and point2
    // Method 1: Compare members individually
    if(p1.x == p2.x && p1.y == p2.y) { }
    
    // Method 2: memcmp (caution: padding bytes!)
    // TODO: Explain why memcmp might fail
}
```

**Pitfall**: memcmp includes padding bytes!

---

### Problem 10: Struct with Function Pointers
**Goal**: Use structs to implement vtables  
**Input**: Structure with function pointers  
**Output**: Polymorphic behavior  

```c
typedef struct {
    char name[30];
    int (*calculate_area)(int, int);  // Function pointer
    int (*calculate_perimeter)(int, int);
} Shape;

int rect_area(int l, int w) { return l * w; }
int rect_perimeter(int l, int w) { return 2 * (l + w); }

void problem_10() {
    // TODO: Create shape with function pointers
    Shape rect = {"Rectangle", rect_area, rect_perimeter};
    
    // TODO: Call through pointers
    int area = rect.calculate_area(5, 10);
}
```

---

## Union Problems

### Problem 11: Basic Union - Memory Sharing
**Goal**: Understand union memory sharing  
**Input**: Union with multiple types  
**Output**: Demonstrate shared memory  

```c
typedef union {
    int int_val;
    float float_val;
    char char_val;
} Data;

void problem_11() {
    Data d;
    
    // TODO: Assign to int_val
    // TODO: Observe what happens to other members
    // Question: Why all members change?
    
    // Demonstration:
    d.int_val = 0x12345678;
    printf("int: 0x%X\n", d.int_val);
    printf("float: %f\n", d.float_val);  // Garbage!
    printf("char: %d\n", d.char_val);    // Only LSB
}
```

**Key Concept**: All members share same memory address

---

### Problem 12: Union Size Calculation
**Goal**: Understand union size  
**Input**: Union with different members  
**Output**: Calculate size without sizeof  

```c
typedef union {
    int a;           // 4 bytes
    double b;        // 8 bytes
    char c;          // 1 byte
    short d;         // 2 bytes
} MyUnion;

void problem_12() {
    // TODO: Predict size
    // Size = size of largest member = 8 bytes
    
    // Without sizeof:
    MyUnion u1, u2;
    int size = (char*)&u2 - (char*)&u1;  // Pointer arithmetic
    printf("Union size: %d\n", size);
    
    // Or using array:
    MyUnion arr[2];
    size = (char*)&arr[1] - (char*)&arr[0];
}
```

---

### Problem 13: Union with Struct - Type Punning
**Goal**: Use union to interpret data differently  
**Input**: Raw data  
**Output**: Different interpretations  

```c
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

typedef union {
    int color;      // 32-bit color value
    RGB components; // RGB breakdown
} Color;

void problem_13() {
    Color c;
    c.color = 0xFF00FF;  // Magenta
    
    // TODO: Access as integer and RGB
    printf("Color: 0x%X\n", c.color);
    printf("R: %d, G: %d, B: %d\n", c.components.r, 
           c.components.g, c.components.b);
           
    // Question: Endianness issues?
}
```

---

### Problem 14: Union in Struct - Communication Protocol
**Goal**: Use union for different message types  
**Input**: Different message formats  
**Output**: Generic message container  

```c
typedef struct {
    int command;
    int data_int;
    float data_float;
    char data_char;
} Message_V1;  // Wastes space!

// Better approach:
typedef union {
    int int_data;
    float float_data;
    char char_data;
} PayloadData;

typedef struct {
    int command;
    int payload_type;  // 0=int, 1=float, 2=char
    PayloadData payload;
} Message_V2;  // Better!

void problem_14() {
    // TODO: Create messages with different payload types
    // Question: Why is second approach better?
}
```

---

### Problem 15: Serial Communication with Union
**Goal**: Read different data types from serial  
**Input**: Byte stream  
**Output**: Interpret as different types  

```c
typedef union {
    int integer_value;
    float float_value;
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
} SerialData;

void problem_15() {
    // Simulate receiving 4 bytes from serial
    unsigned char received[4] = {0x01, 0x02, 0x03, 0x04};
    
    SerialData data;
    // TODO: Copy bytes into union
    // memcpy(&data.bytes, received, 4);
    
    // TODO: Interpret as different types
    printf("As int: %d\n", data.integer_value);
    printf("As float: %f\n", data.float_value);
}
```

---

### Problem 16: Union Endianness Detection
**Goal**: Check system endianness  
**Input**: None  
**Output**: Print endianness  

```c
typedef union {
    int int_val;
    unsigned char bytes[sizeof(int)];
} EndianCheck;

void problem_16() {
    // TODO: Determine endianness using union
    EndianCheck check;
    check.int_val = 0x01020304;
    
    if(check.bytes[0] == 0x01) {
        printf("Big-endian\n");
    } else if(check.bytes[0] == 0x04) {
        printf("Little-endian\n");
    }
}
```

---

## Memory Layout & Alignment

### Problem 17: Struct Padding and Alignment
**Goal**: Understand automatic padding  
**Input**: Struct with different member sizes  
**Output**: Identify padding  

```c
typedef struct {
    char a;      // 1 byte, offset 0
    int b;       // 4 bytes, offset 4 (padded!)
    char c;      // 1 byte, offset 8
} PaddedStruct;

void problem_17() {
    // TODO: Calculate offsets of members
    // Method 1: Using address arithmetic
    PaddedStruct s;
    
    int offset_a = (char*)&s.a - (char*)&s;      // 0
    int offset_b = (char*)&s.b - (char*)&s;      // 4
    int offset_c = (char*)&s.c - (char*)&s;      // 8
    
    printf("Offset of a: %d\n", offset_a);
    printf("Offset of b: %d\n", offset_b);
    printf("Offset of c: %d\n", offset_c);
    
    // TODO: Calculate total size
}
```

**Padding Rules**:
- Struct alignment = alignment of largest member
- Members aligned to their own size or alignment requirement
- Padding added between members as needed

---

### Problem 18: Minimize Struct Size by Reordering
**Goal**: Reduce memory usage through member reordering  
**Input**: Inefficiently ordered struct  
**Output**: Optimized struct  

```c
// Inefficient arrangement
typedef struct {
    char a;      // 1 byte, offset 0
    int b;       // 4 bytes, offset 4
    char c;      // 1 byte, offset 8
    int d;       // 4 bytes, offset 12
} Bad;

// Optimized arrangement
typedef struct {
    int b;       // 4 bytes, offset 0
    int d;       // 4 bytes, offset 4
    char a;      // 1 byte, offset 8
    char c;      // 1 byte, offset 9
} Good;

void problem_18() {
    // TODO: Compare sizes of both structs
    // Bad: 16 bytes, Good: 12 bytes
    
    // Principle: Largest members first
}
```

---

### Problem 19: Packed Struct (No Padding)
**Goal**: Create struct without padding  
**Input**: Need exact memory layout  
**Output**: Packed structure  

```c
// Compiler-specific syntax!

// GCC/Clang
typedef struct __attribute__((packed)) {
    char a;
    int b;
    char c;
} PackedStruct;

// MSVC
#pragma pack(push, 1)
typedef struct {
    char a;
    int b;
    char c;
} PackedStruct;
#pragma pack(pop)

void problem_19() {
    // PackedStruct: 1 + 4 + 1 = 6 bytes (no padding)
    // Normal struct: 12 bytes (with padding)
    
    // Question: Why avoid packing?
    // Answer: Slower access, requires special handling
}
```

---

### Problem 20: Alignment Requirements
**Goal**: Understand alignment rules  
**Input**: Different data types  
**Output**: Calculate alignment needs  

```c
typedef struct {
    char a;          // Alignment: 1
    short b;         // Alignment: 2
    int c;           // Alignment: 4
    long long d;     // Alignment: 8
    float e;         // Alignment: 4
    double f;        // Alignment: 8
} AlignmentTest;

void problem_20() {
    // TODO: Calculate alignment of each member
    
    // Method: Use address arithmetic
    AlignmentTest t;
    
    printf("Offset of a: %d\n", (char*)&t.a - (char*)&t);
    printf("Offset of b: %d\n", (char*)&t.b - (char*)&t);
    printf("Offset of c: %d\n", (char*)&t.c - (char*)&t);
    // etc.
    
    printf("Total size: %d\n", 
        (char*)(&t+1) - (char*)(&t));
}
```

---

## Size Calculation Without sizeof

### Problem 21: Calculate Size Using Array Hack
**Goal**: Find size of type without sizeof  
**Input**: Any type  
**Output**: Size in bytes  

```c
void problem_21() {
    // Classic array hack
    int size = (char*)(&arr[1]) - (char*)(&arr[0]);
    
    // Example:
    typedef struct {
        int x;
        int y;
    } Point;
    
    Point arr[2];
    int point_size = (char*)(&arr[1]) - (char*)(&arr[0]);
    printf("Size of Point: %d\n", point_size);  // 8
}
```

---

### Problem 22: Calculate Member Offset
**Goal**: Find offset of struct member without sizeof  
**Input**: Struct type  
**Output**: Offset of specific member  

```c
typedef struct {
    int a;      // Offset 0
    int b;      // Offset 4
    char c;     // Offset 8
} MyStruct;

void problem_22() {
    // Method 1: Create instance and use addresses
    MyStruct s;
    int offset_b = (char*)&s.b - (char*)&s;
    int offset_c = (char*)&s.c - (char*)&s;
    
    printf("Offset of b: %d\n", offset_b);
    printf("Offset of c: %d\n", offset_c);
}
```

---

### Problem 23: Calculate Struct Size Using Null Pointer
**Goal**: Find struct size using compiler trick  
**Input**: Struct type  
**Output**: Size without sizeof  

```c
void problem_23() {
    // Clever trick using null pointer
    
    typedef struct {
        int a;
        int b;
        char c;
    } MyStruct;
    
    // Cast null pointer to struct pointer
    // Then access next element
    int size = (int)(&((MyStruct*)0)[1]);
    printf("Size of MyStruct: %d\n", size);
}
```

---

### Problem 24: Calculate Union Size
**Goal**: Find union size without sizeof  
**Input**: Union type  
**Output**: Size in bytes  

```c
void problem_24() {
    typedef union {
        int a;
        double b;
        char c;
    } MyUnion;
    
    // Create array to find size
    MyUnion arr[2];
    int size = (char*)&arr[1] - (char*)&arr[0];
    printf("Union size: %d\n", size);  // Size of largest member
}
```

---

### Problem 25: Estimate Size Without Creating Instance
**Goal**: Calculate size before runtime  
**Input**: Struct definition  
**Output**: Calculated size  

```c
void problem_25() {
    // Use offsetof-like calculations
    
    // For simple types:
    // int: 4 bytes
    // char: 1 byte
    // float: 4 bytes
    // double: 8 bytes
    
    // For struct with int, int, char:
    // int (4) + int (4) + char (1 + 3 padding) = 12 bytes
    
    // Alignment rules:
    // 1. Each type aligns to its size
    // 2. Struct aligns to its largest member
    // 3. Add padding as needed
}
```

---

## Bit-Fields

### Problem 26: Basic Bit-Field
**Goal**: Pack multiple members into single byte  
**Input**: Limited memory requirement  
**Output**: Bit-field struct  

```c
typedef struct {
    unsigned int flag1 : 1;    // 1 bit
    unsigned int flag2 : 1;    // 1 bit
    unsigned int flag3 : 1;    // 1 bit
    unsigned int value : 5;    // 5 bits (holds 0-31)
} BitFlags;

void problem_26() {
    BitFlags flags = {0};
    flags.flag1 = 1;
    flags.flag2 = 0;
    flags.flag3 = 1;
    flags.value = 15;
    
    // TODO: Print individual fields
    // Question: Size of BitFlags?
}
```

**Size**: Usually 4 bytes (can't be smaller than int on most systems)

---

### Problem 27: Bit-Field in Embedded Device Register
**Goal**: Map hardware register using bit-fields  
**Input**: Register layout  
**Output**: Struct representing register  

```c
// Hardware register layout:
// Bits 0-2: Mode (3 bits)
// Bits 3-4: Speed (2 bits)
// Bit 5: Enable (1 bit)
// Bits 6-7: Status (2 bits)

typedef struct {
    unsigned int mode : 3;
    unsigned int speed : 2;
    unsigned int enable : 1;
    unsigned int status : 2;
    unsigned int reserved : 0;  // Align to byte boundary
} DeviceControl;

void problem_27() {
    // TODO: Map hardware register
    volatile DeviceControl *reg = (DeviceControl*)0x40000000;
    
    // TODO: Read/write fields
    unsigned int current_mode = reg->mode;
    reg->enable = 1;
}
```

---

### Problem 28: Bit-Field Pitfalls and Issues
**Goal**: Understand bit-field limitations  
**Input**: Various bit-field scenarios  
**Output**: Identify problems  

```c
typedef struct {
    unsigned int a : 3;
    unsigned int b : 3;
} BitStruct;

void problem_28() {
    BitStruct bs;
    
    // Pitfall 1: Can't take address of bit-field
    // unsigned int *p = &bs.a;  // COMPILE ERROR!
    
    // Pitfall 2: Sign extension with signed types
    typedef struct {
        int a : 3;  // DANGEROUS! Could be signed
    } SignedBits;
    
    // Pitfall 3: Not portable across compilers
    // Bit order varies (int vs unsigned)
    // Alignment not guaranteed
    
    // Pitfall 4: Performance
    // Bit-fields require masking/shifting
    // Slower than byte operations
}
```

---

### Problem 29: Count Bits in Bit-Field
**Goal**: Pack maximum info in minimum space  
**Input**: Multiple flags and values  
**Output**: Optimized bit-field  

```c
// Inefficient (wastes memory)
typedef struct {
    char flag1;
    char flag2;
    char flag3;
    int mode;
} Inefficient;  // 7 bytes + padding = 12 bytes

// Optimized with bit-fields
typedef struct {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
    unsigned int flag3 : 1;
    unsigned int mode : 5;  // 2^5 = 32 modes
} Optimized;  // 4 bytes

void problem_29() {
    printf("Inefficient: %zu bytes\n", sizeof(Inefficient));
    printf("Optimized: %zu bytes\n", sizeof(Optimized));
}
```

---

### Problem 30: Network Packet Header with Bit-Fields
**Goal**: Model network packet header  
**Input**: Packet structure  
**Output**: Efficient header representation  

```c
// Network packet header
typedef struct {
    unsigned int version : 4;      // 0-15
    unsigned int ihl : 4;          // 0-15 (header length)
    unsigned int dscp : 6;         // 0-63 (differentiated services)
    unsigned int ecn : 2;          // 0-3 (explicit congestion notif)
    unsigned int total_length : 16; // 0-65535
    unsigned int identification : 16;
    unsigned int flags : 3;
    unsigned int fragment_offset : 13;
} IPv4Header;

void problem_30() {
    // TODO: Parse incoming packet
    unsigned char packet[20];
    
    // Note: Endianness and alignment very tricky!
    // Bit-fields usually NOT recommended for network protocols
    
    // Better: use bitmasks and bit operations
    unsigned char version = (packet[0] >> 4) & 0x0F;
    unsigned char ihl = packet[0] & 0x0F;
}
```

---

## Interview Q&A

### Q1: What's the difference between struct and union?
**Answer**:
```c
struct Student {
    int id;       // 4 bytes
    char grade;   // 1 byte
    float gpa;    // 4 bytes
};              // Total: 12 bytes (with padding)

union Value {
    int i;        // 4 bytes
    float f;      // 4 bytes
    char c;       // 1 byte
};              // Total: 4 bytes (largest member)
```

**Struct**: Members exist simultaneously, each has own memory
**Union**: Members share same memory space, only one at a time

---

### Q2: What's memory padding and why does it exist?
**Answer**: Processor expects data at addresses aligned to their size
```c
typedef struct {
    char a;      // Address: 0x0000
    // Padding: 0x0001, 0x0002, 0x0003
    int b;       // Address: 0x0004 (must be 4-byte aligned)
    char c;      // Address: 0x0008
} PaddedStruct;
```

**Why**:
- Some processors can't access unaligned memory
- Aligned access = faster performance
- Compiler adds padding automatically

---

### Q3: How do you calculate struct size without sizeof?
**Answer**:
```c
typedef struct {
    int x;
    char y;
} Point;

// Method 1: Array trick
Point arr[2];
int size = (char*)&arr[1] - (char*)&arr[0];

// Method 2: Null pointer trick
int size = (int)(&((Point*)0)[1]);

// Method 3: Casting and pointer arithmetic
int size = (char*)(&point + 1) - (char*)(&point);
```

---

### Q4: What's offsetof macro and how to implement it?
**Answer**:
```c
// Standard offsetof
#include <stddef.h>
size_t offset = offsetof(struct MyStruct, member);

// How it works (simplified):
#define MY_OFFSETOF(type, member) \
    ((char*)&((type*)0)->member - (char*)NULL)

typedef struct {
    int x;      // Offset: 0
    int y;      // Offset: 4
    char z;     // Offset: 8
} Point;

int offset_y = MY_OFFSETOF(Point, y);  // 4
```

---

### Q5: Why are union and struct sizes different?
**Answer**:
- **Struct**: Sum of all members + padding
- **Union**: Size of largest member + padding

```c
struct S {
    int a;      // 4 bytes
    int b;      // 4 bytes
    char c;     // 1 byte
};              // Size: 12 bytes (4+4+1+3 padding)

union U {
    int a;      // 4 bytes
    int b;      // 4 bytes
    char c;     // 1 byte
};              // Size: 4 bytes (only largest)
```

---

### Q6: What's type punning and when is it useful?
**Answer**: Interpreting same memory as different types
```c
float f = 3.14;
int i = *(int*)&f;  // Type punning!

// Better with union:
typedef union {
    float f;
    int i;
} FloatInt;

FloatInt fi;
fi.f = 3.14;
int bits = fi.i;  // Get bit representation
```

**Uses**:
- Hardware manipulation
- Protocol parsing
- Debugging bit patterns

---

### Q7: How to minimize struct size?
**Answer**: Reorder members by size (largest first)
```c
// Inefficient
struct Bad {
    char a;     // 1 byte, 0
    int b;      // 4 bytes, 4
    char c;     // 1 byte, 8
    int d;      // 4 bytes, 12
};               // Size: 16 bytes

// Optimized
struct Good {
    int b;      // 4 bytes, 0
    int d;      // 4 bytes, 4
    char a;     // 1 byte, 8
    char c;     // 1 byte, 9
};               // Size: 12 bytes
```

---

### Q8: What are bit-fields and what are their issues?
**Answer**: Allow packing multiple values into bits
```c
struct Flags {
    unsigned int busy : 1;
    unsigned int ready : 1;
    unsigned int error : 1;
};  // Uses 4 bytes for 3 bits!

// Issues:
// 1. Implementation-defined (not portable)
// 2. Can't take address: &flags.busy INVALID
// 3. Slightly slower than bytes
// 4. Bit order varies (compiler-dependent)
// 5. Can't use signed types reliably
```

---

### Q9: How to ensure fixed memory layout for hardware?
**Answer**: Use packed structs and explicit alignment
```c
// Hardware register at fixed address
typedef struct __attribute__((packed)) {
    unsigned char control;
    unsigned char status;
    unsigned short data;
} HardwareReg;

volatile HardwareReg *reg = (HardwareReg*)0x40000000;

// Or use #pragma pack
#pragma pack(push, 1)
typedef struct {
    unsigned char control;
    unsigned char status;
    unsigned short data;
} HardwareReg;
#pragma pack(pop)
```

---

### Q10: Explain alignment requirements for different types
**Answer**: Each type has alignment = sizeof(type) usually
```c
char:       1 byte alignment (any address)
short:      2 byte alignment (even addresses)
int:        4 byte alignment (4-byte aligned)
long:       4 or 8 bytes (depends on system)
long long:  8 byte alignment
float:      4 byte alignment
double:     8 byte alignment
pointer:    4 or 8 bytes (depends on 32/64-bit)
```

**Rule**: Struct alignment = alignment of largest member

---

### Q11: How to detect endianness using union?
**Answer**:
```c
typedef union {
    int int_val;
    unsigned char bytes[4];
} EndianTest;

void check_endianness() {
    EndianTest test = {0x01020304};
    
    if(test.bytes[0] == 0x01) {
        printf("Big-endian\n");    // MSB first
    } else {
        printf("Little-endian\n");  // LSB first
    }
}
```

---

### Q12: When to use typedef struct vs struct?
**Answer**: Always use typedef in modern C
```c
// Old style (avoid)
struct Employee {
    int id;
};
struct Employee emp;

// Modern style (preferred)
typedef struct {
    int id;
} Employee;
Employee emp;

// Best practice: Single typedef keyword
typedef struct Employee {
    int id;
} Employee;
```

---

### Q13: How does struct initialization work?
**Answer**:
```c
typedef struct {
    int x;
    int y;
    char *name;
} Point;

// Designated initializers (C99+)
Point p1 = {.x = 10, .y = 20, .name = "Origin"};

// Positional initialization
Point p2 = {10, 20, "Origin"};

// Partial initialization (rest = 0/NULL)
Point p3 = {10, 20};  // name = NULL

// All zeros
Point p4 = {0};
```

---

### Q14: Struct inside struct - memory layout?
**Answer**:
```c
typedef struct {
    int day;
    int month;
    int year;
} Date;  // 12 bytes

typedef struct {
    int id;         // 4 bytes, offset 0
    Date joinDate;  // 12 bytes, offset 4 (or 8?)
} Employee;

// Alignment matters:
// If Date needs 4-byte alignment, padding added after id
// Total might be 20 bytes, not 16
```

---

### Q15: What's the difference between offsetof and manual calculation?
**Answer**:
```c
#include <stddef.h>

struct S {
    int a;
    char b;
    int c;
};

// Using offsetof
size_t offset_c = offsetof(struct S, c);

// Manual calculation
struct S s;
size_t offset_c = (char*)&s.c - (char*)&s;

// offsetof is:
// - Compile-time constant
// - Works with incomplete types
// - More portable
// - Preferred in real code
```

---

## Advanced Problems

### Problem 31: Implement offsetof Macro
**Goal**: Create your own offsetof  
**Input**: Struct type and member  
**Output**: Offset value  

```c
#define MY_OFFSETOF(type, member) \
    ((size_t)&(((type *)0)->member))

typedef struct {
    int x;
    char y;
    float z;
} Point;

void problem_31() {
    printf("Offset of x: %zu\n", MY_OFFSETOF(Point, x));
    printf("Offset of y: %zu\n", MY_OFFSETOF(Point, y));
    printf("Offset of z: %zu\n", MY_OFFSETOF(Point, z));
}
```

---

### Problem 32: Flexible Array Member
**Goal**: Create struct with variable-length array  
**Input**: Data of unknown size  
**Output**: Struct with trailing array  

```c
typedef struct {
    int count;
    int data[];  // Flexible array member (C99)
} IntArray;

void problem_32() {
    // Allocate for 10 integers
    IntArray *arr = malloc(sizeof(IntArray) + 10 * sizeof(int));
    arr->count = 10;
    
    // TODO: Use array
    arr->data[0] = 100;
    arr->data[5] = 200;
    
    free(arr);
}
```

---

### Problem 33: Struct Copy with memcpy
**Goal**: Copy struct safely  
**Input**: Source and destination structs  
**Output**: Copied structure  

```c
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void problem_33() {
    Employee emp1 = {1, "John", 50000};
    Employee emp2;
    
    // Unsafe (what about pointers inside)?
    memcpy(&emp2, &emp1, sizeof(Employee));
    
    // Question: When is memcpy safe? When not?
    // Answer: Safe only if struct contains no pointers
}
```

---

### Problem 34: Struct in Binary Format
**Goal**: Write/read struct to binary file  
**Input**: Struct data  
**Output**: Binary file  

```c
typedef struct {
    int id;
    char name[32];
    float score;
} Student;

void problem_34() {
    Student s = {1, "John", 95.5};
    
    // Write to file
    FILE *f = fopen("students.bin", "wb");
    fwrite(&s, sizeof(s), 1, f);
    fclose(f);
    
    // Read from file
    f = fopen("students.bin", "rb");
    Student s2;
    fread(&s2, sizeof(s2), 1, f);
    fclose(f);
    
    // Question: Endianness issues?
    // Question: Portability concerns?
}
```

---

### Problem 35: Nested Unions
**Goal**: Union containing union  
**Input**: Hierarchical data  
**Output**: Nested union structure  

```c
typedef union {
    int time;
    struct {
        unsigned int hour : 5;
        unsigned int min : 6;
        unsigned int sec : 6;
    } hms;
} TimeValue;

typedef struct {
    int type;
    union {
        float temperature;
        TimeValue time;
        int pressure;
    } data;
} SensorData;

void problem_35() {
    SensorData s;
    s.type = 2;  // Time sensor
    s.data.time.hms.hour = 14;
    s.data.time.hms.min = 30;
}
```

---

## Common Mistakes

### ❌ Forgetting Struct Tag
```c
struct {      // No tag!
    int x;
    int y;
} point;

point2 = point;  // Can't declare another of this type
```
✓ **Fix**: Add struct name
```c
typedef struct Point {
    int x;
    int y;
} Point;

Point p1, p2;
```

---

### ❌ Accessing Uninitialized Struct
```c
typedef struct {
    int *ptr;
} MyStruct;

MyStruct s;
*s.ptr = 10;  // CRASH! ptr is uninitialized
```
✓ **Fix**: Initialize all members
```c
MyStruct s = {0};  // Zero-initialize
s.ptr = malloc(sizeof(int));
*s.ptr = 10;
```

---

### ❌ Assuming Fixed Size (Portability)
```c
typedef struct {
    char a;
    int b;
} MyStruct;

int size = 5;  // WRONG! Could be 8 on some systems
```
✓ **Fix**: Use actual size
```c
int size = sizeof(MyStruct);
// Or use offsetof and manual calculation
```

---

### ❌ Taking Address of Bit-Field
```c
typedef struct {
    int flag : 1;
} Flags;

Flags f;
int *p = &f.flag;  // COMPILE ERROR! Can't take address
```
✓ **Fix**: Use byte instead
```c
typedef struct {
    unsigned char flag;  // Use whole byte
} Flags;

Flags f;
unsigned char *p = &f.flag;  // OK
```

---

### ❌ Comparing Structs with memcmp
```c
struct S s1 = {10, 'a'};
struct S s2 = {10, 'a'};

if(memcmp(&s1, &s2, sizeof(struct S)) == 0) {  // WRONG!
    printf("Equal\n");
}
// Padding bytes might differ!
```
✓ **Fix**: Compare members individually
```c
if(s1.x == s2.x && s1.y == s2.y) {
    printf("Equal\n");
}
```

---

### ❌ Using sizeof on Type Instead of Variable
```c
typedef struct {
    int data[100];
} Buffer;

void send(Buffer *b, int size) {
    // size is from user, might be wrong
    char *p = malloc(size);
    memcpy(p, b, size);  // Might overflow!
}
```
✓ **Fix**: Use correct calculation
```c
if(size > sizeof(*b)) {
    printf("Size exceeds buffer\n");
    return;
}
memcpy(p, b, size);
```

---

### ❌ Pointer Arithmetic on Struct
```c
typedef struct {
    int x;
    int y;
} Point;

Point *p = ...;
p++;  // Moves by sizeof(Point), not 1 byte!
```
✓ **Fix**: Understand pointer arithmetic
```c
Point *p = ...;
p++;  // Correct - moves to next Point

char *c = (char*)p;
c++;  // Moves 1 byte
```

---

### ❌ Assuming Union Member Persistence
```c
union U {
    int i;
    float f;
};

U u;
u.i = 42;
printf("%d", u.f);  // GARBAGE! Not 42
```
✓ **Fix**: Only one member at a time
```c
u.i = 42;
int i_val = u.i;  // Use same member

u.f = 3.14;
float f_val = u.f;  // New member, old value lost
```

---

### ❌ Bit-Field Sign Extension
```c
typedef struct {
    int flag : 1;  // DANGEROUS!
} Bits;

Bits b;
b.flag = 1;
if(b.flag == -1) {  // Might be true! (Sign extended)
    printf("True\n");
}
```
✓ **Fix**: Use unsigned
```c
typedef struct {
    unsigned int flag : 1;  // Always 0 or 1
} Bits;
```

---

### ❌ Packing Struct Incorrectly
```c
#pragma pack(1)
typedef struct {
    int a;      // Unaligned access!
    int b;      // CPU might not support this
} Packed;
#pragma pack()

volatile Packed *reg = (Packed*)0x40000000;
reg->a = 10;  // Might crash on some CPUs
```
✓ **Fix**: Check hardware requirements
```c
// Or use bit manipulation instead
volatile int *base = (int*)0x40000000;
int a = (base[0] >> 0) & 0xFF;
int b = (base[0] >> 8) & 0xFF;
```

---

## Tips & Tricks

### 1. **Use typedef for faster coding**
```c
// In interviews, save typing
typedef struct {
    int x, y;
} Point;

// Instead of
struct Point {
    int x;
    int y;
};
struct Point p;
```

### 2. **Zero-initialize structs**
```c
MyStruct s = {0};  // All members = 0
// Much safer than uninitialized
```

### 3. **Check struct size**
```c
typedef struct {
    int a;
} MyStruct;

// Early check in code
_Static_assert(sizeof(MyStruct) == 4, "Unexpected size");
```

### 4. **Use designated initializers (C99+)**
```c
// Clear and order-independent
Point p = {.y = 20, .x = 10};

// vs positional
Point p = {10, 20};  // Easy to mess up
```

### 5. **Device register mapping**
```c
volatile HardwareReg *device = (HardwareReg*)0x40000000;
device->control = 1;  // Direct memory access
```

### 6. **Pointer to self for linked structures**
```c
typedef struct Node {
    int data;
    struct Node *next;  // Forward reference
    struct Node *prev;
} Node;
```

### 7. **Use unions for hardware abstraction**
```c
// Makes hardware code more readable
typedef union {
    uint32_t raw;
    struct {
        uint32_t enable : 1;
        uint32_t mode : 3;
        uint32_t reserved : 28;
    } bits;
} ControlReg;
```

### 8. **Calculate size at compile-time**
```c
enum {
    STRUCT_SIZE = sizeof(MyStruct),
    MEMBER_OFFSET = offsetof(MyStruct, member)
};

char buffer[STRUCT_SIZE];
```

### 9. **Use compiler attributes for alignment**
```c
// Align to 16-byte boundary
typedef struct __attribute__((aligned(16))) {
    int x;
} Aligned;
```

### 10. **Flexible array for variable data**
```c
typedef struct {
    int count;
    int items[];  // Variable-length
} IntList;

IntList *list = malloc(sizeof(*list) + count * sizeof(int));
```

---

## Compilation and Testing

```bash
# Compile with alignment warnings
gcc -Wall -Wpadded -o test test.c

# Check struct alignment
gcc -g -o test test.c
./test

# Use compiler warnings about packed structs
gcc -Wpacked -o test test.c

# Verify memory alignment
gcc -O2 -o test test.c
./test
```

---

## Practice Checklist

- [ ] Solve Problems 1-10 (Basic structs)
- [ ] Solve Problems 11-16 (Unions)
- [ ] Solve Problems 17-20 (Memory layout)
- [ ] Solve Problems 21-25 (Size calculation)
- [ ] Solve Problems 26-30 (Bit-fields)
- [ ] Solve Problems 31-35 (Advanced)
- [ ] Answer Q1-Q15 from memory
- [ ] Explain memory layout of structs
- [ ] Calculate alignment without tools
- [ ] Avoid all common mistakes
- [ ] Understand bit-field pitfalls
- [ ] Know union vs struct differences

---

## Interview Tips

1. **Ask clarifications**:
   - "Can I use sizeof?" (Test your knowledge)
   - "Need exact alignments?" (Packing concerns)
   - "Hardware register?" (Union vs struct)

2. **Show memory diagrams**:
   - Draw struct layout on whiteboard
   - Show padding and alignment
   - Explain why positioned that way

3. **Discuss tradeoffs**:
   - Size vs performance
   - Portability vs optimization
   - Clarity vs cleverness

4. **Test edge cases**:
   - Empty struct
   - Large struct
   - Nested structures
   - Unions with different types

5. **Know embedded context**:
   - Hardware register mapping
   - Memory-constrained systems
   - Bit-field limitations
   - Endianness concerns

---

**Good luck with your Embedded C interview! 🎯**
