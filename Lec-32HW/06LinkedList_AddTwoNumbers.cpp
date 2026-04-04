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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    // step 1. reverse both LL
    l1 = reverseIterative(l1);
    l2 = reverseIterative(l2);

    ListNode * dummy = new ListNode(0) ;
    ListNode * temp = dummy ;
    // now start doing sum , and maintain a variable for carry
    int carry = 0 ;
    int sum = 0 ;

    while(l1 != NULL and l2 != NULL)
    {
        sum = l1->val + l2->val + carry ;
        carry = sum / 10 ;
        sum = sum % 10 ;

        temp -> next = new ListNode(sum);
        temp = temp -> next ;

        l1 = l1 -> next ;
        l2 = l2 -> next ;
    }

        while(l1 != NULL and carry != 0)
        {
            sum = l1->val + carry ;
            carry = sum / 10 ;
            sum = sum % 10 ;

            temp -> next = new ListNode(sum);
            temp = temp -> next ;

            l1 = l1 -> next ;
        }
        
        temp -> next = l1 ;

        while(l2 != NULL and carry != 0)
        {
            sum = l2->val + carry ;
            carry = sum / 10 ;
            sum = sum % 10 ;

            temp -> next = new ListNode(sum);
            temp = temp -> next ;

            l2 = l2 -> next ;
        }
        temp -> next = l2 ;
    
    if((l1 == NULL and l2 == NULL) and carry != 0)
    {
        temp->next = new ListNode(carry);
    }

    ListNode * newHead = dummy -> next ;
    newHead = reverseIterative(newHead) ;
    return newHead ;
}

int main() {

	ListNode* head = NULL; // initially, linkedList is initially empty

	insertAtHead(head, 5);
	// insertAtHead(head, 4);
	// insertAtHead(head, 2);
	// insertAtHead(head, 7);

	printLinkedList(head);

	// head = reverseIterative(head);

	// printLinkedList(head);

    ListNode * head2 = NULL;

    insertAtHead(head2, 5);
	// insertAtHead(head2, 6);
	// insertAtHead(head2, 5);

	// printLinkedList(head2);

	// head2 = reverseIterative(head2);

	printLinkedList(head2);

    ListNode * sumLL = addTwoNumbers(head , head2);
    // sumLL = reverseIterative(sumLL) ;

    printLinkedList(sumLL);

	return 0;
}