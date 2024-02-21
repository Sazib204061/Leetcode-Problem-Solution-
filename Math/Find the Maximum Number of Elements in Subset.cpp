class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int,int>mp;
        for(int i = 0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for(int i = n-1; i>=0; i--)
        {
            int p = nums[i], cnt = 1;
            //cout<<"When "<<nums[i]<<endl;
            while(1)
            {
                //cout<<p<<endl;
                int x = sqrt(p);
                if(x==p)break;
                if(x*x==p)
                {
                    if(mp[x]>=2)
                    {
                        cnt+=2;
                        p = x;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        if(mp[1]&1)
        {
            ans = max(mp[1], ans);
        }
        else{
            ans = max((mp[1]-1), ans);
        }
        return ans;
    }
};
