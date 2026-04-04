#include<bits/stdc++.h>
using namespace std;
 
vector <int> fxn(vector<int> A)
{
    // if we want to calculate nearest greeater element to the right of A[i] , we would have data from n-1 to i + 1 , then only for A[i] , work is done in const time , and for n elements , total work is done in O(n) time 

    stack <int> s ; // index of nearest greater element to A[i] would be at the top of the stack 
    vector<int> ans ;
    int n = A.size() ;

    for (int i = n - 1 ; i >= 0; i--)
    {
        while(!s.empty() and A[s.top()] < A[i])
        {
            s.pop() ;
        }
        // while loop se baahar nikalne ke 2 raaste hai 
        if(s.empty())
        {
            ans.push_back(n);
            // s.push(i);
        }
        else {
            ans.push_back(s.top());
            // s.push(i);
        }
        s.push(i);
    }
    reverse(ans.begin() , ans.end());

    return ans ;
    
}
 
int main() 
{
    vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = fxn(A);

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
 
    return 0 ;
}