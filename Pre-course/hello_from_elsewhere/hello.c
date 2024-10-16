#include "hello_from_elsewhere.h"

int main() {
    int result = hello_from_elsewhere();
    int retVal;
    if (result == SUCCESS) {
        retVal = 0;
    } else {
        retVal = 1;
    }
    return result;
}