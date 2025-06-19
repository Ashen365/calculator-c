# Simple Calculator (C++)

A simple command-line calculator written in C++.  
Supports basic arithmetic operations, power, square root, and memory functions.

## Features

- Addition, subtraction, multiplication, division
- Power (`^`) and square root (`s`)
- Memory operations: store (`M`), recall (`R`), clear (`C`)
- Use memory as input for calculations

## Usage

1. **Compile:**
    ```sh
    g++ calculator.cpp -o calculator
    ```

2. **Run:**
    ```sh
    ./calculator
    ```

3. **Follow prompts** to enter numbers and operations.  
   Type `R` at any number prompt to use the memory value.

## Example

```
Simple Calculator App
=====================

Enter first number (or type 'R' to recall memory): 12
Enter operation (+, -, *, /, ^, s, M, R, C): ^
Enter second number (or type 'R' to recall memory): 2
12 ^ 2 = 144
```

A simple C++ command-line calculator supporting basic arithmetic, power, square root, and memory functions.
