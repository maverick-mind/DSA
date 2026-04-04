// count the number of paths , whose sum is equal to targetSum 
// can we do that :
// find the number of paths , jo root pe shuru hote hai and unkaa sum is euqal to targetSum
// and also find the number of paths , jo root pe shuru nahi hote hai and unkaa sun is equal to targetSum 

// ya fir , kya current node se path shuru kar ke targetSum mill sakta hai ? 

#include<bits/stdc++.h>
using namespace std;
 
class TreeNode{

public :
    int val ;
    TreeNode * left ;
    TreeNode * right ;

    TreeNode(int val)
    {
        this->val = val ;
        this->left = NULL ;
        this->right = NULL ;
    }
} ;

void printPreOrder(TreeNode * root)
{
    // base case 
    if(root == NULL)
    {
        cout<<-1<<" ";
        return ;
    }

    // recurrence relation

    // 1. process the root node

    cout<<root->val<<" ";

    // 2. ask your friend to print the preOrder of LST

    printPreOrder(root->left);

    // 3. ask your friend to print the preOrder of RST
    
    printPreOrder(root->right);
}

TreeNode * buildtreePreOrder(vector<int> arr , int & i)
{
    // base case 
    if(i == arr.size() )
    {
        return NULL;
    }

    // leaf-node case 
    if(arr[i] == -1)
    {
        return NULL ; 
    }

    // recurrence relation 

    // ith value will be the value of current root 
    TreeNode * root = new TreeNode(arr[i]);
    i++ ;
    root -> left = buildtreePreOrder(arr , i);
    i++ ;
    root -> right = buildtreePreOrder(arr , i);

    return root ;
}

int pathsByIncludingCurrentNode(TreeNode* root , long long targetSum)
{
    // base case 
    if(root == NULL)
    {
        return 0 ; // no path , if root is NULL
    }

    // recursive case 

    // f(root, targetSum) : count no. of paths in the given tree that start at the root
	// whose sum is equal to targetSum
    int count = 0 ;
    if(root->val == targetSum)
    {
        count++;
    }
         // root ko include karte hue kya left mein path hai ? 
        count += pathsByIncludingCurrentNode(root->left , targetSum - root->val) ; 
           
        // root ko include karte hue kya right mein path hai ?
        count += pathsByIncludingCurrentNode(root->right ,targetSum - root->val) ;
      

      
    return count ;

}

int skippingCurrentNode(TreeNode* root, int targetSum) 
{
    // base case 
    if(root == NULL)return 0 ; 

    // recurrence relation 
    int count = 0 ;

    // question : f(root, targetSum) : count no. of paths in the given tree
	// whose sum is equal to targetSum


    // 1. count no. of paths in the given tree that start at root
	// whose sum is equal to targetSum
    count+= pathsByIncludingCurrentNode(root , targetSum) ; 


    // paths By Excluding Current Node , either in the left or current Node or in it's right , jiska sum targetSum ke equal hai 



    // 2. count no. of paths in the given tree that donot start at
	// root whose sum is equal to targetSum

	// 2.1 count no. of paths in the leftSubtree whose sum is equal to targetSum
    count += skippingCurrentNode(root -> left , targetSum) ; 


    // 2.2. count no. of paths in the rightSubtree whose sum is equal to targetSum
    count += skippingCurrentNode(root -> right , targetSum);

    return count ;

}


int pathSum(TreeNode* root, int targetSum) {
        
    return skippingCurrentNode(root , targetSum);

}

int main() 
{
    // preorder traversal is given 
    // vector<int> arr = {10,5,3,3,-1,-1,-2,-1,-1,2,-1,1,-1,-1,-3,-1,11,-1,-1};
    vector<int> arr = {10,5,3,3,-1,-1,-2,-1,-1,2,-1,1,-1,-1,-3,-1,11,-1,-1};
    int targetSum = 8;
    int i = 0 ;
    TreeNode * root = buildtreePreOrder(arr , i);
 
    printPreOrder(root);
    cout<<endl; 
    cout<<pathSum(root , targetSum)<<endl;
    

    return 0 ;
} 