// WorldsWorstCalc.c
// my mission: a pointer to a struct containing a pointer to a list of pointers to functions returning a pointer to an int
// accomplished! and done so without compiler warnings :)


#include <stdio.h>
#include <stdlib.h>

int* plus(int, int, int*);
int* minus(int, int, int*);
int* multiply(int, int, int*);
int* divide(int, int, int*);

struct WorldsWorstCalc {
    int* (***lista)(int, int, int*);
};


int main()
{
    int* (*more[2])(int, int, int*) = { plus, multiply };
    int* (*less[2])(int, int, int*) = { minus, divide };
    struct WorldsWorstCalc* calc = (struct WorldsWorstCalc*)malloc(sizeof(struct WorldsWorstCalc));
    if (calc == NULL) return 1; // yeah no
    calc->lista = (int* (***)(int, int, int*)) malloc(2 * sizeof(int* (*[2])(int, int, int*)));
    if (calc->lista == NULL) return 1; // nuh uh
    *(calc->lista) = more;
    *((calc->lista) + 1) = less;
    int a = 2137;
    int b = 69;
    int x = 0;
    // (*(*(calc -> lista + 1)))     - subtraction
    // (*(*(calc -> lista + 1) + 1)) - division
    // (*(*(calc -> lista)))         - addition
    // (*(*(calc -> lista) + 1))     - multiplication
    x = *(*(*(calc->lista + 1)))(a, b, &x);
    printf("%d\r\n", x);    // 2137 - 69 = 30 
    x = *(*(*(calc->lista + 1) + 1))(a, b, &x);
    printf("%d\r\n", x);    // 2137 / 69 = 30
    x = *(*(*(calc->lista)))(a, b, &x);
    printf("%d\r\n", x);    // 2137 + 69 = 2206
    x = *(*(*(calc->lista) + 1))(a, b, &x);
    printf("%d\r\n", x);    // 2137 * 69 = 147453
    return 0;
}

int* plus(int a, int b, int* acc) {
    *acc = a + b;
    return acc;
}
int* minus(int a, int b, int* acc) {
    *acc = a - b;
    return acc;
}
int* multiply(int a, int b, int* acc) {
    *acc = a * b;
    return acc;
}
int* divide(int a, int b, int* acc) {
    if (!b) *acc ^= *acc;
    else *acc = a / b;
    return acc;
}