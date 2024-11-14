class Solution {
public:
    bool ispossible(int n, int mid, vector<int>&quantities)
    {
        for(int i = 0; i<quantities.size(); i++)
        {
            int x = quantities[i], div ;
            if(x%mid==0)
            {
                div = x/mid;
            }
            else
            {
                div = (x/mid)+1;
            }
            n-=div;
        }
        if(n>=0)return true;
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end(), greater<int>());

        int l = 1, r = quantities[0], ans = r;
        while(l<=r)
        {
            int mid = (l+r)/2;
            //cout<<mid<<endl;
            if(ispossible(n, mid, quantities))
            {
                ans = min(ans, mid);
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;

    }
};
