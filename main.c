
#include "NumClass.h"
#include <stdio.h>

int main() {
    // Get two positive numbers from the user
    int num1, num2;
    
    printf("Enter the first positive number: ");
    scanf("%d", &num1);

    printf("Enter the second positive number: ");
    scanf("%d", &num2);

    // Validate input
    if (num1 <= 0 || num2 <= 0) {
        printf("Please enter valid positive numbers.\n");
        return 1; // Exit with an error code
    }
    // Swap numbers if needed (to make sure num1 is smaller)
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    

    // Print Armstrong numbers
    printf("The Armstrong numbers are: ");
    for (int i = num1; i <= num2; ++i) {
        if (isArmstrong(i)==1) {
            printf("%d ", i);
        }
    }

    // Print Palindrome numbers
    printf("\n The Palindromes are: ");
    for (int i = num1; i <= num2; ++i) {
        if (isPalindrome(i)==1) {
            printf("%d ", i);
        }
    }

    // Print prime numbers
    printf("\n The Prime numbers are: ");
    for (int i = num1; i <= num2; ++i) {
        if (isPrime(i)==1) {
            printf("%d ", i);
        }
    }

    // Print Strong numbers
    printf("\n The Strong numbers are: ");
    for (int i = num1; i <= num2; ++i) {
        if (isStrong(i)==1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0; // Exit successfully
}


