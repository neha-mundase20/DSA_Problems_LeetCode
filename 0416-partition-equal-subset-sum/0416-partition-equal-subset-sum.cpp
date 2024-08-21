class Solution {
public:

    bool f(int index,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }

        if(index==0){
            if(nums[index]==target){
                return true;
            }
            else{
                return false;
            }
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool notTake=f(index-1,target,nums,dp);
        bool take=false;

        if(nums[index]<=target){
            take=f(index-1,target-nums[index],nums,dp);
        }

        return dp[index][target]=take||notTake;
    }

    bool canPartition(vector<int>& nums) {
        int arraySum=0;

        for(auto it:nums){
            arraySum=arraySum+it;
        }

        if(arraySum%2!=0){  
        //array sum is odd then we can't divide the array into equal sum subsets
            return false;
        }
        else{
        //array sum is even and we can divide the array in two equal sum subsets

        //so now the problem boils down to finding a subset with target sum as 
        //(arraySum/2)

        vector<vector<int>>dp(nums.size()+1,vector<int>((arraySum/2)+1,-1));

        return f(nums.size()-1,arraySum/2,nums,dp);

        }
    }
};