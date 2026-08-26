*This project has been created as part of the 42 curriculum by yuozturk.*

# ft_printf

## Description

This project recreates a simplified version of the standard C `printf` function in pure C. The goal is to understand how formatted output works internally, how variadic arguments are handled, and how a parser can interpret a format string to dispatch the correct output routine for each conversion.

The implementation is called `ft_printf` and supports the following conversions:

- `%c` for characters
- `%s` for strings
- `%p` for pointers
- `%d` and `%i` for signed integers
- `%u` for unsigned integers
- `%x` and `%X` for hexadecimal output
- `%%` for a literal percent sign

This project is designed as a core C exercise focused on argument parsing, recursion, pointer arithmetic, and low-level I/O. It is the foundation for understanding how formatted output is generated in Unix-like systems.

## Instructions

### Compilation

From the root of the repository, run:

```bash
make
```

This creates the library archive:

```bash
libftprintf.a
```

### Cleaning generated files

```bash
make clean
make fclean
```

### Example usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

Compile it with:

```bash
gcc main.c -L. -lftprintf -o test
```

The project uses a custom header file, `ft_printf.h`, and all source files are compiled into the static library.

## Algorithm and Data Structure

The program follows a simple but effective streaming parser model.

### Core idea

The function `ft_printf` walks through the format string from left to right:

1. When it sees a normal character, it prints it immediately.
2. When it encounters `%`, it validates the next character.
3. If the next character is a supported conversion specifier, it dispatches to a dedicated printing routine.
4. It sums the number of characters printed and returns the total count, matching the behavior of the standard library function.

### Validation and dispatch

The format parser checks whether the format string is structurally valid before processing any arguments. This is handled by `integrity_check`, which scans the string and ensures that every `%` is followed by an allowed conversion symbol. This prevents malformed format strings from producing undefined behavior.

The actual conversion dispatch is done in `format_check`, which uses the variadic argument list (`va_list`) and the macro `va_arg` to retrieve the next argument according to the current specifier. The function then calls the appropriate printing helper:

- `ft_print_chr` for `%c` and `%%`
- `ft_print_str` for `%s`
- `ft_print_num` for `%d`, `%i` and `%u`
- `ft_print_hex` for `%x`, `%X`, and `%p`

### Why this algorithm fits the project

This design is intentionally minimal and efficient:

- It uses the C standard variadic interface rather than custom containers.
- It avoids building a complex data structure; the format string itself is the parser input, and the argument list is consumed in order.
- The recursion used in number and hexadecimal conversion keeps the code compact while preserving correct output.
- The output routines all write directly with `write(1, ...)` or the project’s helper wrappers, so the library remains lightweight and predictable.

The project therefore relies on a linear scanning algorithm plus lightweight helper functions instead of a large parsing tree or dynamic data structures. This is a strong fit for a 42-style challenge where the goal is correctness, clarity, and memory efficiency.

## Features

- Custom implementation of the standard `printf` behavior
- Support for major conversion types used in C projects
- Validation of malformed format strings
- Recursive integer and hexadecimal formatting
- Static library build system via `Makefile`

## Resources

### References

- The C standard library documentation for `printf`
- The GNU libc manual on formatted output
- C programming tutorials covering variadic functions and `va_list`
- Articles and notes about recursive number formatting and hexadecimal conversion

### AI usage

AI was used to help with the following tasks:

- Reviewing the project structure and naming conventions for a clean 42-style implementation
- Explaining how `printf` parsing and variadic arguments work conceptually
- Checking edge cases such as `NULL` strings, negative integers, pointer formatting, and hex output
- Drafting and improving the README content and technical explanations
- Validating the correctness of the algorithm description before finalizing the documentation

These AI-assisted steps were used mainly to clarify implementation details and ensure the writing is accurate, readable, and aligned with the project requirements.

## Notes

This project is a simplified version of the standard `printf` implementation and does not cover every advanced feature of the original C function, such as width, precision, flags, or length modifiers. The objective is to build a solid core parser and conversion engine while staying within the constraints of the 42 curriculum.
