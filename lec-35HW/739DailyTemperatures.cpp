#include<bits/stdc++.h>
using namespace std;
 
vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size() ;
    vector<int> ans(n , 0);
    stack<pair<int,int>> s ; // < value , index >

    for (int i = 0; i < n; i++)
    {
        while(!s.empty() and temperatures[i] > s.top().first)
        {
            ans[s.top().second] = (i - s.top().second); // (i - j) days 
            s.pop() ;
        }
        // if(s.empty() or temperatures[i] <= s.top().first )
        // {
            s.push({temperatures[i] , i });
        // }
    }

    return ans ;

} 


int main() 
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
 
 
 
    return 0 ;
}