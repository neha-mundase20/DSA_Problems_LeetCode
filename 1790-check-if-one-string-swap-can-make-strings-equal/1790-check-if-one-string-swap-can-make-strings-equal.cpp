class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char,int>mp1;
        map<char,int>mp2;

        for(auto it:s1){
            mp1[it]++;
        }

        for(auto it:s2){
            mp2[it]++;
        }

        if(mp1!=mp2){
            return false;
        }

        int swapCount=0;
        
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                swapCount++;
            }
        }

        if(swapCount>2){
            return false;
        }
        return true;
    }
};