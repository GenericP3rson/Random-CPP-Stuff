#include <stdio.h>
int count;
void func1(void);
void func2(void);
int main(void) {
    count = 100;
    func1();
    return 0;
}

void func1(void) {
    int temp = count;
    func2();
    printf("count is %d \n", count);
}

void func2(void) {
    int count;
    for (count=1; count < 10; count++) 
        putchar('.');
}
