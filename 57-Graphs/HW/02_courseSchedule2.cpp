class Solution {
public:
    vector<int> BFSKahnAlgorithm(vector<vector<int>> & adj , vector<int> inDegree , int numCourses)
    {
        vector<int> topo ;

        // vector<bool> visited(numCourses , false) ; // as there is no cycle , so there is no need to maintain the visited vector 

        queue<int> que ;

        for(int i = 0 ; i < numCourses ; i++)
        {
            if(inDegree[i] == 0)
            {
                que.push(i) ;
            }
        }

        while(! que.empty())
        {
            int curr = que.front() ;
            que.pop() ;
            topo.push_back(curr) ;

            for(int ngb : adj[curr])
            {
                // reduce the dependency of ngb by 1 , due to curr 
                inDegree[ngb]-- ;
                if(inDegree[ngb] == 0)
                {
                    que.push(ngb) ;
                }
            }
        }

        // return (topo.size() == numCourses) ? topo : {} ; // clssic ternary + {} issue. compiler {} ko as a plain initializer-list treat kar raha hai, aur ternary operator ke dono branches ka type deduce nahi kar pa raha jab ek side pe bare {} ho.

        // Fix — explicitly type the empty vector:
        return (topo.size() == numCourses) ? topo : vector<int>{} ;

        
        // if(topo.size() == numCourses)
        // {
        //     return topo ;
        // }else{
        //     // return vector<int>{} ;
        //     return {};
        // }
    } 


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  
        vector<vector<int>> adj(numCourses) ;

        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            // prerequisites[i][0] depends upon prerequisites[i][1]
            // it means there is an edge from prerequisites[i][1] to prerequisites[i][0]

            adj[prerequisites[i][1]].push_back(prerequisites[i][0]) ; // directed graph
        }

        vector<int> inDegree(numCourses , 0) ;

        for(int i = 0 ; i < numCourses ; i++)
        {
            for(int ngb : adj[i])
            {
                // there in an edge from adj[i] to ngb , so increase the inDegree of ngb by 1
                inDegree[ngb]++ ;
            }
        }

        return BFSKahnAlgorithm(adj , inDegree , numCourses) ; 

    }
};