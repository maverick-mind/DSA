// ****************GOOD questions as per implementation****************

// for a window of size k 
// the window looks like this : 
// (some smaller elements in the left of maximum value) then : Maximum element : then (again some smaller elements in the right of maximum element)

// we don't need to track the smaller element to the left of the maximum element , because it cannot be the possible future answer of any subarray 
// also for the right 
// for ex : 
/*
    nums : [2,8,1,3,0,7,4,5,6] , k : 4
           for subarray 1 [2,8,1,3] : max value : 8 
                            so we don't need , smaller values less than max value in the left of max value , so don't store 2 
                            also in the right of 8 in the same subarray , we have [1,3] , 3 is bigger than 1 , and 3 is in the right of 1 , so 1 cannot be possible answer for any subarray , so don't track 1 also 
*/