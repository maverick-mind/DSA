//1. every element of set is unique  
// insert , erase ,  find 
//2. insert , erase (delete) , find(search) in set takes O(log n) time 
// 3. insertion in set is by-default in increasingly sorted order 

// set is internally a tree and it does not support indexing like s[i]
/*
	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values
*/

#include<iostream>
#include<set>
using namespace std;
 
int main() 
{
    // set<int> s ; // by-default set is in increasing order 
    set<int , greater<int>> ; // for decreasing order set 
    cout<<"size : "<<s.size()<<endl;
    cout<<"empty : "<<s.empty()<<endl; // boolean value

    s.insert(50);
    s.insert(40);
    s.insert(30);
    s.insert(20);
    s.insert(10);
    s.insert(10); // ignored , as 10 is already present
    s.insert(10); // ignored , as 10 is already present

    cout<<"size : "<<s.size()<<endl; // 5


    s.erase(40) ; // if this element exists then only get deleted , if does not exists nothing will happen 

    cout<<"size : "<<s.size()<<endl; // 4

    for( auto it = s.begin() , end = s.end() ; it != end ; it++)
    { // it is like pointer to elements of set s 
        cout<<*it<<"  ";
    }

    cout<<endl;

    for(int x : s)
    {
        cout<< x << " ";
    }
    cout<<endl;

    // set<> does not support indexing
    // for(int i = 0 ; i < s.size() ; i++)
    // { // set is internally a tree and it does not support indexing like s[i]
    //     cout<<s[i]<<" ";
    // }

    if(s.find(30) != s.end()) // if 30 exists
    {                       // then we get location of 30
                    // if 30 does not exists , it s.find() will return 
                  // the end iterator , that is s.end() 
        cout<<"30 is present"<<endl;
    }else{
        cout<<"30 is not present"<<endl;
    }

    if(s.count(40))// set mein unique elements hoonge 
    {             // so , count will return either 1 or 0 
        cout<<"40 is present"<<endl;
    }else{
        cout<<"40 is not present"<<endl;
    }

    s.clear() ; // iss se set khaali ho jaayega 
    cout<<"size : "<<s.size()<<endl;
    cout<<"empty : "<<s.empty()<<endl;

    return 0 ;
}