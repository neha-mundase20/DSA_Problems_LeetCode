class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index=-1;
        
        int l=0,n=nums.size(),u=n-1;
        
        while(l<=u){
            int mid=l+(u-l)/2; // Calculate the mid index
            if(nums[mid]<target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                u=mid-1;
            }
            else{
                index=mid;
                break;
            }
        }
        return index;
    }
};