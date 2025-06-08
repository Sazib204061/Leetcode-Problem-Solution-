class Solution {
public:
    vector<int>ans;
    int n;
    void f(int num)
    {
        if(num>n)return;
        if(num>0)ans.push_back(num);

        for(int i = (num==0)?1:0; i<=9; i++)
        {
            int val = num*10+i;
            if(val>n)break;

            f(val);
        }
    }
    vector<int> lexicalOrder(int n) {
        this->n = n;
        ans.clear();
        f(0);
        return ans;
    }
};