#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

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
    for (int prefix = 997; prefix >= 100; --prefix) {
        int palindrome = prefix;

        for (int digits = prefix; digits > 0; digits /= 10) { //Integer division by 10 drops the last digit each time. For 997, the loop runs with digits equal to 997, then 99, then 9.
            palindrome = palindrome * 10  + digits % 10; //Multiplying by 10 makes room for one digit. digits % 10 takes the last digit, so the first pass turns 997 into 9977
        }
        int lowerBound = 
    }

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
