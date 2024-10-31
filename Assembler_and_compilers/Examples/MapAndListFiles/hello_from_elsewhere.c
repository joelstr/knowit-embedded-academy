#include <stdio.h>
#include "hello_from_elsewhere.h"

static void hello_from_here();
int helloResult = 0;

int hello_from_elsewhere() {
   hello_from_here();
   helloResult = 1;
   return helloResult;
}

static void hello_from_here() {
   printf("Hello World!\n");
}
