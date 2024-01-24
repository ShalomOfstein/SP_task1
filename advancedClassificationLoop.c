#include "NumClass.h"
//calculates x to the power of n
int power(int x, int n){
    int result =1;
    if(n==0){
        return 1;
    }
    for(int i =1; i<=n;i++){
        result *= x;
    }
    return result;
}

//calculate the digits in a given number (the order of a number)
int digits(int num){
    int dig = 0;
    while(num>0){
        dig ++;
        num /=10;
    }
    return dig;
}

/*
will return 1 if the number is an armstrong number.
uses a loop to solve
*/

int isArmstrong(int num){
    int dig = digits(num);
    int temp = num, sum =0;
    for(int i =0; i<dig;i++){
        int r = temp%10;
        sum += power(r,dig);
        temp /= 10;
    }
    if(sum==num) return 1;
    else return 0;
}

/*
is Palindrome will return 1 if the number ia a plindrome
using a loop
*/
int isPalindrome(int num){
    int temp=num;
    int reversed =0;
    while(temp>0){
        int r= temp%10;
        reversed = (reversed*10) + r;
        temp /= 10;
    }
    if(num == reversed) return 1;
    else return 0;
}
