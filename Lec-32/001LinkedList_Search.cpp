#include<bits/stdc++.h>
using namespace std;
 
class ListNode{

public :
// attributes of ListNode 
    int val ;
    ListNode * next ;

// parameterized constructor 
    ListNode(int val)
    {
        this-> val = val ;
        this-> next = NULL;
    }
};
 
void insertAtHead( ListNode * &head , int val )
{
    // create a memory on heap 
    ListNode * n = new ListNode(val);

    // insert at head 
    if(head == NULL)
    {
        head = n ;
        return ;
    }
    else if(head != NULL)
    {
        n->next = head ;
        head = n ;
    }
}

void printLinkedList(ListNode * head)
{
    if(head == NULL)
    {
        cout<<"LL is empty before calling printLinkedList function"<<endl;
    }

    while(head != NULL)
    {
        cout<<head->val<<"-->";
        head = head ->next ;
    }
    cout<<"NULL"<<endl;
}
// check if the given value exist in LL or not
bool searchIterative(ListNode * head , int target)
{
    while(head != NULL)
    {
        if(head->val == target)
        {
            return true ; 
        }
        else{
            head = head-> next ;
        }
    }
    if(head == NULL)
    {
        return false ;
    }
}

// check if the given value exist in LL or not
bool searchRecursive( ListNode * head , int target)
{
    // base case 
    if(head == NULL)
    {
        return false ;
    }
    if(head->val == target)
    {
        return true ;
    }

    // recurrence relation
    // if(searchRecursive(head->next , target))//if it is returning true then return true
    // {
    //     return true ; 
    // }
    // else{
    //     return false ;
    // }

    // whatever friend is returing , you have to return the same 
    return searchRecursive(head->next , target);
    
}

int main() 
{
    ListNode * head = NULL ;
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    printLinkedList(head);
    // cout<<"searched iteratively : " << searchIterative(head , 400)<<endl;
    // cout<<"searched iteratively : " << searchRecursively(head , 400);

    int target = 30 ;
    
    searchIterative(head, target) ? cout << target << " found" << endl : cout << target << " not found" << endl;

	searchRecursive(head, target) ? cout << target << " found" << endl : cout << target << " not found" << endl;
 
    return 0 ;
}