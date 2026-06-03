#include <bits/stdc++.h>
using namespace std;

// in binary search on answer --> ans E [lower_bound , Upper_bound]
// in this question : lower bound = 0 ; (minimum 0 hamburgers to banaa hi lega polycarus)
// lower bound : kitchen mein nb , ns , nc jitna kam ho sakte hai utna kam hai 
//               nb = 1 , ns = 1 , nc = 1 
//               market mein rate jitna jyaada ho sakta hai utna hai , pb = 100 , ps = 100 , pc = 100 
//               bank balance jitna kam ho sakta hai utna kam hai , r = 1 
//               recipe string ka size jitna jyaada ho sakta hai , utna jyaada hai , |recipe| = 100
// so in this case , 0 hamburger is possible to make 




// for upper Bound : maximum kitne hamburgers bann sakte hai --> 
//      1. --> pahle se kitchen ki inventory full honi chaniye , nb = 100 , ns = 100 , nc = 100
//      2. --> market mein saaman bahut saste hoone chahiye , pb = 1 , ps = 1 , pc = 1 
//      3  --> bank balance should be as high as possible , r = 10^12
//      4  --> recipie mein sabse kam ingredient use ho rha ho, |recipie| = 1,length of recipie string 

// so in best case , total burger possible to make --> 100 burgers from kitchen materials , 10^12 burgers after purchasing material from shop
// 

int B ,S,C ; // Global variables mein by-default 0 hota hai , not garbage value 

bool predicate_fxn(string recipe , int nb , int ns , int nc , int pb , int ps , int pc , long long mid , long long r)
{   
    long long burgerCountSoFar = 0 ;
    // burgers that could be made without buying any further ingredients 
    burgerCountSoFar = min((nb / B) , min((ns / S) , (nc / C))) ;
    nb -= burgerCountSoFar * B ;
    nc -= burgerCountSoFar * C ;
    ns -= burgerCountSoFar * S ;

    // mid number of burger mein se burgerCountSoFar number of burgers bann gye hai , now we need to check ki kya hum mid number of burgers banaa sakte hai with the help of kitchen items and the r rubel we have 


    // nb , nc , ns ke remaining value ko unnke respective market rate se multiply kar ke r mein add kar do , ye hum issliye kar rhe hai taaki while loop ke andar extra conditions na lagaana padee ye check karne ke liye ki kitne nb , nc ya ns bachee hue thee kitchen mein
    r = r + (nb * pb) + (ns * ps) + (nc * pc) ;

    // while(r >= 0) // nb , ns , nc ki bhi kuchh value bachi hongi kitchen mein , unn ko bhi account mein lo r mein se minus karne se pahle 
    // {
    //     r = r - B*pb ;

    //     if(r >= 0) r -= C*pc;
    //     if(r >= 0) r -= S*ps;
    //     burgerCount++;
    // }

    r = r - (mid - burgerCountSoFar)*(B*pb + C*pc + S*ps );


    // return burgerCountSoFar >= mid ;
    return r >= 0 ;


}

long long hamburgers(string recipe , int nb , int ns , int nc , int pb , int ps , int pc , long long r)
{
    long long start = 0 ; // min hamburger he can cook is 0
    long long end = 1e12 + 100 ;
    long long ans = 0 ;

    while(start < end)
    {
        long long mid = start + (end - start)/2 ;

        if(predicate_fxn(recipe , nb , ns , nc , pb , ps , pc ,mid , r ))
        { 
            ans = mid ;
            start = mid + 1 ;
        }
        else{
            end = mid - 1 ;
        }
    }
        return ans ;
}

    int main()
{
    string recipe;
    cin >> recipe;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    B = count(recipe.begin(), recipe.end(), 'B'); // bread count 
    S = count(recipe.begin(), recipe.end(), 'S'); // sausage count 
    //int C = count(recipe.begin(), recipe.end(), "C"); // Don't write inside double quotes " " , as it asks for character , and double quotes will make it look like string 
    C = count(recipe.begin(), recipe.end(), 'C'); //cheese count

    cout<<hamburgers(recipe , nb , ns , nc , pb , ps , pc, r );

    return 0;
}