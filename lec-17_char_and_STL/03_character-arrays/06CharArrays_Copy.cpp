#include<iostream>
#include<cstring>
using namespace std ; 

// time : O(length of s2)
void stringCopy(char s1[] , char s2[])
{   
    int i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}
 
 
int main() 
{
     char s1[100] = "abcde" ;
     char s2[] = "xyz";
     cout<<s1<<endl;

    // copy s2 in s1 after coying s2 in s1 , s1 is "xyz"
    // stringCopy(s1 , s2);
    strcpy(s1,s2); // this in-built function copies s2 in s1

    
    cout<<s1<<endl;
 
 
    return 0 ;
}