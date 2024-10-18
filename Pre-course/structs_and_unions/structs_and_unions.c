#include <stdio.h>
#include <stdint.h>

static void test_struct();
static void test_union();
static void test_bitfield();
static void test_message();

struct bitmap {
   unsigned bit0:1;
   unsigned bit1:1;
   unsigned bit2:1;
   unsigned bit3:1;
   unsigned bit4:1;
   unsigned bit5:1;
   unsigned bit6:1;
   unsigned bit7:1;
};

struct message {
   unsigned checksum:4;
   unsigned reserved:1;
   unsigned value:8;
   unsigned direction:1;
   unsigned signalValid:2;
};

struct Rectangle        // Bad alignment here
{
   uint16_t length;
   float breadth;
   char color;
};

union IntFloat {
   uint16_t i;
   float f;
};

union Data {
   uint16_t i;
   struct bitmap b;
   struct message m;
};

uint16_t main() {
   printf("Test struct\n");
   test_struct();
   printf("\nTest union\n");
   test_union();
   printf("\nTest bitfield\n");
   test_bitfield();
   printf("\nTest message\n");
   test_message();
   return 0;
}

static void test_struct()
{
   struct Rectangle rect = {10, 5.0 , 'r'};
   printf("Length: %d\n", rect.length);
   printf("Breadth: %1.2f\n", rect.breadth);
   printf("Size of Rectangle: %lu\n", sizeof(rect));
}

static void test_union()
{
   union IntFloat data;
   data.i = 10;
   data.f = 5.0;
   printf("data.i: %d\n", data.i);
   printf("data.i: %1.2f\n", data.f);
}

static void test_bitfield()
{
   union Data data;
   data.i = 0;
   data.b.bit1 = 1;

   printf("data: %d\n", data.i);
}

static void test_message()
{
   union Data data;
   data.i = 0x758D;                                   /* 0111 0101 1000 1101 */
   printf("Signal Valid: %d\n", data.m.signalValid);  /* 01 */
   printf("Direction: %d\n", data.m.direction);       /* 1 */
   printf("Value: %d\n", data.m.value);               /* 1010 1100 */
   printf("Checksum: %d\n", data.m.checksum);         /* 1101 */
}