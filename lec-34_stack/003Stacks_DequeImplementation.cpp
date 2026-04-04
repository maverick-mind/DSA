#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Stack {

private :
    deque<T> d ; // we are impleenting in such a way that , stack ka top is at deque ka end 

public : 
    void push(T val)
    {
        d.push_back(val);
    }
    void pop(){
        if(empty()) return ;

        d.pop_back();
    }
    T top(){
        return d.back();// or d[d.size()-1] ;
    }
    int size(){
        return d.size();
    }
    bool empty(){
        return d.empty() ;
    }



} ;


int main() 
{
    Stack<int> s ;

 cout << "size : " << s.size() << endl; // 0
	cout << "isEmpty ? " << s.empty() << endl; // 1

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "size : " << s.size() << endl; // 5
	cout << "top : " << s.top() << endl; // 50
	cout << "isEmpty ? " << s.empty() << endl; // false

	s.pop(); // 50 popped

	cout << "size : " << s.size() << endl; // 4
	cout << "top : " << s.top() << endl; // 40

	s.pop(); // 40 popped

	cout << "size : " << s.size() << endl; // 3
	cout << "top : " << s.top() << endl; // 30

	s.pop(); // 30 popped

	cout << "size : " << s.size() << endl; // 2
	cout << "top : " << s.top() << endl; // 20

	s.pop(); // 20 popped

	cout << "size : " << s.size() << endl; // 1
	cout << "top : " << s.top() << endl; // 10

	s.pop(); // 10 popped

	cout << "size : " << s.size() << endl; // 0
	cout << "isEmpty ? " << s.empty() << endl; // true

    return 0 ;
}