class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        multiset<int>mst;   //multiset allows storing of multiple elements that occur more                                 //than once in sorted format
        
        for(int i=0;i<m;i++){
            mst.insert(nums1[i]);
        }
        
        for(int i=0;i<n;i++){
            mst.insert(nums2[i]);
        }
        
        int i=0;
        for(auto it:mst){
            nums1[i++]=it;
        }
    }
};