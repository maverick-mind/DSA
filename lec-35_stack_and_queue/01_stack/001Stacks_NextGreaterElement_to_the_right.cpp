#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementToTheRight(const vector<int> & input)
{
    stack<int> s ; // will be monotonic in nature 
    int n = input.size() ;
    vector<int> output(n) ;

    // for ith element , we have to find nearest greater element 
    // from (i + 1) to (n - 1) 
    // so agar hum O(n) mein build karna chahte hai output vector , so ith element ka kaam const time mein karna padega , and for that jab ith element par pahuche , we should have to already explore elements from (n-1) to (i+1) , so for this , instead of moving from left to right , we will move from right to left (n - 1) to 0th index 

    int i = n - 1 ;
    while( i >= 0)
    {
        // for ith element , if stack empty , it means there is no element greater than ith element to its right 
        if(s.empty())
        {
            output[i] = -1 ;
            s.push(input[i]); // as we don't know if input[i] could be nearest greater element to the right to any other element 
            i-- ;
        }
        else{ // if stack is not empty() , then compare the top of the stack till the time we find any top of stack greater than the ith element in the input array , and if stack gets empty then -1 will be stored in output array 
            
            while(!s.empty() )
            {
                if(s.top() > input[i])
                {
                    output[i] = s.top();
                    s.push(input[i]);
                    i--;
                    break ;
                }

                else{
                    s.pop() ;
                }
            }
            // after exit the while loop , check we came out due to break , or due to s.pop() eventually leading to s.empty()
            if(s.empty())
            {
                output[i] = -1;
                s.push(input[i]);
                i--;
            }
        }

    }
        return output ;
}

int main()
{
    vector<int> input = {5, 3, 6, 7, 2, 1, 4} ;
    vector<int> output = nextGreaterElementToTheRight(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }cout<<endl;

    return 0;
}