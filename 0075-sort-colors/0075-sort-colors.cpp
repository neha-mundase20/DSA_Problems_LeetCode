class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Using Bubble Sort
        int n=nums.size();
        bool didSwap=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-i-1);j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    didSwap=true;
                }
            }
            if(didSwap==false){
                break;
            }
        }
    }
};