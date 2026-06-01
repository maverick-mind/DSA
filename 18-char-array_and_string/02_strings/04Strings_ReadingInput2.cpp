#include<iostream>
#include<string>
#include<iomanip>
using namespace std ; 
 
 
int main() 
{
    string s1 ;
    
    // to read whitespaces 
    // input   :  (space) hello world ,
    // output  :  (space) hello world,
    // by default getline() stops reading as soon as it encounters '\n' 
    getline(cin , s1); // getline() also reads leading whitespaces
    cout<<"1st time --> "<<s1<<endl;

    getline(cin , s1 , '$'); // stops reading as soon as it encounters '$' 
    cout<<"2nd time --> "<<s1<<endl;


    // to ignore leading white spaces , use cin>>ws 
    getline(cin>>ws , s1 ) ; // we are using 'ws' which is an input manipulator while reading the i/p, and what it does is, it ignores leading whitespaces
    cout<<"3rd time --> "<<s1<<endl;

    // cout<<s1;
 
    return 0 ;
}