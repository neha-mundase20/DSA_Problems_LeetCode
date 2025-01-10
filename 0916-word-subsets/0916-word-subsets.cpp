class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>solution;
        vector<int>maxFreq(26,0);

        for(auto word:words2){
            vector<int>freq(26,0);
            for(auto c:word){
                freq[c-'a']++;
            }

            for(int i=0;i<26;i++){
                maxFreq[i]=max(maxFreq[i],freq[i]);
            }
        }

        for(auto word:words1){
            vector<int>freq(26,0);
            for(auto c:word){
                freq[c-'a']++;
            }

            bool isUniversal=true;
            for(int i=0;i<26;i++){
                if(freq[i]<maxFreq[i]){
                    isUniversal=false;
                    break;
                }
            }
            if(isUniversal==true){
                solution.push_back(word);
            }
        }
        return solution;
    }
};