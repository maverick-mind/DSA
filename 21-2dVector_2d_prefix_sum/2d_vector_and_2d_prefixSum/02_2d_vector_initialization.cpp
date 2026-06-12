#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int> > v = {{10, 15, 20, 25},
                              {30, 35, 40, 45},
                              {50, 55, 60, 65}};

    int m = v.size() ; // # rows 
    int n = v[0].size(); // # columns

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}