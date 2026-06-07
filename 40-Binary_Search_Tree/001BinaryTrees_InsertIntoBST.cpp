/*

	Design an algorithm to perform insert operation in a BST.

*/

#include<iostream>
#include<queue>

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


void printInOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	printInOrder(root->left);
	cout << root->val << " ";
	printInOrder(root->right);
}

void printLevelOrder(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode* front = q.front(); q.pop();
		if (front == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {
			cout << front->val << " ";
			if (front->left) q.push(front->left);
			if (front->right)q.push(front->right);
		}
	}
}

TreeNode* insert(TreeNode* root, int key) {

    // base case 
    if(root == NULL)
    {
        return new TreeNode(key);
    }

    // recurrence relation
    if(key < root->val) // insertion will be done in the left subtree
    { // ask your friend to insert the key in the LST which is also a BST
        root->left = insert(root->left , key);
    }

    else if(key > root->val) // insertion will be done in the right subtree
    {// ask your friend to insert the key in the RST which is also a BST
        root->right = insert(root->right , key);
    }

    return root ;

}

// if we are given preOrder or postOrder of a BST and ask to construct a BST from it's preOrder or postOrder
//  just sort it , now we have both (preorder or postOrder) and inorder of BST , using that we can construct a tree 

int main() {

	TreeNode* root = NULL;

	root = insert(root, 10);

	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 7);

	root = insert(root, 15);
	root = insert(root, 13);
	root = insert(root, 17);

	printLevelOrder(root);

	cout << endl;

	printInOrder(root); // inOrder of a BST is always sorted

	cout << endl;

	return 0;
}