*This project has been created as part of the 42 curriculum by hamossai.*

---

# ft_printf

## 📋 Description

`ft_printf` is a custom re-implementation of the standard C library function `printf()`. The primary goal of this project is to discover and master the concept of **variadic functions** (`stdarg.h`) in C. By building a robust formatting engine from scratch, this project strengthens low-level programming skills, modular function design, and precise character tracking (`va_list` management).

The mandatory part handles core format specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`) without relying on external libraries, utilizing a custom set of lightweight helper files:

* `ft_printf.c` (Core parsing and routing)
* `ft_print_char.c` (Character & percent handling)
* `ft_putstr.c` (String handling & `NULL` checks)
* `ft_putnbr.c` (Signed integer & `INT_MIN` handling)
* `ft_uputnbr.c` (Unsigned decimal formatting)
* `ft_print_hex.c` (Hexadecimal conversion for `%x`, `%X`)
* `ft_print_address.c` (Pointer memory formatting & `(nil)` handling)
* `ft_printf.h` (Header declarations and prototypes)

---

## ⚙️ Algorithm & Technical Choices

### Flowchart Architecture

The core logic relies on a sequential pass through the format string using a modular routing approach. The flowchart below shows how the format string is read character by character, how each `%` conversion is routed to its dedicated helper, and how the printed-character count is accumulated and returned.

![ft_printf Flowchart]([./Blank_diagram.svg](https://github.com/Yuuuri01/PRINTF_42/blob/main/Blank%20diagram.svg)

### Algorithm Justification

The format string is traversed **once, from left to right (O(n))**. Regular characters are written directly. When a `%` is found, the next character is read and dispatched to the matching helper function. This keeps `ft_printf` itself small, makes each conversion independently testable, and respects the 42 Norm (short functions, limited scope).

### Data Structure Justification

No complex data structure is needed, and this is intentional:

* **`va_list`** is the only structure used to walk through the variable arguments, as it is the standard and portable mechanism for variadic functions.
* **An `int` counter** accumulates the number of printed characters. Each helper returns its own count, so the final sum matches the return value of the real `printf`.
* **Recursion** is used for number conversion (`%d`, `%u`, `%x`, `%X`, `%p`). It avoids allocating a temporary buffer, so there is no `malloc` and no risk of memory leaks.

### Technical Implementation Details

1. **Variadic Argument Management:** Uses `va_start`, `va_arg`, and `va_end` macros to dynamically parse arguments passed past the format string.
2. **Character Counting:** Every helper function returns the exact number of characters successfully printed, which accumulates into a total return value matching standard `printf` behavior.
3. **Edge Case Safety:**
   * `%s` safely catches `NULL` inputs and outputs `(null)`.
   * `%p` handles `NULL` pointers explicitly by printing `(nil)` under Linux/glibc standards instead of raw zero or incorrect strings.
   * `%d`/`%i` converts standard integers to `long` types internally to prevent overflow errors when evaluating bounds like `INT_MIN`.

---

## 🚀 Instructions

### Compilation & Build

The project includes a Makefile with standard 42 rules. To compile the library (`libftprintf.a`), run:

```bash
make
```

### Available Makefile Rules:

* `make` — Compiles source files and generates `libftprintf.a`.
* `make clean` — Removes object files (`.o`).
* `make fclean` — Removes object files and the compiled archive (`libftprintf.a`).
* `make re` — Re-compiles the entire project from scratch.

### Integration & Usage

To use `ft_printf` in your own C programs, include the header and link the archive during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Hex value: %x\n", "World", 42);
    return (0);
}
```

Compile using:

```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
```

---

## 📚 Resources & AI Usage

### Classic References

* **C Standard Library Documentation:** Man pages for `stdarg(3)` and `printf(3)`.
* **The Linux Programming Interface** (Michael Kerrisk) — System calls and formatting internals.
* **42 Common Core Norms:** Strict syntax, variable declaration limits, and scope management guidelines.

### AI Usage Disclosure

* **Tasks Performed with AI Assistance:**
  * Structuring and drafting documentation layout for the `README.md`.
  * Designing low-level algorithmic flowcharts for edge-case management (`NULL` pointer differentiation between `%s` and `%p`).
* **Human Validation:** All C source files, header definitions, Makefile rules, memory handling logic, and peer-evaluation tests (`Francinette` / custom test suites) were independently written, debugged, and verified by the author.
