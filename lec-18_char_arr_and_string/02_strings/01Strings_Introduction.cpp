// by default jab hum koi integer create karte hai local scope mein , to uss mein garbage value hoti hai 
// lekin jab hum string create karte hai to by default string empty hota hai 
// string str ; // str is an variable of string type 
//              // str is an object of string class

#include<iostream>
#include<string>
using namespace std ; 

// character array is used in c language to store string 
// jo ye string type hai , it is present in c++ , aur iss ka bhi exactly same use hai to store string
// if you are working with string , you can either use a character array or use a string type , purpose of both character array and string is same , syntax is little different 
 
 
int main() 
{
    string s1 ; // here , we have declared variable s1 of string type 
              // OR we have declared s1 as an object of string class 
    s1 = "abc" ; // here we have assigned string literal "abc" to s1
    cout<<s1<<endl;
    cout<<"length of (" <<  s1 << " ) = " <<s1.size()<<endl;
    cout<<"length of (" <<  s1 << " ) = " <<s1.length()<<endl;

    string s2 = "coding"; // here we have initialized a string object 
    cout<< s2<<endl;
    cout<<"length of (" <<  s2 << " ) = " <<s1.size()<<endl;
    
    for (int i = 0; i < s2.size(); i++)
    {
        cout<<s2[i]<<" ";
    }cout<<endl;

    for (int i = 0; s2[i] != '\0'; i++)
    {
        cout<<s2[i]<<" ";
    }cout<<endl;
    

    return 0 ;
}