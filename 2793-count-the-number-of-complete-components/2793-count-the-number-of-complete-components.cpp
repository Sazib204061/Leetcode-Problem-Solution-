class Solution {
public:
    vector<int>graph[51];
    bool vis[51];
    int numberOfNode, numberOfEdge;
    void dfs(int u)
    {
        vis[u] = true;
        cout<<u<<endl;
        numberOfNode++;
        for(auto v : graph[u])
        {
            numberOfEdge++;
            if(vis[v]==false)
            {
                dfs(v);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int node = 0; node<n; node++)
        {
            if(vis[node]==false)
            {
                dfs(node);
                //After DFS

                numberOfEdge/=2;
                int expectedEdge = (numberOfNode*(numberOfNode-1))/2;

                if(expectedEdge==numberOfEdge)
                {
                    ans++;
                }

                numberOfNode = 0;
                numberOfEdge = 0;

            }
        }

        return ans;

    }
};