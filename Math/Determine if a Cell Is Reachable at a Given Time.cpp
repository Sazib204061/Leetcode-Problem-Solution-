class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d_max = max(abs(sx-fx), abs(sy-fy));
        if(d_max==0 && t==1)return false;
        else if(d_max<=t)return true;
        return false;       
    }
};
