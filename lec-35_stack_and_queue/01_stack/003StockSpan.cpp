// nearest max element of left nikaal lo , aur current element ka index - nearest max element in the left nikaal lo , wo hi span hoga current ith element ka
#include <bits/stdc++.h>
using namespace std;

vector<int> stockSpan(const vector<int> & input)
{
    // stack would be of pair type , as we need to store 2 things nearest max element to the left and it's index 
    stack<pair<int , int>> s ;
    vector<int> output ;

    for (int i = 0; i < input.size(); i++)
    {
        while(!s.empty() and s.top().first <= input[i])
        {
            s.pop();
        }
        
        // while loop se baahar aane ke 2 tareeke hai 
        if(s.empty()) // matlab current input[i] se pichhe 
        {             // saare element chhote thee from i-1 to 0 ,
                      //  tabhi upar while loop mein sab pop ho gya stack se
            int cds = max((i-(-1)) , 1); // consecutive days span 
            output.push_back(cds) ;
            s.push({input[i] , i});
        }
        else if(s.top().first > input[i])
        {
            output.push_back(i - s.top().second) ;
            s.push({input[i] , i});
        }
    }

    return output ;

}


int main()
{
    vector<int> input = {100, 80, 60, 70, 60, 75, 80 , 110} ;
    // vector<int> input = {31,41,48,59,79} ;
    vector<int> output = stockSpan(input);


    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }

    return 0;
}