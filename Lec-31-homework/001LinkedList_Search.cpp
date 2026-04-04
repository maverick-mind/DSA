#include<bits/stdc++.h>
using namespace std;
 

class nodeList{

public :
// attributes of nodeList 
    int val ;
    nodeList * next ;

// parameterized constructor 
    nodeList(int val)
    {
        this-> val = val ;
        this-> next = NULL;
    }
};
 
void insertAtHead( nodeList * &head , int val )
{
    // create a memory on heap 
    nodeList * n = new nodeList(val);

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

void printLinkedList(nodeList * head)
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
// search index of a given element iteratively 
int searchIterative(nodeList * head , int val)
{
    int i = 0 ;
    while(head != NULL)
    {
        if(head->val == val)
        {
            return i ; 
        }
        else{
            i++;
            head = head-> next ;
        }
    }
    if(head == NULL)
    {
        return -1 ;
    }
}

int searchRecursively( nodeList * head , int val)
{
    // base case 
    if(head == NULL)
    {
        return -1 ;
    }
    if(head->val == val)
    {
        return 0 ;
    }

    // recurrence relation ke 2 cases 
    int x =searchRecursively(head->next , val) ;
    // 1. kya dost ne -1 return kiya 
    if(x == -1)
    {
        return -1 ;
    }

    // kya dost ne -1 return nahi kiya 
    else {
        return 1+ x ;
    }

}

int main() 
{
    nodeList * head = NULL ;
    insertAtHead(head , 50);
    insertAtHead(head , 40);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    printLinkedList(head);
    cout<<"index searched iteratively : " << searchIterative(head , 40)<<endl;
    cout<<"index searched iteratively : " << searchRecursively(head , 40);
    
    return 0 ;
}