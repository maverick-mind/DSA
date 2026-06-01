#include<iostream>
#include<string>
using namespace std; 
 
int main() 
{
    string s1 ;
    cin>>s1;// input : (space) hello world , output : hello , because cin ignores leading whitespaces and stops as soon as it encounters non-leading whitespaces or at 1st non-leading whitespaces
    cout<<s1<<endl;

    return 0 ;
}