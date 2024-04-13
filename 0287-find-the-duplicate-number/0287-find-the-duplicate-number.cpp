class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        int val=0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>1){
                val=it.first;
                break;
            }
        }
        return val;
    }
};