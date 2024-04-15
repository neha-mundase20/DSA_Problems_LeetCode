class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int>st;
        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            st.insert(nums2[i]);
        }
        
        vector<int>v;
        
        for(multiset<int>::iterator it=st.begin();it!=st.end();it++){
            v.push_back(*it);
        }
        
        double median=0;
        int p=v.size();
        int n=v.size()-1;
        
        if(p%2!=0){ //size of vector is odd
            median=v[(n/2)];
        }
        else{   //size of vector is even
            median=double(v[n/2]+v[(n/2)+1])/2;
        }
        return median;
    }
};