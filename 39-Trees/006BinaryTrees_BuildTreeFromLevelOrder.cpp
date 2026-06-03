// maintain a queue , queue ke andar wo elements rahenge jo tree ka part bann chuke hai , but unn ke child abhi process nahi hue hai , after processing thier children pop them

#include <bits/stdc++.h>
using namespace std;

class TreeNode{

    public :
    int val ; 
    TreeNode* left ;
    TreeNode* right ;

    TreeNode(int val)
    {
        this->val = val ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

void printPreOrder(TreeNode* root)
{
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    } 

    cout<<root->val<<" ";

    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    vector<int> input = {10, 20, 30, 40, 50, -1, 60, -1, -1, 70, -1, -1, -1, -1, -1};

    TreeNode* curr  ;
    if(input[0] != -1)
    {
        curr = new TreeNode(input[0]);
    }else{
        return 0 ; 
    }


    queue<TreeNode*> q ;
    q.push(curr);
    

    // i = 1 starting because , the 0th index is pushed above in the queue
    for(int i = 1 ; i < input.size() ;) 
    {
        // jaise tree ka part banee , push it in queue , to process it's child 
        TreeNode* root = q.front();
        q.pop() ; 

        // left child 
        if(i < input.size() and input[i] != -1)
        {
            TreeNode* leftChild = new TreeNode(input[i]);
            root->left = leftChild ; 
            q.push(leftChild);
            i++;
        }else{
            root->left = NULL ;
            i++;
        }

        // right child 
        if(i < input.size() and input[i] != -1)
        {
            TreeNode* rightChild = new TreeNode(input[i]);
            root->right= rightChild ; 
            q.push(rightChild);
            i++;
        }else{
            root->right = NULL ;
            i++;
        }
    }

    printPreOrder(curr);
    
    return 0;
}