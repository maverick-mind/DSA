#include<iostream>
#include<vector>
#include<stack>
#include<utility>

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
	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int lengthOfLL(ListNode * head)
{
    int l = 0 ;
    while(head != NULL)
    {
        l++;
        head = head -> next ;
    }
    return l;
}

vector<int> nextLargerNodes(ListNode* head) {
 
    // vector<int> ans(lengthOfLL(head) , -1);
    int n = lengthOfLL(head) ;
    vector<int> ans( n , 0);
    stack<pair<ListNode* , int >> s ; // <node , index>

    for (int i = 0; i < n; i++)
    {
        // check current head->val kitne stack ka top se badaa hai
        while(!s.empty() and head->val > s.top().first->val)
        {
            // head -> val is ans for stack ka top
            ans[s.top().second] = head -> val ;
            s.pop();
        }   
        // if(s.empty() or head->val <= s.top().first.val)
        // {
            s.push({head , i});
        // }

        head = head -> next ;
    }
    return ans ;

}


int main() {

	ListNode* head = NULL; // initially, linkedList is empty

	insertAtHead(head, 5);
	insertAtHead(head, 3);
	insertAtHead(head, 4);
	insertAtHead(head, 7);
	insertAtHead(head, 2);

	printLinkedList(head);

    vector<int> ans = nextLargerNodes(head);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }

	// printLinkedList(head);

	return 0;
}