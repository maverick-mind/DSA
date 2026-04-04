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

// time : O(1)
void deleteAtHead(ListNode * &head )
{
    // cases 
    // if LL has 0 node , 1 node , more than 1 node 

    // case 1. : LL has 0 node 
    if(head == NULL) return ;

    // case 2 : if LL has 1 node 
    else if(head->next == NULL)
    {
        delete head ; // head jiss heap memory ko point kar rha hai 
        head = NULL ; // ussko delete kar ke , head ko NULL karna zaruri hai
                      // so that head kisi random memory ko point na karee
    }
    
    // case 3 : if LL has more than 1 node 
    else if(head->next != NULL)
    {
        ListNode * temp = head ;
        head = head -> next ;
        delete temp ;
        temp = NULL; // iss pointer mein NULL daal do delete karne ke baad 
    }
}


int main() {

	ListNode* head = NULL; // linked list is initially empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	printLinkedList(head);

	deleteAtHead(head);

	printLinkedList(head);

	return 0;
}