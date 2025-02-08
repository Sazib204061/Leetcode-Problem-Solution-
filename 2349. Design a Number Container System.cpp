#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
class NumberContainers {
public:
    map<int,int>mp1;
    map<int, ordered_set>mp2;
    NumberContainers() {
        mp1.clear();
        mp2.clear();
    }
    void change(int index, int number) {
        int pre_val = mp1[index];
        if(mp2[pre_val].find(index)!=mp2[pre_val].end())
        {
            mp2[pre_val].erase(mp2[pre_val].find(index));
        }
        mp2[number].insert(index);
        mp1[index] = number;
    }
    
    int find(int number) {
        if(mp2[number].find_by_order(0)!=mp2[number].end())
        {
            return *mp2[number].find_by_order(0);
        }
        else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
