// bloomDay[i] --> ith flower kab tak bloom karega
// m --> total number of bouquets we have to make
// k --> number of flower in 1 bouquets (or adjacent flowers required in each bouquets )

// in binary search
// start = min element in bloomDay array (sabse pahla flower itne dino ke baad bloom karega)
// end = max element in bloomDay array (sabse aakhiri flower itne dino ke baad bloom karega)
// hum constraints ke according bhi start aur end le sakte thee ,
// like --> 1 <= bloomDay[i] <= 1e9 , but ye bound badaa hoga most of the time, min aur max value of bloomDay array se , sometimes start aur end constraints ke according lenge , and if possible jaise iss question mein , to test case ke according lenge

// from start to end , every mid is a potential answer (mid value hai ek day ki)

// mid nikaalne ke baad check , can I make 'm' bouquets of 'k' adjacent flower in mid number of days --> if no then start = mid + 1 , if yes then store the ans = mid , and end = mid - 1

#include <bits/stdc++.h>
using namespace std; 

bool predicate_fxn(const vector<int> & bloomDay , int m , int k , int timelimit)
{ 
    int cbf = 0 ; // to track no. of "consecutive bloomed flowers"
    int tbpsf = 0 ;// to track no. of "total bouquets possible so far" 
    // if tbpsf >= m bouquets return true 
    for (int dayOfBloom : bloomDay)
    {

            if(dayOfBloom <= timelimit ) cbf++ ;

            else if(dayOfBloom > timelimit )
            {
                cbf = 0; // agar flower bloo b=nahi hua hai 
                         // then reset cbf = 0 ;
            }
        

        if(cbf == k)
        {// k consecutive bloomed floowers is required for 1 bouquets
            tbpsf++;
            cbf = 0 ;
            if(tbpsf ==m)
            {
                return true ;
            }
        }
    }
    // return tbpsf >= m ;
    return false 

}

// T.C. = log(*max_element of bloomDay - *min_element of bloomDay) * n

// agar vector ka size bahut badaa ho gya , then copying a vector can be expensive , thus pass it by refrence (&)
int minDays(vector<int> &bloomDay, int m, int k)
{
    int start = *min_element(bloomDay.begin() , bloomDay.end());
    
    int end = *max_element(bloomDay.begin() , bloomDay.end());

    int ans = -1;
    while( start <= end) // Time : log(max - min) * n 
    {
        int mid = start + (end - start)/2 ;

        // can I make 'm' bouquets of 'k' adjacent flowers in 'mid' number of days 
        // so now we need predicate function which tells yes or no , if it is possible to make 'm' bouquets of 'k' adjacent flowers in 'mid' number of days 
        if(predicate_fxn(bloomDay , m , k , mid ))
        {
            ans = mid ;// agar mid days mein ho jaayega to ans = mid kar ke , mid se kam days ke liye check karenge 
            end = mid - 1 ;
        }
        else{// agar mid days mein nahi hua to mid se kam days mein bhi nahi hoga , so start = mid + 1 
            start = mid + 1 ;
        }
    }

    return ans ;
}

int main()
{

    vector<int> bloomDay = {1, 3, 2, 1, 10, 4, 2, 3};

    int m = 2 ; // total number of bouquets 
    int k = 3 ; // adjacent flowers required in each bouquets
    
    cout<<minDays(bloomDay , m , k);

    return 0;
}
