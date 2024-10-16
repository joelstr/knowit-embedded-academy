#include <stdio.h>
#include "hello_from_elsewhere.h"

static void hello_from_here();

int hello_from_elsewhere() {
   hello_from_here();
   return SUCCESS;
}

static void hello_from_here() {
   printf("Hello World!\n");
}
