class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>diff(n);
        for(int i = 0; i<n; i++)
        {
            diff[i] = gas[i]-cost[i];
        }

        for(int i = 0; i<n;)
        {
            //cout<<i<<endl;
            int currGas = diff[i];
            if(currGas<0)
            {
                i++;
                continue;
            }
            else
            {
                int j = (i+1)%n;
                while(1)
                {
                    currGas+=diff[j];
                    if(currGas<0)
                    {
                        currGas = 0;
                        if(j<i)return -1;
                        else i = j;
                        break;
                    }
                    else
                    {
                        j = (j+1)%n;
                        if(j==i)return i;
                    }
                }
            }

        }

        return -1;
    }
};