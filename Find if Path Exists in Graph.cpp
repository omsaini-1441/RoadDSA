// link : https://leetcode.com/problems/find-if-path-exists-in-graph/


class Solution
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
       

        queue<int> traversedNodes;
        vector<bool> isVisited(n, false);
        vector<vector<int>> graph(n);

        traversedNodes.push(source);
        isVisited[source] = true;
        

        for(auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        while(!traversedNodes.empty())
        {
            int cur = traversedNodes.front();
            traversedNodes.pop();

            if(cur == destination)
                return true;

            vector<int> curNode = graph[cur];

            for(int i=0; i<curNode.size(); i++)
            {
                if(!isVisited[curNode[i]])
                {
                    traversedNodes.push(curNode[i]);
                    isVisited[curNode[i]] = true;
                }
            }
        }

        return false;
    }
};
