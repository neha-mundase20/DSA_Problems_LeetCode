class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss1(s1);
        stringstream ss2(s2);
        map<string,int>mp1;
        map<string,int>mp2;

        string token;

        while(ss1>>token){
            mp1[token]++;
        }

        while(ss2>>token){
            mp2[token]++;
        }

        vector<string>result;
        for(auto it:mp1){
            if(it.second==1 && mp2[it.first]==0){
                result.push_back(it.first);
            }
        }

        for(auto it:mp2){
            if(it.second==1 && mp1[it.first]==0){
                result.push_back(it.first);
            }
        }
        return result;
    }
};