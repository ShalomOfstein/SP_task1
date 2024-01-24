#include "NumClass.h"


//calculates x to the power of n using recursion
int power(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return x * power(x, n - 1);
    }
}

// Recursive function to calculate the number of digits
int digits(int num) {
    if (num < 1) {
        return 0;
    }
    else {
        return (digits(num / 10)+1);
    }
}

//recursive helper function to calculate if a number is an armstrong number
int isArmstrongRec(int num, int original, int dig){
    if (num==0) return 0;
    else{
        int r = num % 10;
        return power(r, dig) + isArmstrongRec(num / 10, original, dig);
    }
}

/*
will return 1 if the number is an armstrong number.
uses a the helper function to solve
*/
int isArmstrong(int num){
    int dig = digits(num);
    int result = isArmstrongRec(num, num, dig);
}

/*
is Palindrome will return 1 if the number ia a plindrome
using a recursive function
*/
int isPalindromeRec(int num, int digits){
    if(digits<2) return 1;
    int divider = power(10,digits-1);
    int last = num%10;
    int first = (num - (num%divider))/divider;
    if(first!=last) {return 0;}
    else{
    int smallNum = (num%divider)/10;
    return isPalindromeRec(smallNum, digits-2);
    }
}

int isPalindrome(int num){
    int dig = digits(num);
    return isPalindromeRec(num,dig);
}