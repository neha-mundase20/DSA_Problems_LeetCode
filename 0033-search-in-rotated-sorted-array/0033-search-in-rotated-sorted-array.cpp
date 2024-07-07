class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Finding the PIVOT INDEX
        int n=nums.size(),flag=0;
        int pivotIndex=0,k=0;

        for(int i=0;i<n;i++){
            if(nums[i%n]>nums[(i+1)%n]){
                pivotIndex=i+1;
                break;
            }
        }
            int low=0,high=n-1,mid=0;

            while(low<=high){
                mid=low+((high-low)/2);
                int realMid=(mid+pivotIndex)%n;

                if(nums[realMid]==target){
                    return realMid;
                }
                else if(nums[realMid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        return -1;  //Target Not Found
    }
};