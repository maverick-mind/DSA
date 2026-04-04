#include<bits/stdc++.h>
using namespace std;

// by default cpp STL uses , deque internally to execute stack 
// but we can also tell ki kis type ka data structure internally use karee stack for implementation 
// for vector --> stack<int , vector<int>> S 
// for doubly linked list --> stack<int , list<int>> S 
// for deque (by default) --> stack<int > S 
class Stack{

private :
    vector<int> v ;

public : 
    void push(int val)
    {
        v.push_back(val);
    }

    void pop()
    { // pop can only be doe when there is any element present
        // if(!v.empty()) v.pop_back() ;

        // or we can also call empty fxn to check 
        if(empty()) return ;
        else{
            v.pop_back() ;
        }
    }

    int top()
    {
        // stack only return top value when stack is non-empty
        return v.back() ; // or v[v.size()-1]
    }

    int size()
    {
        return v.size() ;
    }

    bool empty()
    {
        return v.empty() ;

    }

};
 
int main() 
{
    Stack s ;

    s.push(1);
    s.push(2);
    s.push(15);
    s.push(30);

    cout<<"top element : "<<s.top()<<endl;
    s.pop() ;
    cout<<"top element : "<<s.top()<<endl;

    cout<<s.size()<<endl;

    cout<<"is empty : "<<s.empty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<"is empty : "<<s.empty()<<endl;

    return 0 ;
}