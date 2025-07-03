class Solution {
public:
    char kthCharacter(int k) {
        string word = "a", str = "";
        while(word.size()<k)
        {
            str = "";
            for(int i = 0; i<word.size(); i++)
            {
                if(word[i]=='z')
                {
                    str+='a';
                }
                else
                {
                    char ch = word[i];
                    ch++;
                    str+=ch;
                }
            }
            word+=str;
        }
        return word[k-1];
    }
};