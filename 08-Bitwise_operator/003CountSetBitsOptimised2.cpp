#include<iostream>

using namespace std;

int main() {

	int n = 2;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		cnt++;

		// clear the rightmost set bit of n

		n = n & (n - 1); // Brian Kernighan's Algorithm
        // Instead of checking all 32 or 64 bits of a number one by one, this algorithm clears the rightmost set bit in every iteration using the bitwise expression: n = n & (n - 1). The loop runs exactly as many times as there are set bits, achieving a time complexity of O(k), where k is the number of set bits.

	}

	cout << cnt << endl;

	return 0;
}