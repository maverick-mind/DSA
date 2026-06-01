#include <bits/stdc++.h>
using namespace std;


// set<> and map<> as a container takes help of balanced BST internally , thus all operations like insert , find , erase are in O(logn)

// time : O(nlogn)
// time : O(n) avg , O(n^2) in worst case if unordered_map<> is used 
// space : o(n) due to map<>/unordered_map<>

bool isDuplicatePresent(const vector<int> & v)
{
    map<int,int> freqMp ; // key are elements of vector and values are their frequencies 

    // for(auto it : v)
    // {
    //     freqMp[it]++;
    // }

    // bool check = false ;
    // for(auto [element , freq] : freqMp)
    // {
    //     if(freq > 1)
    //     {
    //         check = true ;
    //         cout<<element<<" -> "<<freq<<endl;
    //     }
    // }
    // cout<<endl;

    // return check ;

    for(auto x : v)
    {
        freqMp[x]++;
        if(freqMp[x] > 1) return true ;
    }
    return false ;
}


// for unordered_set 
// operations such as insert , find , erase :  time : avg --> O(1)  , in worst case --> O(n)

// for set<>
// time : O(nlogn)
// space : o(n) due to set<>

// for unordered_set<>
// time : O(n) avg , in-worst case : O(n^2)
// space : O(n)

bool isDuplicatePresent2(const vector<int> & v)
{
    // unordered_set<int> s ;
    // for(auto it : v)
    // {
    //     if(s.find(it) != s.end())
    //     {
    //         return true ; // duplicate found
    //     }
    //     s.insert(it);
    // }

    // return false;



     // store the vector in set or unordered_set , if both set and vector size are unequal then duplicate exist

        return unordered_set<int>(v.begin() , v.end()).size() < v.size() ;
}

int main()
{
    vector<int> v = {1, 2, 3, 1,2};

    isDuplicatePresent(v) ? cout<<"duplicate found"<<endl : cout<<"duplicate not found"<<endl;
    isDuplicatePresent2(v) ? cout<<"duplicate found"<<endl : cout<<"duplicate not found"<<endl;
    return 0;
}