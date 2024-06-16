class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Find the longest prefix match by finding the breakpoint i.e. arr[i]<arr[i+1]
        int n=nums.size();
        int breakPt=-1;
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPt=i;
                break;
            }
        }
        
        if(breakPt==-1){ //Last Permutation
            sort(nums.begin(),nums.end());   //Sort to obtain the first permuatation                                                   //again i.e. [3,2,1]->[1,2,3]
        }
        else{
            //Finding the Immediate Next Number to the breakPt number to find the next                   //permuatation
            
            int immediateNextNumberIndex=breakPt+1;
            
            for(int i=breakPt+1;i<n;i++){
                
                if(nums[i]>nums[breakPt] && nums[i]<=nums[immediateNextNumberIndex]){
                    immediateNextNumberIndex=i;
                }
            }
        
            //Swap the obtained immediate number with the breakpt number
            swap(nums[breakPt],nums[immediateNextNumberIndex]);
        
            //Sort the rest of the array in ascending order
            sort(nums.begin()+(breakPt+1),nums.end());
        }
    }
};