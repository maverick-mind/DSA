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

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

ListNode* oddEvenList(ListNode* head) {
        
    if(head == NULL or head->next == NULL or head->next->next == NULL )
    {
        return head ; 
    }

    ListNode * ptrOdd = head ;
    ListNode * ptrEven = head -> next ;
    ListNode * headEven = head -> next ; // the starting node is considered odd , so it's next node is even

    bool icno = true ; // isCurrentNodeOdd

    while(ptrOdd->next != NULL and ptrEven->next != NULL)
    {
        if(icno)
        {
            ptrOdd->next = ptrEven->next ;
            ptrOdd = ptrEven->next ;
            icno = false ; 
        }
        else{
            ptrEven->next = ptrOdd->next ;
            ptrEven = ptrOdd->next ;
            icno = true ;
        }
    }
    ptrOdd->next = headEven;
    ptrEven->next = NULL ;
    return head ;
}


int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 8);
	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLinkedList(head);
    head = oddEvenList(head);
    printLinkedList(head);

	

	return 0;
}