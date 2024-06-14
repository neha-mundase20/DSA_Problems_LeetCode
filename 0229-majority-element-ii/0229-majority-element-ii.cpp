class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>solution;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>floor(n/3)){
                solution.push_back(it.first);
            }
        }
        
        return solution;
    }
};