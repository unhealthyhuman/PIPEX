Pipex: An Introduction to handling pipes
-
The folllowing project is part of the 42 Cursus and it aimed to introduce us as to how to work with redirections and pipes.

Common Rules
-
• The project must be written in C.

• The functions should not quit unexpectedly (segmentation fault, bus error, double
free, etc) apart from undefined behaviors.

• All heap allocated memory space must be properly freed when necessary.

• Makefile must compile the source files to the required output with the flags -Wall, -Wextra and -Werror, use cc, and it must not relink.

• The Makefile must at least contain the rules $(NAME), all, clean, fclean and
re.

Syntax
-
  ./pipex file1 cmd1 cmd2 file2

The programm takes 4 arguments:
- file1 and file2 are file names.
- cmd1 and cmd2 are shell commands with their parameters.

The programm must behave the same as the shell command:

  < file1 cmd1 | cmd2 > file2
