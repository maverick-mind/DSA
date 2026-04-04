#include<bits/stdc++.h>
using namespace std ; 

// a string of size n has n(n+1)/2 ~ n^2 substrings
void generateSubstrings( string str ) // str is by-default passed by value 
{                                     // i.e. it's copy is sent during the 
                                     // function call 
     int n = str.size() ; 

     for (int i = 0; i < n; i++)
     {
        
         for (int j = i; j < n; j++)
         {
             // generate the sub-string that starts at the ith index and ends at the jth index 
             string temp = str.substr(i , (j-i+1));//  i is first index, from i , next (j-i+1) length of string 
             cout<<temp<<endl;
         }
         
     }

}
 

int main() 
{
    string str = "abc";
    generateSubstrings(str);// sending copy of a string (default behav.) is expensive ;
   
 
 
 
    return 0 ;
}