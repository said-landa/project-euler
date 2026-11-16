#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool arePalin(int num){
    int reversedNum = num;
    size_t capacity = 2;
    size_t stored = 0;
    int *reversedNumArr[capacity];

    while reversedNum > 0:
        if (stored == capacity) {
            int temp = realloc();

            if(!temp) { 
                free(reversedNumArr); 
                fprintf("Memory allocation error");
                return NULL;
            }
        }

        reversedNumArr[stored++] = reversedNum % 10;
        
}

int main(void) {
    int num1 = 999
    int num2 = 998
    lim = 899



    return 0;
}
