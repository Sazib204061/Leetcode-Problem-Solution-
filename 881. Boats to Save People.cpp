class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int l = 0, r = people.size()-1, ans = 0;

        while(l<=r)
        {
            if(l!=r && (people[l]+people[r])<=limit)
            {
                ans++;
                l++;
                r--;
            }
            else
            {
                ans++;
                l++;
            }
        }
        return ans;
    }
};
