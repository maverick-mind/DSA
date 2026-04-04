#include<bits/stdc++.h>
using namespace std;
 
stack<int> insertAtBottom (stack <int> s , int val)
{           // by-default stack is passed by value 
    
    // base case 
    if(s.empty())
    {
        s.push(val);
        return s ;
    }

    // recurrence relation
    // first empty one element and store it in variable 
    int temp = s.top() ;
    s.pop() ;
    s = insertAtBottom(s , val);

    // backtracking --> now push temp on top of the stack 
    s.push(temp);

    return s ;
}

void print( stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop() ;
    }
    cout<<endl;
}

int main() 
{
    stack<int> s ;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    print(s);

    int value = 10 ;
    s = insertAtBottom(s , 10);   

    print(s);


    
 
    return 0 ;
}