class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positives;
        vector<int>negatives;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positives.push_back(nums[i]);
            }
            else{
                negatives.push_back(nums[i]);
            }
        }
        
        int p=0,n=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
               nums[i]=positives[p++]; 
            }
            else{
                nums[i]=negatives[n++];
            }
        }
        return nums;
    }
};