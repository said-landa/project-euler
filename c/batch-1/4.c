#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool arePalin(int num){
    int reversedNum = num;
    size_t capacity = 2;
    size_t stored = 0;
    int *reversedNumArr = malloc(capacity * sizeof * reversedNumArr);
    if (!reversedNumArr) {
        fprintf(stderr, "Memory allocation error");
        return NULL;
    }

    while (reversedNum > 0) {
        if (stored == capacity) {
            int *temp = realloc(reversedNumArr, 2 * capacity * sizeof *reversedNumArr);

            if(!temp) { 
                free(reversedNumArr); 
                fprintf(stderr, "Memory allocation error");
                return NULL;
            }
            capacity *= 2;
            reversedNumArr = temp;
        }
        reversedNumArr[stored++] = reversedNum % 10;
        reversedNum /= 10;
    }

    for(int i = 0; i < stored; i++) {
        reversedNum = reversedNum * 10 + reversedNumArr[i];
    }

    free(reversedNumArr);
    return reversedNum == num;
}

int main(void) {
    int num1 = 999;
    int num2 = 998;
    int lim = 899;

    bool done = false;
    
    while (num1 > lim && !done) {
        while (num2 > lim) {
            int prod = num1 * num2;
            if (arePalin(prod)) {
                printf("Biggest palindrome is %d\n", prod);
                done = true;
                break;
            }
            else {
                num2 -= 1;
            }
        }
        if (num1 == lim + 1) {
            lim = lim - 100;
        }
        num1 -= 1;
        num2 = num1 - 1;
    }

    return 0;
}
