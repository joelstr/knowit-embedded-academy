#include <stdio.h>
#include <stdint.h>

static void using_pointers();
static void passing_pointer();
static void passing_array();
static void passing_null_pointer();
static void increasing_pointer();
static void simple_function_pointer();
static void function_pointer();
static void struct_pointer();
static void pointer_to_pointer();


struct  coords
{
    int32_t x;
    int32_t y;
};

struct example {
    struct coords c;
    void (*func_ptr)(struct coords *);
};

static void inc_by_one(int32_t *x, int32_t * y);
static void inc_by_two(struct coords *c);
static void increase_third_element(int32_t *arr, int32_t size);

int main() {
    using_pointers();
    passing_pointer();
    passing_array();
    // passing_null_pointer();
    increasing_pointer();
    simple_function_pointer();
    function_pointer();
    struct_pointer();
    pointer_to_pointer();
    return 0;
}

static void inc_by_one(int32_t *x, int32_t * y)
{
    *x = *x + 1;
    *y = *y + 1;
}

static void inc_by_two(struct coords *c)
{
    c->x = c->x + 2; // c->x is equivalent to (*c).x;
    c->y = c->y + 2;
}

static void increase_third_element(int32_t *arr, int32_t size)
{
    if (size < 3)
    {
        return;
    }
    arr[2] = arr[2] + 1;
}

static void using_pointers()
{
    int32_t x = 10;
    int32_t *ptr = &x;
    printf("x: %d\n", x);
    printf("ptr: %p\n", ptr);
    printf("*ptr: %d\n", *ptr);
}

static void passing_pointer()
{
    int32_t x = 10;
    int32_t y = 20;
    inc_by_one(&x, &y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
}


static void passing_array()
{
    int32_t arr[5] = {1, 2, 3, 4, 5};
    increase_third_element(arr, 5);
    printf("Third element: %d\n", arr[2]);
    increase_third_element(&arr[0], 5);
    printf("Third element: %d\n", arr[2]);
}

static void passing_null_pointer()
{
    int32_t *ptr = NULL;
    increase_third_element(ptr, 5);
    printf("Third element: %d\n", ptr[2]);
}

static void increasing_pointer()
{
    int32_t arr[5] = {1, 2, 3, 4, 5};
    int32_t *ptr = arr;
    printf("First element: %d\n", *ptr);
    ptr = ptr + 2;
    printf("Third element: %d\n", *ptr);
}

static void simple_function_pointer()
{
    int32_t x = 10;
    int32_t y = 20;
    void (*func_ptr)(int32_t *, int32_t *) = inc_by_one;
    func_ptr(&x, &y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
}

static void function_pointer()
{
    int32_t x = 10;
    int32_t y = 20;
    void (*func_ptr)(int32_t *, int32_t *) = inc_by_one;
    func_ptr(&x, &y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
}

static void struct_pointer()
{
    struct coords c = {10, 20};
    struct example ex = {c, inc_by_two};
    ex.func_ptr(&ex.c);
    printf("x: %d\n", ex.c.x);
    printf("y: %d\n", ex.c.y);
}

static void pointer_to_pointer()
{
    int var = 10;
    int *intptr = &var;
    int **ptrptr = &intptr;

    printf("var: %d \nAddress of var: %p \n\n",var, &var);
    printf("inttptr: %p \nAddress of inttptr: %p \n\n", intptr, &intptr);
    printf("var: %d \nValue at intptr: %d \n\n", var, *intptr);
    printf("ptrptr: %p \nAddress of ptrtptr: %p \n\n", ptrptr, &ptrptr);
    printf("intptr: %p\nValue at ptrptr: %p \n\n", intptr, *ptrptr);
    printf("var: %d \n*intptr: %d \n**ptrptr: %d", var, *intptr, **ptrptr);
}