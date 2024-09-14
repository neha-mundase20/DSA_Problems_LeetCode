class Solution {
public:
    int mySqrt(int x) {

        if(x==0 || x==1){
            return x;
        }

        float low=1;
        float high=(float)x/2;
        long long mid=0;

        while(low<=high){
            mid=low+((high-low)/2);
            long long value=mid*mid;
            if((value<(long long)x)){
                low=mid+1;
            }
            else if(value>(long long)x){
                high=mid-1;
            }
            else{
                return mid;
            }
        }
        return high;
    }
};