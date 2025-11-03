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
or manually:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
Run the shell in interactive mode:

bash
Copy code
./hsh
($) /bin/ls
($) exit
Or in non-interactive mode:

bash
Copy code
echo "/bin/ls" | ./hsh
Files
File	Description
main.c	Entry point, initializes and runs the shell loop
prompt.c	Displays the prompt and reads user input
exec.c	Executes commands using fork and execve
path.c	Resolves commands in the PATH
builtins.c	Contains built-in commands (exit, env)
utils.c	Helper functions (string manipulation, freeing memory)
shell.h	Header file with function prototypes
Makefile	Compilation automation file

Example
bash
Copy code
$ ./hsh
($) ls
main.c shell.c README.md
($) exit
License
This project is part of the Holberton School curriculum and is for educational purposes only.

yaml
Copy code

---

Once you create and commit this `README.md`, we’ll move on to:
- `AUTHORS` (easy, just contributor names), then  
- `man_1_simple_shell` (your manual page, like a mini help command).

Do you want me to show you **exactly what to write in `AUTHORS`** next?






You said:
i want to copy it so can u give it for me as one? as a whole?



ChatGPT said:
Of course — here’s the complete README.md ready for you to copy and paste directly into GitHub.
No need to edit anything right now — it’s fully formatted and valid for your Simple Shell project.

markdown
Copy code
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
or manually:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Usage
Run the shell in interactive mode:

bash
Copy code
./hsh
($) /bin/ls
($) exit
Or in non-interactive mode:

bash
Copy code
echo "/bin/ls" | ./hsh
Files
File	Description
main.c	Entry point, initializes and runs the shell loop
prompt.c	Displays the prompt and reads user input
exec.c	Executes commands using fork and execve
path.c	Resolves commands in the PATH
builtins.c	Contains built-in commands (exit, env)
utils.c	Helper functions (string manipulation, freeing memory)
shell.h	Header file with function prototypes
Makefile	Compilation automation file

Example
bash
Copy code
$ ./hsh
($) ls
main.c shell.c README.md
($) exit
License
This project is part of the Holberton School curriculum and is for educational purposes only.

yaml
Copy code

---
