class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int>mst;   //multiset allows storing of multiple elements that occur more than                             //once in an ordered format
        
        for(int i=0;i<nums.size();i++){
            mst.insert(nums[i]*nums[i]);
        }
        
        vector<int>v;
        
        for(auto it:mst){
            v.push_back(it);
        }
        return v;
    }
};