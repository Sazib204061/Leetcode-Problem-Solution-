class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int,int>mp, mp2;
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
            mp2[nums[i]]++;
        }
        
        for(auto it : mp)
        {
            int nxt = it.first;
            nxt+=1;
            int y = mp2[nxt];
            int x = it.second;
            x+=y;
            if(y>0)
                ans = max(ans, x);
        }
        return ans;
    }
};