#include<bits/stdc++.h>
using namespace std;
 
vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> stk ; // stk ke top ko current asteriods[i] se check karna ki collosion ke baad kaun bachega and kya hoga 

  int i = 0 ;
  while( i < asteroids.size() )
  {
    // chances of collision --> agar stk ka top element right move kare , aur asteroids[i] left move kre 
    // stk ein wo wo elements honge asteroids[i] ke jo abhi tak collosion survive kar chuke hai (from 0 to i - 1 )

    // case 1 : agar stack empty hai --> no collision possible 
    if(stk.empty())
    {
        stk.push(asteroids[i]) ;
        i++;
    }
    
    // case 2 : stk is non-empty
    else{
        // collision occur only when agar stk ka top right mein move kare , aur asteroids[i] left(-ve symbol value less than 0 ) mein move kre 
        // case 2.1 : if collosion occurs 
        if(stk.top() > 0  and  asteroids[i] < 0 )
        {
            // case 2.1.1 both stk.top and asteroids[i] have same magnitude 
            // then both gets destroyed 
            if(abs(stk.top()) == abs(asteroids[i]))
            {
                // cout<<asteroids[i]<<endl;
                stk.pop() ;
                i++; 
            }
            // case 2.1.2 if stk.top has greater magnitude than asteroids[i]  
            // then asteroids[i] gets destroyed 
            else if(abs(stk.top()) > abs(asteroids[i]))
            {
                i++;
            }
            // case 2.1.3 if stk.top has lesser magnitude than asteroids[i]  
            // then stk.top() gets destroyed , but we will not do i++ , as we need to compare next top value of stk with this asteroids[i]
            else if(abs(stk.top()) < abs(asteroids[i]))
            {
                stk.pop() ;
            }
        }

        // case 2.2: no collision occurs as asteroids[i] moving right and stk.top() moving left , in this case push asteroids[i] on top of the stack 
        else if((asteroids[i] > 0 and stk.top() < 0) or  (asteroids[i] < 0 and stk.top() < 0) or (asteroids[i] > 0 and stk.top() > 0) )
        {
            stk.push(asteroids[i]) ;
            i++;
        }
    }
    
  }
  // now push the stack into the vector and reverse the vector 
  // alac = asteriod left after collision
   vector<int> alac ;
  while(!stk.empty())
  {
    alac.push_back(stk.top()) ;
    stk.pop() ;
  }
  // reverse the vector 
  reverse(alac.begin() , alac.end());
  return  alac ;
} 

int main() 
{
    vector<int> asteroids = {7,3,-4,5,2,-8,2,4,1 ,-4};

    // alac = asteriod left after collision
    vector<int> alac = asteroidCollision(asteroids);

    for (int i = 0; i < alac.size(); i++)
    {
        cout<<alac[i]<<" ";
    }cout<<endl;
    
    return 0 ;
}