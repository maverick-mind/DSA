#include<iostream>
#include<cstring>
using namespace std ; 

// time : O(length of s2)
void stringCnt(char s1[] , char s2[])
{   
    int i = strlen(s1);
    int j = 0;
    while(s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}
 
int main() 
{
     char s1[100] = "abcde" ;
     char s2[] = "xyz";
     cout<<s1<<endl;

    // concatenate s2 in s1  , after concatenation  s2 in s1 , s1 is "xyz"
    //stringCnt(s1 , s2);

    strcat(s1,s2); // this in-built function that concatenates s2 in s1 , it will only modify s1 not s2
   
    cout<<s1<<endl;
 
    return 0 ;
}