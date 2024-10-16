class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>>pq;
        if(a>0)
        {
            pq.push({a, 'a'});
        }
        if(b>0)
        {
            pq.push({b, 'b'});
        }
        if(c>0)
        {
            pq.push({c, 'c'});
        }
        string res = "";
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            //cout<<it.second<<" "<<it.first<<endl;

            if(res.size()>=2 && res[res.size()-1]==it.second && res[res.size()-2]==it.second)
            {
                if(pq.empty())break;
                else
                {
                    auto it2 = pq.top();
                    pq.pop();
                    res+=it2.second;
                    if(it2.first>1)
                    {
                        pq.push({it2.first-1, it2.second});
                    }
                }
            }
            else
            {
                res+=it.second;
                it.first--;
            }

            if(it.first>0)pq.push({it.first, it.second});
        }
        return res;
    }
};
