#include<iostream>
using namespace std;

int* f() { // function f() ke call stack empty ho jaane ke baad , agar hum f() ke andar ke local variable x ka address return karee aur &x par padee hue value ko access karne ki koshish karenge , then it may give garbage value or error , this thing is known as DANGLING POINTER problem 
	int x = 10;
	return &x;
}

int main() {

	int* xptr = f();
	cout << *xptr << endl;

	return 0;
}

