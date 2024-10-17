#include <stdio.h>
#include <stdint.h>

static void test_uint8();
static void test_int16();
static void test_uint64();

int main() {
   printf("Test uint8\n");
   test_uint8();
   printf("\nTest int16\n");
   test_int16();
   printf("\nTest uint64\n");
   test_uint64();
   return 0;
}

static void test_uint8()
{
   uint8_t a = 1;
   uint8_t b = 0;
   while (a > b)
   {
      b=a;
      a<<=1;
   }
   b -= 1;
   b *= 2;
   b++;
   printf("a = %d\n", a);
   printf("b = %d\n", b);
}

static void test_int16()
{
   int16_t a = 1;
   int16_t b = 0;
   while (a > b)
   {
      b=a;
      a<<=1;
   }
   b -= 1;
   b *= 2;
   b++;
   printf("a = %i\n", a);
   printf("b = %i\n", b);
}

static void test_uint64()
{
   uint64_t a = 1;
   uint64_t b = 0;
   while (a > b)
   {
      b=a;
      a<<=1;
   }
   b -= 1;
   b *= 2;
   b++;
   printf("a = %lu\n", a);
   printf("b = %lu\n", b);
}