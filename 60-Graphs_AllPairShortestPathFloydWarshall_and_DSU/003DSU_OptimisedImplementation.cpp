#include<bits/stdc++.h>
using namespace std;
 
// disjoint set would be a class 
class disjointSet{

    // the internal representation of disjoint set class is a disjoint forest representation and to implement it , we can use map , or vector as a map

public :
    vector<int> parent ; // map that encodes disjoint forest 

    vector<int> rankMap ; // map that encodes rank of each tree in the disjoint forest 

    // constructor 
    disjointSet(int n)
    {
        parent.resize(n + 1) ; // during resize , all the elements are filled with 0 , and as we are considering nodes from [1 to n] , so if parent[x] == 0 it means x is not in the disjoint set forest yet

        // same as doing 
        // parent.resize(n+1 , 0) ;

        rankMap.resize(n+1 , 0) ; // rankMap refers to height of the tree 
        // initially height of the tree is 0
    }
  

    // operations in disjoint set 
    void createSet(int x) // constant time 
    {
        parent[x] = x ; // node x is pointing to itself 
        rankMap[x] = 0 ; // height of the leaf node in the tree is 0
    }

    // recursive 
    int findSet(int x)
    { // it will return the leader/representative of the set in which x exists

        // base case 
        if(parent[x] == x) return x ;

        // recurrence relation 
        // return findSet(parent[x]) ; // un-optimised 
        return parent[x] = findSet(parent[x]) ; // path compression (make leader as parent of all the nodes in the path from node x to the leader)
        // because of path compression : findset operation is on average constant (in worst case , it is still the height of the disjoint set tree)
    }

    void unionSet(int x , int y)//depends on the height of the tree in the forest set --> union by rank
    {
        int leaderOfX = findSet(x) ; // leader of set in which x exists 
        int leaderOfY = findSet(y) ; // leader of set in which y exists 

        // now based on rank , make connection
        if(leaderOfX != leaderOfY){
            
            if(rankMap[leaderOfX] == rankMap[leaderOfY])
            {
                rankMap[leaderOfX]++ ; // increase the height of any one of the tree , now the lower if-condition will become true 
            }
            if(rankMap[leaderOfX] > rankMap[leaderOfY])
            {
                parent[leaderOfY] = parent[leaderOfX] ; // overtime in the rank-map some values are important and some values will become outdated , like after this operation leaderOfY will be useless for rankMap because leaderOfY is no more a leader of any set
            }else{
                // rankMap[leaderOfX] < rankMap[leaderOfY]
                parent[leaderOfX] = parent[leaderOfY] ;
            }
        }
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