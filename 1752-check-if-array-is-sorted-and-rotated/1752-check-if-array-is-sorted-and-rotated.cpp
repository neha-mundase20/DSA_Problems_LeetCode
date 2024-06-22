class Solution {
public:
    bool check(vector<int>& nums) {
        bool isSorted=true;
        int breakPointCount=0,n=nums.size();
        
        //Obtain the breakpoint where the sorted order disrupts
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                breakPointCount++;
            }
        }
        
        return breakPointCount<=1;
    }
};