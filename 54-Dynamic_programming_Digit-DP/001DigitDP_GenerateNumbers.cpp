/*

Given an integer inp as a string , design a recursive algorithm to innumurate all non-negative number digit-wise upto inp 

*/

#include<bits/stdc++.h>
using namespace std;
 
string input = "15" ;
string output = "" ;

int n = input.size() ;

void fxn(int i)
{
    // base case
    if(i == n){
        if(output > input) return ; // this code can generate output greater than input , if all the digits are not '9' 
        cout<<output<<" ";
        return ;
    }


    // recurrence 
    
    // decide the ith digit of the output
    // to decide for the ith digit , we have [0,9] , total 10 decisions.
    for(int digit = 0 ; digit <= 9 ; digit++)
    {
        // ith digit cold be anything from [0,9]
        output.push_back(digit + '0') ;
        fxn(i+1);

        output.pop_back() ; // backtracking
    }
}
 
int main() 
{
    
    fxn(0); // initially starting from index 0 
 
    return 0 ;
}