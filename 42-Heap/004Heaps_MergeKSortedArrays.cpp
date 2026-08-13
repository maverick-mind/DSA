#include<bits/stdc++.h>
using namespace std;
 

class triple{

public : 
    int val ; 
    int row ; 
    int col ;

    triple(int val , int row , int col)
    {
        this->val = val;
        this->row = row ;
        this->col = col ;
    }
};

class functorCmp{
public : 
    bool operator()(triple & a , triple & b)
    {
        return a.val > b.val ; // if a.val > b.val , a will go below in priority than b , ad because it is min-Heap , so we want larger values to go below in priority 
    }
} ;

int main()
{
    vector<vector<int>> v = {
        {1, 3, 7, 10},
        {2, 4, 5, 11},
        {0, 6, 8, 10}
    } ;
    cout<<"hi"<<endl;
    int m = v.size() ;
    int n = v[0].size() ;

    vector<int> ans ;
    ans.reserve(m * n) ; // we reserved the capacity of vector ans as v.size() * v[0].size()

    priority_queue<triple , vector<triple> , functorCmp> minHeap ; 

    for(int i = 0 ; i < m ; i++)
    {
        minHeap.push({v[i][0] , i , 0}) ;
    }

    while(!minHeap.empty())
    {
        triple temp = minHeap.top() ;
        ans.push_back(temp.val) ;

        minHeap.pop() ;
        
        int row = (temp.row) ;
        int col = ++(temp.col) ;

        if(col < v[row].size()) // in case , if each row has different number of columns 
        {
            minHeap.push({v[row][col] , row , col}) ;
        }
    }

    for(int & val : ans)
    {
        cout<<val<<" ";
    }

    return 0;
}