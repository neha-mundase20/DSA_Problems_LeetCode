class Solution {
public:
    string makeFancyString(string s) {
        string result;
        result.push_back(s[0]);
        char recentLetterPushed=s[0];

        for(int i=1;i<s.length();){
            if(s[i]==recentLetterPushed && s[i+1]==s[i]){
                i++;
            }
            else{
                result.push_back(s[i]);
                recentLetterPushed=s[i];
                i++;
            }
        }
        return result;
    }
};