class Solution {
public:
    vector<string> split_sentence(string sen) {
  
        // Vector to store the words
        vector<string> words;

        // Temporary string to hold each word
        string word = "";

        // Iterate through each character in the sentence
        for (char c : sen) {
            if (c == ' ') {
            
                // If a space is found, add the word to the vector
                words.push_back(word);
            
                // Reset the word
                word = "";
            }
            else {
                // Append the character to the current word
                word += c;
            }
        }

        // Add the last word to the vector
        if (!word.empty()) {
            words.push_back(word);
        }

        // Return the vector containing words
        return words;
    }
    bool areSentencesSimilar(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string a, b;
        if(n>=m)
        {
            a = s1;
            b = s2;
        }
        else
        {
            b = s1;
            a = s2;
        }

        vector<string>aa =split_sentence(a), bb = split_sentence(b);

        int i = 0, j = bb.size()-1, l = 0, r = aa.size()-1;

        while(i<=j)
        {
            if(aa[l]==bb[i])
            {
                l++;
                i++;
                continue;
            }
            if(aa[r]==bb[j])
            {
                j--;
                r--;
                continue;
            }
            return false;
        }
        return true;

    }
};
