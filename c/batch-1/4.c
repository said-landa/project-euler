//version 1.35
//Largest Palindrome Product

//A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

#include <stdio.h>
#include <math.h>

int main(void) {
    for (int prefix = 997; prefix >= 100; --prefix) {
        int palindrome = prefix;

        for (int digits = prefix; digits > 0; digits /= 10) { //Integer division by 10 drops the last digit each time. For 997, the loop runs with digits equal to 997, then 99, then 9.
            palindrome = palindrome * 10  + digits % 10; //Multiplying by 10 makes room for one digit. digits % 10 takes the last digit, so the first pass turns 997 into 9977
        }
        int lowerBound = (int)ceil(palindrome / 999.0);
    }

    return 0;
}
