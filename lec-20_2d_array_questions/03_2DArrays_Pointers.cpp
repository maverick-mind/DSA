
#include<iostream>

using namespace std;

int main() {

	int arr[3][4] = { {10,11,12 ,13},
                      {20,21,22,23},
                      {30,31,32,33} };

    // arr hai 2d array ka naam , arr + 1 means arr + 1 * sizeof(each element of arr , and each element of arr is 1 row ), that would be  1st row of arr 
    //  arr + 2 means arr + 2 * sizeof(row), that would be  2nd row of arr 
    // size of row is number of columns * size of integers 
	cout << arr[0] << " " << &arr[0][0] << " " << arr << endl;
	cout << arr[1] << " " << &arr[1][0] << " " << arr + 1 << endl;
	cout << arr[2] << " " << &arr[2][0] << " " << arr + 2 << endl;

    cout << *arr[0] << " " << arr[0][0] << " " << **arr << endl;
	cout << *arr[1] << " " << arr[1][0] << " " << **(arr + 1) << endl;
	cout << *arr[2] << " " << arr[2][0] << " " << **(arr + 2) << endl;

    //1st row all elements 
    cout<<*(*(arr + 1))<<" "<<*(*(arr + 1)+1)<<" "<<*(*(arr + 1)+2)<<" "<<*(*(arr + 1)+3)<<endl;
    // to get arr[i][j] , internally what is happening is :
    // step 1. go to the ith row --> arr + i
    // step 2. go inside the ith row by derefrencing *(arr + i) which is same as writing arr[i] 
    // step 3. go to the jth column --> arr[i] + j that is *(arr + i) + j
    // and arr[i] + j means arr[i] + j * size of int , sizeof(int) beause arr[i] is an array of integers 

    // step 4. now go inside ith row and jth column by 
    //derefrencing *(arr[i] + j)  which is same as writing *(*(arr + i) + j) again which is same as arr[i][j]

    // arr+1 means hum 1st row ko point kar rhe hai , *(arr+1) will give value at address of 1st row , now again doing derefrencing *(*(arr+1)+2) will give value at 2nd element of 1st row 
    // ab 1st row ke 2nd element par jo value hai uss ko nikaalne ke liye we do *(*(arr + 1)+2)

	return 0;
}
// in cpp , in 1d array , name of the array , arr acts as a pointer to 0th index element, and stores address of 0th index element
// in 2d array ,
//     arr is the name of 2D array 
//     arr[0] is pointer that stores address of 0th element of 0th row 
//     arr[1] is pointer that stores address of 0th element of 1st row 
//     arr[2] is pointer that stores address of 0th element of 2nd row 