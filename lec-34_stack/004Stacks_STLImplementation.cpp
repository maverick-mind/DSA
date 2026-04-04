// khaali stack mein pop() and top() are undefined (garbage value milega)

#include<iostream>
#include<stack>

// by default cpp STL uses , deque internally to execute stack 
// but we can also tell ki kis type ka data structure internally use karee stack for implementation 
// for vector --> stack<int , vector<int>> S 
// for doubly linked list --> stack<int , list<int>> S 
// for deque (by default) --> stack<int > S 

using namespace std;

int main() {

	stack<int> s;
	//cout << "top : " << s.top() << endl; // top() can't be accessed as stack is emppty till now aur ye 11th line ke niche waale line ko execute hoone nahi dega 


	s.push(10);
	s.push(20);
	s.push(30);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();
	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "empty : " << s.empty() << endl; // stack is empty here 

    // stack empty hoone ke baad agar pop() karoge to size() mein garbage value chalaa jaayega and top ko access nahi kar paayenge then 
	s.pop();
	s.pop();
	s.pop();
	s.pop();

    cout << "size : " << s.size() << endl; // size has garbage value here , if tried to pop() after stack is empty

	return 0;

}