#include<bits/stdc++.h>
using namespace std;
 
// disjoint set would be a class 
class disjointSet{

    // the internal representation of disjoint set class is a disjoint forest representation and to implement it , we can use map , or vector as a map

public :
    vector<int> parent ; // map that encodes disjoint forest 

    // constructor 
    disjointSet(int n)
    {
        parent.resize(n + 1) ; // during resize , all the elements are filled with 0 , and as we are considering nodes from [1 to n] , so if parent[x] == 0 it means x is not in the disjoint set forest yet

        // same as doing 
        // parent.resize(n+1 , 0) ;
    }
  

    // operations in disjoint set 
    void createSet(int x) // constant time 
    {
        parent[x] = x ; // node x is pointing to itself 
    }

    // iterative
    int findSet(int x) // depends on the height of the tree in the forest set 
    { // it will return the leader/representative of the set in which x exists

        int currNode = x ;

        while(parent[currNode] != currNode)
        {
            currNode = parent[currNode] ;
        }

        return currNode ;
    }

    // recursive 
    // int findSet(int x)
    // { // it will return the leader/representative of the set in which x exists

    //     if(parent[x] == x) return x ;

    //     return findSet(parent[x]) ;
    // }

    void unionSet(int x , int y)//depends on the height of the tree in the forest set
    {
        int leaderOfX = findSet(x) ; // leader of set in which x exists 
        int leaderOfY = findSet(y) ; // leader of set in which y exists 

        // now we have choice 
        // either make : parent[leaderOfX] = leaderOfY ;
        // or make : parent[leaderOfY] = leaderOfX ;
        if(leaderOfX != leaderOfY)
        parent[leaderOfY] = leaderOfX ;
    }

};


int main() 
{
    int n ; 
    cin >> n ;

    disjointSet ds(n) ;

    ds.createSet(1) ; 
    ds.createSet(2) ; 
    ds.createSet(3) ; 
    ds.createSet(4) ; 
    
    
    cout<<ds.findSet(1)<<endl;
    cout<<ds.findSet(2)<<endl;
    cout<<ds.findSet(3)<<endl;
    cout<<ds.findSet(4)<<endl;

    cout<<endl;

    // currently sets in disjoint set are : [1] , [2] , [3] , [4] 

    ds.unionSet(2 , 3) ; // disjoint set looks like : [1] , [2,3] , [4] 

    cout<<ds.findSet(1)<<endl;
    cout<<ds.findSet(2)<<endl;
    cout<<ds.findSet(3)<<endl;
    cout<<ds.findSet(4)<<endl;

    cout<<endl;

    ds.unionSet(1 , 4) ;

    cout<<ds.findSet(1)<<endl;
    cout<<ds.findSet(2)<<endl;
    cout<<ds.findSet(3)<<endl;
    cout<<ds.findSet(4)<<endl;

    cout<<endl;

    ds.unionSet(3 , 4) ;

    cout<<ds.findSet(1)<<endl;
    cout<<ds.findSet(2)<<endl;
    cout<<ds.findSet(3)<<endl;
    cout<<ds.findSet(4)<<endl;

    cout<<endl;
  
    return 0 ;
}