#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        fast;
        int sum = 0, m = rolls.size();
        for(int i = 0; i<m; i++)
        {
            sum+=rolls[i];
        }
        vector<int>ans;
        int rem = (mean*(n+m))-sum;
        
        //cout<<rem<<endl;

        if(n*6<rem || rem<n)
        {
            return ans;  //impossible
        }
        else
        {           //if possible
            int num = 6, i = 1;
            
            while(1){
                int r = rem-num;
                if(r>=(n-i))
                {
                    ans.push_back(num);
                    rem = r;
                    i++;
                    if(ans.size()==n)return ans;
                }
                else
                {
                    num--;
                }
            }
        }

        return ans;

    }
};
