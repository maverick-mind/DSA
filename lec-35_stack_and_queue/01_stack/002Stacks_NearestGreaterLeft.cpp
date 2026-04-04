#include<bits/stdc++.h>
using namespace std;
 
vector<int> fxn( const vector<int> & v)
{
    stack<int> s ;// monotonic stack

    vector<int> ans ;
    int n = v.size() ;

    for (int i = 0; i < n; i++)
    {
        // find the nearest greater element to the left of v[i]

        while(!s.empty() and s.top() <= v[i])
        {   // s.top() cannot be the nearest greater element to
			// the left of v[i] so we can safely pop them
            s.pop() ;
        }
        // while loop se baahar 2 reason ki wajah se aa sakte hai 
        if(s.empty()) // then ans[i] = -1 
        {   // v[i] doesn't have any greater element to its left
            ans.push_back(-1) ;
            s.push(v[i]);
        }
        else if (s.top() > v[i])
        {
            // s.top() is the nearest greater element to the left of v[i]
            ans.push_back(s.top()) ;
            s.push(v[i]);
        }
    }

    return ans ;

}
 
int main() 
{
    vector<int> v = {5,2,0,4,1,3,6};

    vector<int> ans = fxn(v);

    for (int i = 0; i < ans.size(); i++) // -1 5 2 5 4 4 -1
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
 
 
 
    return 0 ;
}