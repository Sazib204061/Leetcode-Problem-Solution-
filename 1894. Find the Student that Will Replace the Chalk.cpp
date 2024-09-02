#define uppb(a, x)  ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define Sort(a)     ( sort((a).begin(), (a).end()))
#define fast ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        fast;
        int n = chalk.size();
        vector<long long>fsum(n, 0);
        fsum[0] = chalk[0];
        for(int i = 1; i<n; i++)
        {
            fsum[i] = fsum[i-1]+chalk[i];
        }
        k = k%fsum[n-1];
        int ans = uppb(fsum, k);
        return ans;
    }
};
