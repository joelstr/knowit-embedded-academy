# Generating map and list files

To ask gcc to produce map file by adding the flag `-Wl,-Map,output.map`

`gcc -Wl,-Map,hello.map -o hello *.c`

This will however generate temporary o-files with odd names. By manually generating the o-files first theit names can be clearer.

```
# Compile each C file into an object file with a meaningful name
for file in *.c; do
    gcc -c "$file" -o "${file%.c}.o"
done
```
We can then link it together

`gcc -Wl,-Map,hello.map -o hello *.o`

# Link the object files and generate the map file

Use `objdump` to create a list file

`objdump -h -S hello > "hello.list"`

# Linker script

All addresses will now start from zero. This is usually not where we want to put them. We can use a linker script to declare where we want things to end up in memory by including `-T linker_script.ld`

`gcc -T linker_script.ld -Wl,-Map,hello.map -o hello *.o`

Remmeber to regenerate the list file

`objdump -h -S hello > "hello.list"`

# Further information

A good read on the linker file can be found [here](https://medium.com/@pc0is0me/an-introduction-to-linker-file-59ce2e9c5e73).