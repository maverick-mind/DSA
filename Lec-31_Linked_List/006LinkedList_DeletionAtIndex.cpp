#include<iostream>

using namespace std;

class ListNode {

public :

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}

void printLinkedList(ListNode* head) {

    if(head == NULL)
    {
        cout<<"LL is empty before calling printLinkedList function"<<endl;
    }
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

// time : O(n)
void deleteAtIndex(ListNode * &head , int index)
{
    // cases 
    //1. if index < length of the LL 

    // 1.1 index is 0     
         if(index == 0 )
         {
            // 1.1.1 if LL length is 0
            if(head == NULL ) return ;

            // 1.1.2 if LL length is 1 (single element in LL)
            else if(head -> next == NULL)
            {
                delete head ;
                head = NULL;
                return ;
            }

            // 1.1.3 if LL length is more than 1
            else if(head -> next != NULL)
            {
                ListNode * temp = head ;
                head = head->next ;
                delete temp ;
                temp = NULL ;
                return ;
            }
            
         }
   
    int i = 1 ; // technically i = 0 is handled above 
    ListNode * prev = head ;
    ListNode * current = head->next ;
    while(i < index and current != NULL)
    {
        prev = current ;
        current = current-> next ;
        i++;
    }
    // 1.2  1 <= index < length - 1 (index is <= tail , either tail or less than tail)
    if(current != NULL)
    {
        prev->next = current-> next ;
        delete current ;
        current = NULL;
        return ; 
    }

    // 2. index >= length of LL -> no deletion possible
    if(current == NULL)
    {
        cout<<"index "<<index<<" is outside the range of LL"<<endl;
        return ;
    }

    // if index is 0(deletion at head) , if 0 < index < length of LL , if index >= length of LL(no deletio possible)

}


int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtIndex(head , 6); // 0 based indexing 

	printLinkedList(head);

	return 0;
}