#include <stdio.h>

// Object-like macros
#define PI 3.14159
#define STATUS 1
#define DEBUG

// Function-like macros

#define AREA(a,b) (a*b)
#define AREA2(a,b) ((a)*(b))

#define AREA_OF_CIRCLE(radius) (PI * (radius) * (radius))
#define MAX(a,b) ((a > b) ? a : b)

static void calculate_area_of_circle(float radius);
static void print_debug_message();
static void print_status();
static void calculate_area(int a, int b);

int main() {
   printf("Calculating circle radius\n");
   calculate_area_of_circle(5.0);
   print_debug_message();
   print_status();
   calculate_area(5, 10);
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

static void calculate_area(int a, int b)
{
   // Increase the value of a and b by 1 then calculate the area
   printf("Area of rectangle with sides %d and %d is %d\n", a+1, b+1, AREA(a + 1,b + 1));
   printf("Area of rectangle with sides %d and %d is %d\n", a+1, b+1, AREA2(a + 1,b + 1));
}