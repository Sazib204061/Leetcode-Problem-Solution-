#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
static bool comp(const int  a, const int b)
{
    string aa = to_string(a), bb = to_string(b);
    return (aa+bb>bb+aa);

}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        fast;
        int z = 0;
        string ans = "";
        sort(nums.begin(), nums.end(), comp);
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]!=0)z = 1;
            ans+=to_string(nums[i]);
        }
        if(z==0)return "0";
        return ans;
    }
    
};
