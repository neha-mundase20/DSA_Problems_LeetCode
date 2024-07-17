class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peakElementIndex=0;
        int n=nums.size();

        /*nums[-1] = nums[n] = -∞. In other words, an element is always         considered to be strictly greater than a neighbor that is outside the array.*/

        if(n==1){
            return 0;
        }
        else if(n==2){
            if(nums[0]>nums[1]){
                return 0;
            }
            else{
                return 1;
            }
        }

        if(nums[0]>nums[1]){
            /*Just checking for the right side value to 0 i.e. 1 coz to the left side value nums[-1]=-infinity*/
            peakElementIndex=0;
        }
        else{
            for(int i=1;i<=n-2;i++){
                if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                    peakElementIndex=i;
                    break;
                }
            }
        }

    /*Just checking for the left side value to n-1 i.e. n-2 coz to the right side value nums[n]=-infinity*/
        if(nums[n-1]>nums[n-2]){
            peakElementIndex=n-1;
        }

        return peakElementIndex;
    }
};