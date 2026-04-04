/* 
Generate N pairs of parenthesis , design a recursive solution to generate all the combinations of parenthesis.

Ex. 
    Input : N = 2 
    outut : "(())" , "()()" , ")()(" , ....

*/
#include<bits/stdc++.h>
using namespace std;
 

// To generate a combination of parenthesis , we have to take a sequence of 2*n decisions 
void fxn( char output[] , int i , int open , int close , int n )
{
    // base case 
    if(open == n and close == n)
    {
        output[i] = '\0';
        cout<<output<<endl;
        return ;
    }

    // recurrence relation
	// f(i, open, close) = take decisions for the remaining positions i to 2n-1 s.t.
	// you've used open '(' and close '('

	// decide for position i

	// option 1 : use '('
    if(open < n)
    {
        output[i] = '(';
        fxn( output , i + 1 , open + 1 , close , n );
    }

    // option 2 : use ')'
    // if(close < n )
    if(close < open)
    {
        output[i] = ')';
        fxn( output , i + 1 , open  , close + 1 , n );   

    }
}
 
int main() 
{
    int n = 2 ;
    char output[5];
    fxn( output , 0 , 0 , 0 , n );
    
 
 
 
    return 0 ;
}