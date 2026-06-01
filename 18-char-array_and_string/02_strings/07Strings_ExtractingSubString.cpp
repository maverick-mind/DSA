#include<iostream>
#include<string>
using namespace std ; 
 
 
int main() 
{
    string s = "acbddef" ;

    // syntax --> s.substr(starting_index , total_length_of_string)
    string temp = s.substr(2,4); // it will extract a substring from s that starts at 2nd index and has length equals to 4 
    cout<<s.substr(2,4)<<endl;

    cout<<s.substr(2)<<endl;// index 2 se le kar end tak jitne bhi characters hai sab extract kar lega , the length arguement is optional.

    //cout<<s.substr(2 , 100)<<endl;
    return 0 ;
}