// Write a program to check whether a given no is palindrome or not
#include<iostream>
using namespace std;

bool f(int num, int *temp){
    // base case 
    if(num>=0 and num<=9){
        int last_digit_of_temp = (*temp)%10;
        (*temp)/=10;
        return (num == last_digit_of_temp);
    }

    bool result = (f(num/10,temp) and (num%10)==((*temp)%10));
    (*temp)/= 10;
    return result;
}

int main(){
    int num = 12621;
    int anothernum = num;
    int *temp = &anothernum;
    cout<<f(num,temp);
return 0;
}