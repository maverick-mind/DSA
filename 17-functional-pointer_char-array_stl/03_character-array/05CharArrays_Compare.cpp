#include<iostream>
#include<cstring>
using namespace std ; 
// 0 if str1 == str2
// 1 if s1 > s2
// -1 if s2 > s1
 
// lexographical comparison (dictionary order): aphabetical order mein coparison karenge string ko 
// time : min(length of str1 , length of str2)
int compareStrings(char str1[] , char str2[])
{
    int i1 = 0 , n1 = strlen(str1) ;
    int i2 = 0 , n2 = strlen(str2);
    
    while(i1 < n1 and i2 < n2)
    {
        if(str1[i1] > str2[i2])
        {
            return 1 ;
        }
        else if (str1[i1] < str2[i2])
        {
            return -1 ;
        }

            i1++; // else if (str1[i1] == str2[i2])
            i2++;      
    }

    if(i1 < n1)
    {
        return 1 ;
    }

    if(i2 < n2)
    {
        return -1 ;
    }

    // else return 0 , matlab dono string equal hai 
    return 0 ;
}

// method - 2 
int compareStrings2(char str1[] , char str2[])
{
    int i = 0 , n1 = strlen(str1) ;
    // int i2 = 0 ;  // no need of i2 , one iterator is enough
    int n2 = strlen(str2);
    
    while(str1[i] != '\0' and str2[i] != '\0')
    {
        if(str1[i] > str2[i])
        {
            return 1 ;
        }
        else if (str1[i] < str2[i])
        {
            return -1 ;
        }

        i++; // else if (str1[i1] == str2[i2])
        
    }

    if(i < strlen(str1))
    {
        return 1 ;
    }

    if(i < strlen(str2))
    {
        return -1 ;
    }

    // else return 0 , matlab dono string equal hai 
    return 0 ;
}
 
int main() 
{
    char str1[] = "abzz";
    char str2[] = "abzzaa";

    //int result = compareStrings2(str1 , str2);


    // in-built comparison for 2 trings , use strcmp
    int result = strcmp(str1 , str2);    // 0 if str1 == str2
                                         // 1 if s1 > s2
                                         // -1 if s2 > s1

    if(result == 0)
    {
        cout<<str1 << " is equal to "<<str2<<endl;
    }
    else if(result == 1)
    {
        cout<<str1 << " > "<<str2<<endl;
    }
    else{ // result == -1 
        cout<<str1 << " < "<<str2<<endl;
    }
    
 
 
 
    return 0 ;
}