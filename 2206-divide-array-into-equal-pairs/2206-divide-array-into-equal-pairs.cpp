class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        if(n%2!=0){
            return false;
        }
        else{
            unordered_map<int,int>mp;
            for(auto it:nums){
                mp[it]++;
            }

            for(auto it:mp){
                if(it.second%2!=0){ //odd occurences
                    return false;
                }
            }
        }
        return true;
    }
};