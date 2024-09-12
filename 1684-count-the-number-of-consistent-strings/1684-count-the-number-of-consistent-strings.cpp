class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<int,int>mp;
        bool isConsistent=true;
        int count=0;

        for(auto it:allowed){
            mp[it]++;
        }

        for(int i=0;i<words.size();i++){
            for(auto it:words[i]){
                if(mp.find(it)==mp.end()){
                    isConsistent=false;
                    break;
                }
            }
            if(isConsistent==true){
                count++;
            }
            isConsistent=true;
        }
        return count;
    }
};