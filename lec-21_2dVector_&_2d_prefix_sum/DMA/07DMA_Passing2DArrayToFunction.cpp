#include<iostream>
using namespace std;

// heap ke 2d array (int **ptr) ko int ptr[][] aisee nahi bhej sakte error aayega 
// and same vice-versa , stack ke 2d array (int ptr[3][4]) ko int **ptr ki tarah nahi bhej sakte error aayega 
/*
❌ It breaks for 2D arrays:

int arr[3][4];
read(arr, 3, 4); // ❌ Can't go to int**, not compatible
Because arr[i] is of type int[4], and arr is of type int (*)[4], not int**.


*/

void read(int** ptr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ptr[i][j];
		}
	}
}

void print(int** ptr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int m = 3;
	int n = 4;

	int** ptr = new int*[m];

	for (int i = 0; i < m; i++) {
		ptr[i] = new int[n];
	}

	read(ptr, m, n);

	print(ptr, m, n);

	for (int i = 0; i < m; i++) {
		delete [] ptr[i];
	}

	delete [] ptr;

	return 0;
}