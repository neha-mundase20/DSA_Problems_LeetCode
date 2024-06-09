class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,n=nums.size();
        long long maxConsecutiveOnes=0,currentOnes=0;
        
        while(i<n){
            if(nums[i]==1){
                currentOnes++;
                i++;
            }
            else{
                maxConsecutiveOnes=max(maxConsecutiveOnes,currentOnes);
                currentOnes=0;
                i++;
            }
            // In case the array ends with 1s, update maxConsecutiveOnes one last time
            maxConsecutiveOnes=max(maxConsecutiveOnes,currentOnes);
        }
        return maxConsecutiveOnes;
    }
};