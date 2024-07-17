class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int answer=0;

        for(auto i:nums){
            mp[i]++;
        }

        for(auto it:mp){
            if(it.second==1){
                answer=it.first;
            }
        }
        return answer;
    }
};