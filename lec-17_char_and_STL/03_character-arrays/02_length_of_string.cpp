#include<iostream>
#include<cstring>
using namespace std ; 
 // kisi bhi string ki length is --> NULL ke pahle tak jitne character hai unn ko hamee count karna hota hai 
int findLength(char str[])
{
    int count = 0 ;
    while(str[count] != '\0')
    {
        count++;
    }
    return count ;
} 


int main() 
{
    char str[] = "abc";
    cout<<findLength(str)<<endl;
    cout<<strlen(str)<<endl;

    char str2[100];
    cin>>str2; // let's say ABC
    cout<<(sizeof(str2)/sizeof(char)) - 1 <<endl;//  may not always work
    cout<<findLength(str2)<<endl;
    cout<<strlen(str2)<<endl;

 
 
 
    return 0 ;
}