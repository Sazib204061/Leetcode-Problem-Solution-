#define lli long long int
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        lli n = fruits.size(), l, r;
        if(n==1||n==2)
        {
            return n;
        }
        else 
        {
            int i = 2;
            lli cnt = 2, ans = 2, ans1 = 2;
            l = fruits[0];
            r = fruits[1];

            while(l==r)
            {
                if(i==n)break;
                l = fruits[i-1];
                r = fruits[i];
                i++;
                ans++;
                cnt++;
            }
            
            if(l==r)return ans;
            lli same = 0;
            for(i; i<n; i++)
            {
                //cout<<l<<" "<<r<<" "<<cnt<<" "<<ans<<endl;
                if(fruits[i]==l||fruits[i]==r)
                {
                    if(fruits[i]==fruits[i-1])same++;
                    else same = 0;
                    cnt++;
                }
                else
                {
                    l = fruits[i-1];
                    r = fruits[i];
                    //cout<<"s "<<same<<endl;
                    cnt = 2+same;
                    same = 0;
                    
                }
                
                ans = max(ans, cnt);
            }
            return ans;
        }
    }
};