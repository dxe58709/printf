<h1 align="center">
	ft_printf
</h1>

## Summary
> <i>This project will recreate the famous C library printf function.
> The main focus will be on learning how to use variable arguments.</i>

## Getting started

First, clone this repository and `cd` into it:

```zsh
#!/bin/zsh
git clone https://github.com/dxe58709/printf; cd ft_printf
```

Compile the library with:

```zsh
#!/bin/zsh
make
```
### Basic Usage
For example, let's create a ``main.c`` file.

```c
// Include the header
#include "ft_printf.h"

int main(void)
{
      // Call the function
      ft_printf("Hello %d!", 1);
      return (0);
}
```

Compile the ``main.c`` file with the ft_printf library and run the program:
```bash
gcc main.c libftprintf.a && ./a.out
```
Output should be:
```
Hello 1!
```
