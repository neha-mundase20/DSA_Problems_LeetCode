class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //Finding pivot index
        int pivotIndex=0,k=0,n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i%n]>nums[(i+1)%n]){
                pivotIndex=i+1;
                break;
            }
        }

        k=pivotIndex;

        int low=0,high=n-1,mid=0,realMid=0;

        while(low<=high){
            mid=low+((high-low)/2);
            realMid=(mid+k)%n;

            if(nums[realMid]==target){
                return true;
            }
            else if(nums[realMid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};