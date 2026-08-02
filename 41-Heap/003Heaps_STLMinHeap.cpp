/*

	STL implementation of the min_heap data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

    // if we create object of priority_queue class , and if we want it to work as min_heap , we need to pass 3 things [datatype of heap(int , char , etc) , internal representation(vector or deque) , comparator we need to use ]

	// priority_queue<int /* datatype of the heap */, vector<int> /* internal representation of the heap */, greater<int>/* comparator needed for sorting */> m;

    // we can make our own comparator , by any of the methods : function pointer ,function object 


	priority_queue<int /* datatype of the heap */, deque<int> /* internal representation of the heap */, greater<int>/* comparator needed for sorting */> m;

    // internally , greater<int> is a class. SO if we write our custom comparator , that should be inside a class , and should be a functor 

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}