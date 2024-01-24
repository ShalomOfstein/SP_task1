#include "NumClass.h"
/* 
will return 1 if the number is a prime nuber
*/
int isPrime(int num){
    if(num<2) return 0; //check the number is bigger than (or equal to) 2
    if((num%2==0)&&(num!=2)) return 0; //if the number is not 2 but divisible by 2 than it is not a prime
    for( int i =3 ; i*i <= num ; i=i+2 ){
        if(num%i==0){
            return 0;
        }
    }
   return 1;
}

int factorial(int num) {
    int fact=1;
    for(int i=1; i<=num; i++){
            fact=fact*i;
    }
    return fact;
}

int isStrong(int num){
    int digitNum =num;
    int sum=0;
    int temp;
    while(digitNum!=0){
        temp= digitNum%10;
        sum = sum + factorial(temp);
        digitNum = digitNum/10;
    }
    if(sum==num)return 1;
    return 0;
}

