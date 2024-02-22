/*------Problem Link-----:https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22     */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int>ar1(10005,0), ar2(10005,0);
        for(int i = 0; i<trust.size(); i++)
        {
            ar1[trust[i][1]] += trust[i][0];
            ar2[trust[i][0]] = 1;
        }
        int sum = (n*(n+1))/2;
        cout<<sum<<endl;
        for(int i = 0; i<=n; i++)
        {
            if(ar1[i]==(sum-i) && ar2[i]!=1)
            {

                return i;
            }
        }
        return -1;
    }
};
