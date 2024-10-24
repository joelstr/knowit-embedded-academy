# Running arm instructions on x86 hardware

Most of these instructions are based on [this guide](https://azeria-labs.com/arm-on-x86-qemu-user/).

First we need to install the correct compilers and the qemu environment

`sudo apt install gcc-arm-linux-gnueabihf binutils-arm-linux-gnueabihf binutils-arm-linux-gnueabihf-dbg qemu-user qemu-user-static build-essential`

Compile C code by running

`arm-linux-gnueabihf-gcc -static -o hello_world hello_world.c`

Run the code with

`qemu-arm hello_world`

To compile assembler files run

`arm-linux-gnueabihf-as hello_world.s -o hello_world.o && arm-linux-gnueabihf-ld -static hello_world.o -o hello_world`

You can then again run the file with the same command as before

`qemu-arm hello_world`

Debugging assembler code can be done with gdb-multiarch

`sudo apt install gdb-multiarch`

By comiling code with extra debug information we are able to debug it easier

`arm-linux-gnueabihf-gcc -ggdb3 -o add_or_sub add_or_sub.c -static`

We can then run the program as follows

`qemu-arm -L /usr/arm-linux-gnueabihf -g 1234 ./add_or_sub`

This process will wait for a gdb connection at port 1234.
Connect with gdb-multiarch from another termina with the command

`gdb-multiarch -q --nh -ex 'set architecture arm' -ex 'file add_or_sub' -ex 'target remote localhost:1234' -ex 'layout split' -ex 'layout regs'`

Generate disassembly on compile