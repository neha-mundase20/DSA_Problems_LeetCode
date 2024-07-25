class Solution {
public:

    void sorting(vector<int>&nums,int low,int mid,int high){
        vector<int>temp;
        int p=low,q=mid+1;

        while(p<=mid && q<=high){
            if(nums[p]<=nums[q]){
                temp.push_back(nums[p]);
                p++;
            }
            else{
                temp.push_back(nums[q]);
                q++;
            }
        }

        while(p<=mid){
            temp.push_back(nums[p]);
            p++;
        }

        while(q<=high){
            temp.push_back(nums[q]);
            q++;
        }

        //Copy the sorted subarray back to the original array
        for (int i=low;i<=high;i++) {
            nums[i] = temp[i-low];
        }
    }

    void mergeSort(vector<int>&nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low+((high-low)/2);

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        sorting(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        //Using Merge Sort

        //Divide and Merge approach
        int n=nums.size();
        int low=0,high=n-1;

        mergeSort(nums,low,high);
        return nums;
    }
};