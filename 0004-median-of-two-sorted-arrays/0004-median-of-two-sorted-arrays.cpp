class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0,m=nums1.size(),n=nums2.size();
        vector<int>answer;

        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                answer.push_back(nums1[i]);
                i++;
            }
            else{
                answer.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m){
            answer.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            answer.push_back(nums2[j]);
            j++;
        }


        if((m+n)%2==0){ //even number of elements
            double val1=double(answer[(m+n)/2])/2.0;
            double val2=double(answer[((m+n)/2)-1])/2.0;
            return val1+val2;
        }

        return double(answer[(m+n)/2]);
    }
};