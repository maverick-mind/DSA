/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>
        mp; // <original node , clone node> to track visited nodes

    /*
    Node* dfsGraphCopy(Node* node)
    {
        Node* currentNode = NULL ;
        if(node == NULL) return currentNode ;

        if(mp.find(node) == mp.end())
        {
            currentNode = new Node(node->val) ;
            mp[node] = currentNode ;
        }
        else // if(mp.find(node) != mp.end())
        {
            currentNode = mp[node] ;
        }


        for(auto ngb : node->neighbors)
        {
            // if ngb does not exist in map , it means ngb is not visited yet
            if(mp.find(ngb) == mp.end())
            {

                Node* cloneNgb = dfsGraphCopy(ngb) ;

                (currentNode->neighbors).push_back(cloneNgb) ;
            }
            else if(mp.find(ngb) != mp.end())
            {
                Node* cloneNgb = mp[ngb] ;

                // check if the currentNode and ngb are neighbour or not
                bool isngb = false ;
                for(auto ng : currentNode->neighbors)
                {
                    if(ng == cloneNgb)
                    {
                        isngb = true ;
                        break ;
                    }
                }
                if(isngb == false)
                {
                  (currentNode->neighbors).push_back(cloneNgb) ;
                }
            }
        }

        return currentNode ;
    }
    */

    Node* dfsGraphCopy2(Node* node) {

        if (node == NULL)
            return NULL;

        if (mp.find(node) != mp.end())
            return mp[node]; // already cloned? return it directly

        Node* currentNode = new Node(node->val);
        mp[node] = currentNode; // map BEFORE recursing — breaks cycles

        for (Node* ngb : node->neighbors) {
            currentNode->neighbors.push_back(dfsGraphCopy2(ngb));
        }
        return currentNode;
    }

    Node* cloneGraph(Node* node) {

        // return dfsGraphCopy(node) ;
        return dfsGraphCopy2(node);
    }
};