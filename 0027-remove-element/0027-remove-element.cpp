class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Using the two pointer approach
        //'i' to keep a track of elements which are not equal to 'val' and are hence
        //moved to the right
        //'j' to iterate over 'nums' array
        
        int i=0,j=0,count=0,n=nums.size();
        
        while(i<n && j<n){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
                count++;
            }
            j++;
        }
        return count;
    }
};