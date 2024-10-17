#include <stdio.h>

static void test_int();
static void test_int16();
static void test_uint64();

int main() {
   printf("Test int\n");
   test_int();
   printf("\nTest long\n");
   test_int16();
   printf("\nTest long long\n");
   test_uint64();
   return 0;
}

static void test_int()
{
   int a = 1;
   int b = 0;
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
   long a = 1;
   long b = 0;
   while (a > b)
   {
      b=a;
      a<<=1;
   }
   b -= 1;
   b *= 2;
   b++;
   printf("a = %li\n", a);
   printf("b = %li\n", b);
}

static void test_uint64()
{
   long long a = 1;
   long long b = 0;
   while (a > b)
   {
      b=a;
      a<<=1;
   }
   b -= 1;
   b *= 2;
   b++;
   printf("a = %lli\n", a);
   printf("b = %lli\n", b);
}