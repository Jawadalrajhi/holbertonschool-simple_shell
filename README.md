# Simple Shell

## Description
This project is a simple UNIX command interpreter, created as part of the Holberton School curriculum.
It mimics the behavior of a basic shell (`sh`), allowing users to execute commands in both interactive and non-interactive modes.

---

## Authors
- **Jawad Mohammad Alrajhi**
- **Nawaf Saleh Alzahrani**

---

## Features
- Displays a prompt and waits for user commands.
- Executes commands using `fork` and `execve`.
- Handles both interactive and non-interactive modes.
- Supports command-line arguments.
- Handles the PATH to find executables.
- Implements built-in commands: `exit`, `env`.

---

## Compilation
To compile, use:
```bash
make
```

or manually:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

---

## Usage
Run the shell in interactive mode:
```bash
./hsh
($) /bin/ls
($) exit
```

Or in non-interactive mode:
```bash
echo "/bin/ls" | ./hsh
```

---

## Files
| File         | Description                                               |
| ------------ | --------------------------------------------------------- |
| `main.c`     | Entry point, initializes and runs the shell loop          |
| `prompt.c`   | Displays the prompt and reads user input                  |
| `exec.c`     | Executes commands using `fork` and `execve`               |
| `path.c`     | Resolves commands using the system `PATH`                 |
| `builtins.c` | Contains built-in commands (`exit`, `env`)                |
| `parse.c`    | Parses the user input into command and arguments          |
| `utils.c`    | Helper functions (string manipulation, freeing memory)    |
| `shell.h`    | Header file with macros, structs, and function prototypes |
| `Makefile`   | Compilation automation using `make`                       |


---

## Example
```bash
$ ./hsh
($) ls
main.c shell.c README.md
($) exit
```

---

## License
This project is part of the Holberton School curriculum and is for educational purposes only.
