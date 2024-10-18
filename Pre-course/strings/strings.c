#include <stdio.h>
#include <string.h>

static void hello_world();
static void hello_char();
static void hello_array();
static void hello_access();
static void hello_compare();
static void hello_all();

int main() {
   hello_world();
   hello_char();
   hello_array();
   hello_access();
   hello_compare();
   hello_all();
   return 0;
}

static void hello_world()
{
   char greetings[] = "Hello World!\n";
   printf("%s", greetings);
}

static void hello_char()
{
   char greetings[] = "Hello World!";
   for (int i = 0; greetings[i] != '\0'; i++) {
      printf("%c\t%d\n", greetings[i], greetings[i]);
   }
}

static void hello_array()
{
   char greetings[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\n','\0'};
   printf("%s", greetings);
}

static void hello_access()
{
   char greetings[] = "Hello World!\n";
   greetings[3] = 'A';
   printf("%s", greetings);
}

static void hello_compare()
{
   char greetings1[20] = "Hello World!\n";
   char greetings2[20] = "Hello World!\n";

   if (greetings1 == greetings2) { // Compares pointers
      printf("Pointers are equal\n");
   } else {
      printf("Pointers are not equal\n");
   }

   if (strcmp(greetings1, greetings2) == 0) { // Compares strings
      printf("Strings are equal\n");
   } else {
      printf("Strings are not equal\n");
   }
}

static void hello_all()
{
   char greetings[20] = "Hello World!\n";
   greetings[17] = 'b';
   printf("%s", greetings);
   for (int i = 0; i < 22; i++) {
      printf("%c\t%d\n", greetings[i], greetings[i]);
   }
}