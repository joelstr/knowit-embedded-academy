#include <stdio.h>
#include <stdint.h>

static void bitwise_and();
static void bitwise_or();
static void bitwise_xor();
static void shift_left();
static void shift_right();
static void bitwise_not();

int main() {
   printf("Test Bitwise AND\n");
   bitwise_and();
   printf("\nTest Bitwise OR\n");
   bitwise_or();
   printf("\nTest Bitwise XOR\n");
   bitwise_xor();
   printf("\nTest Shift Left\n");
   shift_left();
   printf("\nTest Shift Right\n"); 
   shift_right();
   printf("\nTest Bitwise NOT\n");
   bitwise_not();
   return 0;
}

static void bitwise_and()
{
   int a = 0b11001000;	      /* 200 = 1100 1000 */
   int b = 0b10111000;	      /* 184 = 1011 1000 */
   int c = a & b;             /* 136 = 1000 1000 */
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("a & b = %d\n", c);
}

static void bitwise_or()
{
   int a = 0b11001000;	      /* 200 = 1100 1000 */
   int b = 0b10111000;	      /* 184 = 1011 1000 */
   int c = a | b;             /* 248 = 1111 1000 */
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("a | b = %d\n", c);
}

static void bitwise_xor()
{
   int a = 0b11001000;	      /* 200 = 1100 1000 */
   int b = 0b10111000;	      /* 184 = 1011 1000 */
   int c = a ^ b;             /* 112 = 0111 0000 */
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("a ^ b = %d\n", c);
}

static void shift_left()
{
   int a = 0b11001000;	       /* 200 = 0000 1100 1000 */
   int b = 3;	                /* 2^3 = 8 */
   int c = a << b;             /* 1600 = 0110 0100 0000 */
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("a << b = %d\n", c);
}

static void shift_right()
{
   int a = 0b11001000;	       /* 200 = 0000 1100 1000 */
   int b = 3;	                /* 2^3 = 8 */
   int c = a >> b;             /*  25 = 0000 0001 1001 */
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("a >> b = %d\n", c);
}

static void bitwise_not()
{
   int a = 0b11001000;	       /* 200 = 1100 1000 */
   int c = (uint8_t)~a;        /*  55 = 0011 0111 */
   printf("a = %d\n", a);
   printf("~a = %d\n", c);
}