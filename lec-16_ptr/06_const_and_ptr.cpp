#include<iostream>
using namespace std ; 
 
 
int main() 
{
    int x = 10 ;

    int &ref1 = x ;// ref1 is just another name of same address pointed by x 
    cout<<ref1 <<" "<<x<<endl;
    ref1++;//  ++ ki precedence jyaada hoti hai * se issliye brackets ka use kiya
    cout<<ref1 <<" "<<x<<endl;

    const int & ref2 = x ;
    ref1++;
    cout<<ref1 <<" "<<x<<" "<<ref2<<endl;
    // ref2++; it will give error // const waale ko modify nahi kar sakte 
    cout<<ref1 <<" "<<x<<" "<<ref2<<endl;


 
 
 
    return 0 ;
}