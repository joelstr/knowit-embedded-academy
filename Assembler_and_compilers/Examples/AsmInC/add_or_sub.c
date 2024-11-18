#include <stdio.h>

void AddOrSub();
void AddOrSubC();

int main() {
   AddOrSub();
   AddOrSubC();
   return 0;
}

void AddOrSub()
{
    int y;
    asm(
        "       mov r1, #4          \n\t"
        "       mov r2, #23         \n\t"
        "       cmp r1, r2          \n\t"
        "       ble .jump           \n\t"
        "       sub r3, r1, r2      \n\t"
        "       b .exit             \n\t"
        ".jump:                     \n\t"
        "       add r3, r1, r2      \n\t"
        ".exit:                     \n\t"
        "       mov %[result], r3   \n\t"
        : [result] "=r" (y)
    );
    printf("%d\n", y);
}

void AddOrSubC()
{
    int x = 4;
    int y = 23;
    int result;
    if (x > y)
    {
        result = x - y;
    }
    else
    {
        result = x + y;
    }
    printf("%d\n", result);
}