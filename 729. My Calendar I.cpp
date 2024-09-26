class MyCalendar {
public:
    set<int>st, ed;
    MyCalendar() {
        st.clear();
        ed.clear();
    }
    
    bool book(int start, int end) {
        end--;
        bool ans = true;
        if(st.size()==0)
        {
            st.insert(start);
            ed.insert(end);
        }
        else
        {
            auto it1 = st.lower_bound(start);
            auto it2 = st.lower_bound(end);

            auto it3 = ed.lower_bound(start);
            auto it4 = ed.lower_bound(end);

            if(it1==st.end() && it2==st.end() && it3==ed.end() && it4==ed.end())
            {
                st.insert(start);
                ed.insert(end);
            }
            else if((*it1)==(*it2) && (*it3)==(*it4) && (*it3!=end && *it1!=end) && *it1<=*it3 && (it1!=st.end() && it2!=st.end() && it3!=ed.end() && it4!=ed.end()))
            {
                st.insert(start);
                ed.insert(end);
            }
            else ans = false;
        }
        return ans;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
