#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool arePalin(int num){
    int reversedNum = num;
    size_t capacity = 2;
    size_t stored = 0;
    int *reversedNumArr = malloc(capacity * sizeof * reversedNumArr);
    if (!reversedNumArr) {
        fprintf("Memory allocation error");
        return NULL;
    }

    while reversedNum > 0{
        if (stored == capacity) {
            int *temp = realloc(reversedNumArr, 2 * capacity * sizeof *reversedNumArr);

            if(!temp) { 
                free(reversedNumArr); 
                fprintf("Memory allocation error");
                return NULL;
            }
            reversedNumArr = temp;
        }
        reversedNumArr[stored++] = reversedNum % 10;
        reversedNum /= 10;
    }

    for(sizeof i = 0; i < stored; i++) {
        reversedNum = reversedNum * 10 + reversedNumArr[i];
    }
    
       
    
}

int main(void) {
    int num1 = 999
    int num2 = 998
    lim = 899



    return 0;
}
