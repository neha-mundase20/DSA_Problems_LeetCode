// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=0,high=n-1,mid=0,currentBad=0;
        
        while(low<=high){
            mid=low+((high-low)/2);
            
            bool answer=isBadVersion(mid+1);    //0-based Indexing
            
            if(answer==false){  //all versions previous to thus will also be good versions
                low=mid+1;
            }
            else{
                currentBad=mid+1;
                high=mid-1; //this version is bad so check for any other bad version before                                //this
            }
        }
        return currentBad;
    }
};