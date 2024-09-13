class Solution {
public:
    #define mx 100001
    int arr[mx];
    int tree[mx * 3];
    void init(int node, int b, int e)
    {
        if (b == e) {
            tree[node] = arr[b];
            return;
        }
        int Left = node * 2;
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        init(Left, b, mid);
        init(Right, mid + 1, e);
        tree[node] = tree[Left] ^ tree[Right];
    }
    int query(int node, int b, int e, int i, int j)
    {
        if (i > e || j < b)
            return 0; //বাইরে চলে গিয়েছে
        if (b >= i && e <= j)
            return tree[node]; //রিলেভেন্ট সেগমেন্ট
        int Left = node * 2; //আরো ভাঙতে হবে
        int Right = node * 2 + 1;
        int mid = (b + e) / 2;
        int p1 = query(Left, b, mid, i, j);
        int p2 = query(Right, mid + 1, e, i, j);
        return p1 ^ p2; //বাম এবং ডান পাশের যোগফল
    }
    vector<int> xorQueries(vector<int>& ar, vector<vector<int>>& queries) {
        vector<int>ans;

        for(int i = 0; i<ar.size(); i++)
        {
            arr[i+1] = ar[i];
        }
        int n = ar.size();
        init(1,1,n);

        for(int i = 0; i<queries.size(); i++)
        {
            int x = query(1,1,n,queries[i][0]+1, queries[i][1]+1);
            ans.push_back(x);
        }
        return ans;
    }
};
