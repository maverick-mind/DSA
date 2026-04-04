// 10-->20-->30-->20-->10
// steps to find if a LL is pallindrome or not
// 1. find the mid point 
// 2. reverse the part of LL after the mid-point 
// 3. mid->next = NULL
// 4. now compare headfromFront with headfromEnd easily after reversing the part of LL after mid-point

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

ListNode* reverseIterative(ListNode* head) {

	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur != NULL) {
		ListNode* temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}

	return prev;

}

ListNode * findMidPoint(ListNode * head )
{
    if(head == NULL) return head ; // agar zero node hai , to return head 
    ListNode * slow = head ;
    ListNode * fast = head->next ;

    while(fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next ;
        slow = slow->next ;
    }

    return slow ;
}

bool isPalindrome(ListNode* head) {
    
    // step 1. find the midpoint node
    ListNode * midPoint = findMidPoint(head) ; 

    // step 2. reverse the sub linked list after midPoint
    ListNode * headfromEnd = reverseIterative(midPoint->next);

    // step 3. now compare head from the front with head from the end 
    while(headfromEnd != NULL) // agar ll odd size ki hai to pahle
    {          // second half waala sub-ll khatam hoga , aur agar
               // even size ki hai , to dono sub-ll ek saath khatam hoge 
        if(head-> val != headfromEnd->val)
        {
            return false ;
        }
        head = head->next ;
        headfromEnd = headfromEnd->next ;
    }

    // mann kre to waapas se linked list ko sahi kar do , jiss ko todee marodee ho , but na bhi karo to chalegaa , as question mein sirf true ya false bataana hai  

    return true ;

}

int main() 
{
    ListNode * head = NULL ;
    // insertAtHead(head , 50);
    insertAtHead(head , 10);
    insertAtHead(head , 20);
    insertAtHead(head , 30);
    insertAtHead(head , 30);
    insertAtHead(head , 20);
    insertAtHead(head , 10);

    printLinkedList(head);
    ListNode * midPoint = findMidPoint(head);

    (midPoint != NULL ) ? cout<<"middle node is : " <<midPoint->val<<endl : cout<<"midPoint is NULL"<<endl; 

    isPalindrome(head) ? cout<<"pallindrome"<<endl : cout<<"not pallindrome"<<endl;
    printLinkedList(head);
    
    return 0 ;
}