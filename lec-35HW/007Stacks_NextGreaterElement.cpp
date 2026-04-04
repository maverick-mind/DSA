#include <bits/stdc++.h>
using namespace std;

// finding next greater element in the right by moving/scanning left to right
vector<int> fxn(vector<int> A)
{
    stack<pair<int, int> > s; // <value , index>
    cout << "hi ";
    vector<int> ans(A.size());

    for (int i = 0; i < A.size(); i++)
    {
        if (s.empty()) // matlab ith element se pichee
        {              // sabhi element ka nearest greater element
          //  to the right mill chucka hai
            s.push({A[i], i});
        }
        else
        {  //if stack is not empty then A[i] could be possible 
           // next greater element to few elements at the top of stack
            while (!s.empty() and A[i] > s.top().first)
            {
                ans[s.top().second] = A[i];
                s.pop();
            }
            // if (s.empty())
            // {
            //     s.push({A[i], i});
            // }
            // else if (A[i] <= s.top().first)
            // {
            //     s.push({A[i], i});
            // }

            // agar !(A[i] > s.top().first) , it means abd A[i] ko stack mein push kar do so that in future isske liye bhi next greater element in right dhund sakee 
            s.push({A[i], i});
        }
    }
    // after iterating over complete array A[] , there may be few elements jinnke right mein koi greater element na ho aur wo abhi bhi stack mein padee ho , to unnko correspending -1 daal do ans mein
    while (!s.empty())
    {
        ans[s.top().second] = -1;
        s.pop();
    }
    return ans;
}

int main()
{
    vector<int> A = {5, 3, 6, 7, 2, 1, 4};
    vector<int> ans = fxn(A);

    for (int i = 0; i < A.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}