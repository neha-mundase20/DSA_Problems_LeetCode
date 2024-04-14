class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int flag=0,val=0;
        for(int i=0;i<n;i++){   //check if the element is already present and make flag=1;
            if(nums[i]==target){
                flag=1;
                val=i;
                break;
            }
        }
        
        if(flag==0){
            int i=0;
            while(i<n && nums[i]<target){   //if the element isn't already present, iterate                                               //over the array to find the position where it                                                 //should be inserted
                i++;
            }
            val=i;
        }
        
        return val;
    }
    
    /*int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left; // If target is not found, left represents the index where target should                           be inserted
    }*/
};