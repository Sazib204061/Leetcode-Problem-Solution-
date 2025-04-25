class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        int preSum = 0;
        map<int,int>cnt;
        cnt[k] = 1;
        for(int i = 0; i<n; i++)
        {
            preSum+=nums[i];
            int x = preSum%k, y = k-(preSum%k);
            cout<<x<<" "<<y<<endl;

            if(x<0)
            {
                ans+=cnt[abs(x)];
                cnt[abs(x)]++;
            }
            else{
                ans+=cnt[y];
                cnt[y]++;
            }
        }
        return ans;
    }
};