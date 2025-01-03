class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0;
        for(auto it:nums){
            sum=sum+it;
        }

        int splits=0;
        long long leftSum=0,rightSum=sum;

        //There is at least one element to 
        //the right of i. That is, 0 <= i < n - 1

        for(int i=0;i<nums.size()-1;i++){
            leftSum=leftSum+nums[i];
            rightSum=rightSum-nums[i];

            if(leftSum>=rightSum){
                splits++;
            }
        }
        return splits;
    }
};