/* A permutation of a given string is a rearrangement of it's characters 
 Input : "abc"
 Output : "abc" , "acb" , "bac" , "bca" , "cab" , "cba"

 To generate a permutaion , you have to take a sequence of 'n' decisions ( you have to decicde which character is assigned to each position , and since we are trying to build a recursive solution , what we will do is , we will just take the 1st decision( just decide the character to be assigned to the 1st location) rest of the decisions can be taken recursively )
 */
#include<bits/stdc++.h>
using namespace std;
 
// i <= j <= n - 1 
void fxn( char input[] , int i , int j , int n)
{
    // base case for completing all permutations at position i
    if(input[i] == '\0') {
        cout << input << endl;
        return;
    }

    // base case for when we've tried all options for position i
    if(input[j] == '\0') {
        return;
    }

    // recurrence relation
    // 1st position par kya kya aa sakta hai 
    
    // take decisions for the remaining positions i to n-1 
    // OR
    // generate permutations for input[i.....n-1]
    // decide which character will be assigned to ith index , rest everything can be done recursively 
   
     // Choose: swap input[i] with input[j]
    swap(input[i], input[j]);
    
    // Recurse: generate permutations for remaining positions
    fxn(input, i + 1, i + 1, n);
    
    // Backtrack: restore original state ,
    // backtracking jo original position thaa wahi kar do , taaki baad mein further swap karte time koi duplicate permutation na aaye ya fir koi permutation miss na ho jaaye 
    swap(input[i], input[j]);
    
    // Try next option: move j to next position
    fxn(input, i, j + 1, n);
    

}
 
int main() 
{
    char input[4] = "abc";
    char output[4];

    int i = 0 ;
    fxn(input , i , 0 , 4 );

 
 
    return 0 ;
}

