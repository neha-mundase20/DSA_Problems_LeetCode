class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int sum=0;
        int minLength=INT_MAX;

        while(j<nums.size()){
            sum=sum+nums[j];

            while(sum>=target){
                minLength=min(minLength,j-i+1);
                sum=sum-nums[i];
                i++;
            }
            j++;
        }
        if(minLength==INT_MAX){
            return 0;
        }
        return minLength;
    }
};