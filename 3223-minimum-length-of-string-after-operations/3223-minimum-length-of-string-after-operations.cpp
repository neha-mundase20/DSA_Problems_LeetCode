class Solution {
public:
    int minimumLength(string s) {
        if(s.length()<=2){
            return s.size();
        }

        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        int minLength=0;

        for(auto it:mp){
            int cnt = it.second;
            if(it.second>2){
                while(cnt>2){
                    cnt=cnt-2;
                }
            }
            minLength=minLength+cnt;
        }
        return minLength;
    }
};