class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), zero = 0;
        vector<int>ans;
        for(int i = 0; i<n-1; i++)
        {
            if(nums[i]==nums[i+1] && nums[i]!=0)
            {
                nums[i]*=2;
                ans.push_back(nums[i]);
                nums[i+1] = 0;
                //zero++;
            }
            else if(nums[i]==0)zero++;
            else
            {
                ans.push_back(nums[i]);
            }
        }
        if(nums[n-1]==0)zero++;
        else ans.push_back(nums[n-1]);
        //sort(nums.begin(), nums.end(), greater<int>());
        while(zero--)
        {
            ans.push_back(0);
        }
        return ans;
    }
};