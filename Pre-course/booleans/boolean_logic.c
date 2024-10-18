#include <stdio.h>
#include <stdint.h>

static void test_operators();
static void test_bad_example();

int main() {
   printf("Test operators\n");
   test_operators();
   printf("\nTest bad example\n");
   test_bad_example();
   return 0;
}

static void test_operators()
{
   int8_t a = -5;	      // All non-zero numbers are true
   uint8_t b = 0;	      // Zero is false
   printf("a && b = %d\n", a && b);
   printf("a || b = %d\n", a || b);
   printf("!a = %d\n", !a);

   uint8_t c = a && b;
   c++;
   printf("c++ = %d\n", c);

   c = (a || b) + !b;
   printf("c = %d\n", c);
}

static uint8_t green_button_pushed()
{
   uint8_t sensorA = 5; // 5 means pushed
   return sensorA;
}

static uint8_t red_button_pushed()
{
   uint8_t sensorA = 1;
   uint8_t sensorB = 1;
   return sensorA && sensorB;
}

static void test_bad_example()
{
   if (green_button_pushed()) {
      printf("Green button is pushed\n");
   }
   if (red_button_pushed()) {
      printf("Red button is pushed\n");
   }
   if (green_button_pushed() != red_button_pushed()) {
      printf("Only one button is pushed\n");
   }
}