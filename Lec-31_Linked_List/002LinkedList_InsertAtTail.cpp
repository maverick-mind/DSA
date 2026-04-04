#include <bits/stdc++.h>
using namespace std;

class nodeList
{

public:
    int val;
    nodeList *next;

    nodeList(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// time : O(n) where n is the length of the linked list 
void insertAtTail(nodeList *&head, int val) // head sirf tabhi change hoga insert at tail 
{                               // ke case mein , agar linked list empty hai ,
                                // so for that edge case , we need to pass head by refrence 
    // creating a new node for val on heap
    nodeList *n = new nodeList(val);
    nodeList * temp = head ;

    if (temp== NULL)
    {
        head = n;
    }
    else if(temp != NULL)
    {
        while (temp->next != NULL) // if we don't put the above if condition 
        {                          // the head is NULL we can't do head->next as it will
                                   // error(segmentation fault) ,
                                   // coz NULL pointer can't be dereferenced in cpp
            temp = temp->next;
        }
        temp->next = n;
    }
}

// here we are passing head ptr by value since we don't want changes done to head inside the fxn to be reflected in the caller fxn(i.e. int main() here)
void printLinkedList(nodeList *head) // head pointer is not passed by refrence ,
{                                    // issliye directly head se traverse kar sakte hai
                                     // koi nayaa pointer banaane ki zarurat nahi hai
    if(head == NULL)
    {
        cout<<"LL is empty before calling printLinkedList function"<<endl;
    }
    
    while (head != NULL)
    {
        cout << head->val << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    nodeList *head = NULL; // initially jab linked list create nahi hui hai then
                           // head is pointing to NULL
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
    }

    printLinkedList(head); // 10 20 30 40 50

    // insertAtTail(head , 0);

    // printLinkedList(head); // 0 10 20 30 40 50

    return 0;
}