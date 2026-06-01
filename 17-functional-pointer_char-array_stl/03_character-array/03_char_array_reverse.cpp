#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ; 

void reverseString(char str[])
{
    int i = 0 ; 
    int j = strlen(str)-1;
    while(i < j)
    {
        swap(str[i] , str[j]);
        i++;
        j--;
    }
}
 
int main() 
{
    char str[] = "hello";
   // reverseString(str); mannual

   int n = strlen(str);

   reverse(str , str + n); // [ str , str + strlen(str) )
    cout<<str<<endl;
    return 0 ;
}