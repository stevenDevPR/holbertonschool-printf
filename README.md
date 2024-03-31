# Custom printf Function in C

This repository contains an implementation of a custom printf function in C, along with auxiliary functions for printing various data types. This custom printf function aims to replicate the behavior of the standard `printf()` function in the C standard library.

## Features

- Supports printing of characters, strings, integers, unsigned integers, pointers, and special characters like '%'.
- Handles different format specifiers including `%d`, `%i`, `%u`, `%o`, `%x`, `%X`, `%c`, `%s`, `%p`, and `%%`.
- Offers a simplified version of the `printf()` function for educational purposes.

## Getting Started

To use this custom printf function in your C project, follow these steps:

1. Clone this repository to your local machine:

    ```bash
    git clone https://github.com/your-username/custom-printf-c.git
    ```

2. Include the `main.h` header file in your C source files:

    ```c
    #include "main.h"
    ```

3. Compile your project along with the provided source files:

    ```bash
    gcc your_source_file.c main.c -o your_executable
    ```

4. Use the `_printf()` function in your code as you would use `printf()`.

## Usage

Here's an example of how to use the custom printf function:

```c
#include "main.h"
#include <stdio.h>

int main() {
    _printf("Hello, %s!\n", "world");
    return 0;
}

