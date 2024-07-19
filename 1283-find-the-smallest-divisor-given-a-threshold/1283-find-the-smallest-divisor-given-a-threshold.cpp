class Solution {
public:

    bool isLessThanThreshold(vector<int>& nums, int threshold, int divisor){
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum=sum+(nums[i]+divisor-1)/divisor;
        }

        if(sum<=threshold){
            return true;
        }
        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold){
        //Use Binary Search

        //Minimum divisor will be the 1
        int low=1;

        //Maximum divisor will be the maximum element
        int high=*max_element(nums.begin(),nums.end());

        int mid=0;

        while(low<high){
            mid=low+((high-low)/2);

            if(isLessThanThreshold(nums,threshold,mid)==true){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};