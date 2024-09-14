class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=0,j=0;
        unordered_set<char>st;
        int maxLength=INT_MIN;

        while(i<s.length() && j<s.length()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
                maxLength=max(maxLength,j-i);
            }
            else{
                st.clear();
                i++;
                j=i;
            }
        }
        return maxLength;
    }
};