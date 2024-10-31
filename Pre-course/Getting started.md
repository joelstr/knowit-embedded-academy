# Getting started
## Setting up environment
- Install your favorite IDE, I use [VSCode](https://code.visualstudio.com/)
- Install Windows Subsystem for Linux [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)

## Running code
In the linux terminal, run the following commands to compile your c-file.

Navigate to the folder with the desired code, for example hello_world assuming you've opened a terminal at the git repo root folder:

`cd Pre-course/hello_world/`


Compil your c-file with gcc.

`gcc -c hello_world.c -o hello_world.o`

Link the object file to an executable.

`gcc -o hello_world hello_world.o`

Run the executable.

`./hello_world`

A shorter way to accomplish the same thing would be to write

`gcc hello_world.c -o hello_world && ./hello_world`

If using VSCode you could also install the extension [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) which will add a play button in the top right corner of the file in your editor, which you can use to run your code.