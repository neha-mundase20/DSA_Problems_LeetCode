class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Using the two pointer approach
        
        //'i' to keep a track of the non-zero elements shifted to left of the array
        //'j' to iterate over the array
        
        int i=0,j=0,n=nums.size();
        
        while(i<n && j<n){
            if(nums[j]!=0){
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        
        for(int k=i;k<n;k++){
            nums[k]=0;
        }
    }
};