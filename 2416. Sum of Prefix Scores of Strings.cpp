struct Node{
    unordered_map<char, pair<int,Node*>>ump;
    //bool is_end = false;
};

class Trie{
private:
    Node* root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node* curr = root;

        for(int i = 0; i<s.size(); i++)
        {
            if(curr->ump.find(s[i])==curr->ump.end())
            {
                curr->ump[s[i]].second = new Node();
            }
            curr->ump[s[i]].first++;
            curr = curr->ump[s[i]].second;
        }
        //curr->is_end = true;
        return;
    }

    int check_prefix_count(string s)
    {
        Node *curr = root;
        
        int cnt = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(curr->ump.find(s[i])==curr->ump.end())
            {
                break;
            }
            cnt+=curr->ump[s[i]].first;
            curr = curr->ump[s[i]].second;
        }
        return cnt;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int>ans;
        Trie t;
        for(int i = 0; i<words.size(); i++)
        {
            t.insert(words[i]);
        }

        for(int i = 0; i<words.size(); i++)
        {
            int cnt = t.check_prefix_count(words[i]);
            ans.push_back(cnt);
        }
        return ans;
    }
};
