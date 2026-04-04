#include<bits/stdc++.h>
using namespace std;
 
// same element ka same element ke saath swapping tab hi karna agar wo element aage exist nahi karta ho 
// swap(input[i] with input[j] ) only after checking ki [j+1 .... n-1 ]  , aage koi identical character na ho as same as input[j], like agar input[j] par 'b' hai to aage kahi fir se 'b' nahi hona chahiye , tab hi hum input[i] ko input[j] se swap karenge 

// set<string> s ;
void fxn( char input[] , int i , int n)
{
    // base case 
    if(input[i] == '\0') // it means from i = 0 to i == n - 1 , we have decided 
    {               // ki har location par kaun sa character jaayega 
        // cout<<input<<endl;

       // s.insert(input); // insertion in set is logarithmic 
       cout<<input<<endl;

        return ;
    }
    // recurrence relation

    for (int j = i; input[j] != '\0' ; j++ )
    {
        // can I even take the jth option
        bool flag = true ; // assume you can take the jth option 
        for (int k = j+1; input[k] != '\0'; k++)
        {
            if(input[k] == input[j])
            {
                flag = false ;
                false ;
            }
        }

        // choose the jth option only if it is allowed to take jth option , i.e. assign inp[j] to inp[i]
        if(flag)
        {
             swap(input[i] , input[j]);
             fxn(input , i + 1 , n);

             // backtracking jo original position thaa wahi kar do , taaki baad mein further swap karte time koi duplicate permutation na aaye ya fir koi permutation miss na ho jaaye 
             // int temp = j - 1 ;

            swap(input[i] , input[j]);
        }   
    }
      
}
 
int main() 
{
    char input[5] = "aabc";
    int n = strlen(input);

    //char output[4];

    fxn(input , 0 , n );
    
    // for( auto  p : s)
    // {
    //     cout<<p<<endl;
    // }

    return 0 ;
}

