#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template <typename T>
class Stack {
	vector<T> v; // internal representation of stack
    stack<T> minStack;
public :

	void push(T val) {
		v.push_back(val);
        if(minStack.empty() or val <= minStack.top()) minStack.push(val) ;
	}

	void pop() {
		if (empty()) {
			// stack is empty
			return;
		}
        T data = v.back() ;
        v.pop_back();

        // check wether the current top is also on the top of the getMinimum 
        if(data == minStack.top()) minStack.pop() ;
	}

	int size() {
		return v.size();
	}
	T top() {
		return v.back(); // return v[v.size()-1]
	}
	bool empty() {
		return v.empty();
	}
    T getMinimum()
    {       
        if(!minStack.empty())
        {
            return minStack.top() ;
        }
    }
};

int main() {

	Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(2);
    s.push(40);
    s.push(-5);
    s.push(60);

    cout<<s.getMinimum()<<endl;// -5
    s.pop(); // 60 popped 
    s.pop(); // -5 popped 

    cout<<s.getMinimum()<<endl;// 0

	
	return 0;
}