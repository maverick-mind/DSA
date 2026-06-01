/*
	Vectors Part I

	How to create a vector ?
		> use empty container constructor (default constructor)
	How to add elements to a vector ?
	    > use vector::push_back to add element at back (constant time operator)
	How to remove elements from a vector ?
	    > use vector::pop_back to remove element from back (constant time operation)
	    > use vector::clear to remove all the elements from a vector
	How to check size of a vector ?
		> use vector::size to know number of elements in a vector
		> use vector::capacity to know current capacity of the vector
		> use vector::max_size to know maximum number of elements that can added in a vector
	How to check if a vector is empty ?
	    > use vector::empty or check if vector size is 0
	How to access elements in a vector at a particular index ?
	    > use vector::operator[]
	    > use vector::at
	How to iterate over elements in a vector ?
	    > use indexing like arrays
	    > use an iterator
	    > use forEach loop

*/


#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int> v ; // default constructor or empty container constructor

    cout<<"size : "<<v.size()<<endl; // 0
    cout<<"capacity : "<<v.capacity()<<endl; // 0

    v.push_back(10);

    cout<<"size : "<<v.size()<<endl; // 1
    cout<<"capacity : "<<v.capacity()<<endl; // 1

    v.push_back(20);

    cout<<"size : "<<v.size()<<endl; // 2
    cout<<"capacity : "<<v.capacity()<<endl; // 2

    v.push_back(30);

    cout<<"size : "<<v.size()<<endl; // 3
    cout<<"capacity : "<<v.capacity()<<endl; // 4

    v.push_back(40);

    cout<<"size : "<<v.size()<<endl; // 4
    cout<<"capacity : "<<v.capacity()<<endl; // 4

    v.push_back(10);

    cout<<"size : "<<v.size()<<endl; // 5
    cout<<"capacity : "<<v.capacity()<<endl; // 8

    cout<<"First Element : "<<v[0]<<endl;
    cout<<"First Element : "<<v.front()<<endl;

    cout<<"Last Element : "<<v[v.size()-1]<<endl;
    cout<<"Last Element : "<<v.back()<<endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    for(int x : v){ // x ek int type ka variable hai jo ek ek kar ke vector v ke values ko lega , jahaa tak v ka size hoga utna ye chalega , and iss mein x < v.size() ya x++ ya sab karne ki zarurat nahi hai , ame goes for auto x : v
        cout<<x<<" ";
    }
    cout<<endl;

    for(auto x : v){// auto ka matlab hai ki compiler khud se pta lagaa lega ki kis type ka datatye x mein aa rha hai , jis type ka datatype hoga uss type ka variable hoga x 
        cout<<x<<" ";
    }
    cout<<endl;

    //v.begin() ->first element ka address
    // v.end() --> last element ka address + 1 (it means v.end() is not inclusive it is exclusive , it is not included)
    // so to iterate through addresses we need pointers and to access value of it we need * operator on pointer 
    for (auto ptr = v.begin() ; ptr != v.end(); ptr++) {
		cout << *ptr << " ";
	}
	cout << endl;

    v.pop_back();// will delete the last element , but do not shrink the capacity of the vector
    cout << "size : " << v.size() << endl;
	cout << "capacity : " << v.capacity() << endl;
    for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

    v.clear();// will clear all elements from array but do not shrink the capacity of the vector 

	cout << "size : " << v.size() << endl;
	cout << "capacity : " << v.capacity() << endl;

	v.empty() ? cout << "true, vector is empty" << endl :  cout << "false, vector is non-empty" << endl;

    return  0 ;
}