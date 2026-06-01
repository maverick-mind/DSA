#include<iostream>
using namespace std;

int main()
{
	int array[] = { 1,-2,3,-2,4,-3,4,-20,3};
	int n = sizeof(array)/sizeof(int) ;

	int max_sum_so_far = array[0];// let the first element be largest and then compare 
	int sum_so_far = array[0];

	for(int i = 0 ; i < n ; i++)
	{
		// this code works in all case , for negative as well as positive number or mixed positive and negative numbers 

		sum_so_far = max(array[i] , sum_so_far + array[i]) ;// sum_so_far negative hoga kabhi kabhi but koi baat nahi , jaise hi next positive array[i] milega wo handle ho jaayega 
		
		max_sum_so_far = max( sum_so_far , max_sum_so_far);

	}

	cout<<max_sum_so_far;

	return 0 ; 
}
