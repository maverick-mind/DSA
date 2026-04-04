// normal linked list is also called --> singly linked list or forward linked list 
// doubly linked list , circular linked list 

// c++ mein doubly linked list ko LIST bhi bolte hai
// doubly linked list mein tail pointer bhi maintain karte hai 
#include<bits/stdc++.h>
using namespace std;

// node is not a datatype in cpp , so to create a node we need CLASS 
//  int that CLASS , we need one variable to store value of data 
// one more variable of node pointer type to make link : pointer to a node 

class ListNode{

    public : 
        // attributes of ListNode --> val , next 
        int val ;
        ListNode* next ; // next is pointer of ListNode type to store address of ListNode

        ListNode(int val) // parameterized constructor
        {
            this->val = val ;// jo ListNode type ka object banega parameterised constructor ke through , this ussko point karega 
            this->next = NULL;
        }
};
 
// to pass a LL to a fxn all you have to do is -> pass the address of HEAD NODE 
// teo return a LL from a fxn all you have to return is --> return the address of HEAD NODE 

int main() 
{
     // new ListNode(10); // heap pe new address return karega uss ListNode ka jahaa 10 insert hua hai ,so the pointer should be of ListNode type to store this address

     ListNode *ptr = new ListNode(10); // ptr is a pointer to ListNode 

     // both syntax are correct to access the val
     cout<<(*ptr).val<<"   "<<ptr->val<<endl;

     if(ptr->next == NULL)
     {
        cout<<"there is no node following this node"<<endl;
     }

 
    return 0 ;
}