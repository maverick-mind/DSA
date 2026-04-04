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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head == NULL) return head ;

    ListNode * slowKaPrev = NULL ;
    ListNode * slow = head ;
    ListNode * fast = head ;

    int i = 1 ;
    while(i <= n)
    {
        fast = fast -> next ;
        i++;
    }
    
    while(fast != NULL)
    {
        slowKaPrev = slow ;
        slow = slow -> next ;
        fast = fast -> next ;
    }
    if(slow != head)
    {
        slowKaPrev->next = slow->next ; 
        return head ;
    }
    else{
        head = head -> next ;
        return head ;
    }
    

}

int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);

	printLinkedList(head);
    head = removeNthFromEnd(head , 2);
    printLinkedList(head);


	return 0;
}