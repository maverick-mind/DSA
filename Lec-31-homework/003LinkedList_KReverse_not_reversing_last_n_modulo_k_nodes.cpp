#include <bits/stdc++.h>
using namespace std;

class nodeList
{

public:
    // attributes of nodeList
    int val;
    nodeList *next;

    // parameterized constructor
    nodeList(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(nodeList *&head, int val)
{
    // create a memory on heap
    nodeList *n = new nodeList(val);

    // insert at head
    if (head == NULL)
    {
        head = n;
        return;
    }
    else if (head != NULL)
    {
        n->next = head;
        head = n;
    }
}

void printLinkedList(nodeList *head)
{
    if (head == NULL)
    {
        cout << "LL is empty before calling printLinkedList function" << endl;
    }

    while (head != NULL)
    {
        cout << head->val << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// void reverse_k_sized_ll(nodeList * pntc  , nodeList *nntc  nodeList   * snoc , nodeList * tnoc)
// {
//     nodeList * ahead = snoc->next ;

// }

// void linkedListK_ReverseIterative(nodeList * head , int k)
// {
//     nodeList * pntc = NULL ; // previous node to chain of k-size
//     nodeList * nntc = NULL ; // next node to chain of k-size
//     nodeList * snoc = head ; // starting node of chain
//     nodeList * tnoc = head ; // tail node of chain for now is head , jaise jaise head update hoga tnoc bhi update kar denge

//     while(head != NULL)
//     {
//         int i = 1 ;
//         while(i <= k and head != NULL)
//         {
//             tnoc = head ;
//             head = head -> next ;
//             i++ ;
//         }
//         // again set i to 1
//         nntc = head ;
//         reverse_k_sized_ll(pntc , nntc , snoc , tnoc) ;

//     }

// }

int lengthOfLL(nodeList *head , int k)
{
    int length = 0;
    while (head != NULL and length < k ) // length jaise hi >= k  
    {                  // hoga , base case nahi chalega ,
                      // so no need to further iterate in this loop
        head = head->next;
        length++;
    }
    return length;
}
// space : O(n/k) : total recursive calls = n/k , so fxn call stack ki maximum height would be n/k

// time : (n/k <-- total recursive call) * (k baar while loop chalega in each recursive call) * (base case waala lengthOfLL fxn k time chalega)
// so , time : O(n/k * 2k) ~ O(n.k)
nodeList *kReverseRecursive(nodeList *head, int k)
{
    // base case
    // no need to reverse the last part which is smaller than k
    if (lengthOfLL(head , k) < k) // or lengthOfLL(head) < (n%k)
    {
        return head;
    }

    // recurence relation
    // first k nodes ko reverse karne ka kaam mera , baaki saara friend laa ke dega , it means baaki ke (n/k - 1) nodes ko k parts mein friend reverse karega , aur jo kaam friend kar lega usska hff (head from my friend laa ke dega)

    // 1. mera kaam hai to reverse the 1st k nodes 
    nodeList *prev = NULL;
    nodeList *current = head;
    nodeList *ahead = NULL;
    int i = 1;
    while (i <= (k) and current != NULL)
    {
        ahead = current->next;
        current->next = prev;
        prev = current;
        current = ahead;
        i++;
    }

    // 2. ask your friend to K-Reverse the remaining subList 
    nodeList *headFromMyFriend = kReverseRecursive(current, k);

    // 3. attach the 1st K nodes with K-Reversed sublist 
    head->next = headFromMyFriend;
    return prev;
}

int main()
{
    nodeList *head = NULL;
    insertAtHead(head, 100);
    insertAtHead(head, 90);
    insertAtHead(head, 80);
    insertAtHead(head, 70);
    insertAtHead(head, 60);
    insertAtHead(head, 50);
    insertAtHead(head, 40);
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    insertAtHead(head, 10);

    printLinkedList(head);
    int k = 2;
    head = kReverseRecursive(head, 3);
    printLinkedList(head);

    return 0;
}