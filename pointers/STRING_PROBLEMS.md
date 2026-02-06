# String Problems for Embedded C Interview

## Table of Contents
1. [Basic String Problems](#basic-string-problems)
2. [String Manipulation](#string-manipulation)
3. [String Searching & Matching](#string-searching--matching)
4. [String Parsing & Conversion](#string-parsing--conversion)
5. [Embedded C String Problems](#embedded-c-string-problems)
6. [Advanced String Problems](#advanced-string-problems)
7. [Interview Q&A](#interview-qa)
8. [Common Mistakes](#common-mistakes)
9. [Tips & Tricks](#tips--tricks)

---

## Basic String Problems

### Problem 1: Implement strlen() - Find String Length
**Goal**: Calculate string length without using library function  
**Input**: `const char *str`  
**Output**: Length (not including null terminator)  
**Complexity**: O(n) time, O(1) space

```c
int string_length(const char *str)
{
    // TODO: Return length of string
    // Hint: Increment pointer until '\0'
}
```

**Test Cases**:
```
"" → 0
"Hello" → 5
"ABC123" → 6
```

---

### Problem 2: Implement strcpy() - String Copy
**Goal**: Copy one string to another  
**Input**: `char *dest`, `const char *src`  
**Output**: Destination string with source content  
**Important**: Include null terminator!

```c
char* string_copy(char *dest, const char *src)
{
    // TODO: Copy src to dest
    // Hint: Copy character by character until '\0'
    // Don't forget to copy null terminator!
    return dest;
}
```

**Common Issue**: Buffer overflow if dest is too small!

**Test Cases**:
```
src="Hello", dest has 6 chars → dest="Hello\0"
src="AB", dest has 10 chars → dest="AB\0"
```

---

### Problem 3: Implement strcmp() - String Comparison
**Goal**: Compare two strings  
**Input**: Two strings  
**Output**: 0 if equal, <0 if first < second, >0 if first > second  
**Complexity**: O(n)

```c
int string_compare(const char *str1, const char *str2)
{
    // TODO: Compare strings lexicographically
    // Return 0 (equal), -1 (str1<str2), 1 (str1>str2)
}
```

**Test Cases**:
```
"abc" vs "abc" → 0
"abc" vs "abd" → -1
"abd" vs "abc" → 1
"a" vs "abc" → -1
```

---

### Problem 4: Implement strcat() - String Concatenation
**Goal**: Append one string to another  
**Input**: `char *dest`, `const char *src`  
**Output**: Destination with src appended  

```c
char* string_concat(char *dest, const char *src)
{
    // TODO: Append src to end of dest
    // Hint: Find null terminator of dest first
    // Then copy src character by character
}
```

**Risk**: Buffer overflow! Need to verify dest has enough space

**Test Cases**:
```
dest="Hello", src=" World" → "Hello World"
dest="", src="Test" → "Test"
```

---

### Problem 5: Implement strrev() - Reverse String
**Goal**: Reverse a string in-place  
**Input**: `char *str`  
**Output**: Reversed string  
**Complexity**: O(n) time, O(1) space

```c
char* string_reverse(char *str)
{
    // TODO: Reverse string in-place
    // Hint: Use two pointers from start and end
}
```

**Test Cases**:
```
"hello" → "olleh"
"a" → "a"
"ab" → "ba"
```

---

### Problem 6: Check if String is Palindrome
**Goal**: Determine if string reads same forwards and backwards  
**Input**: `const char *str`  
**Output**: 1 if palindrome, 0 otherwise  
**Note**: Usually ignore case and spaces in interviews

```c
int is_palindrome(const char *str)
{
    // TODO: Check if string is palindrome
    // Simple: compare char from start with char from end
}
```

**Test Cases**:
```
"racecar" → 1
"hello" → 0
"a" → 1
"madam" → 1
```

---

### Problem 7: Find First Occurrence of Character
**Goal**: Find position of first occurrence  
**Input**: String and character to find  
**Output**: Position (or -1 if not found)  

```c
int find_char(const char *str, char ch)
{
    // TODO: Return index of first occurrence of ch
}
```

**Test Cases**:
```
"hello", 'l' → 2
"hello", 'z' → -1
"hello", 'h' → 0
```

---

### Problem 8: Count Occurrences of Character
**Goal**: Count how many times character appears  
**Input**: String and character  
**Output**: Count  

```c
int count_char(const char *str, char ch)
{
    // TODO: Count occurrences of ch in str
}
```

**Test Cases**:
```
"hello", 'l' → 2
"aaa", 'a' → 3
"hello", 'z' → 0
```

---

### Problem 9: Remove All Occurrences of Character
**Goal**: Remove character from string (in-place)  
**Input**: String and character to remove  
**Output**: Modified string  

```c
char* remove_char(char *str, char ch)
{
    // TODO: Remove all occurrences of ch
    // Move remaining characters forward
}
```

**Test Cases**:
```
"hello", 'l' → "heo"
"aaa", 'a' → ""
"test", 'z' → "test"
```

---

### Problem 10: Convert String to Integer (atoi clone)
**Goal**: Convert string to integer  
**Input**: String representation of number  
**Output**: Integer value  
**Complexity**: O(n)

```c
int string_to_int(const char *str)
{
    // TODO: Convert string to integer
    // Handle negative numbers: "-123" → -123
    // Handle leading spaces: "  123" → 123
    // For invalid: return 0 or error code
}
```

**Test Cases**:
```
"123" → 123
"-456" → -456
"  789" → 789
"0" → 0
"abc" → 0 (invalid)
```

---

## String Manipulation

### Problem 11: Remove Leading & Trailing Spaces (trim)
**Goal**: Remove whitespace from start and end  
**Input**: String  
**Output**: String without leading/trailing spaces  

```c
char* trim_string(char *str)
{
    // TODO: Remove leading and trailing spaces in-place
    // Hint: Find first non-space, last non-space
    // Move characters forward and add null terminator
}
```

**Test Cases**:
```
"  hello  " → "hello"
"test" → "test"
"   " → ""
```

---

### Problem 12: Convert String to Uppercase/Lowercase
**Goal**: Change case of all letters  
**Input**: String  
**Output**: Modified string  

```c
char* to_uppercase(char *str)
{
    // TODO: Convert to uppercase ('a' → 'A')
}

char* to_lowercase(char *str)
{
    // TODO: Convert to lowercase ('A' → 'a')
}
```

**Test Cases**:
```
"Hello World" → "HELLO WORLD"
"ABC123" → "abc123"
```

---

### Problem 13: Reverse Words in String
**Goal**: Reverse order of words  
**Input**: String with words separated by spaces  
**Output**: Reversed word order  

```c
char* reverse_words(char *str)
{
    // TODO: Reverse words
    // "Hello World Test" → "Test World Hello"
    // Challenge: Do it in-place!
}
```

**Test Cases**:
```
"Hello World" → "World Hello"
"one two three four" → "four three two one"
"a" → "a"
```

---

### Problem 14: Remove Duplicate Characters
**Goal**: Keep only first occurrence of each character  
**Input**: String  
**Output**: String with duplicates removed  

```c
char* remove_duplicates(char *str)
{
    // TODO: Remove duplicate characters
    // "hello" → "helo"
    // "aabbcc" → "abc"
}
```

**Test Cases**:
```
"hello" → "helo"
"aabbcc" → "abc"
"abcabc" → "abc"
```

---

### Problem 15: Replace All Occurrences of Substring
**Goal**: Replace substring with another  
**Input**: Original string, old substring, new substring  
**Output**: Modified string (dynamically allocated)  

```c
char* replace_substring(const char *str, const char *old, const char *new)
{
    // TODO: Replace all occurrences of old with new
    // Must allocate new string (original unchanged)
    // "hello world", "world", "test" → "hello test"
    return NULL;  // Return newly allocated string
}
```

**Test Cases**:
```
"hello world", "world", "test" → "hello test"
"aaa", "aa", "b" → "ba"
"test", "x", "y" → "test" (no change)
```

---

### Problem 16: Count Words in String
**Goal**: Count number of words  
**Input**: String  
**Output**: Word count  

```c
int count_words(const char *str)
{
    // TODO: Count words separated by spaces
    // Handle multiple spaces: "hello  world" → 2 words
}
```

**Test Cases**:
```
"hello world test" → 3
"  one   two  " → 2
"single" → 1
"" → 0
```

---

### Problem 17: Implement strstr() - Find Substring
**Goal**: Find position of substring  
**Input**: String and substring  
**Output**: Pointer to first occurrence (or NULL)  

```c
char* find_substring(const char *str, const char *substr)
{
    // TODO: Find first occurrence of substr
    // Return pointer to start of substring or NULL
}
```

**Test Cases**:
```
"hello world", "world" → pointer to 'w' (index 6)
"hello world", "xyz" → NULL
"aaaa", "aa" → pointer to first 'a'
```

---

### Problem 18: String Rotation Check
**Goal**: Check if string2 is rotation of string1  
**Input**: Two strings  
**Output**: 1 if rotation, 0 otherwise  
**Hint**: Use strstr on concatenation!

```c
int is_rotation(const char *str1, const char *str2)
{
    // TODO: Check if str2 is rotation of str1
    // "waterbottle" is rotation of "bottlewater"
    // Hint: Check lengths first
}
```

**Test Cases**:
```
"waterbottle", "bottlewater" → 1
"hello", "llohe" → 1
"hello", "world" → 0
```

---

### Problem 19: Implement strncat() - Safe String Concatenation
**Goal**: Append at most n characters  
**Input**: Destination, source, max characters  
**Output**: Modified destination  

```c
char* string_ncat(char *dest, const char *src, int n)
{
    // TODO: Concatenate at most n chars from src
    // Prevent buffer overflow
}
```

**Test Cases**:
```
dest="Hello", src=" World", n=3 → "Hello Wo"
```

---

### Problem 20: Compress String (Run-Length Encoding)
**Goal**: Compress consecutive characters  
**Input**: String  
**Output**: Compressed representation  

```c
char* compress_string(const char *str)
{
    // TODO: Compress using run-length encoding
    // "aaabba" → "a3b2a1"
    // Must allocate new string
    return NULL;
}
```

**Test Cases**:
```
"aaabba" → "a3b2a1"
"abcdef" → "a1b1c1d1e1f1"
"aaa" → "a3"
```

---

## String Searching & Matching

### Problem 21: Implement strpbrk() - Search for Any Character
**Goal**: Find first occurrence of any character from set  
**Input**: String and character set  
**Output**: Pointer to first match (or NULL)  

```c
char* find_first_of(const char *str, const char *chars)
{
    // TODO: Find first char in str that's in chars
    // "hello", "la" → pointer to 'l' (index 2)
}
```

**Test Cases**:
```
"hello", "la" → index 2 ('l')
"hello", "aei" → index 1 ('e')
"hello", "xyz" → NULL
```

---

### Problem 22: Pattern Matching - KMP Algorithm
**Goal**: Find pattern in text efficiently  
**Input**: Text and pattern  
**Output**: Index of first match (or -1)  
**Complexity**: O(n+m) vs O(n*m) for naive  

```c
int kmp_search(const char *text, const char *pattern)
{
    // TODO: Implement Knuth-Morris-Pratt algorithm
    // Build failure function for pattern
    // Search text using pattern
    return -1;  // Return index of first match or -1
}
```

**Test Cases**:
```
"ABABDABACDABABCABAB", "ABABCABAB" → 10
"hello world", "world" → 6
"test", "xyz" → -1
```

---

### Problem 23: Count Non-Overlapping Pattern Occurrences
**Goal**: Count pattern matches (non-overlapping)  
**Input**: String and pattern  
**Output**: Count  

```c
int count_pattern(const char *str, const char *pattern)
{
    // TODO: Count non-overlapping occurrences
    // "aaaa", "aa" → 2 (not 3!)
}
```

**Test Cases**:
```
"aaaa", "aa" → 2
"abcabc", "ab" → 2
"hello hello", "hello" → 2
```

---

### Problem 24: Anagram Check
**Goal**: Check if two strings are anagrams  
**Input**: Two strings  
**Output**: 1 if anagrams, 0 otherwise  
**Complexity**: O(n log n) or O(n) with hash

```c
int is_anagram(const char *str1, const char *str2)
{
    // TODO: Check if str1 and str2 are anagrams
    // Same characters, different order
    // "listen" and "silent" → 1
}
```

**Test Cases**:
```
"listen", "silent" → 1
"hello", "olleh" → 1
"hello", "world" → 0
```

---

### Problem 25: Longest Common Prefix
**Goal**: Find longest common prefix of multiple strings  
**Input**: Array of strings  
**Output**: Common prefix string  

```c
char* longest_common_prefix(char **strings, int count)
{
    // TODO: Find longest common prefix
    // ["flower", "flow", "flight"] → "fl"
    return NULL;  // Return newly allocated string
}
```

**Test Cases**:
```
["flower", "flow", "flight"] → "fl"
["dog", "racecar", "car"] → ""
["test"] → "test"
```

---

## String Parsing & Conversion

### Problem 26: Parse CSV Line
**Goal**: Parse comma-separated values  
**Input**: CSV string  
**Output**: Array of fields  

```c
char** parse_csv(const char *line, int *field_count)
{
    // TODO: Split by comma and return fields
    // Handle quoted fields: "a,\"b,c\",d" → ["a", "b,c", "d"]
    // Set field_count
    return NULL;  // Return array of strings
}
```

**Test Cases**:
```
"a,b,c" → ["a", "b", "c"], count=3
"name,age,city" → ["name", "age", "city"], count=3
```

---

### Problem 27: Convert String to IP Address
**Goal**: Parse dot-separated IP notation  
**Input**: String like "192.168.1.1"  
**Output**: Array of octets  

```c
int* parse_ip(const char *ip_str, int *valid)
{
    // TODO: Parse IP address
    // Validate: each octet 0-255
    // Return array of 4 integers
    // Set *valid = 1 if valid, 0 if invalid
    return NULL;
}
```

**Test Cases**:
```
"192.168.1.1" → [192, 168, 1, 1], valid=1
"256.1.1.1" → NULL, valid=0
"192.168.1" → NULL, valid=0
```

---

### Problem 28: Convert Number to Roman Numerals
**Goal**: Convert integer to Roman numeral string  
**Input**: Integer (1-3999)  
**Output**: Roman numeral string  

```c
char* int_to_roman(int num)
{
    // TODO: Convert number to Roman numerals
    // 1=I, 5=V, 10=X, 50=L, 100=C, 500=D, 1000=M
    // 1994 → "MCMXCIV"
    return NULL;  // Return newly allocated string
}
```

**Test Cases**:
```
1 → "I"
5 → "V"
1994 → "MCMXCIV"
3999 → "MMMCMXCIX"
```

---

### Problem 29: String Tokenization (strtok clone)
**Goal**: Split string by delimiter  
**Input**: String and delimiter  
**Output**: Array of tokens  

```c
char** tokenize_string(const char *str, const char *delim, int *token_count)
{
    // TODO: Split string by delimiter
    // Must allocate memory for tokens
    return NULL;
}
```

**Test Cases**:
```
"hello:world:test", ":" → ["hello", "world", "test"], count=3
"a,b,c,d", "," → ["a", "b", "c", "d"], count=4
```

---

### Problem 30: Validate Email Address
**Goal**: Basic email validation  
**Input**: Email string  
**Output**: 1 if valid, 0 if invalid  
**Note**: Simple pattern, not full RFC  

```c
int is_valid_email(const char *email)
{
    // TODO: Basic validation
    // Rules: must have @ and . (basic)
    // local@domain.extension
}
```

**Test Cases**:
```
"user@example.com" → 1
"invalid.email@" → 0
"no@domain" → 0
```

---

## Embedded C String Problems

### Problem 31: Fixed-Size String Buffer (No Dynamic Memory)
**Goal**: Work with fixed buffers (common in embedded)  
**Input**: Fixed-size char array  
**Output**: Modified string  

```c
// Embedded systems often can't use malloc!
#define MAX_STRING 64

void safe_string_copy(char dest[MAX_STRING], const char *src)
{
    // TODO: Copy src to dest safely
    // Don't exceed MAX_STRING
    // Always null-terminate
}

void safe_string_append(char str[MAX_STRING], const char *append)
{
    // TODO: Append to fixed-size buffer
    // Check remaining space!
}
```

**Key Points**:
- No dynamic allocation
- Always check buffer bounds
- Prevent buffer overflow

---

### Problem 32: snprintf - Safe Formatted String
**Goal**: Formatted string with size limit  
**Input**: Format string and values  
**Output**: Formatted result in fixed buffer  

```c
#define BUF_SIZE 128

void format_log_message(char buf[BUF_SIZE], const char *level, const char *msg)
{
    // TODO: Use snprintf for safe formatting
    // "[INFO] message here"
    // Make sure null terminator fits!
    int written = snprintf(buf, BUF_SIZE, "[%s] %s\n", level, msg);
}
```

**Better than sprintf** (no buffer overflow):
```c
sprintf(buf, "%s", data);      // Dangerous!
snprintf(buf, MAX_LEN, "%s", data);  // Safe
```

---

### Problem 33: Circular String Buffer (Ring Buffer)
**Goal**: Implement circular buffer for strings  
**Input**: String to add  
**Output**: Manage circular FIFO buffer  

```c
#define RING_SIZE 256

typedef struct {
    char buffer[RING_SIZE];
    int head;
    int tail;
    int count;
} RingBuffer;

void ring_buffer_init(RingBuffer *rb)
{
    // TODO: Initialize ring buffer
}

int ring_buffer_add(RingBuffer *rb, const char *str)
{
    // TODO: Add string to ring buffer
    // Return 1 if success, 0 if full
}

char* ring_buffer_get(RingBuffer *rb)
{
    // TODO: Get oldest string from ring buffer
    // Return pointer or NULL if empty
}
```

---

### Problem 34: Parse Command Line Arguments
**Goal**: Parse command-line input safely  
**Input**: Command string  
**Output**: Command and arguments  

```c
typedef struct {
    char command[32];
    char *args[10];
    int arg_count;
} Command;

int parse_command(const char *line, Command *cmd)
{
    // TODO: Parse "set temperature 25"
    // cmd->command = "set"
    // cmd->args = ["temperature", "25"]
    // Return 0 on success
}
```

---

### Problem 35: String to Hex Conversion
**Goal**: Convert bytes to hex string  
**Input**: Byte array  
**Output**: Hex string representation  

```c
char* bytes_to_hex(const uint8_t *data, int len)
{
    // TODO: Convert bytes to hex string
    // [0xAB, 0xCD, 0xEF] → "ABCDEF"
    return NULL;  // Return newly allocated string
}

int hex_string_to_bytes(const char *hex_str, uint8_t *data, int max_len)
{
    // TODO: Convert hex string to bytes
    // "ABCDEF" → [0xAB, 0xCD, 0xEF]
    // Return number of bytes converted
}
```

---

### Problem 36: CRC/Checksum on String
**Goal**: Calculate checksum for data validation  
**Input**: String  
**Output**: Checksum value  

```c
uint16_t calculate_crc16(const char *str)
{
    // TODO: Calculate CRC16 checksum
    // Used for data integrity in embedded systems
    return 0;
}

uint8_t calculate_checksum(const char *str)
{
    // TODO: Simple checksum (sum of bytes % 256)
}
```

---

### Problem 37: Case-Sensitive vs Case-Insensitive Compare
**Goal**: Compare strings with case handling  
**Input**: Two strings and case sensitivity flag  
**Output**: Comparison result  

```c
int safe_strcmp(const char *str1, const char *str2, int case_sensitive)
{
    // TODO: Compare with or without case sensitivity
    // case_sensitive = 1: "Hello" != "hello"
    // case_sensitive = 0: "Hello" == "hello"
}
```

---

### Problem 38: String to Enum Conversion
**Goal**: Parse string to enum value  
**Input**: String  
**Output**: Enum value  

```c
typedef enum {
    MODE_OFF = 0,
    MODE_IDLE = 1,
    MODE_ACTIVE = 2,
    MODE_ERROR = 3
} DeviceMode;

int string_to_mode(const char *str, DeviceMode *mode)
{
    // TODO: Convert "ACTIVE" → MODE_ACTIVE
    // "OFF" → MODE_OFF
    // Return 0 on success, -1 on error
}

const char* mode_to_string(DeviceMode mode)
{
    // TODO: Convert MODE_ACTIVE → "ACTIVE"
    return NULL;
}
```

---

### Problem 39: Format Bytes as Human-Readable Size
**Goal**: Convert bytes to KB/MB/GB  
**Input**: Number of bytes  
**Output**: Formatted string  

```c
char* format_bytes(uint64_t bytes)
{
    // TODO: Convert bytes to human-readable format
    // 1024 → "1.0 KB"
    // 1048576 → "1.0 MB"
    // 1099511627776 → "1.0 TB"
    return NULL;  // Return newly allocated string
}
```

---

### Problem 40: Escape Special Characters
**Goal**: Escape special characters in string  
**Input**: Raw string  
**Output**: Escaped string  

```c
char* escape_string(const char *str)
{
    // TODO: Escape special characters for display
    // "hello\nworld" → "hello\\nworld"
    // "tab\there" → "tab\\there"
    return NULL;  // Return newly allocated string
}
```

---

## Advanced String Problems

### Problem 41: Longest Palindromic Substring
**Goal**: Find longest substring that is palindrome  
**Input**: String  
**Output**: Palindromic substring  
**Complexity**: O(n²) naive, O(n) with Manacher's  

```c
char* longest_palindrome(const char *str)
{
    // TODO: Find longest palindromic substring
    // Approach 1: Expand around center O(n²)
    // Approach 2: Manacher's algorithm O(n)
    return NULL;
}
```

**Test Cases**:
```
"babad" → "bab" or "aba"
"cbbd" → "bb"
"racecar" → "racecar"
```

---

### Problem 42: Regular Expression Matching (Simple)
**Goal**: Match string against simple pattern  
**Input**: String and pattern (with * and .)  
**Output**: 1 if matches, 0 otherwise  

```c
int match_pattern(const char *str, const char *pattern)
{
    // TODO: Simple pattern matching
    // '.' matches any single character
    // '*' matches zero or more of previous character
    // "*a*b*" matches "aab", "b", "aaab"
}
```

---

### Problem 43: Text Justification
**Goal**: Format text with even spacing  
**Input**: Array of words, max width  
**Output**: Justified lines  

```c
char** justify_text(char **words, int count, int width)
{
    // TODO: Justify text to given width
    // Distribute spaces evenly
    // "This is an example" with width=16
    // "This    is    an"
    // "example"
    return NULL;
}
```

---

### Problem 44: Longest Substring Without Repeating Characters
**Goal**: Find longest substring with unique chars  
**Input**: String  
**Output**: Length  
**Complexity**: O(n) with sliding window  

```c
int longest_unique_substring(const char *str)
{
    // TODO: Find longest substring without repeating
    // "abcabcbb" → 3 ("abc")
    // "bbbbb" → 1 ("b")
    // "pwwkew" → 3 ("wke")
}
```

---

### Problem 45: Word Ladder (Graph Problem)
**Goal**: Find shortest path between words  
**Input**: Start word, end word, dictionary  
**Output**: Sequence of words (each differs by 1 char)  

```c
char** find_word_ladder(const char *start, const char *end, char **dictionary, int dict_size)
{
    // TODO: Find path where each step changes 1 letter
    // "hit" → "hot" → "dot" → "dog" → "lot" → "log" → "cog"
    return NULL;
}
```

---

## Interview Q&A

### Q1: What's the difference between char *str and char str[]?
**Answer**:
```c
char *str = "hello";       // Pointer to string literal (read-only)
char str[] = {'h','e','l','l','o','\0'};  // Array (can modify)
char str[] = "hello";      // Array initialized with string (can modify)
```

**Key Difference**:
- `char *str`: Pointer, points to string literal (may be in read-only memory)
- `char str[]`: Array, modifiable, can change characters

---

### Q2: What's string.h and why use library functions?
**Answer**:
```c
#include <string.h>

strlen(str);           // Get length
strcpy(dest, src);     // Copy (UNSAFE - can overflow)
strncpy(dest, src, n); // Safe copy with max chars
strcmp(str1, str2);    // Compare
strcat(str1, str2);    // Concatenate (UNSAFE)
strncat(str1, str2, n); // Safe concatenate
strchr(str, ch);       // Find character
strstr(str, substr);   // Find substring
strtok(str, delim);    // Tokenize
```

**Embedded C**: Sometimes can't use standard library!

---

### Q3: Why is strcpy() dangerous?
**Answer**: No bounds checking - can overflow buffer!

```c
char buffer[5];
strcpy(buffer, "Hello World");  // CRASH! "Hello World" is 12 chars
```

**Safe alternatives**:
```c
strncpy(buffer, "Hello World", 4);  // Max 4 chars
buffer[4] = '\0';                   // Ensure null terminator

// or better, use snprintf
snprintf(buffer, sizeof(buffer), "%s", "Hello World");
```

---

### Q4: How to avoid buffer overflow?
**Answer**:
1. **Always know buffer size**
   ```c
   char buf[100];
   ```

2. **Use size-limited functions**
   ```c
   strncpy(buf, src, sizeof(buf)-1);
   buf[sizeof(buf)-1] = '\0';
   ```

3. **Use snprintf instead of sprintf**
   ```c
   snprintf(buf, sizeof(buf), "%s", data);
   ```

4. **Check length before copying**
   ```c
   if(strlen(src) < sizeof(buf)) {
       strcpy(buf, src);
   }
   ```

---

### Q5: What's the null terminator and why important?
**Answer**: `'\0'` marks end of string
- Every string MUST end with `'\0'`
- Functions like `strlen` depend on it
- Forgot to null-terminate = undefined behavior

```c
char str[6];
str[0] = 'H';
str[1] = 'e';
str[2] = 'l';
str[3] = 'l';
str[4] = 'o';
str[5] = '\0';  // CRITICAL!

strlen(str);     // Looks for '\0' to find length
```

---

### Q6: What's the difference between string literals and char arrays?
**Answer**:
```c
const char *ptr = "hello";    // String literal, read-only (in ROM in embedded)
char arr[] = "hello";         // Char array (read-write, in RAM)
```

**String Literal**:
- Stored in read-only memory
- Can't modify: `ptr[0] = 'H'` → CRASH!
- Shared by multiple pointers (compiler optimization)

**Char Array**:
- Stored in writable memory (stack or heap)
- Can modify: `arr[0] = 'H'` → OK
- Own separate copy

---

### Q7: How does strtok() work and what are its pitfalls?
**Answer**:
```c
char str[] = "apple,banana,cherry";
char *token = strtok(str, ",");

while(token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, ",");  // NULL = continue with last string
}
```

**Problems**:
1. **Modifies original string** (replaces delimiters with '\0')
2. **Not thread-safe** (static internal pointer)
3. **Can't parse multiple strings** (overwrites state)

**Better alternatives**:
```c
// Manual parsing with strchr
char *pos = str;
while(*pos) {
    char *end = strchr(pos, ',');
    if(end) {
        // Process substring from pos to end
        pos = end + 1;
    } else {
        break;
    }
}
```

---

### Q8: When to use dynamic string allocation?
**Answer**: Use malloc/calloc when:
1. **Size known at runtime**
   ```c
   int len = get_string_length_from_user();
   char *str = malloc(len + 1);  // +1 for null terminator
   ```

2. **Returning string from function**
   ```c
   char* concatenate(const char *a, const char *b) {
       char *result = malloc(strlen(a) + strlen(b) + 1);
       strcpy(result, a);
       strcat(result, b);
       return result;  // Caller must free!
   }
   ```

3. **Resizable strings**
   ```c
   char *str = malloc(100);
   // ... later need more space
   str = realloc(str, 200);
   ```

---

### Q9: How to safely pass strings to functions?
**Answer**:
```c
// Function 1: Pass const pointer (read-only)
void print_string(const char *str) {
    printf("%s\n", str);
    // str[0] = 'X';  // Compile error! Good!
}

// Function 2: Modify string (must pass buffer + size)
void uppercase_string(char *str, int max_len) {
    for(int i = 0; i < max_len && str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Function 3: Return string from function
char* allocate_string(const char *initial) {
    char *str = malloc(strlen(initial) + 1);
    strcpy(str, initial);
    return str;  // Caller must free!
}
```

---

### Q10: Embedded C - How to handle strings without malloc?
**Answer**: Use fixed-size buffers

```c
#define MAX_CMD_LEN 64
#define MAX_RESPONSE 256

typedef struct {
    char command[MAX_CMD_LEN];
    char response[MAX_RESPONSE];
    int response_len;
} Message;

void process_message(Message *msg) {
    // Always check bounds!
    if(strlen(msg->command) < MAX_CMD_LEN) {
        // Safe to use
    }
}

void safe_copy(char *dest, int dest_size, const char *src) {
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}
```

---

### Q11: What's string interning and when useful?
**Answer**: Storing only one copy of each unique string

```c
// Without interning: many copies of "hello"
char *a = "hello";
char *b = "hello";
printf("%p %p\n", a, b);  // May be same address (interned)

// Useful for:
// 1. Large numbers of duplicate strings
// 2. Fast comparison (pointer equality)
// 3. Memory efficiency

typedef struct {
    char *strings[1000];
    int count;
} StringPool;
```

---

### Q12: How to implement case-insensitive string comparison?
**Answer**:
```c
#include <ctype.h>

int strcasecmp(const char *str1, const char *str2) {
    while(*str1 && *str2) {
        if(tolower(*str1) != tolower(*str2))
            return tolower(*str1) - tolower(*str2);
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// Test
if(strcasecmp("Hello", "hello") == 0) {
    printf("Equal (case-insensitive)\n");
}
```

---

### Q13: What's Unicode vs ASCII in C strings?
**Answer**:
- **ASCII**: 7-bit (0-127), fits in `char`
- **Unicode**: Multiple encodings (UTF-8, UTF-16, etc.)

```c
char ascii[] = "hello";        // ASCII OK
char *utf8 = "你好";           // UTF-8 works (multi-byte)

// Be careful with strlen on UTF-8!
const char *emoji = "😀";      // 4 bytes in UTF-8
int len = strlen(emoji);       // Returns 4, but 1 character!
```

---

### Q14: How to parse CSV safely?
**Answer**:
```c
typedef struct {
    char field[100];
} Field;

int parse_csv_line(const char *line, Field *fields, int max_fields) {
    int field_count = 0;
    const char *start = line;
    
    while(field_count < max_fields && *start) {
        const char *end = start;
        int in_quotes = 0;
        
        while(*end && (*end != ',' || in_quotes)) {
            if(*end == '"') in_quotes = !in_quotes;
            end++;
        }
        
        int len = end - start;
        if(len >= sizeof(fields[0].field)) len = sizeof(fields[0].field) - 1;
        
        strncpy(fields[field_count].field, start, len);
        fields[field_count].field[len] = '\0';
        
        field_count++;
        start = *end == ',' ? end + 1 : end;
    }
    
    return field_count;
}
```

---

### Q15: Memory efficient string handling tips?
**Answer**:
1. **Use string literals for constants**
   ```c
   const char *VERSION = "1.0.0";  // No allocation
   ```

2. **Avoid unnecessary copies**
   ```c
   // Bad
   char temp[100];
   strcpy(temp, source);
   process(temp);
   
   // Good
   process(source);
   ```

3. **Use stack allocation for small strings**
   ```c
   char buf[256];  // Stack, fast
   // vs
   char *buf = malloc(256);  // Heap, slower
   ```

4. **Pre-allocate if size known**
   ```c
   int total_len = strlen(a) + strlen(b);
   char *result = malloc(total_len + 1);
   ```

5. **Pool allocator for many small strings**
   ```c
   typedef struct {
       char data[10000];
       int offset;
   } StringPool;
   ```

---

## Common Mistakes

### ❌ Forgetting Null Terminator
```c
char str[5];
str[0] = 'H'; str[1] = 'i';
// Missing str[2] = '\0'
printf("%s\n", str);  // Reads garbage!
```
✓ **Fix**: Always terminate
```c
char str[5] = {0};  // Initialize to zeros
```

---

### ❌ Buffer Overflow on strcpy
```c
char buf[5];
strcpy(buf, "Hello World");  // "Hello World" has 12 chars!
```
✓ **Fix**: Use size-limited function
```c
strncpy(buf, "Hello World", sizeof(buf)-1);
buf[sizeof(buf)-1] = '\0';
```

---

### ❌ String Literal Modification
```c
char *str = "hello";
str[0] = 'H';  // CRASH! String literal is read-only
```
✓ **Fix**: Use array instead
```c
char str[] = "hello";  // Modifiable copy
str[0] = 'H';
```

---

### ❌ Comparing String Pointers Instead of Content
```c
char *a = "hello";
char *b = "hello";
if(a == b) {  // WRONG! May not be equal even if content is
    printf("Equal\n");
}
```
✓ **Fix**: Use strcmp
```c
if(strcmp(a, b) == 0) {
    printf("Equal\n");
}
```

---

### ❌ Memory Leak with malloc
```c
char *str = malloc(100);
str = "new value";  // LEAK! Lost malloc'd pointer
// Original block never freed
```
✓ **Fix**: Track allocations
```c
free(str);
str = malloc(strlen("new value") + 1);
strcpy(str, "new value");
```

---

### ❌ Using strlen on Non-Terminated String
```c
char str[5];
str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
// Missing null terminator
int len = strlen(str);  // Reads past array! Undefined behavior
```
✓ **Fix**: Ensure null termination
```c
char str[5] = {0};  // Initialize all to 0
str[0] = 'a'; str[1] = 'b'; str[2] = 'c';  // str[3] = '\0'
```

---

### ❌ strtok Destroying Original
```c
const char *original = "apple,banana,cherry";
// Can't do: strtok(original, ",");
// strtok modifies the string!
```
✓ **Fix**: Copy first
```c
char copy[100];
strcpy(copy, original);
strtok(copy, ",");  // Now safe
```

---

### ❌ Off-by-One Error
```c
char buf[10];
strncpy(buf, "Hello World", 10);  // Exactly 10 chars
// No null terminator! buf[9] might be 'd'
```
✓ **Fix**: Leave room for null
```c
strncpy(buf, "Hello World", sizeof(buf)-1);
buf[sizeof(buf)-1] = '\0';
```

---

### ❌ Modifying Const Pointer
```c
const char *str = "hello";
strcpy(str, "world");  // COMPILE ERROR (Good!)
// But sometimes cast away const...
char *ptr = (char*)str;
strcpy(ptr, "world");  // CRASH at runtime!
```
✓ **Fix**: Don't cast away const
```c
const char *original = "hello";
char *copy = malloc(strlen(original) + 1);
strcpy(copy, original);
// Modify copy, not original
```

---

### ❌ Returning Pointer to Local Variable
```c
char* get_string() {
    char local[] = "hello";
    return local;  // WRONG! local dies when function returns
}
```
✓ **Fix**: Use malloc or static
```c
char* get_string() {
    char *str = malloc(6);
    strcpy(str, "hello");
    return str;  // Caller must free!
}

// or for constants
const char* get_version() {
    return "1.0.0";  // String literal, always valid
}
```

---

### ❌ Assuming String Always Has Char
```c
char *str = get_user_input();
if(str[0] == 'a') {  // What if str is NULL or empty?
    // ...
}
```
✓ **Fix**: Always validate
```c
if(str != NULL && str[0] != '\0' && str[0] == 'a') {
    // Safe
}
```

---

## Tips & Tricks

### 1. **Use `sizeof(array)` for static buffers**
```c
char buf[256];
strncpy(buf, source, sizeof(buf)-1);  // Self-documenting
```

### 2. **Initialize strings to all zeros**
```c
char buf[100] = {0};  // All bytes = '\0'
// or
char buf[100];
memset(buf, 0, sizeof(buf));
```

### 3. **Know common character classification**
```c
#include <ctype.h>

isalpha(c)    // Is letter
isdigit(c)    // Is digit
isalnum(c)    // Is letter or digit
isspace(c)    // Is whitespace
isupper(c)    // Is uppercase
islower(c)    // Is lowercase
```

### 4. **String length optimization**
```c
// Cache length if using multiple times
const char *str = "hello";
int len = strlen(str);
for(int i = 0; i < len; i++) {  // len already computed
    // ...
}
```

### 5. **Combine conditions**
```c
// Check null and dereference safely
if(str && str[0] == 'h') {
    // str is not NULL and first char is 'h'
}
```

### 6. **Use memcpy for binary data**
```c
// For non-text data
memcpy(dest, src, size);

// For strings with null terminators
strcpy(dest, src);
```

### 7. **Embedded: Use static allocation**
```c
// Embedded systems often avoid dynamic allocation
#define BUFFER_SIZE 256
static char buffer[BUFFER_SIZE];

void init() {
    memset(buffer, 0, sizeof(buffer));
}
```

### 8. **Use const for read-only strings**
```c
const char *get_error_message(int code) {
    static const char *messages[] = {
        "No error",
        "Invalid input",
        "Not found"
    };
    if(code >= 0 && code < 3) {
        return messages[code];
    }
    return "Unknown error";
}
```

### 9. **String literals are shared**
```c
const char *a = "hello";
const char *b = "hello";
// a == b is likely true (compiler optimization)
```

### 10. **Use snprintf for safety**
```c
char buf[100];
// Instead of: sprintf(buf, "%d %s", num, str);
snprintf(buf, sizeof(buf), "%d %s", num, str);  // Bounded!
```

---

## Compilation and Testing

```bash
# Compile with warnings
gcc -Wall -Wextra -o string_practice string_practice.c

# Compile with debugging
gcc -g -Wall -Wextra -o string_practice string_practice.c

# Check memory with Valgrind
valgrind --leak-check=full ./string_practice

# Compile with address sanitizer
gcc -fsanitize=address -g -o string_practice string_practice.c
./string_practice
```

---

## Practice Checklist

- [ ] Implement Problems 1-10 (Basic)
- [ ] Implement Problems 11-20 (Manipulation)
- [ ] Implement Problems 21-25 (Searching)
- [ ] Implement Problems 26-30 (Parsing)
- [ ] Implement Problems 31-40 (Embedded C)
- [ ] Implement Problems 41-45 (Advanced)
- [ ] Answer Q1-Q15 from memory
- [ ] Avoid all common mistakes
- [ ] Use all tips in your code
- [ ] Run with Valgrind to verify no leaks

---

## Interview Tips

1. **Ask for clarification**: Size constraints? Use malloc? Handle edge cases?
2. **Think about edge cases**: Empty strings, NULL pointers, very long strings
3. **Propose multiple approaches**: Naive O(n²), optimized O(n)
4. **Discuss tradeoffs**: Time vs space, clarity vs performance
5. **Write defensive code**: Check bounds, validate inputs
6. **Explain choices**: Why snprintf over sprintf? Why strcpy unsafe?
7. **Fix buffer overflows**: Always a concern in embedded systems
8. **Consider memory**: Static vs dynamic, stack vs heap
9. **Test examples**: Walk through test cases during implementation
10. **Handle errors gracefully**: Return codes, NULL checks

---

**Good luck with your Embedded C interview! 🚀**
