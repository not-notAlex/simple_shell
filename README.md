# Simple Shell


This project is a simple command line interpreter that takes input from the user and generally executes other commands.

  - Can work in interactive and non-interactive modes!
    - Includes built-in commands!
      - Can interpret arguments and handles the path!

      ### Installation

      Clone the repository and compile.

      ```sh
      $ git clone https://github.com/not-notAlex/simple_shell.git
      $ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
      $ ./hsh
      ```

      Example of non-interactive use

      ```sh
      $ echo "command" | ./hsh
      ```

      ## Current Built-in Commands
      - exit - Terminates the shell and returns the value if specified.
      - env - Lists all of the current environment varibales.
      - cd - Changes the current directory to the specified one. Can be used with a dash to move to the previous directory, or without argument to move to $HOME.

      ## Example of use
      ```sh
      (your shell)$ ./hsh
      $ /bin/ls
      file1 file2 file3 hsh
      $ ls
      file1 file2 file3 hsh
      $ exit
      (your shell)$ echo "ls" | ./hsh
      file1 file2 file3 hsh
      ```

      ### Todos

       - Create more built-in commands (eg. setenv, getenv, alias, etc.)
        - Remove read/write valgrind errors

	### Authors

	-[Alex Smith]
	-[David Duval]



	   [Alex Smith]: <https://github.com/not-notAlex>
	   [David Duval]: <https://github.com/GreenCyberNinja>
