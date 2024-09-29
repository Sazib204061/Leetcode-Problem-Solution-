class AllOne {
public:
    unordered_map<string, int>cnt;
    set<pair<int,string>>st;
    AllOne() {
        cnt.clear();
        st.clear();
    }
    
    void inc(string key) {
        int prev_cnt = cnt[key]; //old
        st.erase({prev_cnt, key}); //old remove from set
        cnt[key]++;      //update cnt map
        st.insert({prev_cnt+1, key});  //updated element insert on set
    }
    
    void dec(string key) {
        int prev_cnt = cnt[key];   //old
        st.erase({prev_cnt, key});   //old remove from set

        cnt[key]--;      //update cnt map

        if(prev_cnt-1>0)
        {
            st.insert({prev_cnt-1, key});  //updated element insert on set
        }
        else cnt.erase(key);  //if frequency of key is zero        
    }
    
    string getMaxKey() {
        if(!st.empty())
        {
            return st.rbegin()->second;
        }
        return "";
    }
    
    string getMinKey() {
        if(!st.empty())
        {
            return st.begin()->second;
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
