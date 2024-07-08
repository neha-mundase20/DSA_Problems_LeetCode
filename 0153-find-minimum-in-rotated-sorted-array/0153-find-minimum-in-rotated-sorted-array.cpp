class Solution {
public:
    int findMin(vector<int>& nums) {
        //Finding Pivot Index
        int n=nums.size(),minElement=0;

        if(n==1){
            return nums[0];
        }

        for(int i=0;i<n;i++){
            if(nums[i%n]>nums[(i+1)%n]){    
                //%n for wrapping indexes within length
                minElement=nums[(i+1)%n];
                break;
            }
        }
        return minElement;
    }
};