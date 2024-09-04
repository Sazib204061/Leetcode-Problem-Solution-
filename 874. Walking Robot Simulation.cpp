class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,int>mp;
        for(int i = 0; i<obstacles.size(); i++)
        {
            mp[{obstacles[i][0], obstacles[i][1]}] = 1;
        }

        int x = 0, y = 0, d = 1, ans = 0; 

        for(int i = 0; i<commands.size(); i++)
        {
            if(commands[i]>=1 && commands[i]<=9)
            {
                if(d==1)
                {
                    for(int j = 0; j<commands[i]; j++)
                    {
                        if(mp[{x, y+1}]!=1)
                        {
                            y++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if(d==2)
                {
                    for(int j = 0; j<commands[i]; j++)
                    {
                        if(mp[{x+1, y}]!=1)
                        {
                            x++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if(d==3)
                {
                    for(int j = 0; j<commands[i]; j++)
                    {
                        if(mp[{x, y-1}]!=1)
                        {
                            y--;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    for(int j = 0; j<commands[i]; j++)
                    {
                        if(mp[{x-1, y}]!=1)
                        {
                            x--;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                if(commands[i]==-1)
                {
                    d++;
                    if(d==5)d = 1;
                }
                else
                {
                    d--;
                    if(d==0)d = 4;
                }
            }

            ans = max(ans, x*x+y*y);
            //cout<<i<<" "<<x<<" "<<y<<endl;
        }

        return ans;
    }
};
