 // for a single decision , it we have multiple options , we need to iterate over those options 
// also , if for a single decision , if we have multiple otions , HAMESHA "BACKTRACKING" HOGI



/* A permutation of a given string is a rearrangement of it's characters 
 Input : "abc"
 Output : "abc" , "acb" , "bac" , "bca" , "cab" , "cba"

 To generate a permutaion , you have to take a sequence of 'n' decisions ( you have to decicde which character is assigned to each position , and since we are trying to build a recursive solution , what we will do is , we will just take the 1st decision( just decide the character to be assigned to the 1st location) rest of the decisions can be taken recursively )
 */
#include<bits/stdc++.h>
using namespace std;
 
set<string> s ;
void fxn( char input[] , int i , int n)
{
    // base case 
    if(input[i] == '\0') // it means from i = 0 to i == n - 1 , we have decided 
    {               // ki har location par kaun sa character jaayega 
        // cout<<input<<endl;

        s.insert(input); // insertion in set is logarithmic 

        return ;
    }
    // recurrence relation

    // for a single decision , it we have multiple options , we need to iterate over those options , for that iteration we need loop inside recursive function 
    
    // also , if for a single decision , if we have multiple otions , HAMESHA "BACKTRACKING" HOGI
    for (int j = i; input[j] != '\0' ; j++ )
    {
        // choose the jth option , i.e. assign inp[j] to inp[i]
            swap(input[i] , input[j]);
            fxn(input , i + 1 , n);
        
        // backtracking jo original position thaa wahi kar do , taaki baad mein further swap karte time koi duplicate permutation na aaye ya fir koi permutation miss na ho jaaye 
        // int temp = j - 1 ;

            swap(input[i] , input[j]);
    }
      
}
 
int main() 
{
    char input[5] = "abac";
    int n = strlen(input);

    //char output[4];

    fxn(input , 0 , n );
    
    for( auto  p : s)
    {
        cout<<p<<endl;
    }

    return 0 ;
}

