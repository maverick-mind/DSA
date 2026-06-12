#include<bits/stdc++.h>
using namespace std ; 
 
/*
🔍 Summary:
Operation                       	Meaning
v[i].push_back(x);	             Adds a column to row i
v.push_back({a, b, c});     	Adds a new row to the 2D vector

*/
 
int main() 
{
    int m = 3 , n = 2 ;
    vector< vector<int>> v(m , vector<int>(n , 12));// 3 rows, 2 columns
    // initializing all elements with 12
    
    v[0].push_back(39);  // Now row 0 has 3 elements , jaggered 2-d vectors
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }

    // adding new row 
    v.push_back({7,7,7,7,7});
    cout<<"2-d vector after adding new row "<<endl;
     for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
 
    return 0 ;
}