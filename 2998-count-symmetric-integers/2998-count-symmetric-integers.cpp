class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        //string s1 = to_string(low), s2(to_string(high));
        int cnt = 0;
        for(int i = low; i<=high; i++)
        {
            string s1 = to_string(i);
            //cout<<s1<<endl;
            if(s1.size() & 1)continue;
            else if(s1.size()==2)
            {
                if(s1[0]==s1[1])cnt++;
                
            }
            else
            {
                if((s1[0]-'0'+s1[1]-'0')==(s1[2]-'0'+s1[3]-'0'))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};