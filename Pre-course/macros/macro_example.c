#include <stdio.h>

// Object-like macros
#define PI 3.14159
#define STATUS 1
#define DEBUG

// Function-like macros
#define AREA_OF_CIRCLE(radius) (PI * radius * radius)
#define MAX(a,b) ((a > b) ? a : b)

static void calculate_area_of_circle(float radius);
static void print_debug_message();
static void print_status();

int main() {
   printf("Calculating circle radius\n");
   calculate_area_of_circle(5.0);
   print_debug_message();
   print_status();
   return 0;
}

static void calculate_area_of_circle(float radius)
{
   #ifdef PI
      printf("Area of circle with radius %f is %f\n", radius, AREA_OF_CIRCLE(radius));
   #else
      printf("PI is not defined\n");
   #endif
}

static void print_debug_message()
{
   #ifdef DEBUG
   // #undef DEBUG
      printf("Debug message\n");
   #endif

   #ifndef DEBUG
      printf("Data is encrypted\n");
   #endif
}

static void print_status()
{
   #if STATUS == 1
      printf("Status is 1\n");
   #elif STATUS == 2
      printf("Status is 2\n");
   #elif STATUS > 2
      #error "Status is too large"
   #else
      printf("Status is not 1 or 2\n");
   #endif
}