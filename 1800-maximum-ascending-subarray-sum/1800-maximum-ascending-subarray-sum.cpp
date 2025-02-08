class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxAscSum=nums[0];
        int currentSum=nums[0];

        if(nums.size()==1){
            return nums[0];
        }

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currentSum=currentSum+nums[i];
            }
            else{
                currentSum=nums[i];
            }
            maxAscSum=max(maxAscSum,currentSum);
        }
        return maxAscSum;
    }
};