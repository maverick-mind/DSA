/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// because as per the problem constraints : all the nodes val are unique 
// I maintained vector<vector<int>> adj(number of nodes + 1) , and it passed test case
// but we should have maintained unordered_map<int , vector<int>> adj and set<int> visited and unordered_map<int , int> distMap , because as per constraints , the nodes can take "any" unique values in the range [1,500]

// we could also have made adjacency list of 500 size , visited vector of 500 size , because the problem constraints on the leetcode are small , i.e. 500

 // consider target as source and apply BFS 
class Solution {

    void dfsAdj(vector<vector<int>> & adj , TreeNode * root)
    {
        if(! root) return ;

        TreeNode* leftChild = root->left ;
        TreeNode* rightChild = root->right ;

        if(leftChild != NULL)
        {
            adj[root->val].push_back(leftChild->val);
            adj[leftChild->val].push_back(root->val) ;
        }
        if(rightChild != NULL)
        {
            adj[root->val].push_back(rightChild->val);
            adj[rightChild->val].push_back(root->val) ;
        }

        dfsAdj(adj , root->left) ;
        dfsAdj(adj , root->right) ;
    }

    int dfsNodeCount(TreeNode * root)
    {
        if(root == NULL) return 0 ;

        return 1 + dfsNodeCount(root->left) + dfsNodeCount(root->right) ;
    }

    vector<int> bfsSSSP(vector<vector<int>> & adj , int target , int k , int n)
    {
        if(k == 0) return {target} ;
        vector<bool> visited(n , false) ;

        vector<int> kDistNodes ; // nodes at distance k from target node

        queue<int> que ; 

        vector<int> distMap(n) ;
        distMap[target] = 0 ;

        que.push(target) ;
        visited[target] = true ;

        while( ! que.empty())
        {
            int curr = que.front() ;
            que.pop() ; 

            int distcurr = distMap[curr] ;
            int distngb = distcurr + 1 ; 

            for(int ngb : adj[curr])
            {
                if(visited[ngb] == false)
                {
                    visited[ngb] = true ; 

                    if(distngb == k)
                    {
                        kDistNodes.push_back(ngb) ;
                    }

                    if(distngb < k) // there is no point to explore the graph
                    {               // beyond shortest distance as "k"
                        distMap[ngb] = distngb ;
                        que.push(ngb) ;
                    }
                }
            }
        }

        return kDistNodes ;

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // conver the binary tree into an undirected graph , now consider the given target as source and apply BFS as single source shortest path algorithm

        
        // step 1 : count the number of nodes 
        int n = dfsNodeCount(root) ;
        n++ ; // because tree nodes are [1,n]

        vector<vector<int>> adj(n) ; 
        // step 2 : fill the adjacency list based on undirected edges 
        dfsAdj(adj , root) ;

        // step 3 : on adjacency list , run bfs to find all the nodes at a distance 'k' from the target node (single source shortest path from the target node)

        return bfsSSSP(adj , target->val , k , n) ;



    }
};