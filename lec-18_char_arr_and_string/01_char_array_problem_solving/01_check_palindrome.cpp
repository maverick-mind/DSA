#include<iostream>
#include<cstring>
using namespace std ; 

// steps ~ n/2 
// time ~ O(n)
// space ~ O(1)

bool checkPalindrome (char str[])
{
    int i = 0;
    int j = strlen(str) - 1 ;
    while(i < j)
    {
        if(str[i] != str[j])  return false ; 
        i++;
        j--;
    }
    return true ;
}

int main() 
{
    char str1[] = "rotator";
    char str2[] = "racecar";
    char str3[] = "hello";
    
    checkPalindrome(str1) ? cout<<str1<<" is palindrome"<<endl : cout<<str1<<" is not a palindrome"<<endl;
   
    checkPalindrome(str2) ? cout<<str2<<" is palindrome"<<endl : cout<<str2<<" is not a palindrome"<<endl;

    checkPalindrome(str3) ? cout<<str3<<" is palindrome"<<endl : cout<<str3<<" is not a palindrome"<<endl;

    return 0 ;
}