// maintain 2 heaps : (Left heap) | median | (right heap)

// for the left side of the median : we need to access the larger elements
// for the right side of the median : we need to access the smaller elements

// when median will decreases , some element from the left heap should go to the right heap
// when median will increases , some element from the right heap should go to the left heap


// difference in the size of the heap can be either 0 or 1 , then only the top of the heap could be around the centre or near median 
class MedianFinder {
    priority_queue<int>
        left; // max heap on the elements smaller than the median
    priority_queue<int, vector<int>, greater<>>
        right; // min heap on the elemlargerents
    int median ;

public:
    MedianFinder() {}

    void addNum(int num) {
        // if(left.size() == right.size()){
        if(left.empty() and right.empty())
        { 
            left.push(num);
            median = left.top() ;
        }

        else if(num <= median) { // insert into the left heap
            if (left.size() == right.size()) {
                left.push(num);
                median = left.top();
            } else if (left.size() < right.size()) {
                left.push(num) ;
                median = (left.top() + right.top()) / 2.0 ;
            }
            else if(left.size() > right.size())
            {
                right.push(left.top()) ;
                left.pop() ; 
                left.push(num) ;

                median = (left.top() + right.top()) / 2.0 ;
            }
        }else if(num > median){
            // num > median 
            if(left.size() == right.size())
            {
                right.push(num) ;
                median = right.top() ;
            }
            else if (left.size() < right.size())
            {
                left.push(right.top()) ;
                right.pop() ;
                right.push(num);

                median = (left.top() + right.top()) / 2.0 ;
            }
            else if(left.size() > right.size())
            {
                right.push(num) ;
                median = (left.top() + right.top()) / 2 ;
            }
        }
    }

    double findMedian() {
        if(left.size() > right.size())
        {
            return left.top() ;
        }else if(left.size() < right.size())
        {
            return right.top() ;
        }
        // else if(left.size() == right.size())
        // {
            return (left.top() + right.top()) / 2.0 ;
        // }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();



class MedianFinder {
    priority_queue< int > left ; // max heap on the elements smaller than the
median priority_queue<int , vector<int> , greater<> > right ; // min heap on the
elemlargerents  than the median int median  ; int count = 0 ;


// maintain 2 heaps : (Left heap) | median | (right heap)

// for the left side of the median : we need to access the larger elements
// for the right side of the median : we need to access the smaller elements

// // when median will decreases , some element from the left heap should go to
the right heap
// void shiftLeftToRightHeap(pq<int> & left , pq<int , vector<int> , greter<>> &
right)
// {

// }

// // when median will increases , some element from the right heap should go to
the left heap
// void shiftRightToLeftHeap(pq<int> & left , pq<int , vector<int> , greter<>> &
right)
// {

// }



public:

    MedianFinder() {

    }


    void addNum(int num) {
        // initially both the heap are empty
        count++ ;
        // if(left.empty() and right.empty()){
        if(count == 1){
            median = num ;
            left.push(num) ;
        }
        else{

            // if num > median : median will shift to the right side
            if(num >= median)
            {
                if(right.empty())
                {
                    median = double(left.top()) + (double(num) - left.top()) / 2
; // update the median right.push(num) ; }else{ // if num > median and right
heap is not empty
                    // the new median depends on the size of the left heap and
the size of the right heap if(count % 2 != 0) // total element count in the
stream is ODD right now
                    {
                        median = right.top() ;
                        right.pop() ;
                        left.push(median) ; // left is storing values <= median
                    }
                    else{ // count % 2 == 0 // total element count in the stream
is EVEN right now right.push(num) ; median = double(left.top()) +
(double(right.top()) - left.top()) / 2 ; // update the median
                    }
                }
            }
            else{ // num < median // median will shift to the left side
                // if(num < median)
                // {
                    if(count % 2 != 0) // odd number of elements in the stream
                    {
                        left.push(num) ;
                        median = left.top() ;
                    }
                    else{ // even number of elements in the stream
                        left.push(num) ;
                        median = double(left.top()) + (double(right.top()) -
left.top()) / 2 ; // update the median right.push(left.top()) ; left.pop() ;
                    }
                // }
            }
        }
    }



    double findMedian() {
       if(left.empty() and !right.empty())
        {
            return right.top() ;
        }
        if(right.empty() and !left.empty())
        {
            return left.top() ;
        }

        return ((double)(left.top()) + right.top()) / 2 ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
