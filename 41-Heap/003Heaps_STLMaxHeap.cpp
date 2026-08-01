/*

	STL implementation of the heap/priority_queue data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

    // internally , we can implement a heap using either vector or deque 

    // we can tell the compiler to internally use a deque 
    priority_queue<int , deque<int>> heapdq ; // by this syntax , the priority queueo internally uses deque of <int> type 

    // by-default , internally priority_queue is implemented using vector 
	// priority_queue<int> m; // maxHeap by default

    // by default , heap is a max heap 
    // by default , internal representation of max heap initialisation syntax : priority_queue<int> m is : 
    priority_queue<int , vector<int> , less<int>> m ;

	m.push(1);
	m.push(3);
	m.push(2);
	m.push(7);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(9);
	m.push(8);

	cout << m.size() << endl;

	while (!m.empty()) { // it is the user responsibility to access heap.top() only when it is non-empty , same as we only access stack.top() when it is non-empty , same as we only access queue.front() when it is non-empty
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}