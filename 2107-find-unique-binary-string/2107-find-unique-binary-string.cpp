class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums[0].size();
        string x = "", ans = "";
        for(int i = 0; i<=nums.size(); i++)
        {
            ans = "";
            bitset<16> str(i);
            x = str.to_string();
            int p = n-1;
            for(int j = 16-n; j<16; j++)
            {
                ans+=x[j];
            }
            if(i==n)return ans;
            if(ans!=nums[i])return ans;
            //cout<<x<<endl;
        }

        return x;
    }
};