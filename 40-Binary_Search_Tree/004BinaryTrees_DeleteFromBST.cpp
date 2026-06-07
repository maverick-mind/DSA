/*

	Given a BST, design an algorithm to find the minimum and the maximum value inside it.

*/

#include<iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

// time : O(h) : height of the tree 

TreeNode* findMinimum(TreeNode* root) {

	if (root == NULL) {
		return NULL;
	}

	while (root->left != NULL) { // smallest node will be the left most node 
                                 // jisska koi left child nahi hai
		root = root->left;
	}

	return root;

}

// time : O(h) : height of the tree 

TreeNode* findMaximum(TreeNode* root) {

	if (root == NULL) {
		return NULL;
	}

	while (root->right != NULL) { // largest will be the right most node
                                  // jisska koi right child nahi hai 
		root = root->right;
	}

	return root;

}

// in-order predecessor 
TreeNode* rightMostNodeOfLeftSubtree(TreeNode* root)
{
    if(root == NULL) return NULL ; 

    while(root->right != NULL)
    {
        root = root->right;
    }
    return root ;

}


/*

    In the standard approach (copy predecessor value + delete), the height stays balanced-ish. But here, the right subtree gets hung down to the bottom of the left subtree, increasing height.

    what I am doing here : inserting right child of node with val(key) to the in-order predecessor(rightmost child in the left subtree) , and after doing this delete the node

                10                                 
              /    \                             
            7        15                        
          /  \      /   \                    
         6    9    13    17                
             /
            8
    delete node with val : 10 

        this approach :                     standard aproach :

           7                                          9
         /   \                                      /   \
       6      9                                   7      15
            /   \                               /  \    /   \
           8     15                            6    8  13   17
                /  \
              13    17                 height : 3 (height decresed in standard approach )
        height : 4                 

      so , I guess with this strategy of code , I just chaged the formation of BST in my own way , long term impact would be , tree can be skewed to one side 

            6
             \
              9
            /   \
           8     15
                /  \
              13    17 
    // if now deleting 9 
            6
             \
              8
                \
                 15
                /  \
              13    17 

    // If now deleting 15 
            6
             \
              8
                \
                 13
                   \
                    17 
    The tree become skewed this way 

*/


//rightmost of left subtree is the biggest value still smaller than root, so hang the right subtree there
// If a left subtree exists, the entire BST can be repaired by attaching the original right subtree to the rightmost node of the left subtree and returning the left subtree root.
// while deleting , ask What subtree should replace the deleted node so that the BST property remains true?
TreeNode* deleteInBST(TreeNode* root , int key)
{
    // base case 
    if(root == NULL) return NULL;

    // recurrence relation
    // 1. first search and check , does key exist in bst 

    if(root->val == key) // this node is to be deleted 
    {
        // the immediate left child of this root node will be attached to it's parent node ,and the right child of this original root node will become right child of the rightmost node from the leftSubtree
        TreeNode* rightChild = root->right ;
        TreeNode* leftChild =  root->left ;
        if(leftChild != NULL)
        {
            TreeNode* rightMostNodeFromLeftSubtree = rightMostNodeOfLeftSubtree(leftChild);
            rightMostNodeFromLeftSubtree->right = root->right ; // in-order predecessor
            delete root ;
            return leftChild;
        }else{
            delete root ;
            return rightChild ;
        }
    }
    else if(key < root->val)
    {
        root->left = deleteInBST(root->left , key);
    }
    else{ // key > root->val
        root->right = deleteInBST(root->right , key);
    }
    return root ;
}

void printInOrder(TreeNode* root)
{
    if(root == NULL) return ;

    printInOrder(root->left);
    cout<<root->val<<" ";
    printInOrder(root->right);
}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->left->right->right->left = new TreeNode(8);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

    printInOrder(root);
    cout<<endl;
    root = deleteInBST(root , 10);
    printInOrder(root);

	return 0;
}