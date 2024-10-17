#include <stdio.h>
#include <stdint.h>

static void test_overflow();
static void test_implicit_promotion();
static void test_typecast_subtraction();

int main() {
   printf("Test overflow\n");
   test_overflow();
   printf("\nTest implicit promotion\n");
   test_implicit_promotion();
   printf("\nTest typecast subtraction\n");
   test_typecast_subtraction();
   return 0;
}

static void test_overflow()
{
   uint16_t a = 40000;
   int16_t b = 16000;
   int32_t c = (int16_t)a + b;
   printf("%d\n",c); 
}

static void test_implicit_promotion()
{
   uint8_t a = 100;
   uint8_t b = a*90;
   b /= 100;
   uint8_t c = a*(uint8_t)90/(uint8_t)100;
   printf("B is calculated in several steps\n");
   printf("%d\n",b); 
   printf("C is calculated in one step\n");
   printf("%d\n",c); 
}

static void test_typecast_subtraction()
{
   uint8_t a = 80;
   uint8_t b = 200;
   int8_t c = a - b;
   printf("%d\n",c); 
   printf("%d\n",(uint8_t)c); 
}