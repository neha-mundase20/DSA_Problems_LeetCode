class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>m1;
        map<char,int>m2;
        
        // Check if the lengths of the strings are equal
        if (s.length() != t.length())
        return false;
        
        for(char c:s){
            m1[c]++;
        }
        
        for(char c:t){
            m2[c]++;
        }
        
        return m1==m2;
    }
};