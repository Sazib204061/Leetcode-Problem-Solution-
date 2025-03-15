class Solution {
public:
    bool isPossibleToRobbed(vector<int>&numbers, int k, int PossibleAnswer)
    {
        int length = numbers.size(), robbed = 0;
        for(int i = 0; i<length; i++)
        {
            if(numbers[i]<=PossibleAnswer)
            {
                robbed++;
                i++;  //skip adjacent house
            }
        }
        if(robbed>=k)return true;
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int low = nums[0], high = nums[0], mid;
        for(int i = 0; i<nums.size(); i++)
        {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }
        int answer = INT_MAX;
        while(low<=high)
        {
            mid = ((high-low)/2)+low;
            if(isPossibleToRobbed(nums, k, mid))
            {
                answer = min(answer, mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return answer;
    }
};