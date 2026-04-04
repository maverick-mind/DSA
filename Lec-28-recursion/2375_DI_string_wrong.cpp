#include<bits/stdc++.h>
using namespace std;

vector < pair<char, bool >> nums = {
                            {'0', false},
                            {'1', true}, {'2', true}, {'3', true}, {'4', true},
                            {'5', true}, {'6', true}, {'7', true}, {'8', true} , {'9', true}
};

// WRONG
int selectNum(char last_ch , char symbol)
{


    if(symbol == 'I'){ // matlab current element , pichhle element se badaa hoga , so we have to look from last_ch - '0' to 9 th index , ki kaun sa char par true boolean value hai 
        for (int i = last_ch - '0' + 1 ; i <= 9; i++)
        {
            if(nums[i].second == true)
            {
                return i ; 
            }
        }
    }

    if(symbol == 'D'){ // matlab current element , pichhle element se chhota hoga , so we have to look from 1 to j-1 th index , ki kaun sa char par true boolean value hai 
        for (int i = 1; i < last_ch - '0' ; i++)
        {
            if(nums[i].second == true)
            {
                return i ; 
            }
        }
    }

    // return something absurd , agar koi character select karna possible nahi ho rha hai to 
    return -1;
}
 
// if string pattern is of length 'n' , we need to take sequence of 'n+1' decisions to get the lexographically smallest string

// i --> to track the current index in string pattern 
void fxn( string pattern , string ans , string &final , char symbol , int i)
{
    // base case 
    if( ans.size() == pattern.size() + 1 )
    {
        final = ans ;
        return ;
    }

    // recurrence relation 
    // har decision ke liye we have 9 choices available 
    for(int j = 1 ; j <= 9 ; j++)
    {
        if(ans.empty())
        {
            ans.push_back(nums[j].first);
            nums[j].second = false ;

            fxn(pattern , ans , final , pattern[i] , i ) ; 

            // backtracking
             nums[j].second = true ;
             ans.pop_back() ;
        }

        else { 
        // kya hum j daal sakte hai , or can we push jth char at ans.push_back()
        int indx = selectNum(ans[ans.size()-1] , symbol);
        
        if(indx == -1) return ;
        else if(symbol == 'I')
        {
           if(indx != -1 and  ans[ans.size()-1] < nums[indx].first )
           {
             ans.push_back(nums[indx].first);
             nums[indx].second = false ;
             fxn(pattern , ans , final , pattern[i] , i + 1 );

             // backtracking 
             nums[indx].second = true ;
             ans.pop_back() ;
           }
        }

        else if (symbol == 'D')
        {
            if( indx != -1 and   ans[ans.size()-1] < nums[indx].first )
           {
             ans.push_back(nums[indx].first);
             nums[indx].second = false ;
             fxn(pattern , ans , final , pattern[i] , i + 1 );

             // backtracking 
             nums[indx].second = true ;
             ans.pop_back() ;
           }
        }

       }
    }
}


string smallestNumber(string pattern) {
        
    string ans = "";
    string final = "";
    fxn(pattern , ans , final , 'I' , 0 );

    return final ;
} 


int main() 
{
    string pattern = "DIID";
    string ans = smallestNumber(pattern) ; 

    cout<<ans;
    
    return 0 ;
}