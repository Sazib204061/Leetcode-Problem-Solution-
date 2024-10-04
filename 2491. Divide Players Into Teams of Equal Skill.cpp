class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int l = 0, r = skill.size()-1;
        long long sum = skill[l]+skill[r], ans = skill[l]*skill[r];

        l++;
        r--;

        while(l<r)
        {
            if(sum==skill[l]+skill[r])
            {
                ans+=(skill[l]*skill[r]);
            }
            else return -1;
            l++;
            r--;
        }

        return ans;
    }
};
