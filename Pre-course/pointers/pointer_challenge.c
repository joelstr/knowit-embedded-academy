#include <stdio.h>
#include <stdint.h>

static void pointer_challenge(int32_t* arr, int32_t* loc);

int main() {
   int32_t x[5] = {1, 2, 3, 4, 5};
   pointer_challenge(&x[1], (int32_t *)&x);
   return 0;
}

static void pointer_challenge(int32_t* arr, int32_t* loc)
{
    int32_t res = arr[*loc] + arr[*loc+1];
    printf("%d\n",res);
}