class Solution {
public:
    bool isDigit(char ch)
    {
        if(ch>='0' && ch<='9')return true;
        return false;
    }
    bool isCharacter(char ch)
    {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))return true;
        return false;
    }

    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U')return true;
        return false;
    }

    bool isValid(string word) {
        int n = word.size(), Vowel = 0, Consonent = 0;
        if(n>=3)
        {
            for(int i = 0; i<n; i++)
            {
                if(isDigit(word[i]))
                {
                    continue;
                }
                else if(isCharacter(word[i]))
                {
                    if(isVowel(word[i]))
                    {
                        Vowel++;
                    }
                    else
                    {
                        Consonent++;
                    }
                }
                else
                {
                    return false;
                }
            }
            if(Vowel>=1 && Consonent>=1)return true;

        }
        return false;
    }
};