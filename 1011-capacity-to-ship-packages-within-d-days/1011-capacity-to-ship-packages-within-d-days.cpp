class Solution {
public:
    //Function to calculate the number of days required to ship
    //items in ship having certain weight

    int getDays(vector<int>& weights,int wt){
        int load=0,days=1;
        for(auto it:weights){
            if(load+it>wt){
                days++;
                load=it;
            }
            else{
                load=load+it;
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        //The lowest capacity the ship can have is atleast the maximum element
        int sum=0;
        for(auto it:weights){
            sum=sum+it;
        }
        int high=sum;
        //The highest capacity the ship can have is the totalSum of all items
        int mid=0;

        while(low<=high){
            mid=low+(high-low)/2;
            if(getDays(weights,mid)<=days) {
                /* If the current capacity can ship within required days, try a smaller capacity*/
                high=mid-1;
            } else {
                // Otherwise, increase the capacity
                low=mid+1;
            }
        }
        return low;
    }
};