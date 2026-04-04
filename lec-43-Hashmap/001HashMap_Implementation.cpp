// internally unordered_map is an ARRAY 
// if multiple keys points to a single hash_idx , then COLLISION will occur , we can't avoid collisions , we can only handle them 
// in c++ , we say unordered_map for HASH_MAP or HASH_TABLE
// we want to create an array of size 'n' on the heap , such that every element of that array should be a node pointer 
// for creating integer type array of size n on heap :  int ptr = new int[n];
// for creating array of size 'n' and of node* type :
//                                    node** ptr = new node*[n];

#include<bits/stdc++.h>
using namespace std;
 
class node{

public :
    int key ;
    int value ;
    node* next ; // singly linkedList (forward linkedList)

    node(int key ,int value)
    {
        this->key = key ;
        this->value = value;
        next = NULL ; 
    }
};

class HashMap{
    int N ; // to store the hash table capacity 
    int M ; // to store the hash table size 
    double L ;// to store the load factor thrashold 

    // T is pointer to the node pointer
    node* * T ; // to store the pointer to the dynamic 
                // array that represents hash table 

    int hashfn(int key)
    {
        // transform key into a hash index 
        return key % N ; 
    }

    void transfer(node* head)
    {
        // 1. rehash (key , value) pairs present in the linkedList 
        // represented by "head" pointer to the updated hashMap 
        node * temp = head ;
        while(head != NULL)
        {
            insert(head->key , head->value);
            temp = head ; 
            head = head -> next ;

        // 2. release memory allocated for the linkedList represented 
        // by head pointer 
            delete temp ;
            temp = NULL ;
        }

    }

    void rehash(){
        // 1. save pointer to the current hashmap and it's capacity 
        node** oldT = T ;
        int oldN = N ; 

        // 2. create a hashMap with double capacity 
        N = 2 * N ;
        M = 0 ; // nayi table mein abhi kuchh nahi hai 
        T = new node*[N];
        for (int i = 0; i < N; i++)
        {
            T[i] = NULL ;
        }

        // 3. transfer (key , value) pairs from old hashMap to the updated hashMap 
        for (int i = 0; i < oldN; i++)
        {
            transfer(oldT[i]) ;
        }

        // 4. release the memory allocated to the old hashMap 
        delete [] oldT ;
    }

public :
    HashMap(int N = 5 , double L = 0.7)
    {
        this->N = N ; // initial capacity : N 
        this->M = 0 ; // initial size : 0 
        this->L = L ;
        T = new node*[N];
    
        // initialise all elements of node* array on heap with NULL
        for (int i = 0; i < N; i++)
        {
            T[i] = NULL ;
        }
    }
        void insert (int key , int value )
        {
            // 1. transform the key into hash index using the hash function 
            int hashIdx = hashfn(key);


            // 2.create a node with the given (key , value) pair and insert it at 
            // head of the linkedList stored at the hash index 
            node * temp = new node(key , value);
            temp->next = T[hashIdx];

            // 3. update the pointer to the head of the linkedList stored at the hash index such that it holds the address of the newly created node 
            T[hashIdx] = temp ; 
            M++; // ek (key , value) pair badh gya hai after inserting temp 


            // 4.rehash , if loadFactor exceeds the loadfactor thrashold 
            double loadFactor = (double)M/N ;
            if(loadFactor > L) // insertion ke time bhi rehashing ho sakti hai
            {   // so insertion is constant in average case , not in worst case
                // ...rehash
                cout<<"rehashing due to loadFactor = "<<loadFactor<<endl; 
                rehash() ;
            }
        }

        node * find(int key)
        {
            // 1. transform the key into hash index using the hash function 
            int hashIdx = hashfn(key);

            // 2. search for the node with the given key in the linked list 
            // stored at the hash index 
            node * temp = T[hashIdx];
            while(temp != NULL)
            {
                if(temp->key == key)
                { // you have found the node with the given key 
                    return temp ; 
                }
                temp = temp -> next ;
            }
            return NULL ; // if key is not find 
        }

        void erase(int key)
        {
            // 1. transform the key into hash index using the hash function 
            int hashIdx = hashfn(key);

            // 2. delete the node with the given key from the linked list 
            // stored at the hash index 
            node * temp = T[hashIdx];
            node * prev = NULL ;
            while(temp != NULL)
            {
                if(temp->key == key)
                {
                    // check if temp is head of this LL i.e. T[hashIdx] or not

                    if( temp == T[hashIdx] ) // if temp is head of LL
                    {
                        T[hashIdx] = temp -> next ;
                        delete temp ; 
                        temp = NULL ;
                        M--; 
                    }
                    else{ // if temp is not head of the LL
                            prev->next = temp->next ;
                            delete temp ; 
                            temp = NULL ;
                            M--;
                    }
                    break ;
                }
                prev = temp ;
                temp = temp -> next ;
            }
        }

        void printLinkedList(node * head)
        {
            while(head != NULL)
            {
              cout<<"("<<head->key<<" , "<<head->value<<") "; 
              head = head -> next ; 
            }
            cout<<endl;
        }

        void printHashMap()
        {   // iterate over buckets in the hashMap
            for (int i = 0; i < N; i++)
            {   // print the linkedList stored at ith bucket of the hashmap
                cout<<i<<" : "; 
                printLinkedList(T[i]);
            }
            cout<<endl; 
        }
    

};
 
int main() 
{
    // HashMap Hm(13 , 0.6); // initial capacity of Hm : 13 , load factor : 0.6

    HashMap Hm ;
    Hm.insert(2,4);
    Hm.insert(3,9);
    Hm.insert(7,49);

    // Hm.find(3);
    Hm.printHashMap() ;
    Hm.insert(4,16);
    Hm.printHashMap() ;

    int key = 7 ;
    node * temp = Hm.find(key);

    if(temp != NULL)
    {
        cout<<key <<" is present and key value pair : "<<temp->key<<" , "<<temp->value<<endl;
    }else{
        cout<<key<<" is not present"<<endl;
    }

    Hm.erase(key);
    cout<<key<<" is deleted by performing erase operation"<<endl;
    temp = Hm.find(key);

    if(temp != NULL)
    {
        cout<<key <<" is present and key value pair : "<<temp->key<<" , "<<temp->value<<endl;
    }else{
        cout<<key<<" is not present"<<endl;
    }

    Hm.printHashMap() ;

    return 0 ;
}