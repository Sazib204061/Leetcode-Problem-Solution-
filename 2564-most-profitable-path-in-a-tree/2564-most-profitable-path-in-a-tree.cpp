
class Solution {
public:
    
    vector<int>graph[100005];
    
    int depth_form_alice[100005];
    int parent_sequence[100005];
    void dfs_with_depth(int node, int parent)
    {
        //cout<<node<<endl;
        for(auto v : graph[node])
        {
            if(v==parent)continue;
            depth_form_alice[v] = depth_form_alice[node]+1;
            parent_sequence[v] = node;
            dfs_with_depth(v, node);
        }
    }

    int max_ans = INT_MIN;
    void dfs(int node, int parent, int cost, vector<int>&amount)
    {
        //cout<<node<<endl;
        if(graph[node].size()==1 && node!=0) // is it leaf node?
        {
            //cout<<"YES"<<endl;
            max_ans = max(max_ans, cost);
        }
        for(auto v : graph[node])
        {
            if(v==parent)continue;
            dfs(v, node, cost+amount[v], amount);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        for(int i = 0; i<n; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs_with_depth(0, -1);

        // for(int i = 0; i<=n; i++)
        // {
        //     cout<<i<<" -> "<<depth[i]<<endl;
        //     cout<<parent_sequence[i]<<endl;
        // }
        int new_bob = bob, depth_of_new_bob = 0;
        while(new_bob!=0)
        {
            if(depth_of_new_bob < depth_form_alice[new_bob])
            {
                amount[new_bob] = 0;
            }
            else if(depth_of_new_bob == depth_form_alice[new_bob])
            {
                amount[new_bob] = amount[new_bob]/2;
            }
            depth_of_new_bob++;
            new_bob = parent_sequence[new_bob];
        }

        // for(int i = 0; i<=n; i++)
        // {
        //     cout<<i<<" "<<amount[i]<<endl;
        // }

        dfs(0, -1, amount[0], amount);

        return max_ans;
    }
};